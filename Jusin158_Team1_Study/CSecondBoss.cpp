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

	m_fSpeed = 7.f;
}

int CSecondBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;



	return OBJ_NOEVENT;
}

void CSecondBoss::LateUpdate()
{
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
}
