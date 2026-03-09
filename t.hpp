#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>
#include <stdexcept>

class vect2 {
public:
    int x;
    int y;

    vect2(int x, int y) : x(x), y(y) {}
    vect2() : x(0), y(0) {}

    vect2(const vect2&) = default;
    vect2& operator=(const vect2&) = default;

    int& operator[](size_t index)
    {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("vect2 index must be 0 or 1");
    }

    int operator[](size_t index) const
    {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("vect2 index must be 0 or 1");
    }

    friend std::ostream& operator<<(std::ostream& o, const vect2& v)
    {
        return o << "{" << v.x << ", " << v.y << "}";
    }

    vect2 operator++(int) { vect2 tmp(*this); ++x; ++y; return tmp; }
    vect2& operator++() { ++x; ++y; return *this; }

    vect2 operator--(int) { vect2 tmp(*this); --x; --y; return tmp; }
    vect2& operator--() { --x; --y; return *this; }

    vect2& operator+=(const vect2& o) { x += o.x; y += o.y; return *this; }
    vect2& operator-=(const vect2& o) { x -= o.x; y -= o.y; return *this; }

    vect2& operator*=(const vect2& o) { x *= o.x; y *= o.y; return *this; }
    vect2& operator*=(int n) { x *= n; y *= n; return *this; }

    vect2 operator*(int n) const { return vect2(x*n, y*n); }
    vect2 operator+(const vect2& o) const { return vect2(x+o.x, y+o.y); }
    vect2 operator-(const vect2& o) const { return vect2(x-o.x, y-o.y); }

    friend vect2 operator*(int n, const vect2& v)
    {
        return vect2(v.x*n, v.y*n);
    }

    vect2 operator-() const { return vect2(-x, -y); }

    friend bool operator==(const vect2& a, const vect2& b)
    {
        return a.x == b.x && a.y == b.y;
    }

    friend bool operator!=(const vect2& a, const vect2& b)
    {
        return !(a == b);
    }
};

#endif