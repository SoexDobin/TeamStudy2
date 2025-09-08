#pragma once
#include "CMonster.h"
class CGuideMonster : public CMonster
{
public:
	CGuideMonster();
	~CGuideMonster();
	
public:
	void	Initialize()										override;
	int		Update()											override;
	void	LateUpdate()										override;
	void	Render(HDC _hDC)									override;
	void	Release()											override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)	override;

};

