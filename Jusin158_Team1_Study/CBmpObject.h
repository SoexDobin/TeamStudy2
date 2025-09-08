#pragma once
class CBmpObject
{
public:
	CBmpObject();
	virtual ~CBmpObject();

public:
	HDC			GetMemDC() { return m_hMemDC; }

	void		LoadBmp(const TCHAR* _pFilePath);
	void		Release();

private:
	HDC			m_hMemDC;
	HBITMAP		m_hBitmap;
	HBITMAP		m_hPrevBitmap;
};

