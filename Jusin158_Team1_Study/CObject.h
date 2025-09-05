#pragma once
#include "Define.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();
public:
	const RECT&			GetRect()		{ return m_tRect; }
	const Vector2&		GetPivot()		{ return m_vPivot; }
	const Vector2&		GetSize()		{ return m_vSize; }
	const Vector2&		GetDir()		{ return m_vDir; }
	const float&		GetSpeed()		{ return m_fSpeed; }
	
	void	SetPivot(const Vector2& _vPivot)	{ m_vPivot = _vPivot; }
	void	SetSize(const Vector2& _vSize)		{ m_vSize = _vSize; }
	void	SetDir(const Vector2& _vDir)		{ m_vDir = _vDir; }
	void	SetSpeed(const float& _fSpeed)		{ m_fSpeed = _fSpeed; }
	void	SetDestroy()						{ m_bDestroy = true; }

public:
	virtual void		Initialize()						PURE;
	virtual int			Update()							PURE;
	virtual void		LateUpdate()						PURE;
	virtual void		Render(HDC _hDC)					PURE;
	virtual void		OnCollision(CObject* _pColObj)		PURE;
	virtual void		Release()							PURE;

protected:
	virtual void		UpdateRect();

protected:
	RECT			m_tRect;
	Vector2			m_vPivot;
	Vector2			m_vSize;
	Vector2			m_vDir;

	float			m_fSpeed;
	bool			m_bDestroy;
	bool			m_bCollision;
};

