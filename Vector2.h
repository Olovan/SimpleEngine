#ifndef VECTOR2_H
#define VECTOR2_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <string>


class Vector2
{
    public:
        Vector2();
        Vector2(float iX, float iY);
        Vector2(sf::Vector2f iVector2);
        Vector2(b2Vec2 iVector2);
        float x;
        float y;

        sf::Vector2f sfml();
        b2Vec2 box2D();
        std::string print();

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


    protected:
    private:
};

#endif // VECTOR2_H
