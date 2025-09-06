#include "pch.h"
#include "CLine.h"

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
	MoveToEx(hDC, (int)m_tLine.tLPoint.fX, (int)m_tLine.tLPoint.fY, nullptr);
	LineTo(hDC, (int)m_tLine.tRPoint.fX, (int)m_tLine.tRPoint.fY);
}