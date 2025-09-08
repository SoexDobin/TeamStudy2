#pragma once
#include <map>
#include "CBmpObject.h"

class CBmpManager
{
private:
	CBmpManager();
	~CBmpManager();
	CBmpManager(const CBmpManager& _rhs) = delete;
	CBmpManager& operator=(const CBmpManager& _rhs) = delete;

public:
	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC			Find_Img(const TCHAR* pImgKey);
	void		Release();

public: 
	static CBmpManager* GetInstance();
	static void DestroyInstance();

private:
	static CBmpManager* m_pInstance;
	map<const TCHAR*, CBmpObject*>		m_mapBit;
};

