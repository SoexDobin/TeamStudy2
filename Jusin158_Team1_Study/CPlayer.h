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

private:
	void	KeyInput();
	void	Jump();

private:
	bool m_bFaceRight;
	bool m_bJump;
	float m_fJumpSpeed;
	float m_fJumpTime;

};