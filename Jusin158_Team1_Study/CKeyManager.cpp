#include "pch.h"
#include "CKeyManager.h"

CKeyManager* CKeyManager::m_pInstance = nullptr;

CKeyManager::CKeyManager()
{
	ZeroMemory(m_bKeyState, sizeof(m_bKeyState));
}

CKeyManager::~CKeyManager()
{
}

// 계속 누르고 있는 경우
bool CKeyManager::KeyPressing(int _iKey)
{
	if (GetAsyncKeyState(_iKey) & 0x8001)
		return true;

	return false;
}
bool CKeyManager::KeyUp(int _iKey)
{
	if ((m_bKeyState[_iKey]) && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}
bool CKeyManager::KeyDown(int _iKey)
{
	if ((!m_bKeyState[_iKey]) && GetAsyncKeyState(_iKey) & 0x8000)
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}

void CKeyManager::KeyUpdate()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		if ((m_bKeyState[i]) && !(GetAsyncKeyState(i) & 0x8000))
		{
			m_bKeyState[i] = !m_bKeyState[i];
		}

		if ((!m_bKeyState[i]) && (GetAsyncKeyState(i) & 0x8000))
		{
			m_bKeyState[i] = !m_bKeyState[i];
		}
	}
}
