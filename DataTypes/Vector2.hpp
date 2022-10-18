#pragma once

#include <math.h>

template <class T>
class Vector2T
{
    T X;
    T Y;

public:


    Vector2T(T x = 0, T y = 0) : X(x), Y(y) {}

    // typecast
    template <class T2>
    operator Vector2T<T2>()
    {
        Vector2T<T2> res;
        res.SetX(static_cast<T2>(X));
        res.SetY(static_cast<T2>(Y));
        return res;
    }

    // ==
    template <class T2>
    bool operator==(const Vector2T<T2> b)
    {
        return X == b.X && Y == b.Y;
    }

    // !=
    template <class T2>
    bool operator!=(const Vector2T<T2> b)
    {
        return X != b.X && Y != b.Y;
    }

    // +
    template <class T2>
    Vector2T operator+(const Vector2T<T2> b)
    {
        Vector2T<T2> res = *this;
        res.X += static_cast<T2>(X);
        res.Y += static_cast<T2>(Y);
        return res;
    }

    template <class T2>
    void operator+=(const Vector2T<T2> b)
    {
        X += static_cast<T2>(b.X);
        Y += static_cast<T2>(b.Y);
    }

    // -
    template <class T2>
    Vector2T operator-(const Vector2T<T2> b)
    {
        Vector2T<T2> res = *this;
        res.X -= static_cast<T2>(X);
        res.Y -= static_cast<T2>(Y);
        return res;
    }

    template <class T2>
    void operator-=(const Vector2T<T2> b)
    {
        X -= static_cast<T2>(b.X);
        Y -= static_cast<T2>(b.Y);
    }

    // *
    template <class Scalar>
    Vector2T operator*(const Scalar scalar)
    {
        Vector2T<Scalar> res = *this;
        res.X *= scalar;
        res.Y *= scalar;
        return res;
    }

    template <class Scalar>
    void operator*=(const Scalar scalar)
    {
        X *= scalar;
        Y *= scalar;
    }

    // /
    template <class Scalar>
    Vector2T operator/(const Scalar scalar)
    {
        Vector2T<Scalar> res = *this;
        res.X /= scalar;
        res.Y /= scalar;
        return res;
    }

    template <class Scalar>
    void operator/=(const Scalar scalar)
    {
        X /= scalar;
        Y /= scalar;
    }

    T Length() const { return sqrtf(LengthSquared); }

    T LengthSquared() const { return (X * X) + (Y * Y); }

    Vector2T Normalize() const
    {
        float oneOverL = 1.0f / Length();
        Vector2T<T> res = Vector2T<T>(X * oneOverL, Y * oneOverL);
        return res;
    }

    void SetX(T x) { X = x; }
    void SetY(T y) { Y = y; }
    T GetX() const { return X; }
    T GetY() const { return Y; }

    void SetXPlus(T x) { X = X+x; }
    void SetYPlus(T y) { Y = Y+y; }

    void SetXMinus(T x) { X = X-x; }
    void SetYMinus(T y) { Y = Y-y; }
};

typedef Vector2T<int> Vector2;
typedef Vector2T<float> Vector2F;
typedef Vector2T<double> Vector2D;