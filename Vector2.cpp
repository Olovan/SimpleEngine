#include "Vector2.h"
#include <iostream>
#include <sstream>

//patch for to_string because of MinGW glitch
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float iX, float iY)
{
    x = iX;
    y = iY;
}

Vector2::Vector2(sf::Vector2f iVector2)
{
    x = iVector2.x;
    y = iVector2.y;
}

Vector2::Vector2(b2Vec2 iVector2)
{
    x = iVector2.x;
    y = iVector2.y;
}

sf::Vector2f Vector2::sfml()
{
    return sf::Vector2f(x,y);
}

b2Vec2 Vector2::box2D()
{
    return b2Vec2(x,y);
}

Vector2 Vector2::add(Vector2 other)
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::subtract(Vector2 other)
{
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::multiply(Vector2 other)
{
    return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::divide(Vector2 other)
{
    return Vector2(x / other.x, y / other.y);
}

Vector2 Vector2::operator+(const Vector2 &right)
{
    return this->add(right);
}

Vector2 Vector2::operator-(const Vector2 &right)
{
    return this->subtract(right);
}

Vector2 Vector2::operator*(const Vector2 &right)
{
    return this->multiply(right);
}

Vector2 Vector2::operator*(const float &right)
{
    return Vector2(this->x * right, this->y * right);
}

Vector2 Vector2::operator/(const Vector2 &right)
{
    return this->divide(right);
}

Vector2 Vector2::operator/(const float &right)
{
    return Vector2(this->x / right, this->y / right);
}

Vector2& Vector2::operator+=(const Vector2 &right)
{
    (*this) = *this + right;
    return *this;
}

std::string Vector2::print()
{
    return patch::to_string(this->x) + ", " + patch::to_string(this->y);
}
