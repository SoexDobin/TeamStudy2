#include "pch.h"
#include "CAbstractFactory.h"
#include "CScene01.h"
#include "CLineManager.h"
#include "CKeyManager.h"
#include "CFirstBoss.h"

CScene01::CScene01() :m_bDead(false), m_pBoss(nullptr), m_pPlayer(nullptr)
{
}
CScene01::~CScene01()
{
	Release();
}
void CScene01::Initialize()
{
	CLineManager::GetInstance()->LoadDataOne();
	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CFirstBoss>::Create(488.f, 222.f));
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();
}

int CScene01::Update()
{
	if (m_bDead == true)
		return OBJ_DESTROY;

	for (auto iter = CObjectManager::GetInstance()->GetMonsterList()->rbegin();
		iter != CObjectManager::GetInstance()->GetMonsterList()->rend();
		++iter)
	{
		dynamic_cast<CMonster*>(*iter)->SetPlayerXY(m_pPlayer->GetPivot().x, m_pPlayer->GetPivot().y);
	}

	if (GetAsyncKeyState('Y'))
	{
		m_bDead = true;
	}
	return OBJ_NOEVENT;
}
void CScene01::LateUpdate()
{
#pragma region 저장
	if (GetAsyncKeyState('S'))
	{
		CLineManager::GetInstance()->SaveDataOne();
		return;
	}
#pragma endregion
	if (CObjectManager::GetInstance()->GetMonsterList()->empty())
	{
		m_bDead = true;
	}
}
void CScene01::Render(HDC _hDC)
{
	
}
void CScene01::Release()
{
	for (auto& monster : m_MonsterList)
	{
		monster->SetDestroy();
	}
	CLineManager::GetInstance()->DestroyInstance();
}