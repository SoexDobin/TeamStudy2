#pragma once
#include "CObject.h"

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	void	Initialize()		;
	int		Update()			;
	void	LateUpdate()		;
	void	Render(HDC _hDC)	;
	void	Release()			;

};