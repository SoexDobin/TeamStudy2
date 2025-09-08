#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CLineManager.h"
#include "CAbstractFactory.h"
#include "CObjectManager.h"
#include "CScrollManager.h"
#include "CKeyManager.h"

CPlayer::CPlayer() : m_bFaceRight(true), m_bJump(false), m_fJumpSpeed(0.f), m_fJumpTime(0.f), m_fBulletDir(1.f)
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

	m_fSpeed = 8.f;
	m_fJumpSpeed = 20.f;

	m_iHp = 100;
}

int CPlayer::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();

	KeyInput();

	return OBJ_NOEVENT;
}

void CPlayer::LateUpdate()
{
	Jump();
	Offset();
	CheckOutOfBound();
}

void CPlayer::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Ellipse(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
}

void CPlayer::KeyInput()
{
	float fY = 0.f;
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_bFaceRight == false)
		{
			m_bFaceRight = true;
			m_fBulletDir = 1.f;

		}

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
		else if (CKeyManager::Get_Instance()->KeyDown(VK_SPACE))
		{
			m_bJump = true;
		}
		else
		{
			m_vPivot.x += m_fSpeed;
		}
		//if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		//{
		//	m_vPivot.y = fY;
		//}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_bFaceRight == true)
		{
			m_bFaceRight = false; 
			m_fBulletDir = -1.f;
			
		}
		


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
		else if (CKeyManager::Get_Instance()->KeyDown(VK_SPACE))
		{
			m_bJump = true;
		}
		else
		{
			m_vPivot.x -= m_fSpeed;
		}
		//if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		//{
		//	m_vPivot.y = fY;
		//}
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		m_vPivot.y -= m_fSpeed;
		//if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		//{
		//	m_vPivot.y = fY;
		//}
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_vPivot.y += m_fSpeed;
		//if (CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y, &fY, m_vSize.x / 2.f))
		//{
		//	m_vPivot.y = fY;
		//}
	}

	else if (CKeyManager::Get_Instance()->KeyDown(VK_SPACE))
	{
		m_bJump = true;
	}

	if (CKeyManager::Get_Instance()->KeyDown('A'))
	{
		CObjectManager::GetInstance()->GetBulletList()->push_back(AbstractFactory<CBullet>::Create(m_vPivot.x, m_vPivot.y));
		CObject* pLastBullet = CObjectManager::GetInstance()->GetBulletList()->back();
		pLastBullet->SetSpeed(pLastBullet->GetSpeed() * m_fBulletDir);
	}
}

void CPlayer::Jump()
{
	float fY(0.f);

	bool bLineCol = CLineManager::GetInstance()->Collision_Bottom_Line(m_vPivot.x, m_vPivot.y + m_vSize.y / 2.f, &fY, m_vSize.x / 2.f);

	if (m_bJump)
	{
		m_vPivot.y -= m_fJumpSpeed * m_fJumpTime - (9.8f * m_fJumpTime * m_fJumpTime) * 0.5f;
		m_fJumpTime += 0.2f;

		if (bLineCol && (fY < m_vPivot.y))
		{
			m_bJump = false;
			m_fJumpTime = 0.f;
			m_vPivot.y = fY;
		}
	}
	else if (bLineCol)
	{
		m_vPivot.y = fY;
	}
}
void CPlayer::CheckOutOfBound()
{
	if (m_tRect.top > WINCY || m_tRect.bottom < 0)
		m_vPivot = Vector2(WINCX / 2, WINCY / 2);
}
void CPlayer::Offset()
{
	int iOffsetminX = WINCX - 700;
	int iOffsetmaxX = WINCX - 300;


	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();

	if (iOffsetminX > m_vPivot.x + iScrollX)
		CScrollManager::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffsetmaxX < m_vPivot.x + iScrollX)
		CScrollManager::Get_Instance()->Set_ScrollX(-m_fSpeed);

}