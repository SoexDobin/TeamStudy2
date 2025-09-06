#include "pch.h"
#include "CSceneManager.h"
#include "CObjectManager.h"

CSceneManager::CSceneManager() : m_pScene(nullptr)
{
}
CSceneManager::~CSceneManager()
{
	Release();
}
void CSceneManager::Initialize()
{
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = AbstractFactory<CPlayer>::Create();
	}
}
void CSceneManager::Update()
{

	switch (m_iSceneNumber)
	{
		case SCENE1:
		{

		}

		case SCENE2:
		{

		}

		case SCENE3:
		{

		}
	}
}
void CSceneManager::LateUpdate()
{

}
void CSceneManager::Render(HDC hdc)
{
}
void CSceneManager::Release()
{
}