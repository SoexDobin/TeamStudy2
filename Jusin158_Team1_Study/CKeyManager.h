#pragma once
#include "Define.h"

class CKeyManager
{
private:
	CKeyManager();
	~CKeyManager();
	CKeyManager(const CKeyManager& _rhs) = delete;
	void operator=(const CKeyManager& _rhs) = delete;

public:
	bool		KeyPressing(int iKey);
	bool		KeyUp(int iKey);		// �����ٰ� ���� ��
	bool		KeyDown(int iKey);		// �����ڸ���
	void		KeyUpdate();

public:
	static CKeyManager* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CKeyManager;

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
	static CKeyManager* m_pInstance;
	bool		m_bKeyState[VK_MAX];
};

