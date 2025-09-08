#include "pch.h"
#include "CObjectManager.h"
#include "CObject.h"
#include "CCollisionManager.h"

CObjectManager* CObjectManager::m_pInstance = nullptr;

CObjectManager::CObjectManager()
{
}
CObjectManager::~CObjectManager()
{
	Release();
}
CObject* CObjectManager::AddObject(OBJECT _eID, CObject* _pObject)
{
	if (_eID >= OBJ_END || _pObject == nullptr)
		return 0;

	m_ObjectList[_eID].push_back(_pObject);

	return _pObject;
}

void CObjectManager::Initialize()
{

}
int CObjectManager::Update()
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
	return 0;
}
void CObjectManager::LateUpdate()
{
	for (auto& list : m_ObjectList)
		for (auto& obj : list)
			obj->LateUpdate();
}
void CObjectManager::Render(HDC hdc)
{
	for (auto& list : m_ObjectList)
		for (auto& obj : list)
			obj->Render(hdc);

	CCollisionManager::Collision(&m_ObjectList[PLAYER], &m_ObjectList[MONSTER], CIRCLE_TO_RECT);
	CCollisionManager::Collision(&m_ObjectList[MONSTER], &m_ObjectList[BULLET], CIRCLE_TO_RECT);
}
void CObjectManager::Release()
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