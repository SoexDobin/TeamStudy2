#include "pch.h"
#include "CScene04.h"
#include "CLine.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CLineManager.h"
#include "CObjectManager.h"
#include "FourthBoss.h"

CScene04::CScene04() : m_MonsterIDX(1), m_bStart(false), m_bDead(false), m_bKillCount(false)
{

}
CScene04::~CScene04()
{
	Release();
}
void CScene04::Initialize()
{
	CLineManager::GetInstance()->LoadDataFour();
	CObjectManager::GetInstance()->GetPlayer()->back()->SetPivot({50.f, 500.f});
	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();
	
	//for (int i = 1; i < m_MonsterIDX; i++)
	//{
	//	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(300.f * i, 500.f));
	//	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
	//}
	m_pBoss = CObjectManager::GetInstance()->AddObject(FOURTHBOSS, CAbstractFactory<FourthBoss>::Create());

	m_dTime = GetTickCount64();
}

int CScene04::Update()
{
	


	if (m_bDead == true)
		return OBJ_DESTROY;

	if (m_pBoss == nullptr || m_pBoss->GetDestroy())
	{
		m_bDead = true;
	}

		//if (m_dTime + 2000 <  GetTickCount64()&&m_MonsterIDX<6)
		//{
		//	CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(300.f*m_MonsterIDX, 500.f));
		//	m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
		//	m_MonsterIDX++;
		//
		//
		//	m_dTime = GetTickCount64();
		//
		//}

	if (m_dTime + 2000 < GetTickCount64() && m_MonsterIDX < 6)
	{
		CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(300.f * m_MonsterIDX, 500.f));
		m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
		m_MonsterIDX++;

		m_dTime = GetTickCount64();
	}



	return OBJ_NOEVENT;
}
void CScene04::LateUpdate()
{
	if (GetAsyncKeyState('S'))
	{
		CLineManager::GetInstance()->SaveDataFour();
		return;
	}
}
void CScene04::Render(HDC _hDC)
{
}
void CScene04::Release()
{


}