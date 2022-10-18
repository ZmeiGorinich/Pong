#pragma once

#include "Size.hpp"
#include "Vector2.hpp"

template<class T>
class RectangleT
{
public:
    int X = 0;
    int Y = 0;
    int Width = 0;
    int Height = 0;

    RectangleT() {}
    RectangleT(T x, T y, T width, T height) : X(x), Y(y), Width(width), Height(height) {}
    RectangleT(SizeT<T> size) : Width(size.Width), Height(size.Height) {}

    //typecast
    template<class T2>
    operator RectangleT<T2>()
    {
        RectangleT<T2> res;
        res.X = static_cast<T2>(X);
        res.Y = static_cast<T2>(Y);
        res.Width = static_cast<T2>(Width);
        res.Height = static_cast<T2>(Height);
        return res;
    }

    // ==
    template<class T2>
    bool operator == (const RectangleT<T2> b)
    {
        return X == b.X && Y == b.Y && Width == b.Width && Height == b.Height;
    }

    // !=
    template<class T2>
    bool operator != (const RectangleT<T2> b)
    {
        return  X != b.X && Y != b.Y && Width != b.Width && Height != b.Height;
    }

    // +
    template<class T2>
    RectangleT operator + (const RectangleT<T2> b)
    {
        RectangleT<T2> res = *this;
        res.X += static_cast<T2>(X);
        res.Y += static_cast<T2>(Y);
        res.Width += static_cast<T2>(Width);
        res.Height += static_cast<T2>(Height);
        return res;
    }

    template<class T2>
    void operator += (const RectangleT<T2> b)
    {
        X += static_cast<T2>(b.X);
        Y += static_cast<T2>(b.Y);
        Width += static_cast<T2>(b.Width);
        Height += static_cast<T2>(b.Height);
    }

    // -
    template<class T2>
    RectangleT operator - (const RectangleT<T2> b)
    {
        RectangleT<T2> res = *this;
        res.X -= static_cast<T2>(X);
        res.Y -= static_cast<T2>(Y);
        res.Width -= static_cast<T2>(Width);
        res.Height -= static_cast<T2>(Height);
        return res;
    }

    template<class T2>
    void operator -= (const RectangleT<T2> b)
    {
        X -= static_cast<T2>(b.X);
        Y -= static_cast<T2>(b.Y);
        Width -= static_cast<T2>(b.Width);
        Height -= static_cast<T2>(b.Height);
    }

    Vector2T<T> Location()
    {
        Vector2T<T> res;
        res.X = X;
        res.Y = Y;
        return res;
    }

    Vector2T<T> LocationB()
    {
        Vector2T<T> res;
        res.X = X + Width;
        res.Y = Y + Height;
        return res;
    }

    void Inflate(const SizeT<T> Amount)
    {
        Width += static_cast<T>(Amount.Width);
        Height += static_cast<T>(Amount.Height);
    }

    void Offset(const Vector2T<T> OffsetAmount)
    {
        X += static_cast<T>(OffsetAmount.X);
        Y += static_cast<T>(OffsetAmount.Y);
    }

    T Left() const
    {
        return X;
    }

    T Right() const
    {
        return X + Width;
    }

    T Top() const
    {
        return Y;
    }

    T Bottom() const
    {
        return Y + Height;
    }

    bool Contains(Vector2T<T> location) const
    {
        return (Left() < location.X && location.X < Right() &&
            Top() < location.Y&& location.Y < Bottom());
    }

    bool Contains(RectangleT<T> rectB) const
    {
        bool a = Contains(rectB.Location());
        bool b = Contains(rectB.LocationB());

        return a && b;
    }

    bool IntersectsWith(const RectangleT<T> rectB) const
    {
        return (Right() > rectB.Left() && rectB.Right() > Left() &&
            Top() < rectB.Bottom() && rectB.Top() < Bottom());
    }
};

typedef RectangleT<int> Rectangle;
typedef RectangleT<float> RectangleF;