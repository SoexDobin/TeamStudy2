#pragma once
#include "CMonster.h"
class CSecondBoss : public CMonster
{
public:
	CSecondBoss();
	virtual ~CSecondBoss() override;

public:
	void	Initialize()										override;
	int		Update()											override;
	void	LateUpdate()										override;
	void	Render(HDC _hDC)									override;
	void	Release()											override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;

private:
	ULONGLONG	m_lFirstskilltime;
	ULONGLONG	m_lSecondskilltime;
};

