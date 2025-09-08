#include "pch.h"
#include "CLine.h"
#include "CScrollManager.h"

CLine::CLine()
{

}
CLine::CLine(LINEPOINT& tLeft, LINEPOINT& tRight) : m_tLine(tLeft, tRight)
{

}
CLine::~CLine()
{

}

void CLine::Render(HDC hDC)
{
	int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();

	MoveToEx(hDC, (int)m_tLine.tLPoint.fX + iScrollX, (int)m_tLine.tLPoint.fY, nullptr);
	LineTo(hDC, (int)m_tLine.tRPoint.fX + iScrollX, (int)m_tLine.tRPoint.fY);
}