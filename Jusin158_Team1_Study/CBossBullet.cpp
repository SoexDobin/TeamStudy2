#include "pch.h"
#include "CBossBullet.h"
#include "CScrollManager.h"

CBossBullet::CBossBullet()
{
}

CBossBullet::~CBossBullet()
{
	Release();
}

void CBossBullet::Initialize()
{
	m_vSize = { 20.f, 20.f };

	m_fSpeed = 7.f;
}

int CBossBullet::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();

	m_vPivot.x += m_fSpeed * cosf(fAngle);
	m_vPivot.y -= m_fSpeed * sin(fAngle);

	return OBJ_NOEVENT;
}

void CBossBullet::LateUpdate()
{
}

void CBossBullet::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Ellipse(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CBossBullet::Release()
{
}

void CBossBullet::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	SetDestroy();
}