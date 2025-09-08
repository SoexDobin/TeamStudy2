#include "pch.h"
#include "CScene04.h"
#include "CLine.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CLineManager.h"
#include "CObjectManager.h"

CScene04::CScene04()
{

}
CScene04::~CScene04()
{
	Release();
}
void CScene04::Initialize()
{
	CLineManager::GetInstance()->LoadDataFour();
	
	for (int i = 0; i < 3; i++)
	{
		m_dTime = GetTickCount();

		if (m_dTime + 50000 > GetTickCount())
		{
			CObjectManager::GetInstance()->AddObject(MONSTER, CAbstractFactory<CMonster>::Create(600.f+i*300, 500.f));
			m_MonsterList.push_back(CObjectManager::GetInstance()->GetMonsterList()->back());
		
		}
	}

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
	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L" TIME : %f", m_dTime);
	TextOut(_hDC, 300, 600, szBuff, lstrlen(szBuff));
}
void CScene04::Release()
{


}