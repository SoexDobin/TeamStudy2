#pragma once
#include "CScene.h"
#include "CLine.h"

class CScene01 : public CScene
{
public:
	CScene01();
	virtual ~CScene01();
public:
	void		Initialize()	override;
	int			Update()		override;
	void		LateUpdate()	override;
	void		Render(HDC _hDC)override;
	void		Release()		override;

public:
	BOOL Get_Dead() { return m_bDead; }

private:
	list<CObject*> m_MonsterList;
	CObject* m_pPlayer;
	CObject* m_pBoss;
	BOOL	m_bDead;
};

//씬 자체에 있는 Obj만 담아두는 용도임 그리고 각 변수들을 이용해서 조건처리를 해서 씬을 컨트롤 하기 위해서 하는거임
//ObjectList는 Objectmanager에서 계속 돌아가고 있어야 함