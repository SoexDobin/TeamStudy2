#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CLineManager.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_vSize = { 50.f, 50.f };
	m_vPivot = { 500.f , 300.f };

	m_fSpeed = 5.f;

}

int CPlayer::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();

	Key_Input();

	return OBJ_NOEVENT;
}

void CPlayer::LateUpdate()
{
}

void CPlayer::Render(HDC _hDC)
{
	Ellipse(_hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::OnCollision(CObject* _pColObj)
{
}

void CPlayer::Key_Input()
{
	float fY = 0.f;
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_vPivot.x += m_fSpeed / sqrtf(2.f);
			m_vPivot.y -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_vPivot.x += m_fSpeed / sqrtf(2.f);
			m_vPivot.y += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_vPivot.x += m_fSpeed;
		}
		if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		{
			m_vPivot.y = fY;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_vPivot.x -= m_fSpeed / sqrtf(2.f);
			m_vPivot.y -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_vPivot.x -= m_fSpeed / sqrtf(2.f);
			m_vPivot.y += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_vPivot.x -= m_fSpeed;
		}
		if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		{
			m_vPivot.y = fY;
		}
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		m_vPivot.y -= m_fSpeed;
		if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		{
			m_vPivot.y = fY;
		}
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_vPivot.y += m_fSpeed;
		if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		{
			m_vPivot.y = fY;
		}
	}
}
