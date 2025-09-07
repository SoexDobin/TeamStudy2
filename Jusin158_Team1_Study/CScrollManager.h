#pragma once
#include "Define.h"
class CScrollManager {
private:
	CScrollManager();
	~CScrollManager();
	CScrollManager(const CScrollManager& rhs) = delete;
	CScrollManager& operator=(CScrollManager& rMgr) = delete;

	static CScrollManager* m_pInstance;
	float m_fScrollScenefX;
	float m_fScrollScenefY;
	float m_fScrollPlayerfX;
	float m_fScrollPlayerfY;
	float m_fScrollSpeed;
public:
	static CScrollManager* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CScrollManager;
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

	void SetScrollSceneX() { m_fScrollScenefX += WINCX; }
	void SetScrollSceneY() { m_fScrollScenefY += WINCY; }
	float GetScrollSceneX() { return m_fScrollScenefX; }
	float GetScrollSceneY() { return m_fScrollScenefY; }
	
	void SetScrollPlayerX() { m_fScrollPlayerfX += WINCX - m_fScrollPlayerfX; }
	void SetScrollPlayerY() { m_fScrollPlayerfY += WINCY - m_fScrollPlayerfY; }
	float GetScrollPlayerX() { return m_fScrollPlayerfX; }
	float GetScrollPlayerY() { return m_fScrollPlayerfY; }

	float GetScrollSpeed() { return m_fScrollSpeed; }
};