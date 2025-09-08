#include "pch.h"
#include "CScene04.h"
#include "CLine.h"
#include "CAbstractFactory.h"
#include "CMonster.h"

CScene04::CScene04()
{

}
CScene04::~CScene04()
{

}
void CScene04::Initialize()
{

	CObjectManager::GetInstance()->AddObject(MONSTER,CAbstractFactory<CMonster>::Create(300.f,50.f));
}
int CScene04::Update()
{

	return OBJ_NOEVENT;
}
void CScene04::LateUpdate()
{

}
void CScene04::Render(HDC _hDC)
{

}
void CScene04::Release()
{

}