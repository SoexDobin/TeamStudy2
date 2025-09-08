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
	m_hBitmap = (HBITMAP)LoadImage(NULL,			// ���α׷� �ν��Ͻ� �ڵ�
								_pFilePath,			// ������ ���
								IMAGE_BITMAP,		// � Ÿ���� �о���� ���ΰ�
								0, 0,				// �̹����� ����, ���� ������
								LR_LOADFROMFILE | LR_CREATEDIBSECTION);
								// LR_LOADFROMFILE : ���Ͽ��� �̹��� �ҷ����̱� 
								// LR_CREATEDIBSECTION : �о�� ������ DIB ���·� ��ȯ

	m_hPrevBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CBmpObject::Release()
{
	SelectObject(m_hMemDC, m_hPrevBitmap);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}