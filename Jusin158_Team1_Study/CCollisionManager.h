#pragma once
#include "Define.h"

class CObject;
class CCollisionManager
{
public:
	static void Collision(list<CObject*> _Src1, list<CObject*> _Src2, COLLISION_FLAG _eFlag);
private:
	static void RTRCollision(list<CObject*> _Src1, list<CObject*> _Src2);
	static void CTCCollision(list<CObject*> _Src1, list<CObject*> _Src2);
	static void RTCCollision(list<CObject*> _Src1, list<CObject*> _Src2);
	static void CTRCollision(list<CObject*> _Src1, list<CObject*> _Src2);
};

