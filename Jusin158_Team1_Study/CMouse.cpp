#include "pch.h"
#include "CMouse.h"
#include "CLineManager.h"

CMouse::CMouse() : m_szBuffer(L"")
{
    ZeroMemory(&m_tCurPos, sizeof(POINT));
    ZeroMemory(&m_tCurLine, sizeof(LINE));
}

CMouse::~CMouse()
{

}

void CMouse::Initialize()
{
    
}

int CMouse::Update()
{
    GetCursorPos(&m_tCurPos);
    
    ScreenToClient(g_hWnd, &m_tCurPos);

    __super::UpdateRect();

    return OBJ_NOEVENT;
}

void CMouse::LateUpdate()
{

}

void CMouse::Render(HDC _hDC)
{    
    swprintf_s(m_szBuffer, L"LPt X:%d y:%d  RPt : x:%d y:%d"
        , CLineManager::GetInstance()->GetCurLeftX(), CLineManager::GetInstance()->GetCurLeftY()
        , m_tCurPos.x, m_tCurPos.y);
    TextOut(_hDC, m_tCurPos.x - 150, m_tCurPos.y - 40, m_szBuffer, lstrlen(m_szBuffer));
}

void CMouse::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{

}

void CMouse::Release()
{

}