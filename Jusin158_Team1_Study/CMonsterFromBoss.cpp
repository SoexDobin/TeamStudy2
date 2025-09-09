#include "pch.h"
#include "CMonsterFromBoss.h"
#include "CScrollManager.h"

CMonsterFromBoss::CMonsterFromBoss()
{

}
CMonsterFromBoss::~CMonsterFromBoss()
{
	Release();
}

void CMonsterFromBoss::Initialize()
{
	m_vSize = { 50.f, 50.f };
	m_fSpeed = 3.f;
}
int CMonsterFromBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	m_vPivot.x -= m_fSpeed;

	__super::UpdateRect();

	return OBJ_NOEVENT;
}
void CMonsterFromBoss::LateUpdate()
{
	if (0 >= m_tRect.left || WINCY <= m_tRect.right)
	{
		m_fSpeed *= -1.f;
	}
}
void CMonsterFromBoss::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Rectangle(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}
void CMonsterFromBoss::Release()
{

}
void CMonsterFromBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	SetDestroy();
}