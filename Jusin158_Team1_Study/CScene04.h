#pragma once

#include "CScene.h"

class CLine;

class CScene04 : public CScene
{
public:
	CScene04();
	virtual ~CScene04();
public:
	void		Initialize()		override;
	int			Update()			override;
	void		LateUpdate()		override;
	void		Render(HDC _hDC)	override;
	void		Release()			override;

private:

	list<CObject*> m_MonsterList;
	CObject* m_pPlayer;
	CObject* m_pBoss;
	BOOL	m_bDead;
	ULONGLONG	m_dTime;
	int	m_MonsterIDX;
	BOOL m_bStart;
	BOOL m_bKillCount;

};



