#include "pch.h"
#include "CFourthBoss.h"

CFourthBoss::CFourthBoss()
{
	
}
CFourthBoss::~CFourthBoss()
{

}
void CFourthBoss::Initialize()
{
	m_vPivot = { 700.f, 300.f };
	m_vSize = { 100.f, 100.f };

	m_fSpeed = 3.f;
}
int CFourthBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	m_vPivot.y -= m_fSpeed;

	__super::UpdateRect();

	return OBJ_NOEVENT;
}
void CFourthBoss::LateUpdate()
{
}
void CFourthBoss::Render(HDC _hDC)
{
}
void CFourthBoss::Release()
{

}
void CFourthBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
}
