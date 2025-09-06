#pragma once

#include "CScene.h"

class CScene04 : public CScene
{
public:
	CScene04();
	virtual ~CScene04();
public:
	void		Initialize();
	int			Update();
	void		LateUpdate();
	void		Render(HDC _hDC);
	void		Release();
};



