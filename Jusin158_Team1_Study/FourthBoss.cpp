#include "pch.h"
#include "FourthBoss.h"
#include "CObjectManager.h"
#include "CLineManager.h"

FourthBoss::FourthBoss()
{

}

FourthBoss::~FourthBoss()
{

}

void FourthBoss::Initialize()
{
	m_vPivot.y = CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().y ; //좌표 불러오기
	m_vSize = { 300.f, 300.f };
}

int FourthBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	m_vPivot.x -= m_fSpeed;

	float fY(0.f);

	if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
	{
		m_vPivot.y = fY;
	}

	__super::UpdateRect();

	return OBJ_NOEVENT;
}

void FourthBoss::LateUpdate()
{

}

void FourthBoss::Render(HDC _hDC)
{
	Ellipse(_hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void FourthBoss::Release()
{
}

void FourthBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
}
