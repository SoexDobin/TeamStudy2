#pragma once

#include "CObject.h"

class CBossBullet : public CObject
{
private:
public:
	CBossBullet();
	virtual ~CBossBullet();

public:
	void	Initialize()					override;
	int		Update()						override;
	void	LateUpdate()					override;
	void	Render(HDC _hDC)				override;
	void	Release()						override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;
};