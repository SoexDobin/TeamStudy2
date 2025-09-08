#include "pch.h"
#include "Define.h"
#include "CBmpObject.h"


CBmpObject::CBmpObject()
	: m_hMemDC(nullptr), m_hBitmap(nullptr), m_hPrevBitmap(nullptr)
{

}

CBmpObject::~CBmpObject()
{
	Release();
}

void CBmpObject::LoadBmp(const TCHAR* _pFilePath)
{
	HDC hDC = GetDC(g_hWnd);

	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);
	m_hBitmap = (HBITMAP)LoadImage(NULL,			// 프로그램 인스턴스 핸들
								_pFilePath,			// 파일의 경로
								IMAGE_BITMAP,		// 어떤 타입을 읽어들일 것인가
								0, 0,				// 이미지의 가로, 세로 사이즈
								LR_LOADFROMFILE | LR_CREATEDIBSECTION);
								// LR_LOADFROMFILE : 파일에서 이미지 불러들이기 
								// LR_CREATEDIBSECTION : 읽어온 파일을 DIB 형태로 변환

	m_hPrevBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CBmpObject::Release()
{
	SelectObject(m_hMemDC, m_hPrevBitmap);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}