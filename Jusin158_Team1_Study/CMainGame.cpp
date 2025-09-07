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

CMainGame::CMainGame() : m_hDC(nullptr)
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
	SetPlayer(CObjectManager::GetInstance()->AddObject(PLAYER, AbstractFactory<CPlayer>::Create()));
	CSceneManager::GetInstance()->ChangeScene(SCENE01);
	
	CObjectManager::GetInstance()->AddObject(MOUSE, AbstractFactory<CMouse>::Create());
}

void CMainGame::Update()
{
	CSceneManager::GetInstance()->Update();
	CLineManager::GetInstance()->Update();

}

}
void CMainGame::LateUpdate()
{
	CSceneManager::GetInstance()->LateUpdate();
}
void CMainGame::Render()
{
	CSceneManager::GetInstance()->Render(m_hDC);
}

void CMainGame::Release()
{
	CKeyManager::Destroy_Instance();
	CLineManager::DestroyInstance();
	CObjectManager::DestroyInstance();
	CSceneManager::DestroyInstance();
}