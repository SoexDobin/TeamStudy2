#pragma once

#include "CScene.h"

class CScene03 : public CScene
{
public:
	CScene03();
	virtual ~CScene03();
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
};

