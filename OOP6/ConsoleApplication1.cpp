#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "point.h"

using namespace sf;
const int mas_size = 2;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Lab6");
    point mas[mas_size] = { {rand() % 997 + 20, rand() % 997 + 20, 0, 0}, {rand() % 997 + 20, rand() % 997 + 20, 1, 0} };
    cir mas_cir[mas_size] = { {0, 0, 0, 0}, {400, 400, 1, 0} };
    segment mas_segment[mas_size] = { {500, 500, 20, 1, 0, 0}, {500, 500, 20, 1, 0, 1} };
    rectangle mas_rectangle[mas_size] = { {400, 400, 20, 5, 0, 1}, {400, 400, 5, 20, 0, 0} };
    trinagle mas_trinagle[mas_size] = { {rand() % 997 + 20, rand() % 997 + 20, 0, 0, 10}, {rand() % 997 + 20, rand() % 997 + 20, 0, 1, 10} };
    square mas_square[mas_size] = { {rand() % 997 + 20, rand() % 997 + 20, 0, 0, 10}, {rand() % 997 + 20, rand() % 997 + 20, 0, 1, 10} };
    ellipse mas_ellipse[mas_size] = { {rand() % 997 + 20, rand() % 997 + 20, 20, 0, 0, 10}, {rand() % 997 + 20, rand() % 997 + 20, 20, 0, 1, 10} };
    
    point* uk1[mas_size];
    cir* uk2[mas_size];
    segment* uk3[mas_size];
    rectangle* uk4[mas_size];
    trinagle* uk5[mas_size];
    square* uk6[mas_size];
    ellipse* uk7[mas_size];

    parent* uk[mas_size * 7];

    for (int i = 0; i < mas_size; i++)
    {
        uk1[i] = &mas[i];
        uk2[i] = &mas_cir[i];
        uk3[i] = &mas_segment[i];
        uk4[i] = &mas_rectangle[i];
        uk5[i] = &mas_trinagle[i];
        uk6[i] = &mas_square[i];
        uk7[i] = &mas_ellipse[i];

    }

     uk[0] = &mas[0];
     uk[1] = &mas[1];
     uk[2] = &mas_cir[0];
     uk[3] = &mas_cir[1];
     uk[4] = &mas_segment[0];
     uk[5] = &mas_segment[1];
     uk[6] = &mas_rectangle[0];
     uk[7] = &mas_rectangle[1];
     uk[8] = &mas_trinagle[0];
     uk[9] = &mas_trinagle[1];
     uk[10] = &mas_square[0];
     uk[11] = &mas_square[1];
     uk[12] = &mas_ellipse[0];
     uk[13] = &mas_ellipse[1];
    
    mas_cir[0].size_swap(400);
    mas_cir[1].size_swap(3);

    mas_rectangle[0].set_leng(350);
    mas_rectangle[1].set_leng(350);
    mas_rectangle[0].set_thick(2);
    mas_rectangle[1].set_thick(5);

    while (window.isOpen())
    {
        srand(clock());
        for (int i = 0; i < mas_size * 7; i++)
        {
            if (uk[i]->get_methodNum() == 0)
            {
                uk[i] -> A_move();
            }
            if (uk[i]->get_methodNum() == 1)
            {
                uk[i] -> B_move();
            }
        }
        window.clear();
        //for (int i = 0; i < mas_size; i++)
        //    window.draw(uk1[i] ->creating());
        for (int i = 0; i < mas_size; i++)
            window.draw(uk2[i] ->creating());
        //for (int i = 0; i < mas_size; i++)
        //    window.draw(uk3[i] ->creating());
        for (int i = 0; i < mas_size; i++)
            window.draw(uk4[i] ->creating());
        //for (int i = 0; i < mas_size; i++)
        //    window.draw(uk5[i] ->creating());
        //for (int i = 0; i < mas_size; i++)
        //    window.draw(uk6[i] ->creating());
        //for (int i = 0; i < mas_size; i++)
        //    window.draw(uk7[i] ->creating());
        window.display();
        Sleep(50);
    }
    free(mas);
    free(mas_cir);

    return 0;
}