#pragma once
#include "CLine.h"

class CLineManager {
private:
	static CLineManager* m_pInstance;
	vector<CLine*> vecLine;
	LINEPOINT m_tLinePoint[LINECHECK];

	CLineManager();
	CLineManager(const CLineManager& _rhs) = delete;
	CLineManager operator=(CLineManager& _rMgr) = delete;
	~CLineManager();
public:
	void		Initialize();
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

	static CLineManager* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CLineManager;
		}
		return m_pInstance;
	}
	static void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	bool Collision_Bottom_Line(float _fUnderX, float _fUnderY, float* _pY, float fPlayerSize);
	bool Collision_Top_Line(float _fUpX, float _fUpY, float fPlayerSize);
};