#include "pch.h"
#include "CScrollManager.h"

CScrollManager* CScrollManager::m_pInstance = nullptr;

CScrollManager::CScrollManager() : m_fScrollScenefX(0.f), m_fScrollScenefY(0.f), m_fScrollSpeed(7.f)
, m_fScrollPlayerfX(0.f), m_fScrollPlayerfY(0.f)
{

}
CScrollManager::~CScrollManager()
{

}