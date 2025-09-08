#pragma once
#include "CMonster.h"

class CThirdBoss final : public CMonster
{
public:
	CThirdBoss();
	~CThirdBoss() override;

public:
	void	Initialize()						override;
	int		Update()							override;
	void	LateUpdate()						override;
	void	Render(HDC _hDC)					override;
	void	Release()							override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)		override;

private:
	void	ShotBullet();
	void	StandingJump();
	void	ThrowCurveBullet();

private:
	const int	m_iPatternCount = 3;
	int			m_iPattern;
	ULONGLONG	m_ullPatternCool;

	bool		m_bIsJumping;
	float		m_fJumpSpeed;
	float		m_fJumpTime;
};