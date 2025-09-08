#include "pch.h"
#include "CThirdBoss.h"
#include <random>

#include "CObjectManager.h"
#include "CAbstractFactory.h"
#include "CLineManager.h"
#include "CBullet.h"

CThirdBoss::CThirdBoss() 
	: m_iPattern(3), m_ullPatternCool(0)
	, m_bIsJumping(false), m_fJumpSpeed(10.f), m_fJumpTime(0.f)
{

}

CThirdBoss::~CThirdBoss()
{

}

void CThirdBoss::Initialize()
{
	
}

int CThirdBoss::Update()
{
	if (m_bDestroy) return OBJ_DESTROY;

	__super::UpdateRect();

	StandingJump();

	return OBJ_NOEVENT;
}

void CThirdBoss::LateUpdate()
{
	std::random_device rd;
	int iCase = rd() % m_iPatternCount;

	switch (iCase)
	{
	case 0:		ShotBullet();		break;
	case 1:		m_bIsJumping = true;break;
	case 2:		ThrowCurveBullet(); break;
	default:	break;
	}
}

void CThirdBoss::Render(HDC _hDC)
{
	Rectangle(_hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CThirdBoss::Release()
{

}

void CThirdBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{

}

void CThirdBoss::ShotBullet()
{
	CObjectManager::GetInstance()->AddObject(BULLET, AbstractFactory<CBullet>::Create());
}

void CThirdBoss::StandingJump()
{
	if (m_bIsJumping == false) return;
	
	float fY;
	bool bColLine = CLineManager::GetInstance()
		->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.y);

	m_vPivot.y -= m_fJumpSpeed * m_fJumpTime - (9.8f * m_fJumpTime * m_fJumpTime);
	m_fJumpTime += 0.2f;



}

void CThirdBoss::ThrowCurveBullet()
{

}
