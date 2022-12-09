#include "point.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void parent::set_x(int r)
    {
        x = 10;
        x = r;
    }
void parent::set_y(int r)
    {
        y = 10;
        y = r;
    }
void parent::set_methodNum(int r)
    {
        metodNum = r;
    }
int parent::get_methodNum()
    {
        return metodNum;
    }
int parent::get_x()
    {
        return x;
    }
int parent::get_y()
    {
        return y;
    }
void parent::A_move()
    {
        if (n == 0) x++;
        if (n == 1) x--;
        if (x > 980) n = 1;
        if (x < 1) n = 0;
        if (l == 0) y++;
        if (l == 1) y--;
        if (y > 980) l = 1;
        if (y < 1) l = 0;
    }
void parent::B_move()
    {
        rotation++;
        if (rotation > 360) rotation = 0;
    }
void parent::set_rotation(int rotation)
{
    this->rotation = rotation;
}
int parent::get_rotation()
{
    return rotation;
}

void point::set_size(int size)
{
    this->size = size;
    set_s();
}
void point::A_move()
{
    //if (n == 0) x++;
    //if (n == 1) x--;
    //if (x > 980) n = 1;
    //if (x < 1) n = 0;
    //if (l == 0) y++;
    //if (l == 1) y--;
    //if (y > 980) l = 1;
    //if (y < 1) l = 0;
    circle.setPosition(get_x(), get_y());
}
void point::B_move()
{
    rotation++;
    if (rotation > 360) rotation = 0;
    circle.rotate(get_rotation());
}
CircleShape point::creating()
{
    return circle;
}
void point::set_s()
{
    circle.setRadius(size);
}
void cir::size_swap(int size)
{
    set_size(size);
}

void segment::set_thickness(int thickness)
{
    this->thickness = thickness;
    line.setSize(Vector2f(length, this->thickness));
}
void segment::A_move()
{
    //if (n == 0) x++;
    //if (n == 1) x--;
    //if (x > 980) n = 1;
    //if (x < 1) n = 0;
    //if (l == 0) y++;
    //if (l == 1) y--;
    //if (y > 980) l = 1;
    //if (y < 1) l = 0;
    line.setPosition(get_x(), get_y());
    rotation = 1;
    line.rotate(get_rotation());
}
void segment::B_move()
{
    line.setPosition(get_x(), get_y());
    rotation = 2;
    line.rotate(get_rotation());
}
RectangleShape segment::creating()
{
    return line;
}
void segment::set_length(int length)
{
    this->length = length;
    line.setSize(Vector2f(this->length, thickness));
}

void rectangle::set_leng(int leng)
{
    set_length(leng);
}
void rectangle::set_thick(int thick)
{
    set_thickness(thick);
}

void trinagle::A_move()
{
    if (n == 0) x++;
    if (n == 1) x--;
    if (x > 980) n = 1;
    if (x < 1) n = 0;
    if (l == 0) y++;
    if (l == 1) y--;
    if (y > 980) l = 1;
    if (y < 1) l = 0;
    trinagl.setPosition(get_x(), get_y());
}
void trinagle::B_move()
{
    rotation++;
    if (rotation > 360) rotation = 0;
    trinagl.rotate(get_rotation());
}
CircleShape trinagle::creating()
{
    return trinagl;
}

void square::A_move()
{
    if (n == 0) x++;
    if (n == 1) x--;
    if (x > 980) n = 1;
    if (x < 1) n = 0;
    if (l == 0) y++;
    if (l == 1) y--;
    if (y > 980) l = 1;
    if (y < 1) l = 0;
    squar.setPosition(get_x(), get_y());
}
void square::B_move()
{
    rotation++;
    if (rotation > 360) rotation = 0;
    squar.rotate(get_rotation());
}
CircleShape square::creating()
{
    return squar;
}

ConvexShape ellipse::creating()
{
    return ellips;
}
void ellipse::A_move()
{
    if (n == 0) x++;
    if (n == 1) x--;
    if (x > 980) n = 1;
    if (x < 1) n = 0;
    if (l == 0) y++;
    if (l == 1) y--;
    if (y > 980) l = 1;
    if (y < 1) l = 0;
    ellips.setPosition(get_x(), get_y());
}
void ellipse::B_move()
{
    rotation++;
    if (rotation > 360) rotation = 0;
    ellips.rotate(get_rotation());
}
