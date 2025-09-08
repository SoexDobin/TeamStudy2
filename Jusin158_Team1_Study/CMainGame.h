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

public:
	CObject* GetPlayer() { return m_pPlayer; }
	void	SetPlayer(CObject* _pPlayer) { m_pPlayer = _pPlayer; }

private:
	HDC				m_hDC;

	// Dubble buffering
	RECT	    m_tRect = {};
	HDC			m_hDCBack = {};
	HBITMAP		m_bmpBack = {};

	CObject* m_pPlayer;
};

