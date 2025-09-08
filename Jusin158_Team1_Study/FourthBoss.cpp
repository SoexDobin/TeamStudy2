#include "pch.h"
#include "FourthBoss.h"
#include "CObjectManager.h"
#include "CLineManager.h"
#include "CMonster.h"
#include "CScrollManager.h"

FourthBoss::FourthBoss()
{
}

FourthBoss::~FourthBoss()
{
}

void FourthBoss::Initialize()
{
	m_vPivot={1000.f, 150.f};
	m_vSize = {300.f, 300.f};

	m_fSpeed = 5.f;
    //m_vPivot.y = CObjectManager::GetInstance()->GetPlayer()->back()->GetPivot().y ; //좌표 불러오기

}

int FourthBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;


	float fY(0.f);

	
	__super::UpdateRect();

	return OBJ_NOEVENT;
}

void FourthBoss::LateUpdate()
{

}

void FourthBoss::Render(HDC _hDC)
{
	int iScrollx = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Ellipse(_hDC, m_tRect.left+iScrollx, m_tRect.top, m_tRect.right+iScrollx, m_tRect.bottom);
}
void FourthBoss::Release()
{
}

void FourthBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
}
