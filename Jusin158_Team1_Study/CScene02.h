#pragma once
#include "CScene.h"

class CScene02 : public CScene
{
public:
	CScene02();
	virtual ~CScene02();
public:
	void		Initialize();
	int			Update();
	void		LateUpdate();
	void		Render(HDC _hDC);
	void		Release();
};
