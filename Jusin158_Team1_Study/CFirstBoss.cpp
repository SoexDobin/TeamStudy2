#include "pch.h"
#include "CFirstBoss.h"
#include "CBullet.h"

CFirstBoss::CFirstBoss()
{

}
CFirstBoss::~CFirstBoss()
{
	Release();
}

void	CFirstBoss::Initialize()
{
	m_vPivot = { 700.f, 300.f };
	m_vSize = { 100.f, 100.f };

	m_fSpeed = 3.f;
}
int		CFirstBoss::Update()
{
	return OBJ_NOEVENT;
}
void	CFirstBoss::LateUpdate()
{
	FirstPattern();
	SecondPattern();
	ThirdPattern();
}
void	CFirstBoss::Render(HDC _hDC)
{
	Rectangle(_hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
void	CFirstBoss::Release()
{

}
void	CFirstBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{

}

void CFirstBoss::FirstPattern()
{
	//float fDegree = CheckDegree();
	//m_pBullet->push_back(CAbstractFactory<CBullet>::Create(m_vPivot.x, m_vPivot.y + m_vSize.y / 2, 7.f, fDegree * 180.f / 3.14f));
}
void CFirstBoss::SecondPattern()
{

}
void CFirstBoss::ThirdPattern()
{

}

//float CFirstBoss::CheckDegree()
//{
//	if (m_fPlayerVY > m_vPivot.y)
//		return 2 * PI - acosf((m_fPlayerVX - m_vPivot.x) / sqrt(
//			(m_fPlayerVX - m_vPivot.x) * (m_fPlayerVX - m_vPivot.x) + (m_fPlayerVY - m_vPivot.y) * (m_fPlayerVY - m_vPivot.y)));
//	return acosf((m_fPlayerVX - m_vPivot.x) / sqrt(
//		(m_fPlayerVX - m_vPivot.x) * (m_fPlayerVX - m_vPivot.x) + (m_fPlayerVY - m_vPivot.y) * (m_fPlayerVY - m_vPivot.y)));
//}