#pragma once

#include "CObject.h"

class CBullet : public CObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void	Initialize()					override;
	int		Update()						override;
	void	LateUpdate()					override;
	void	Render(HDC _hDC)				override;
	void	Release()						override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;
private:
	ULONGLONG	m_ullTime;
};