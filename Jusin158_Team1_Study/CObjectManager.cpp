#include "pch.h"
#include "CObjectManager.h"
#include "CObject.h"

CObjectManager::CObjectManager()
{
}
CObjectManager::~CObjectManager()
{
}
void CObjectManager::AddObject(OBJECT _eID, CObject* _pObject)
{
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