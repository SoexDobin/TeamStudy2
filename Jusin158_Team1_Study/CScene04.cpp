#include "pch.h"
#include "CScene04.h"
#include "CLine.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CLineManager.h"
#include "CObjectManager.h"
#include "FourthBoss.h"

CScene04::CScene04() : m_MonsterIDX(1)
{

}
CScene04::~CScene04()
{
	Release();
}
void CScene04::Initialize()
{
	CLineManager::GetInstance()->LoadDataFour();
	m_dTime = GetTickCount64();
	m_pPlayer = CObjectManager::GetInstance()->GetPlayer()->back();

}
int CScene04::Update()
{

	if (m_bDead == true)
		return OBJ_DESTROY;

	if (m_pBoss == nullptr)
	{
		m_bDead = true;
	}

		if (m_dTime + 2000 <  GetTickCount64()&&m_MonsterIDX<6)
		{
			CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(300.f*m_MonsterIDX, 500.f));
			m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
			m_MonsterIDX++;


			m_dTime = GetTickCount64();

		}

	if (m_MonsterList.empty()==true)
	{
		CObjectManager::GetInstance()->AddObject(FOURTHBOSS, CAbstractFactory<FourthBoss>::Create());
	}
	//이거 한 번만 생성되게 수정해야 함!
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