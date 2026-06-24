//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"

class CMath
{
public:
    // VECTOR --------------------------------------------------------------------------

    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(float _x, float _y, float _z);
    };

    static void VectorAdd(Vector3& out, const Vector3& a, const Vector3& b);
    static void VectorSub(Vector3& out, const Vector3& a, const Vector3& b);
    static void VectorMul(Vector3& out, const Vector3& v, float scalar);
    static float VectorLength(const Vector3& v);
    static float VectorLength2D(const Vector3& v);
    static float VectorDot(const Vector3& a, const Vector3& b);
    static void VectorNormalize(Vector3& v);
    static void VectorCross(Vector3& out, const Vector3& a, const Vector3& b);
    static float VectorDistance(const Vector3& a, const Vector3& b);
    static float VectorDistance2D(const Vector3& a, const Vector3& b);
    static void CalculateDeltaPosition(Vector3& out, const Vector3& from, const Vector3& to);

    // UTILITIES -----------------------------------------------------------------------

    static float CalculateAngle(const Vector3& from, const Vector3& to);
    static float NormalizeAngle(float angle);
    static float Lerp(float a, float b, float t);
    static int GetRandomNumber(int min, int max);
    static float GetRandomFloat(float min, float max);

    // MATRIX --------------------------------------------------------------------------

    struct Matrix4x4
    {
        float m[16];

        void Identity();
        void Transform(Vector3& out, const Vector3& in) const;
    };

    static float Math_CalculateDistance2D(float dx, float dz);
    static float Math_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2);

    // GAME CALLS ----------------------------------------------------------------------

    static void Vector_Transform(DWORD output, DWORD input, DWORD matrix);
    static void CalculateEntityTransform(DWORD thisPtr, DWORD output);
};