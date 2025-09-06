#pragma once
#include "CScene.h"

class CScene01 : public CScene
{
public:
	CScene01();
	virtual ~CScene01();
public:
	void		Initialize();
	int			Update();
	void		LateUpdate();
	void		Render(HDC _hDC);
	void		Release();
};