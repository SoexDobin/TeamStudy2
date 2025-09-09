#include "pch.h"
#include "FourthBoss.h"
#include "CObjectManager.h"
#include "CLineManager.h"
#include "CMonster.h"
#include "CScrollManager.h"
#include "CAbstractFactory.h"
#include "CBullet.h"

FourthBoss::FourthBoss()
{

}

FourthBoss::~FourthBoss()
{

}

void FourthBoss::Initialize()
{
	m_vPivot={2300.f, 150.f};
	m_vSize = {300.f, 300.f};

	m_fSpeed = 100.f;

	m_iHp = 150;

    //m_vPivot.y = CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().y ; //좌표 불러오기

	m_uTime = GetTickCount64();
}

int FourthBoss::Update()
{
	if (m_iHp <= 0)
	{
		m_bDestroy = true;
	}

	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();

	
	
		if (m_uTime + 1000 < GetTickCount64())
		{
			Vector2 m_vPrePivot = CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot();

			float fWidth(0.f), fHeight(0.f), fDiagonal(0.f);

			fWidth = m_vPivot.x - (CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().x);
			fHeight = m_vPivot.y - (CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().y);
			fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
			float fRadian = acosf(fWidth / fDiagonal);

			if (CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().y > m_vPivot.y)
			{
				fRadian = 2.f * 3.14f - fRadian; //360도 = 2파이
			}

			m_vPivot.x -= m_fSpeed * cosf(fRadian);
			m_vPivot.y -= m_fSpeed * sinf(fRadian);

			m_uTime = GetTickCount64();
		}
	



	return OBJ_NOEVENT;
}

void FourthBoss::LateUpdate()
{

}

void FourthBoss::Render(HDC _hDC)
{
	int iScrollx = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Ellipse(_hDC, m_tRect.left+iScrollx, m_tRect.top, m_tRect.right+iScrollx, m_tRect.bottom);
}
void FourthBoss::Release()
{
}

void FourthBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	m_iHp -= 10;
}
