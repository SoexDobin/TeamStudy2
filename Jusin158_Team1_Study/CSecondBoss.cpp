#include "pch.h"
#include "CSecondBoss.h"
#include "CBullet.h"
#include "CScrollManager.h"
#include "CAbstractFactory.h"
#include "CGuideMonster.h"
#include "CMonster.h"
#include "CObjectManager.h"

CSecondBoss::CSecondBoss()
{
	m_lFirstskilltime = GetTickCount64();
	m_lSecondskilltime = GetTickCount64();
}

CSecondBoss::~CSecondBoss()
{
	Release();
}

void CSecondBoss::Initialize()
{
	m_vSize = { 100.f, 200.f };

	m_fSpeed = 3.f;

	m_iHp = 100;
}

int CSecondBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	m_vPivot.y -= m_fSpeed;
	__super::UpdateRect();

	return OBJ_NOEVENT;
}

void CSecondBoss::LateUpdate()
{
	if (m_iHp <= 0)
	{
		m_bDestroy = true;
	}

	if (0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_fSpeed *= -1.f;
	}

	if (m_lFirstskilltime + 7000 < GetTickCount64())
	{
		CObjectManager::GetInstance()->GetMonsterList()->push_back(CAbstractFactory<CGuideMonster>::Create(5000.f, 600.f));
		CObjectManager::GetInstance()->GetMonsterList()->push_back(CAbstractFactory<CGuideMonster>::Create(5100.f, 600.f));
		
		m_lFirstskilltime = GetTickCount64();
	}

	if (m_lSecondskilltime + 15000 < GetTickCount64())
	{
		CObjectManager::GetInstance()->GetMonsterList()->push_back(CAbstractFactory<CMonster>::Create(4950.f, 300.f));
	
		m_lSecondskilltime = GetTickCount64();
	}

}

void CSecondBoss::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Rectangle(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CSecondBoss::Release()
{
}

void CSecondBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	m_iHp = m_iHp - 10;
}
