#include "pch.h"
#include "CLineManager.h"
#include "CKeyManager.h"

CLineManager* CLineManager::m_pInstance = nullptr;

CLineManager::CLineManager()
{
	ZeroMemory(m_tLinePoint, sizeof(m_tLinePoint));
}
CLineManager::~CLineManager()
{
	Release();
}

void CLineManager::Initialize()
{
	
}
int	CLineManager::Update()
{
	// get mouse x,y
	POINT pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// starting point
	if (CKeyManager::Get_Instance()->KeyDown(VK_LBUTTON))
	{
		m_tLinePoint[LEFT].fX = (float)pt.x;
		m_tLinePoint[LEFT].fY = (float)pt.y;
	}
	// ending point
	else if (CKeyManager::Get_Instance()->KeyDown(VK_RBUTTON) && (m_tLinePoint[LEFT].fX != 0.f || m_tLinePoint[LEFT].fY != 0.f))
	{
		m_tLinePoint[RIGHT].fX = (float)pt.x;
		m_tLinePoint[RIGHT].fY = (float)pt.y;
	}

	// if left and right have value, push back in vector
	if ((m_tLinePoint[LEFT].fX != 0.f || m_tLinePoint[LEFT].fY != 0.f) && (m_tLinePoint[RIGHT].fX != 0.f || m_tLinePoint[RIGHT].fY != 0.f))
	{
		vecLine.push_back(new CLine(m_tLinePoint[LEFT], m_tLinePoint[RIGHT]));
		m_tLinePoint[LEFT].fX = 0.f;
		m_tLinePoint[LEFT].fY = 0.f;
		m_tLinePoint[RIGHT].fX = 0.f;
		m_tLinePoint[RIGHT].fY = 0.f;
	}
	return OBJ_NOEVENT;
}
void CLineManager::Late_Update()
{
	if (CKeyManager::Get_Instance()->KeyDown('S'))
	{
		SaveData();
		return;
	}
}
void CLineManager::Render(HDC hDC)
{
	for (auto& pLine : vecLine)
		pLine->Render(hDC);
}
void CLineManager::Release()
{
	for_each(vecLine.begin(), vecLine.end(), DeleteObj());
	vecLine.clear();
}

bool CLineManager::Collision_Bottom_Line(float _fX, float _fY, float* _pY, float fPlayerSize)
{
	if (vecLine.empty())
	{
		return false;
	}

	CLine* pLine = nullptr;

	for (int i = 0; i < vecLine.size(); ++i)
	{
		// check left and right pointX
		if ((_fX >= vecLine[i]->GetLineInfo().tLPoint.fX &&
			_fX <= vecLine[i]->GetLineInfo().tRPoint.fX) ||
			(_fX <= vecLine[i]->GetLineInfo().tLPoint.fX &&
				_fX >= vecLine[i]->GetLineInfo().tRPoint.fX))
		{
			// check left and right pointY
			if ((_fY >= vecLine[i]->GetLineInfo().tLPoint.fY &&
				_fY <= vecLine[i]->GetLineInfo().tRPoint.fY) ||
				(_fY <= vecLine[i]->GetLineInfo().tLPoint.fY &&
					_fY >= vecLine[i]->GetLineInfo().tRPoint.fY))
			{
				pLine = vecLine[i];
				break;
			}
		}
	}

	if (!pLine)
	{
		return false;
	}

	// left point's X and Y
	float fFirstX = pLine->GetLineInfo().tLPoint.fX;
	float fFirstY = pLine->GetLineInfo().tLPoint.fY;

	// right point's X and Y
	float fSecondX = pLine->GetLineInfo().tRPoint.fX;
	float fSecondY = pLine->GetLineInfo().tRPoint.fY;

	// distance from circle's pivot to line 
	float fDistance = fabsf(((fSecondY - fFirstY) / (fSecondX - fFirstX) * _fX +
		(-1 * (_fY)) + fFirstY +
		(-1 * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * fFirstX)) /
		sqrtf(((fSecondY - fFirstY) / (fSecondX - fFirstX)) * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) + 1));

	// collision of circle and line
	if (fPlayerSize >= fDistance)
	{
		*_pY = ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * (_fX - fFirstX) + fFirstY;
		float fRadian = 3.14f * 0.5f -
			acosf((_fX - fFirstX) / sqrtf((_fX - fFirstX) * (_fX - fFirstX) + (*_pY - fFirstY) * (*_pY - fFirstY)));
		*_pY -= fPlayerSize * sinf(fRadian);
		return true;
	}
	return false;
}

void CLineManager::SaveData()
{
	HANDLE hFile = CreateFile(L"../Data/Line.dat",
		GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(g_hWnd, L"Saved Fail", _T("Error"), MB_OK);
		return;
	}

	DWORD dwByte = 0;
	
	for (auto& pLine : vecLine)
	{
		WriteFile(hFile, &(pLine->GetLineInfo()), sizeof(LINE), &dwByte, nullptr);
	}
	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Success", _T("Save Success"), MB_OK);
}
void CLineManager::LoadData()
{
	HANDLE hFile = CreateFile(L"../Data/Line.dat",
		GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(g_hWnd, L"Saved Fail", _T("Error"), MB_OK);
		return;
	}

	DWORD dwByte = 0;
	LINE tLine{};

	while (ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr))
	{
		if (dwByte == 0)
		{
			break;
		}
		vecLine.push_back(new CLine(tLine.tLPoint, tLine.tRPoint));
	}
	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Success", _T("Load Success"), MB_OK);
}

// inactive
//bool CLineManager::Collision_Top_Line(float _fX, float _fY, float fPlayerSize)
//{
//	if (vecLine.empty())
//	{
//		return false;
//	}
//
//	CLine* pLine = nullptr;
//
//	for (int i = 0; i < vecLine.size(); ++i)
//	{
//		if (_fX > vecLine[i]->GetLineInfo().tLPoint.fX &&
//			_fX < vecLine[i]->GetLineInfo().tRPoint.fX)
//		{
//			if ((_fY > vecLine[i]->GetLineInfo().tLPoint.fY &&
//				_fY < vecLine[i]->GetLineInfo().tRPoint.fY) ||
//				(_fY < vecLine[i]->GetLineInfo().tLPoint.fY &&
//					_fY > vecLine[i]->GetLineInfo().tRPoint.fY))
//			{
//				pLine = vecLine[i];
//				break;
//			}
//		}
//	}
//
//	if (!pLine)
//	{
//		return false;
//	}
//
//	float fFirstX = pLine->GetLineInfo().tLPoint.fX;
//	float fFirstY = pLine->GetLineInfo().tLPoint.fY;
//
//	float fSecondX = pLine->GetLineInfo().tRPoint.fX;
//	float fSecondY = pLine->GetLineInfo().tRPoint.fY;
//
//	float fdistance = fabsf(((fSecondY - fFirstY) / (fSecondX - fFirstX) * _fX +
//		(-1 * (_fY)) + fFirstY +
//		(-1 * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * fFirstX)) /
//		sqrtf(((fSecondY - fFirstY) / (fSecondX - fFirstX)) * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) + 1));
//
//	if (fPlayerSize < fdistance)
//	{
//		return true;
//	}
//	return false;
//}