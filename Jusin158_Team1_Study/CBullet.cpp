#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_vSize = { 20.f, 20.f };

	m_fSpeed = 7.f;
}

int CBullet::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();

	m_vPivot.x += m_fSpeed;

	return OBJ_NOEVENT;
}

void CBullet::LateUpdate()
{
}

void CBullet::Render(HDC _hDC)
{
	Ellipse(_hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
}
