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

//�� ��ü�� �ִ� Obj�� ��Ƶδ� �뵵�� �׸��� �� �������� �̿��ؼ� ����ó���� �ؼ� ���� ��Ʈ�� �ϱ� ���ؼ� �ϴ°���
//ObjectList�� Objectmanager���� ��� ���ư��� �־�� ��