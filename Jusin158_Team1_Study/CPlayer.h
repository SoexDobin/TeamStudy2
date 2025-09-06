#pragma once

#include "CObject.h"

class CPlayer : public CObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void	Initialize()					override;
	int		Update()						override;
	void	LateUpdate()					override;
	void	Render(HDC _hDC)				override;
	void	Release()						override;
	void	OnCollision(CObject* _pColObj)	override;

private:
	void	Key_Input();

};