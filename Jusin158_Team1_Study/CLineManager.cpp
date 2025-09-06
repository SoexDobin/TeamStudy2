#include "pch.h"
#include "CLineManager.h"

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
	POINT pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if (!m_tLinePoint[LEFT].fX && !m_tLinePoint[LEFT].fY)
		{
			m_tLinePoint[LEFT].fX = (float)pt.x;
			m_tLinePoint[LEFT].fY = (float)pt.y;
		}

		else
		{
			m_tLinePoint[RIGHT].fX = (float)pt.x;
			m_tLinePoint[RIGHT].fY = (float)pt.y;

			vecLine.push_back(new CLine(m_tLinePoint[LEFT], m_tLinePoint[RIGHT]));

			m_tLinePoint[LEFT].fX = m_tLinePoint[RIGHT].fX;
			m_tLinePoint[LEFT].fY = m_tLinePoint[RIGHT].fY;
		}
	}
	return OBJ_NOEVENT;
}
void CLineManager::Late_Update()
{

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
		if ((_fX > vecLine[i]->GetLineInfo().tLPoint.fX &&
			_fX < vecLine[i]->GetLineInfo().tRPoint.fX) ||
			(_fX < vecLine[i]->GetLineInfo().tLPoint.fX &&
				_fX > vecLine[i]->GetLineInfo().tRPoint.fX))
		{
			if ((_fY > vecLine[i]->GetLineInfo().tLPoint.fY &&
				_fY < vecLine[i]->GetLineInfo().tRPoint.fY) ||
				(_fY < vecLine[i]->GetLineInfo().tLPoint.fY &&
					_fY > vecLine[i]->GetLineInfo().tRPoint.fY))
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

	float fFirstX = pLine->GetLineInfo().tLPoint.fX;
	float fFirstY = pLine->GetLineInfo().tLPoint.fY;

	float fSecondX = pLine->GetLineInfo().tRPoint.fX;
	float fSecondY = pLine->GetLineInfo().tRPoint.fY;

	float fDistance = fabsf(((fSecondY - fFirstY) / (fSecondX - fFirstX) * _fX +
		(-1 * (_fY)) + fFirstY +
		(-1 * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * fFirstX)) /
		sqrtf(((fSecondY - fFirstY) / (fSecondX - fFirstX)) * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) + 1));

	if (fPlayerSize > fDistance)
	{
		*_pY = ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * (_fX - fFirstX) + fFirstY;
		return true;
	}
	return false;
}

bool CLineManager::Collision_Top_Line(float _fX, float _fY, float fPlayerSize)
{
	if (vecLine.empty())
	{
		return false;
	}

	CLine* pLine = nullptr;

	for (int i = 0; i < vecLine.size(); ++i)
	{
		if (_fX > vecLine[i]->GetLineInfo().tLPoint.fX &&
			_fX < vecLine[i]->GetLineInfo().tRPoint.fX)
		{
			if ((_fY > vecLine[i]->GetLineInfo().tLPoint.fY &&
				_fY < vecLine[i]->GetLineInfo().tRPoint.fY) ||
				(_fY < vecLine[i]->GetLineInfo().tLPoint.fY &&
					_fY > vecLine[i]->GetLineInfo().tRPoint.fY))
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

	float fFirstX = pLine->GetLineInfo().tLPoint.fX;
	float fFirstY = pLine->GetLineInfo().tLPoint.fY;

	float fSecondX = pLine->GetLineInfo().tRPoint.fX;
	float fSecondY = pLine->GetLineInfo().tRPoint.fY;

	float fdistance = fabsf(((fSecondY - fFirstY) / (fSecondX - fFirstX) * _fX +
		(-1 * (_fY)) + fFirstY +
		(-1 * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) * fFirstX)) /
		sqrtf(((fSecondY - fFirstY) / (fSecondX - fFirstX)) * ((fSecondY - fFirstY) / (fSecondX - fFirstX)) + 1));

	if (fPlayerSize < fdistance)
	{
		return true;
	}
	return false;
}