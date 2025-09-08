#include "pch.h"
#include "CGuideMonster.h"
#include "CScrollManager.h"

CGuideMonster::CGuideMonster()
{
}

CGuideMonster::~CGuideMonster()
{
    Release();
}

void CGuideMonster::Initialize()
{
    m_vSize = { 40.f, 40.f };

    m_fSpeed = 4.f;
}

int CGuideMonster::Update()
{
    if (m_bDestroy)
        return OBJ_DESTROY;

    __super::UpdateRect();

    return OBJ_NOEVENT;
}

void CGuideMonster::LateUpdate()
{
}

void CGuideMonster::Render(HDC _hDC)
{
    int iScrollX = (int)CScrollManager::Get_Instance()->Get_ScrollX();
    Rectangle(_hDC, m_tRect.left + iScrollX, m_tRect.top, m_tRect.right + iScrollX, m_tRect.bottom);
}

void CGuideMonster::Release()
{
}

void CGuideMonster::OnCollision(CObject* _pColObj, Vector2 _vColSize)
{
    SetDestroy();
}
