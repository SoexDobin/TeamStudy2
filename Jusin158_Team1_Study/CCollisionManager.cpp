#include "pch.h"
#include "CObject.h"
#include "CCollisionManager.h"

void CCollisionManager::Collision(list<CObject*> _Src1, list<CObject*> _Src2, COLLISION_FLAG _eFlag)
{
	switch (_eFlag)
	{
	case RECT_TO_RECT: RTRCollision(_Src1, _Src2); break;
	case CIRCLE_TO_CIRCLE: CTCCollision(_Src1, _Src2); break;
	case RECT_TO_CIRCLE: RTRCollision(_Src1, _Src2); break;
	case CIRCLE_TO_RECT: RTRCollision(_Src1, _Src2); break;
	default: break;
	}
}

void CCollisionManager::RTRCollision(list<CObject*> _Src1, list<CObject*> _Src2)
{
	RECT tColBox{ 0,0,0,0 };

	for (auto& Src1 : _Src1)
		for (auto& Src2 : _Src2)
		{
			Vector2 vFrom(Src1->GetPivot()), vTo(Src2->GetPivot());
			Vector2 vDst = vFrom - vTo;
			vDst.x = fabsf(vDst.x);
			vDst.y = fabsf(vDst.y);

			Vector2 vFromSize(Src1->GetSize()), vToSize(Src2->GetSize());
			Vector2 fSumHalfSize = (vFromSize + vToSize) * 0.5f;

			bool isCol = fSumHalfSize.x >= vDst.x && fSumHalfSize.y >= vDst.y;
			if (isCol == true)
			{
				Src1->SetCollision(true);
				Src2->SetCollision(true);
				// 반지름의 합 - 중점 사이 거리
				Vector2 vDifference = fSumHalfSize - vFromSize;
				vDifference = Vector2(fabsf(vDifference.x), fabsf(vDifference.y));
				if (vDifference.x > vDifference.y) // To(Src)기준 상하 충돌
				{
					if (vFrom.y < vTo.y) // 상 충돌
					{
						Src1->OnCollision(Src2, vDifference);
						Src2->OnCollision(Src1, vDifference);
					}
					else if (vFrom.y >= vTo.y) // 하 충돌
					{
						Src1->OnCollision(Src2, vDifference);
						Src2->OnCollision(Src1, vDifference);
					}
				}
				else if (vDifference.x <= vDifference.y) // To(Src)의 좌우 충돌
				{
					if (vFrom.x < vTo.x) // 우 충돌
					{
						Src1->OnCollision(Src2, vDifference);
						Src2->OnCollision(Src1, vDifference);
					}
					else if (vFrom.x >= vTo.x) // 좌 충돌
					{
						Src1->OnCollision(Src2, vDifference);
						Src2->OnCollision(Src1, vDifference);
					}
				}
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
				Src1->OnCollision(Src2, Vector2::UnitX);
				Src2->OnCollision(Src1, Vector2::UnitX);
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