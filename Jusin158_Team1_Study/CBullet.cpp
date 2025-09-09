#include "pch.h"
#include "CBullet.h"
#include "CScrollManager.h"

CBullet::CBullet() : m_ullTime(0)
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

	int iAttack = 10;

	m_ullTime = GetTickCount64();
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
	if (m_ullTime + 3000 < GetTickCount64())
		SetDestroy();
}

void CBullet::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Ellipse(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	SetDestroy();
}