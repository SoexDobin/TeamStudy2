#pragma once
#include "Define.h"

#include "CPlayer.h"
#include "CBUllet.h"

class CObject;
class CMainGame
{
public:
	CMainGame();
	virtual ~CMainGame();
public:
	void		Initialize();
	void		Update();
	void		LateUpdate();
	void		Render();
	void		Release();
private:
	HDC				m_hDC;
	//list<CObject*>	m_ObjectList[OBJ_END];

	// Dubble buffering
	RECT	    m_tRect = {};
	HDC			m_hDCBack = {};
	HBITMAP		m_bmpBack = {};
};

