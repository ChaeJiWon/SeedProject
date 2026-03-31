#pragma once
#include <assert.h>

#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include <memory>
#include <wrl.h>

#include "seEnums.h"
#include "seMath.h"


#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = nullptr; }
#define SAFE_RELEASE(p) if (p) { p->Release(); p = nullptr; }