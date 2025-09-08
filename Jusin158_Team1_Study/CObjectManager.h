#pragma once
#include "CObject.h"

class CObjectManager
{
private:

	CObjectManager();
	CObjectManager(const CObjectManager& rhs) = delete;
	CObjectManager& operator=(CObjectManager& rManager) = delete;
	~CObjectManager();

public:
	CObject* AddObject(OBJECT _eID, CObject* _pObject);
	void Initialize();
	int Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();
	list<CObject*>* GetBulletList() { return &m_ObjectList[BULLET]; }

public:
	list<CObject*>* GetMonsterList() { return  &m_ObjectList[MONSTER]; }
	list<CObject*>* GetPlayer() {return &m_ObjectList[PLAYER];}

public:
	static CObjectManager* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CObjectManager;
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


private:
	list<CObject*> m_ObjectList[OBJ_END];
	static CObjectManager* m_pInstance;
};

