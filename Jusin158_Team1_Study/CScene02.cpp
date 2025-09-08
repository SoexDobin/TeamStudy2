#include "pch.h"
#include "CAbstractFactory.h"
#include "CScene02.h"
#include "CMonster.h"
#include "CLineManager.h"
#include "CKeyManager.h"

CScene02::CScene02()
{

}
CScene02::~CScene02()
{
	Release();
}
void CScene02::Initialize()
{
	CLineManager::GetInstance()->LoadDataTwo();

	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CMonster>::Create());

}
int CScene02::Update()
{
	

	return OBJ_NOEVENT;
}
void CScene02::LateUpdate()
{
	if (GetAsyncKeyState('S'))
	{
		CLineManager::GetInstance()->SaveDataTwo();
		return;
	}
}
void CScene02::Render(HDC _hDC)
{
	
}
void CScene02::Release()
{
	
}