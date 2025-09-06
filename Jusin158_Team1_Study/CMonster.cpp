#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
}

int CMonster::Update()
{
	return OBJ_NOEVENT;
}

void CMonster::LateUpdate()
{
}

void CMonster::Render(HDC _hDC)
{
}

void CMonster::Release()
{
}
