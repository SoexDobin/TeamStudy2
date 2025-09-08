#pragma once

#include "Define.h"

class CScrollManager
{
private:
	CScrollManager();
	~CScrollManager();

public:
	void		Set_ScrollX(float _X) { m_fScrollX += _X; }
	void		Set_ScrollY(float _Y) { m_fScrollY += _Y; }

	float		Get_ScrollX() { return m_fScrollX; }
	float		Get_ScrollY() { return m_fScrollY; }

public:
	static CScrollManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CScrollManager;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CScrollManager* m_pInstance;

	float			m_fScrollX;
	float			m_fScrollY;
};

