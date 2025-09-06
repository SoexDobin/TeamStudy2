#include "pch.h"
#include "CMainGame.h"
#include "CObject.h"
#include "CSceneManager.h"
#include "CObjectManager.h"
#include "CAbstractFactory.h"
#include "CPlayer.h"

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
	CObjectManager::GetInstance()->AddObject(PLAYER, AbstractFactory<CPlayer>::Create());

}

void CMainGame::Update()
{
	CObjectManager::GetInstance()->Update();
}

void CMainGame::LateUpdate()
{
	CObjectManager::GetInstance()->LateUpdate();
}



void CMainGame::Render()
{
	{ // 기존 Rectangle을 그려서 깜빡임 최소화 한걸 더블 버퍼링으로 바꿈
		//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
		BitBlt(m_hDC, 0, 0, m_tRect.right, m_tRect.bottom, m_hDCBack, 0, 0, SRCCOPY);
		PatBlt(m_hDCBack, 0, 0, m_tRect.right, m_tRect.bottom, WHITENESS);
	}


	CObjectManager::GetInstance()->Render(m_hDC);
	// dc 사용 시 m_hDCBack 멤버 변수 사용할 것
	// 백버퍼 시점 dc를 따로 복사해서 사용해야 함
	
	// 여기서 충돌검사를 실행
}

void CMainGame::Release()
{
	CObjectManager::GetInstance()->Release();
}