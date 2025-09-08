#pragma once

#include "CObject.h"

template<typename T>
class CAbstractFactory
{
	public:
		static CObject* Create()
		{
			CObject* pObject= new T;
			pObject->Initialize();
			
			return pObject;
		}

		static CObject* Create(float fX, float fY)
		{
			CObject* pObject = new T;
			pObject->Initialize();
			pObject->SetPivot(Vector2(fX, fY));

			return pObject;
		}
};