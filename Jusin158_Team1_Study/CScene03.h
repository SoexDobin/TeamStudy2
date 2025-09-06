#pragma once

#include "CScene.h"

class CScene03 : public CScene
{
public:
	CScene03();
	virtual ~CScene03();
public:
	void		Initialize();
	int			Update();
	void		LateUpdate();
	void		Render(HDC _hDC);
	void		Release();
};

