#include "pch.h"
#include "CMonster.h"
#include "CScrollManager.h"

CMonster::CMonster() : fPlayerX(0.f), fPlayerY(0.f)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_vPivot = { 700.f, 300.f };
	m_vSize = { 100.f, 100.f };

	m_fSpeed = 3.f;

	m_iHp = 70;
}

int CMonster::Update()
{
	if (m_bDestroy)

		return OBJ_DESTROY;

	m_vPivot.y -= m_fSpeed;
	__super::UpdateRect();

	return OBJ_NOEVENT;
}

void CMonster::LateUpdate()
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

void CMonster::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Rectangle(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CMonster::Release()
{

}

void CMonster::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	m_iHp = m_iHp - 10;
}
