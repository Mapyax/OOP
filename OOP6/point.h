#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

class parent
{
protected:
    CircleShape circle;
    CircleShape trinagl;
    RectangleShape line;
    CircleShape squar;
    ConvexShape ellips;
    int x;
    int y;
    int metodNum;
    int n = 0;
    int l = 0;
    int rotation;
public:
    void set_x(int r);
    void set_x();
    void set_y(int r);
    void set_y();
    void set_methodNum(int r);
    int get_methodNum();
    int get_x();
    int get_y();
    virtual void A_move();
    virtual void B_move();
    void set_rotation(int rotation);
    int get_rotation();

};

class point : public parent
{
private:
    int size;
public:
    point(int x = 0, int y = 0, int methodNum = 0, int rotation = 0)
    {
        set_x(x);
        set_y(y);
        set_methodNum(methodNum);
        set_rotation(rotation);
        circle.setRadius(3);
        circle.setPosition(get_x(), get_y());
        circle.setRotation(get_rotation());
        circle.setFillColor(Color(85, 107, 47));
    }
    point();
    CircleShape creating();
    void A_move();
    void B_move();
    void set_size(int size);
    void set_s();
 
};

class cir : public point
{
private:
    int size;
public:
    point::point;
    void size_swap(int size);
};

class segment : public parent
{
private:
    int thickness;
    int length;
public:
    segment(int x = 0, int y = 0, int length = 0, int thickness = 1, int rotation = 0, int methodNum = 0)
    {
        set_x(x);
        set_y(y);
        set_rotation(rotation);
        set_thickness(thickness);
        this->length = length;
        line.setSize(Vector2f(length, thickness));
        set_methodNum(methodNum);
    }
    void set_thickness(int thickness);
    void set_length(int length);
    RectangleShape creating();
    void A_move();
    void B_move();
};

class rectangle : public segment
{
public:
    segment::segment;
    void set_leng(int leng);
    void set_thick(int thick);
};

class trinagle : public parent
{
private:
    int radius;
public:
    trinagle(int x = 0, int y = 0, int rotation = 0, int methodNum = 0, int radius = 0)
    {
        set_x(x);
        set_y(y);
        set_methodNum(methodNum);
        set_rotation(rotation);
        trinagl.setPointCount(3);
        trinagl.setPosition(get_x(), get_y());
        trinagl.setRotation(get_rotation());
        trinagl.setRadius(radius);
        trinagl.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
    }
    CircleShape creating();
    void A_move();
    void B_move();
};

class square : public parent
{
private:
    int radius;
public:
    square(int x = 0, int y = 0, int rotation = 0, int methodNum = 0, int radius = 0)
    {
        set_x(x);
        set_y(y);
        set_methodNum(methodNum);
        set_rotation(rotation);
        squar.setPointCount(4);
        squar.setPosition(get_x(), get_y());
        squar.setRotation(get_rotation());
        squar.setRadius(radius);
        squar.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
    }

    CircleShape creating();
    void A_move();
    void B_move();
};

class ellipse : public parent
{
public:
    float x_rad = 20;
    float y_rad = 40;
    unsigned short LL = 70;
    ellipse(int x = 0, int y = 0, unsigned short LL = 0, float rotation = 0, int methodNum = 0, int radius = 0)
    {
        set_x(x);
        set_y(y);
        set_methodNum(methodNum);
        set_rotation(rotation);
        ellips.setPointCount(LL);
        ellips.setPosition(get_x(), get_y());
        ellips.setRotation(get_rotation());
        ellips.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        for (unsigned short i = 0; i < LL; ++i)
        {
            float rad = (360 / LL * i) / (360 / 3.1415926 / 2);
            float x = cos(rad) * x_rad;
            float y = sin(rad) * y_rad;

            ellips.setPoint(i, Vector2f(x, y));
        }
    }
    void A_move();
    void B_move();
    ConvexShape creating();
};