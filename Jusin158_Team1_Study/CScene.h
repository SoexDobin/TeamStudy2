#pragma once
#include "CObject.h"
#include "CObjectManager.h"
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void	Initialize()		=0;
	virtual int		Update()			=0;
	virtual void	LateUpdate()		=0;
	virtual void	Render(HDC _hDC)	=0;
	virtual void	Release()			=0;

};