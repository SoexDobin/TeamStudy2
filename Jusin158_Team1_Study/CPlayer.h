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
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;
	void	Offset();

private:
	void	KeyInput();
	void	Jump();
	void	CheckOutOfBound();

private:
	bool	m_bFaceRight;
	float	m_fBulletDir;
	bool	m_bJump;
	float	m_fJumpSpeed;
	float	m_fJumpTime;

};