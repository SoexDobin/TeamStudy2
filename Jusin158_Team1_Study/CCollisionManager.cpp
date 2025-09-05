#include "pch.h"
#include "CObject.h"
#include "CCollisionManager.h"

void CCollisionManager::Collision(list<CObject*> _Src1, list<CObject*> _Src2, COLLISION_FLAG _eFlag)
{
	switch (_eFlag)
	{
	case RECT_TO_RECT: RTRCollision(_Src1, _Src2); break;
	case CIRCLE_TO_CIRCLE: CTCCollision(_Src1, _Src2); break;
	case RECT_TO_CIRCLE: CTCCollision(_Src1, _Src2); break;
	case CIRCLE_TO_RECT: CTCCollision(_Src1, _Src2); break;
	default: break;
	}
}

void CCollisionManager::RTRCollision(list<CObject*> _Src1, list<CObject*> _Src2)
{
	RECT tColBox{ 0,0,0,0 };

	for (auto& Src1 : _Src1)
		for (auto& Src2 : _Src2)
		{
			if (IntersectRect(&tColBox, &Src1->GetRect(), &Src2->GetRect()))
			{
				Src1->SetCollision(true);
				Src2->SetCollision(true);
				Src1->OnCollision(Src2);
				Src2->OnCollision(Src1);
			}
			else
			{
				Src1->SetCollision(false);
				Src2->SetCollision(false);
			}
		}
}

void CCollisionManager::CTCCollision(list<CObject*> _Src1, list<CObject*> _Src2)
{
	for (auto& Src1 : _Src1)
		for (auto& Src2 : _Src2)
		{
			Vector2 vDst = Src1->GetPivot() - Src2->GetPivot();
			float fHypot = sqrtf(vDst.GetSquared());
			float fSumRadius = (Src1->GetSize().x + Src2->GetSize().x) * 0.5f;
			
			if (fSumRadius >= fHypot)
			{
				Src1->SetCollision(true);
				Src2->SetCollision(true);
				Src1->OnCollision(Src2);
				Src2->OnCollision(Src1);
			}
			else
			{
				Src1->SetCollision(false);
				Src2->SetCollision(false);
			}
		}
}

void CCollisionManager::RTCCollision(list<CObject*> _Src1, list<CObject*> _Src2)
{

}

void CCollisionManager::CTRCollision(list<CObject*> _Src1, list<CObject*> _Src2)
{

}