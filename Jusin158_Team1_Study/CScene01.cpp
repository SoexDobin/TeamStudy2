#include "pch.h"
#include "CAbstractFactory.h"
#include "CScene01.h"
#include "CMonster.h"
#include "CLineManager.h"

CScene01::CScene01() :m_bDead(false)
{
}
CScene01::~CScene01()
{
	Release();
}

void CScene01::Initialize()
{
	CLineManager::GetInstance()->LoadDataOne();
	CObjectManager::GetInstance()->AddObject(MONSTER, AbstractFactory<CMonster>::Create());
	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());

	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();
}

int CScene01::Update()
{
	if (m_bDead == true)
		return OBJ_DESTROY;

	if (GetAsyncKeyState('Y'))
	{
		m_bDead = true;
	}

	return OBJ_NOEVENT;
}
void CScene01::LateUpdate()
{
	if (GetAsyncKeyState('S'))
	{
		CLineManager::GetInstance()->SaveDataOne();
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