#include "pch.h"
#include "CMainGame.h"
#include "CObject.h"

CMainGame::CMainGame() : m_hDC(nullptr)
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	{ // 더블 버퍼링
		GetClientRect(g_hWnd, &m_tRect);
		m_hDCBack = CreateCompatibleDC(m_hDC);
		m_bmpBack = CreateCompatibleBitmap(m_hDC, m_tRect.right, m_tRect.bottom);
		HBITMAP prev = (HBITMAP)::SelectObject(m_hDCBack, m_bmpBack);
		DeleteObject(prev);
	}

}

void CMainGame::Update()
{
	bool bIsDestroy(false);
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjectList[i].begin(); iter != m_ObjectList[i].end();)
		{
			bIsDestroy = (*iter)->Update();

			if (bIsDestroy)
			{
				SafeDelete<CObject*>((*iter));
				iter = m_ObjectList[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CMainGame::LateUpdate()
{
	for (auto& list : m_ObjectList)
		for (auto& obj : list)	
			obj->LateUpdate();
}

void CMainGame::Render()
{
	{ // 기존 Rectangle을 그려서 깜빡임 최소화 한걸 더블 버퍼링으로 바꿈
		//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
		BitBlt(m_hDC, 0, 0, m_tRect.right, m_tRect.bottom, m_hDCBack, 0, 0, SRCCOPY);
		PatBlt(m_hDCBack, 0, 0, m_tRect.right, m_tRect.bottom, WHITENESS);
	}

	for (auto& list : m_ObjectList)
		for (auto& obj : list)
			obj->Render(m_hDC);

	// dc 사용 시 m_hDCBack 멤버 변수 사용할 것
	// 백버퍼 시점 dc를 따로 복사해서 사용해야 함
	
	// 여기서 충돌검사를 실행
}

void CMainGame::Release()
{
	for (int i = 0; i < OBJ_END; ++i)
		for_each(m_ObjectList[i].begin(), m_ObjectList[i].end()
			, [](CObject* _p) -> void {
				if (_p)
				{
					delete _p;
					_p = nullptr;
				}
			});
}