#ifndef VECTOR2_H
#define VECTOR2_H

#include <SFML/Graphics.hpp>
#include <string>


class Vector2
{
    public:
        Vector2();
        Vector2(float iX, float iY);
        Vector2(sf::Vector2f iVector2);
        float x;
        float y;
        Vector2 add(Vector2 other);
        Vector2 subtract(Vector2 other);
        Vector2 multiply(Vector2 other);
        Vector2 divide(Vector2 other);
        Vector2 operator+(const Vector2 &right);
        Vector2 operator-(const Vector2 &right);
        Vector2 operator*(const Vector2 &right);
        Vector2 operator*(const float &right);
        Vector2 operator/(const Vector2 &right);
        Vector2 operator/(const float &right);
        Vector2& operator+=(const Vector2 &right);
        sf::Vector2f sfVector2();
        std::string print();
    protected:
    private:
};

#endif // VECTOR2_H
