#pragma once
#include "CObject.h"
#include "CObjectManager.h"
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