#pragma once
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string>
#include "SDKsound.h"
#include "SDKwavefile.h"
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "dsound.lib")

#define g_Device DXUTGetD3D9Device()
#define DT DXUTGetElapsedTime()

const float WINSIZE_X = 320;
const float WINSIZE_Y = 720;

using namespace std;
using Vec2 = D3DXVECTOR2;
using Matrix = D3DXMATRIX;
#include "Math.h"
using namespace Math;

#include "cSingleton.h"
#include "cImageManager.h"
#include "cCameraManager.h"
#include "cInputManager.h"
#include "cSoundManager.h"
#include "cSceneManager.h"
#include "cScheduleManager.h"
#include "cObjectManager.h"

#include "cComponent.h"
#include "cRenderer.h"
#include "cAnimation.h"
#include "cCollider.h"
#include "cCircleCollider.h"
#include "cBoxCollider.h"

void Debug(wchar_t* str)
{
    OutputDebugString(str);
}

template<typename T>

void Debug(wchar_t* format, const T& src)
{
    wchar_t str[200];
    swprintf(str, format, src);
    OutputDebugString(str);
}
