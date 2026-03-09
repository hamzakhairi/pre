

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
    public :
        int x;
        int y;
        vect2() : x(0), y(0) {}
        vect2(int x, int y) : x(x), y(y) {}
        vect2(const vect2& other)
        {
            x = other.x;
            y = other.y;
        }
        vect2 operator=(const vect2& other)
        {
            if (this != &other)
            {
                x = other.x;
                y = other.y;
            }
            return *this;
        }
        int& operator[](int index) 
        {
            if (index == 0)
                return x;
            return y;
        }
        int operator[](int index) const
        {
            if (index == 0)
                return x;
            return y;
        }
        friend std::ostream& operator<<(std::ostream& os, const vect2& other)
        {
            os << "{" << other[0] << ", " << other[1] << "}";
            return os;
        }

        vect2 operator++(int)
        {
            vect2 tmp(*this);
            x++;
            y++;
            return tmp;
        }
        vect2& operator++()
        {
            x++;
            y++;
            return *this;
        }
        vect2 operator--(int)
        {
            vect2 tmp(*this);
            x--;
            y--;
            return tmp;
        }
        vect2& operator--()
        {
            x--;
            y--;
            return *this;
        }

        vect2& operator+=(const vect2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        vect2& operator-=(const vect2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }
        vect2& operator*=(const vect2& other)
        {
            x *= other.x;
            y *= other.y;
            return *this;
        }
        vect2& operator*=(int index)
        {
            x *= index;
            y *= index;
            return *this;
        }

        vect2 operator*(int index) const
        {
            return (vect2(x * index, y * index));
        }
        vect2 operator+(const vect2& other) const
        {
            return vect2(x + other.x, y + other.y);
        }
        vect2 operator-(const vect2& other) const
        {
            return vect2(x - other.x, y - other.y);
        }

        friend vect2 operator*(int number, const vect2& other)
        {
            return (vect2(number * other.x, number * other.y));
        }
        vect2 operator-()
        {
            return vect2(x * -1, y * -1);
        }

        friend bool operator==(const vect2& o1, const vect2& o2)
        {
            return (o1.x == o2.x && o1.y == o2.y);
        }

        friend bool operator!=(const vect2& o1, const vect2& o2)
        {
            return !(o1 == o2);
        }

};

#endif
