#pragma once

#include "CObject.h"

class CMonster : public CObject
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void	Initialize()						override;
	int		Update()							override;
	void	LateUpdate()						override;
	void	Render(HDC _hDC)					override;
	void	Release()							override;
	void		OnCollision(CObject* _pColObj)	override;
	
};