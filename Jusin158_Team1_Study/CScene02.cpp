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
	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();
	m_pPlayer->SetPivot(Vector2(100.f, 500.f));
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(3300.f, 100.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CSecondBoss>::Create(5300.f, 300.f));
	m_pBoss = CObjectManager::GetInstance()->GetMonsterList()->back();
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(800.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(600.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(500.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(700.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(1000.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(1400.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(1800.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(2000.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CGuideMonster>::Create(2500.f, 200.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
}
int CScene02::Update()
{
	if (m_pBoss->GetDestroy())
		CSceneManager::GetInstance()->ChangeScene(SCENE03);
	
	
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
	for (auto& monster : m_MonsterList)
	{
		monster->SetDestroy();
	}
	CLineManager::GetInstance()->DestroyInstance();
}