#include "pch.h"
#include "Define.h"
#include "CBmpManager.h"
#include "CBmpObject.h"

CBmpManager* CBmpManager::m_pInstance = nullptr;

CBmpManager::CBmpManager()
{
}

CBmpManager::~CBmpManager()
{
}

void CBmpManager::Insert_Bmp(const TCHAR* _pFilePath, const TCHAR* _pImgKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(_pImgKey));

	if (m_mapBit.end() == iter)
	{
		CBmpObject* pBmp = new CBmpObject;

		pBmp->LoadBmp(_pFilePath);

		m_mapBit.insert({ _pImgKey, pBmp });
	}
}

HDC CBmpManager::Find_Img(const TCHAR* _pImgKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(_pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->GetMemDC();
}

void CBmpManager::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), DeleteMap());
	m_mapBit.clear();
}

CBmpManager* CBmpManager::GetInstance() 
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CBmpManager;
	}

	return m_pInstance;
}

void CBmpManager::DestroyInstance()
{
	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

