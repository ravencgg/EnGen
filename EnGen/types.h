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

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t b8;
typedef int16_t b16;
typedef int32_t b32;

const float pixelsPerMeter = 30.f;
const float metersPerPixel = 1.f / pixelsPerMeter;

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

union Vec2 
{
    struct { float x, y; };
    struct { float r, g; };
    float e[2];
};

union Vec3
{
    struct { float x, y, z; };
    struct { float r, g, b; };
    struct { Vec2 xy; float _ignoredv3; };
    float e[3];
};

union Vec4
{
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };
    struct { Vec3 xyz; float _ignoredv4; }; 
    float e[4];
};

inline Vec2 vec2(float x, float y)
{
    Vec2 result = { x, y };
    return result;
}

inline Vec3 vec3(float x, float y, float z)
{
    Vec3 result = { x, y, z };
    return result;
}

inline Vec3 vec3(Vec2 xy, float z)
{
    Vec3 result = { xy.x, xy.y, z };
    return result;
}

inline Vec4 vec4(float x, float y, float z, float w)
{
    Vec4 result = { x, y, z, w };
    return result;
}

#define PI 3.1415926f
#define RAD_2_DEG 57.29577951308232f
#define DEG_2_RAD 0.0174532925f

inline int32 round_float_to_int32(float num)
{
    int32 result = (int32)(num + 0.5f);
    return result;
}

inline float rad_to_deg(float f)
{
    float result = (f * 180.f) / PI;
    return result;
}

inline float deg_to_rad(float f)
{
    float result = (f * PI) / 180.f;
    return result;
}

inline u32 Max(u32 a, u32 b)
{
    u32 result = (a < b ? b : a);
    return result;
}

inline uint32 Min(uint32 a, uint32 b)
{
    uint32 result = (a < b ? a : b);
    return result;
}

inline int32 Max(int32 a, int32 b)
{
    int32 result = (a < b ? b : a);
    return result;
}

inline int32 Min(int32 a, int32 b)
{
    int32 result = (a < b ? a : b);
    return result;
}

inline float Max(float a, float b)
{
    float result = (a < b ? b : a);
    return result;
}

inline float Min(float a, float b)
{
    float result = (a < b ? a : b);
    return result;
}

inline float clamp01(float f)
{
    float result = Min(Max(f, 0.f), 1.f);
    return result;
}

inline Vec2
Perp(Vec2 A)
{
    Vec2 result = {-A.y, A.x};
    return result;
}

inline Vec2
operator*(float A, Vec2 B)
{
    Vec2 result;

    result.x = A*B.x;
    result.y = A*B.y;

    return result;
}

inline Vec2
operator*(Vec2 B, float A)
{
    Vec2 result = A*B;

    return result;
}

inline Vec2 &
operator*=(Vec2 &B, float A)
{
    B = A * B;

    return B;
}

inline Vec2
operator-(Vec2 A)
{
    Vec2 result;

    result.x = -A.x;
    result.y = -A.y;

    return result;
}

inline Vec2
operator+(Vec2 A, Vec2 B)
{
    Vec2 result;

    result.x = A.x + B.x;
    result.y = A.y + B.y;

    return result;
}

inline Vec2 &
operator+=(Vec2 &A, Vec2 B)
{
    A = A + B;

    return(A);
}

inline Vec2
operator-(Vec2 A, Vec2 B)
{
    Vec2 result;

    result.x = A.x - B.x;
    result.y = A.y - B.y;

    return result;
}

inline Vec2
hadamard(Vec2 A, Vec2 B)
{
    Vec2 result = {A.x*B.x, A.y*B.y};

    return result;
}

inline float
dot(Vec2 A, Vec2 B)
{
    float result = A.x*B.x + A.y*B.y;

    return result;
}

inline float
length_sq(Vec2 A)
{
    float result = dot(A, A);

    return result;
}

inline float
length(Vec2 A)
{
    float result = sqrt(length_sq(A));
    return result;
}

//inline float
//clamp01(float value)
//{
//	float result = Max(Min(0.f, value), 1.f); 
//    return result;
//}

inline Vec2
clamp01(Vec2 Value)
{
   Vec2 result;

   result.x = clamp01(Value.x);
   result.y = clamp01(Value.y);

   return result;
}

inline
std::string to_string(Vec2 v)
{
    std::string x_str = std::to_string(v.x);
    std::string y_str = std::to_string(v.y);
    std::string result = "(" + x_str + ", " + y_str + ")";
    return result;
}

//
// NOTE(casey): Vec3 operations
//

inline Vec3
operator*(float A, Vec3 B)
{
    Vec3 result;

    result.x = A*B.x;
    result.y = A*B.y;
    result.z = A*B.z;
    
    return result;
}

inline Vec3
operator*(Vec3 B, float A)
{
    Vec3 result = A*B;

    return result;
}

inline Vec3 &
operator*=(Vec3 &B, float A)
{
    B = A * B;

    return(B);
}

inline Vec3
operator-(Vec3 A)
{
    Vec3 result;

    result.x = -A.x;
    result.y = -A.y;
    result.z = -A.z;

    return result;
}

inline Vec3
operator+(Vec3 A, Vec3 B)
{
    Vec3 result;

    result.x = A.x + B.x;
    result.y = A.y + B.y;
    result.z = A.z + B.z;

    return result;
}

inline Vec3 &
operator+=(Vec3 &A, Vec3 B)
{
    A = A + B;

    return(A);
}

inline Vec3
operator-(Vec3 A, Vec3 B)
{
    Vec3 result;

    result.x = A.x - B.x;
    result.y = A.y - B.y;
    result.z = A.z - B.z;

    return result;
}

inline Vec3
Hadamard(Vec3 A, Vec3 B)
{
    Vec3 result = {A.x*B.x, A.y*B.y, A.z*B.z};

    return result;
}

inline float
dot(Vec3 A, Vec3 B)
{
    float result = A.x*B.x + A.y*B.y + A.z*B.z;

    return result;
}

inline float
LengthSq(Vec3 A)
{
    float result = dot(A, A);

    return result;
}

inline float
Length(Vec3 A)
{
    float result = sqrt(LengthSq(A));
    return result;
}

inline Vec3
Normalize(Vec3 A)
{
    Vec3 result = A * (1.0f / Length(A));

    return result;
}

inline Vec3
Clamp01(Vec3 Value)
{
    Vec3 result;

    result.x = clamp01(Value.x);
    result.y = clamp01(Value.y);
    result.z = clamp01(Value.z);

    return result;
}

inline Vec3
Lerp(Vec3 A, float t, Vec3 B)
{
    Vec3 result = (1.0f - t)*A + t*B;

    return result;
}

//
// NOTE(casey): Vec4 operations
//

inline Vec4
operator*(float A, Vec4 B)
{
    Vec4 result;

    result.x = A*B.x;
    result.y = A*B.y;
    result.z = A*B.z;
    result.w = A*B.w;
    
    return result;
}

inline Vec4
operator*(Vec4 B, float A)
{
    Vec4 result = A*B;

    return result;
}

inline Vec4 &
operator*=(Vec4 &B, float A)
{
    B = A * B;

    return(B);
}

inline Vec4
operator-(Vec4 A)
{
    Vec4 result;

    result.x = -A.x;
    result.y = -A.y;
    result.z = -A.z;
    result.w = -A.w;

    return result;
}

inline Vec4
operator+(Vec4 A, Vec4 B)
{
    Vec4 result;

    result.x = A.x + B.x;
    result.y = A.y + B.y;
    result.z = A.z + B.z;
    result.w = A.w + B.w;

    return result;
}

inline Vec4 &
operator+=(Vec4 &A, Vec4 B)
{
    A = A + B;

    return(A);
}

inline Vec4
operator-(Vec4 A, Vec4 B)
{
    Vec4 result;

    result.x = A.x - B.x;
    result.y = A.y - B.y;
    result.z = A.z - B.z;
    result.w = A.w - B.w;

    return result;
}

inline Vec4
Hadamard(Vec4 A, Vec4 B)
{
    Vec4 result = {A.x*B.x, A.y*B.y, A.z*B.z, A.w*B.w};

    return result;
}

inline float
dot(Vec4 A, Vec4 B)
{
    float result = A.x*B.x + A.y*B.y + A.z*B.z + A.w*B.w;

    return result;
}

inline float
LengthSq(Vec4 A)
{
    float result = dot(A, A);

    return result;
}

inline float
Length(Vec4 A)
{
    float result = sqrt(LengthSq(A));
    return result;
}

inline Vec4
Clamp01(Vec4 Value)
{
    Vec4 result;

    result.x = clamp01(Value.x);
    result.y = clamp01(Value.y);
    result.z = clamp01(Value.z);
    result.w = clamp01(Value.w);

    return result;
}

inline Vec4
Lerp(Vec4 A, float t, Vec4 B)
{
    Vec4 result = (1.0f - t)*A + t*B;

    return result;
}


#pragma once

#include <assert.h>

template <typename T>
struct Array
{
    T* data;
    int size;
    int capacity;

    Array<T>(int initialSize = 2)
    {
        data = new T[initialSize];
        size = 0;
        capacity = initialSize;
    }

    ~Array<T>()
    {
        delete[] data;
    }

    void Reserve(int newSize)
    {
        if (newSize > capacity)
        {
            T* old = data;
            data = new T[newSize];
            memcpy(data, old, sizeof(T) * size);
            delete[] old;
            capacity = newSize;
        }
    }

    // Does not free the memory, just invalidates the members
    void Clear()
    {
        size = 0;
    }

    void Reset(int newSize = 2)
    {
        delete[] data;
        data = new T[newSize];
    }

    void Reallocate()
    {
        T* old = data;
        capacity *= 2;
        data = new T[capacity];
        memcpy(data, old, sizeof(T) * size);
        delete[] old;
    }

    void Add(T d)
    {
        if (size >= capacity)
        {
            Reallocate();
        }
        data[size++] = d;
    }

    void SwapDelete(int index)
    {
        assert(index < size);
        memcpy(&data[index], &data[size - 1], sizeof(T));
        size -= 1;
    }

    void RemoveBack()
    {
        size -= 1;
    }

    T& Get(int index)
    {
        T& result = data[index];
        return result;
    }

    T& operator[](int index)
    {
        T& result = data[index];
        return result;
    }
};
