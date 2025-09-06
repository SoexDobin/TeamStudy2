#pragma once

#include "CObject.h"

template<typename T>
class AbstractFactory
{
	public:
		static CObject* Create()
		{
			CObject* pObject= new T;
			pObject->Initialize();
			
			return pObject;
		}

};