#include "pch.h"
#include "CAbstractFactory.h"
#include "CGuideMonster.h"
#include "CScene02.h"
#include "CMonster.h"
#include "CSecondBoss.h"
#include "CLineManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"

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

	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CMonster>::Create(3300.f, 100.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CSecondBoss>::Create(5300.f, 300.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(800.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(600.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(500.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(700.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(1000.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(1400.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(1800.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(2000.f, 200.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CGuideMonster>::Create(2500.f, 200.f));

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