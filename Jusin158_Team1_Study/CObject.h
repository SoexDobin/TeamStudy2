#pragma once
#include "Define.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();
public:
	const RECT&			GetRect()		{ return m_tRect; }
	Vector2				GetPivot()		{ return m_vPivot; }
	Vector2				GetSize()		{ return m_vSize; }
	Vector2				GetDir()		{ return m_vDir; }
	const float&		GetSpeed()		{ return m_fSpeed; }
	bool				GetCollision()  { return m_bCollision; }
	
	void	SetPivot(const Vector2& _vPivot)	{ m_vPivot = _vPivot; }
	void	SetSize(const Vector2& _vSize)		{ m_vSize = _vSize; }
	void	SetDir(const Vector2& _vDir)		{ m_vDir = _vDir; }
	void	SetSpeed(const float& _fSpeed)		{ m_fSpeed = _fSpeed; }
	void	SetCollision(const bool& _bCol)		{ m_bCollision = _bCol; }
	void	SetDestroy()						{ m_bDestroy = true; }
	//void	SetBullet(list<CObject*>* pBullet)	{ m_pBullet = pBullet; }

public:
	virtual void		Initialize()										PURE;
	virtual int			Update()											PURE;
	virtual void		LateUpdate()										PURE;
	virtual void		Render(HDC _hDC)									PURE;
	virtual void		OnCollision(CObject* _pColObj, Vector2 _vColSize)	PURE;
	virtual void		Release()											PURE;

protected:
	virtual void		UpdateRect();

protected:
	RECT			m_tRect;
	Vector2			m_vPivot;
	Vector2			m_vSize;
	Vector2			m_vDir;

	list<CObject*> m_pBullet;

	float			m_fSpeed;
	bool			m_bDestroy;

private:
	bool			m_bCollision;
};

