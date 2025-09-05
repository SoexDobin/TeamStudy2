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

}