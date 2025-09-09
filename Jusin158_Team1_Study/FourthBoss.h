#pragma once
#include "CObject.h"

class FourthBoss : public CObject
{
public:
	FourthBoss();
	virtual ~FourthBoss();

public:
	void	Initialize()						override;
	int		Update()							override;
	void	LateUpdate()						override;
	void	Render(HDC _hDC)					override;
	void	Release()							override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)		override;

private:

	ULONGLONG m_uTime;
	int	m_iHp;
};