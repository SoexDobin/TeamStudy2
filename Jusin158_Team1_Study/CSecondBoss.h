#pragma once
#include "CMonster.h"
class CSecondBoss : public CMonster
{
public:
	CSecondBoss();
	~CSecondBoss();

public:
	void	Initialize()										override;
	int		Update()											override;
	void	LateUpdate()										override;
	void	Render(HDC _hDC)									override;
	void	Release()											override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;
};

