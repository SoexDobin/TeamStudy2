#include "pch.h"
#include "CGuideMonster.h"
#include "CScrollManager.h"
#include "CObjectManager.h"

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
    m_pTarget = CObjectManager::GetInstance()->GetTarget(PLAYER, this);

    if(m_pTarget)
    {
        float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f);

        fWidth = m_pTarget->GetPivot().x - m_vPivot.x;
        fHeight = m_pTarget->GetPivot().y - m_vPivot.y;

        fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

        float fRadian = acosf(fWidth / fDiagonal);

        if (m_pTarget->GetPivot().y > m_vPivot.y)
            fRadian = 2.f * PI - fRadian;

        m_fAngle = fRadian * (180.f / PI);
    }

    m_vPivot.x += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
    m_vPivot.y -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
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
