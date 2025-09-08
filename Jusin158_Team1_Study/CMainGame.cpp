#include "pch.h"

#include "CMainGame.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMouse.h"

#include "CLineManager.h"
#include "CAbstractFactory.h"
#include "CSceneManager.h"
#include "CObjectManager.h"
#include "CScene04.h"`
#include "CKeyManager.h"
#include "CScrollManager.h"
#include "CBmpManager.h"

CMainGame::CMainGame() : m_hDC(nullptr), m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	// 더블 버퍼링
	{
		GetClientRect(g_hWnd, &m_tRect);
		m_hDCBack = CreateCompatibleDC(m_hDC);
		m_bmpBack = CreateCompatibleBitmap(m_hDC, m_tRect.right, m_tRect.bottom);
		HBITMAP prev = (HBITMAP)::SelectObject(m_hDCBack, m_bmpBack);
		DeleteObject(prev);
	}
	CLineManager::GetInstance()->Initialize();
	SetPlayer(CObjectManager::GetInstance()->AddObject(PLAYER, CAbstractFactory<CPlayer>::Create()));
	CSceneManager::GetInstance()->ChangeScene(SCENE04);
	
	CObjectManager::GetInstance()->AddObject(MOUSE, CAbstractFactory<CMouse>::Create());

	CBmpManager::GetInstance()->Insert_Bmp(L"../../Image/Back.bmp", L"Back");
}

void CMainGame::Update()
{
	CSceneManager::GetInstance()->Update();
	CLineManager::GetInstance()->Update();
	CKeyManager::Get_Instance()->KeyUpdate();
}

void CMainGame::LateUpdate()
{
	CSceneManager::GetInstance()->LateUpdate();
	CLineManager::GetInstance()->Late_Update();
}
void CMainGame::Render()
{
	{
		//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
		BitBlt(m_hDC, 0, 0, m_tRect.right, m_tRect.bottom, m_hDCBack, 0, 0, SRCCOPY);		
		PatBlt(m_hDCBack, 0, 0, m_tRect.right, m_tRect.bottom, WHITENESS);
	}

	CLineManager::GetInstance()->Render(m_hDCBack);
	CObjectManager::GetInstance()->Render(m_hDCBack);
	// dc 사용 시 m_hDCBack 멤버 변수 사용할 것
	// 백버퍼 시점 dc를 따로 복사해서 사용해야 함

	// 여기서 충돌검사를 실행
	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L" 스테이지 : %d", CSceneManager::GetInstance()->GetSceneNumber());
	TextOut(m_hDCBack, 50, 200, szBuff, lstrlen(szBuff));

	HDC	hBackDC = CBmpManager::GetInstance()->Find_Img(L"Back");
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBackDC, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	CBmpManager::DestroyInstance();
	CKeyManager::Destroy_Instance();
	CLineManager::DestroyInstance();
	CObjectManager::DestroyInstance();
	CSceneManager::DestroyInstance();
	CScrollManager::Destroy_Instance();
	ReleaseDC(g_hWnd, m_hDC);
}