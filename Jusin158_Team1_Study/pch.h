#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include <list>
#include <vector>
#include <algorithm>
// custom header
#include "Vector2.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif
#endif
using namespace std;

#endif //PCH_H
