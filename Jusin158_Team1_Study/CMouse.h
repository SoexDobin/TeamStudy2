#pragma once
#include "CObject.h"

class CMouse final : public CObject
{
public:
	CMouse();
	virtual ~CMouse() override;

public:
	void	Initialize()										override;
	int		Update()											override;
	void	LateUpdate()										override;
	void	Render(HDC _hDC)									override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;
	void	Release() override;

private:
	POINT	m_tCurPos;
	LINE	m_tCurLine;
	TCHAR	m_szBuffer[64];
};

