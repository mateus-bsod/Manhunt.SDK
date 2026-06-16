//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------
 
#include "CMath.h"

CMath::Vector3::Vector3() : x(0), y(0), z(0) {}
CMath::Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

void CMath::VectorAdd(Vector3& out, const Vector3& a, const Vector3& b)
{
    out.x = a.x + b.x;
    out.y = a.y + b.y;
    out.z = a.z + b.z;
}

void CMath::VectorSub(Vector3& out, const Vector3& a, const Vector3& b)
{
    out.x = a.x - b.x;
    out.y = a.y - b.y;
    out.z = a.z - b.z;
}

void CMath::VectorMul(Vector3& out, const Vector3& v, float scalar)
{
    out.x = v.x * scalar;
    out.y = v.y * scalar;
    out.z = v.z * scalar;
}

float CMath::VectorLength(const Vector3& v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float CMath::VectorLength2D(const Vector3& v)
{
    return sqrtf(v.x * v.x + v.z * v.z);
}

float CMath::VectorDot(const Vector3& a, const Vector3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

void CMath::VectorNormalize(Vector3& v)
{
    float len = VectorLength(v);
    if (len > 0.0001f)
    {
        v.x /= len;
        v.y /= len;
        v.z /= len;
    }
}

void CMath::VectorCross(Vector3& out, const Vector3& a, const Vector3& b)
{
    out.x = a.y * b.z - a.z * b.y;
    out.y = a.z * b.x - a.x * b.z;
    out.z = a.x * b.y - a.y * b.x;
}

float CMath::VectorDistance(const Vector3& a, const Vector3& b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

float CMath::VectorDistance2D(const Vector3& a, const Vector3& b)
{
    float dx = a.x - b.x;
    float dz = a.z - b.z;
    return sqrtf(dx * dx + dz * dz);
}

void CMath::CalculateDeltaPosition(Vector3& out, const Vector3& from, const Vector3& to)
{
    out.x = from.x - to.x;
    out.y = from.y - to.y;
    out.z = from.z - to.z;
}

float CMath::CalculateAngle(const Vector3& from, const Vector3& to)
{
    float dx = to.x - from.x;
    float dz = to.z - from.z;
    return atan2f(dz, dx) * 180.0f / 3.14159f;
}

float CMath::NormalizeAngle(float angle)
{
    while (angle > 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}

float CMath::Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

int CMath::GetRandomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

float CMath::GetRandomFloat(float min, float max)
{
    return min + (float)rand() / (float)RAND_MAX * (max - min);
}

void CMath::Matrix4x4::Identity()
{
    for (int i = 0; i < 16; i++) m[i] = 0;
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

void CMath::Matrix4x4::Transform(Vector3& out, const Vector3& in) const
{
    out.x = in.x * m[0] + in.y * m[4] + in.z * m[8] + m[12];
    out.y = in.x * m[1] + in.y * m[5] + in.z * m[9] + m[13];
    out.z = in.x * m[2] + in.y * m[6] + in.z * m[10] + m[14];
}

float CMath::Math_CalculateDistance2D(float dx, float dz)
{
    return sqrtf(dx * dx + dz * dz);
}

float CMath::Math_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dx = x1 - x2;
    float dy = y1 - y2;
    float dz = z1 - z2;
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

void CMath::Vector_Transform(DWORD output, DWORD input, DWORD matrix)
{
    Call<0x4044F0, DWORD, DWORD, DWORD>(output, input, matrix);
}

void CMath::CalculateEntityTransform(DWORD thisPtr, DWORD output)
{
    Call<0x43A940, DWORD, DWORD>(thisPtr, output);
}