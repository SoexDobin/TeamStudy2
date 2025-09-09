#include "pch.h"
#include "CScene03.h"
#include "CLineManager.h"
#include "CKeyManager.h"
#include "CObjectManager.h"
#include "CSceneManager.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
CScene03::CScene03() : m_pPlayer(nullptr), m_pBoss(nullptr)
{

}
CScene03::~CScene03()
{
	Release();
}
void CScene03::Initialize()
{
	CLineManager::GetInstance()->LoadDataThree();
	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();
	m_pPlayer->SetPivot(Vector2(500, 300));
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(2700.f, 300.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	m_pBoss = CObjectManager::GetInstance()->GetMonsterList()->back();
	m_pBoss->SetHp(500);
}
int CScene03::Update()
{
	if (m_pBoss == nullptr || m_pBoss->GetDestroy())
	{
		m_pPlayer->SetPivot(Vector2(500.f, 300.f));
		CSceneManager::GetInstance()->ChangeScene(SCENE04);
	}
		

	return OBJ_NOEVENT;
}
void CScene03::LateUpdate()
{
	

	if (CKeyManager::GetInstance()->KeyDown('Y'))
		CSceneManager::GetInstance()->ChangeScene(SCENE04);

	if (CKeyManager::GetInstance()->KeyDown('S'))
		CLineManager::GetInstance()->SaveDataThree();
}
void CScene03::Render(HDC _hDC)
{

}
void CScene03::Release()
{
	for (auto& monster : m_MonsterList)
	{
		monster->SetDestroy();
	}
	CLineManager::GetInstance()->DestroyInstance();
}