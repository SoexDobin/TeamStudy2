#pragma once

// world variable
extern		HWND		g_hWnd;

// mecro
#define		PURE				= 0
#define		WINCX				1000
#define		WINCY				600
#define		OBJ_DESTROY			1
#define		OBJ_NOEVENT			0
#define		VK_MAX				0xFF

// enum 
enum OBJECT
{
	PLAYER,
	MONSTER,
	BULLET,
	//LINE,
	MOUSE,
	BOSS,

	OBJ_END
};

enum COLLISION_FLAG
{
	RECT_TO_RECT,
	CIRCLE_TO_CIRCLE,
	RECT_TO_CIRCLE,
	CIRCLE_TO_RECT,

	COL_FLAG_END
};

template <typename T>
static void SafeDelete(T& _p)
{
	if (_p)
	{
		delete _p;
		_p = nullptr;
	}
}

typedef struct tagLinePoint {
	float fX, fY;

	tagLinePoint()
	{
		ZeroMemory(this, sizeof(tagLinePoint));
	}
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY)
	{

	}
}LINEPOINT;

typedef struct tagLine 
{
	LINEPOINT tLPoint;
	LINEPOINT tRPoint;

	tagLine()
	{
		ZeroMemory(this, sizeof(tagLine));
	}

	tagLine(LINEPOINT _tLPoint, LINEPOINT _tRPoint) : tLPoint(_tLPoint), tRPoint(_tRPoint)
	{

	}
}LINE;

enum LINESTATE {
	LEFT,
	RIGHT,
	LINECHECK
};

enum SCENENUMBER {
	SCENE01 = 1,
	SCENE02,
	SCENE03,
	SCENE04,
	SCENE_END
};

struct DeleteObj
{
	template<typename T>
	void	operator()(T& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};