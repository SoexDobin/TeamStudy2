#pragma once
#include "CMonster.h"

class CFirstBoss : public CMonster 
{
private:
public:
	CFirstBoss();
	~CFirstBoss();

	void	Initialize() override;
	int		Update() override;
	void	LateUpdate() override;
	void	Render(HDC _hDC) override;
	void	Release() override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize) override;

	void FirstPattern();
	void SecondPattern();
	void ThirdPattern();
	/*void CheckDegree();*/
};