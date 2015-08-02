#pragma once

#include <stdint.h>
#include <string>

typedef float real32;
typedef double real64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t bool8;
typedef int16_t bool16;
typedef int32_t bool32;

// Maybe don't put this here
#ifdef _DEBUG
const std::string res_path("./../Release/res/");
#elif _NDEBUG
const std::string res_path("./res/");
#endif

namespace DrawLayer
{
    enum Enum: uint32{ BACKGROUND, PRE_TILEMAP, TILEMAP, POST_TILEMAP, PLAYER, FOREGROUND, UI, LAYER_COUNT };
}

struct Dimension
{
	int32 width, height;
};

struct Point2
{
	int32 x, y;
};

struct Point3
{
	int32 x, y, z;
};

struct Rect
{
	union
	{
		struct
		{
			int32 x, y, w, h;
		};
		struct
		{
			int32 left, top, width, height;
		};
		int32 E[4];
	};
};

struct Rectf
{
	union
	{
		struct
		{
			float x, y, w, h;
		};
		struct
		{
			float left, top, width, height;
		};
		float E[4];
	};	
};

inline Rect rect(int32 x, int32 y, int32 w, int32 h)
{
	Rect result = {};
	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return result;
}

inline Rectf rect(float x, float y, float w, float h)
{
	Rectf result = {};
	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return result;
}