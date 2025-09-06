#pragma once
#include "CScene.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"
class CSceneManager
{

public:
	CSceneManager();
	CSceneManager(const CSceneManager& rhs) = delete;
	CSceneManager& operator=(CSceneManager& rManager) = delete;
	~CSceneManager();

public:
	static CSceneManager* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CSceneManager;

		}

		return m_pInstance;
	}

	static void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}



public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

private:
	static CSceneManager* m_pInstance;
	CScene* m_pScene;
	CObject* m_pPlayer;
	int m_iSceneNumber;
};

