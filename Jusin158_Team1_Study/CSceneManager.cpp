#include "pch.h"
#include "CSceneManager.h"
#include "CScene01.h"
#include "CScene02.h"
#include "CScene03.h"
#include "CScene04.h"

CSceneManager* CSceneManager::m_pInstance = nullptr;

CSceneManager::CSceneManager() : m_pScene(nullptr),m_SceneNumber(SCENE_END)
{
}
CSceneManager::~CSceneManager()
{
	Release();
}
void CSceneManager::Initialize()
{
	
}
void CSceneManager::Update()
{
	CObjectManager::GetInstance()->Update();
	if (m_pScene)
	{
		m_bDead= m_pScene->Update();


		if (m_bDead)
		{
			switch (m_SceneNumber)
			{
			case SCENE01:
				CSceneManager::GetInstance()->ChangeScene(SCENE02);
				break;
			case SCENE02:
				CSceneManager::GetInstance()->ChangeScene(SCENE03);
				break;
			case SCENE03:
				CSceneManager::GetInstance()->ChangeScene(SCENE04);
				break;
			}
		}

		else
		{
			return;
		}

	}





}
void CSceneManager::LateUpdate()
{
	CObjectManager::GetInstance()->LateUpdate();
	if (m_pScene)
	{
		m_pScene->LateUpdate();
	}
}
void CSceneManager::Render(HDC hdc)
{
	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"스테이지 : %d", CSceneManager::GetInstance()->GetSceneNumber());
	TextOut(hdc, 50, 200, szBuff, lstrlen(szBuff));
	CObjectManager::GetInstance()->Render(hdc);
	if (m_pScene)
	{
		m_pScene->Render(hdc);
	}
}
void CSceneManager::Release()
{
	SafeDelete(m_pScene);
}

int CSceneManager::ChangeScene(SCENENUMBER _eSceneNumber)
{
	if (m_SceneNumber == _eSceneNumber)
		return 0;

	CScene* newScene = nullptr;

	switch (_eSceneNumber)
	{
	case SCENE01:
		newScene = new CScene01;
		m_SceneNumber = SCENE01;
		break;
	case SCENE02:
		newScene = new CScene02;
		m_SceneNumber = SCENE02;
		break;
	case SCENE03:
		newScene = new CScene03;
		m_SceneNumber = SCENE03;
		break;
	case SCENE04:
		newScene = new CScene04;
		m_SceneNumber = SCENE04;
			break;
	}
	//�⺻ �Ҵ�� Scene ����
	SafeDelete(m_pScene);
	//���ο� Scene �Ҵ�
	m_pScene = newScene;	

	m_pScene->Initialize();
	return 0;
}

