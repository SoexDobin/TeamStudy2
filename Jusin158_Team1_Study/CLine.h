#pragma once
#include "Define.h"

class CLine {
private:
	LINE m_tLine;
public:
	CLine();
	CLine(LINEPOINT& tLeft, LINEPOINT& tRight);
	~CLine();

	void Render(HDC hDC);
	const LINE& GetLineInfo() const { return m_tLine; }
};