#include "pch.h"
#include "CFirstBoss.h"
#include "CBullet.h"
#include "CObjectManager.h"
#include "CAbstractFactory.h"
#include "CMonsterFromBoss.h"
#include "CBossBullet.h"
#include "CScrollManager.h"
#include <random>

CFirstBoss::CFirstBoss() : timer(GetTickCount64()), iHp(0)
{

}
CFirstBoss::~CFirstBoss()
{
	Release();
}

void	CFirstBoss::Initialize()
{
	m_vSize = { 100.f, 100.f };

	m_fSpeed = 3.f;

	iHp = 10;

}
int		CFirstBoss::Update()
{
	if (m_bDestroy)
		return OBJ_DESTROY;

	__super::UpdateRect();
	random_device rd;
	mt19937 gen(rd());

	vector<int>randNum(2, 0);
	for (int i = 0; i < randNum.size(); ++i)
	{
		randNum[i] = i;
	}
	shuffle(randNum.begin(), randNum.end(), gen);

	if(timer + 1000 < GetTickCount64())
	{
		switch (randNum[0])
		{
		case 0:
			FirstPattern();
			break;
		case 1:
			SecondPattern();
			break;
		default:
			break;
		}
		timer = GetTickCount64();
	}

	if(m_vPivot.y < 100)
	{
		m_fSpeed *= -1;
	}
	
	else if (m_vPivot.y > 277)
	{
		m_fSpeed *= -1;
	}
	m_vPivot.y += m_fSpeed;
	return OBJ_NOEVENT;
}
void	CFirstBoss::LateUpdate()
{

}
void	CFirstBoss::Render(HDC _hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
	Rectangle(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}
void	CFirstBoss::Release()
{

}
void	CFirstBoss::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
	/*m_bDestroy = true;
	SetDestroy();*/

	if(iHp <= 0)
	{
		m_bDestroy = true;
		SetDestroy();
	}
	iHp--;
}

void CFirstBoss::FirstPattern()
{
	int iMonSize = CObjectManager::GetInstance()->GetMonsterList()->size();
	if(iMonSize < 10)
	{
		CObjectManager::GetInstance()->GetMonsterList()->push_back(AbstractFactory<CMonsterFromBoss>::Create(m_vPivot.x, m_vPivot.y));
	}
}
void CFirstBoss::SecondPattern()
{
	float fDegree = CheckDegree();
	CObjectManager::GetInstance()->GetBulletList()->push_back(AbstractFactory<CBossBullet>::Create(m_vPivot.x, m_vPivot.y + m_vSize.y + 5.f / 2, fDegree));
	CObjectManager::GetInstance()->GetBulletList()->push_back(AbstractFactory<CBossBullet>::Create(m_vPivot.x, m_vPivot.y + m_vSize.y + 5.f / 2, 3.14f * 7 / 4));
}

float CFirstBoss::CheckDegree()
{
	if (fPlayerY > m_vPivot.y)
		return 2 * 3.14f - acosf((fPlayerX - m_vPivot.x) / sqrt(
			(fPlayerX - m_vPivot.x) * (fPlayerX - m_vPivot.x) + (fPlayerY - m_vPivot.y) * (fPlayerY - m_vPivot.y)));
	return acosf((fPlayerX - m_vPivot.x) / sqrt(
		(fPlayerX - m_vPivot.x) * (fPlayerX - m_vPivot.x) + (fPlayerY - m_vPivot.y) * (fPlayerY - m_vPivot.y)));
}