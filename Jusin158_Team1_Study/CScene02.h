#pragma once
#include "CScene.h"

class CScene02 : public CScene
{
public:
	CScene02();
	virtual ~CScene02();
public:
	void		Initialize()		override;
	int			Update()			override;
	void		LateUpdate()		override;
	void		Render(HDC _hDC)	override;
	void		Release()			override;
};
