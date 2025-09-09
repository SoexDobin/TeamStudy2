#include "pch.h"
#include "CSecondBoss.h"
#include "CBullet.h"
#include "CScrollManager.h"

CSecondBoss::CSecondBoss()
{
}

CSecondBoss::~CSecondBoss()
{
	Release();
}

void CSecondBoss::Initialize()
{
	m_vSize = { 100.f, 200.f };

	m_fSpeed = 3.f;

	m_iHp = 200;
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
