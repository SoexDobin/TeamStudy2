#pragma once
#include "CObject.h"

class CObjectManager
{
private:

	CObjectManager();
	~CObjectManager();

public:
	void AddObject(OBJECT _eID, CObject* _pObject);
	int Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

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

