/* 2251265 计拔 苏传州 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include"popstar.h"
#include "cmd_console_tools.h"
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_star_pro(int x, int y, int array[][10])
{
    cct_gotoxy(0, 0);
    cout << "屏幕当前设置为：" << 7 + 4 * x << "行" << 5 + 8 * y << "列";
    for (int i = 0; i < x; i++)
    {
        Sleep(1);
        for (int j = 0; j < y; j++)
        {
            cct_gotoxy(4 + j * 8, 3 + i * 4);
            cct_setcolor(array[i][j] + 8, COLOR_BLACK);
            for (int m = 0; m < 3; m++)
            {
                cct_gotoxy(4 + j * 8, 3 + i * 4 + m);
                switch (m)
                {
                    case 0:
                        cout << "╔═╗";
                        break;
                    case 1:
                        cout << "║★║";
                        break;
                    case 2:
                        cout << "╚═╝";
                }
            }
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_border_pro(int x, int y, int array[][10])
{
    cct_cls();
    cout << endl;
    for (int j = 0; j < 7 + 4 * x; j++)
    {
        Sleep(30);
        for (int i = 0; i < 4 + 8 * y; i += 2)
        {
            if (j == 0)
            {
                if ((i + 2) % 8 == 0 && i != 0)
                {
                    cct_gotoxy(i, j + 1);
                    cout << (i + 2) / 8 - 1;
                }
            }
            else if (j == 1)
            {
                if (i == 2)
                {
                    cct_gotoxy(2, j + 1);
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "╔";
                }
                else if ((i - 2) % 8 == 0 && i != 2 + 8 * y)
                    cout << "╦";
                else if (i > 2 && i < 2 + 8 * y)
                    cout << "═";
                else if (i == 2 + 8 * y)
                    cout << "╗";
            }
            else if (j > 2 && j <= 1 + 4 * x)
            {
                if (j % 4 == 0 && i == 0 && j != 0)
                {

                    cct_gotoxy(0, j);
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                    cout << (char)(j / 4 - 1 + 'A');

                }
                if ((j - 2) % 4 == 0 && j != 2)
                {
                    if (i == 2)
                    {
                        cct_gotoxy(2, j);
                        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                        cout << "╠";
                    }
                    else if ((i - 2) % 8 == 0 && i != 2 + 8 * y)
                        cout << "╬";
                    else if (i > 2 && i < 2 + 8 * y)
                        cout << "═";
                    else if (i == 2 + 8 * y)
                        cout << "╣";
                }
                else
                {
                    if (i == 2)
                    {
                        cct_gotoxy(2, j);
                        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                        cout << "║";
                    }
                    else if ((i - 2) % 8 == 0 && i != 2 + 8 * y)
                        cout << "║";
                    else if (i > 2 && i < 2 + 8 * y)
                        cout << "  ";
                    else if (i == 2 + 8 * y)
                        cout << "║";
                }
            }
            else if (j == 2 + 4 * x)
            {
                if (i == 2)
                {
                    cct_gotoxy(2, j);
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "╚";
                }
                else if ((i - 2) % 8 == 0 && i != 2 + 8 * y)
                    cout << "╩";
                else if (i > 2 && i < 2 + 8 * y)
                    cout << "═";
                else if (i == 2 + 8 * y)
                    cout << "╝";
            }
        }
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_star(int x, int y, int array[][10])
{
    cct_gotoxy(0, 0);
    cout << "屏幕当前设置为：" << 8 + 3 * x << "行" << 7 + 6 * y << "列";
    for (int i = 0; i < x; i++)
    {
        Sleep(1);
        for (int j = 0; j < y; j++)
        {
            cct_gotoxy(4 + j * 6, 3 + i * 3);
            cct_setcolor(array[i][j] + 8, COLOR_BLACK);
            for (int m = 0; m < 3; m++)
            {
                cct_gotoxy(4 + j * 6, 3 + i * 3 + m);
                switch (m)
                {
                    case 0:
                        cout << "╔═╗";
                        break;
                    case 1:
                        cout << "║★║";
                        break;
                    case 2:
                        cout << "╚═╝";
                }
            }
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_border(int x, int y, int array[][10])
{
    cct_cls();
    cout << endl;
    for (int j = 0; j < 3 + 3 * x; j++)
    {
        Sleep(30);
        for (int i = 0; i < 6 + 6 * y; i += 2)
        {
            if (j == 0)
            {
                if (i % 6 == 0 && i != 0)
                {
                    cct_gotoxy(i, j + 1);
                    cout << i / 6 - 1;
                }
            }
            else if (j == 1)
            {
                if (i == 2)
                {
                    cct_gotoxy(2, j + 1);
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "╔";
                }
                else if (i > 2 && i < 4 + 6 * y)
                    cout << "═";
                else if (i == 4 + 6 * y)
                    cout << "╗";
            }
            else if (j >= 2 && j <= 1 + 3 * x)
            {
                if (j % 3 == 0 && i == 0 && j != 0)
                {

                    cct_gotoxy(0, j + 1);
                    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                    cout << (char)(j / 3 - 1 + 'A');

                }

                if (i == 2)
                {
                    cct_gotoxy(2, j + 1);
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "║";
                }
                else if (i > 2 && i < 4 + 6 * y)
                    cout << "  ";
                else if (i == 4 + 6 * y)
                    cout << "║";
            }
            else if (j == 2 + 3 * x)
            {
                if (i == 2)
                {
                    cct_gotoxy(2, j + 1);
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "╚";
                }
                else if (i > 2 && i < 4 + 6 * y)
                    cout << "═";
                else if (i == 4 + 6 * y)
                    cout << "╝";
            }

        }
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void change_color_pro(int x1, int y1, int array[][10], int x)
{
    if (x == 3 || array[y1 - 'A'][x1] == 0)
        cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
    else if (x == 2)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_HWHITE);
    else if (x == 1)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_WHITE);
    else if (x == 0)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_BLACK);
    for (int m = 0; m < 3; m++)
    {
        cct_gotoxy(4 + x1 * 8, 3 + (y1 - 'A') * 4 + m);
        switch (m)
        {
            case 0:
                cout << "╔═╗";
                break;
            case 1:
                cout << "║★║";
                break;
            case 2:
                cout << "╚═╝";
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void change_color(int x1, int y1, int array[][10], int x)
{
    if (x == 3 || array[y1 - 'A'][x1] == 0)
        cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
    else if (x == 2)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_HWHITE);
    else if (x == 1)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_WHITE);
    else if (x == 0)
        cct_setcolor(array[y1 - 'A'][x1] + 8, COLOR_BLACK);
    for (int m = 0; m < 3; m++)
    {
        cct_gotoxy(4 + x1 * 6, 3 + (y1 - 'A') * 3 + m);
        switch (m)
        {
            case 0:
                cout << "╔═╗";
                break;
            case 1:
                cout << "║★║";
                break;
            case 2:
                cout << "╚═╝";
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drop(int x, int y, int array[][10], int input)
{
    int t = 1;
    for (int j = 0; j <= y - t; j++)
    {
        int flag = 0;
        for (int i = 0; i < x; i++)
        {
            if (array[i][j] != 0)
            {
                int k = i;
                if (i != x - 1)
                    if (array[k + 1][j] == 0)
                    {
                        while (1)
                        {
                            if (array[k + 1][j] != 0 || k + 1 >= x)
                                break;
                            Sleep(10);
                            if (input == 6)
                                change_color(j, k + 'A', array, 3);
                            else if (input == 7)
                                change_color_pro(j, k + 'A', array, 3);
                            array[k + 1][j] = array[k][j];
                            array[k][j] = 0;
                            if (input == 6)
                                change_color(j, k + 1 + 'A', array, 0);
                            else if (input == 7)
                                change_color_pro(j, k + 1 + 'A', array, 0);
                            k++;
                        }
                        i = -1;
                        flag = 0;
                        continue;
                    }
                flag++;
            }

        }
        if (flag == 0)
        {
            for (int m = 0; m < x; m++)
                for (int n = j; n < y - t; n++)
                {
                    change_color_pro(n + 1, m + 'A', array, 3);
                    array[m][n] = array[m][n + 1];
                    array[m][n + 1] = 0;
                    change_color_pro(n, m + 'A', array, 0);
                }
            j--;
            t++;
        }
    }
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int read_mouse_and_key_pro(int x, int y, int array[][10], int input, int& score_total)
{
    int  score = 0;
    cct_gotoxy(0, 3 + 4 * x);
    cout << "箭头键/鼠标移动，回车键/单击左键选择并结束";
    int mx = 0, my = 0, ma, key1, key2, x1 = 0, y1 = 'A', mx_pre = 0, my_pre = 0;
    change_color_pro(x1, y1, array, 1);
    while (1)
    {
        bool flag = 0;
        if (check_left(x, y, array) == 0)
        {
            int sum = 0;
            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    if (array[i][j] != 0)
                        sum++;
            cct_gotoxy(0, 3 + 4 * x);
            cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
            cout << "剩余" << sum << "个不可消除项，本关结束!";
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            cout << "回车继续下一关";
            if (sum < 10)
            {
                score_total += (10 - sum) * 180;
                cct_gotoxy(0, 0);
                cout << "奖励分:" << (10 - sum) * 180 << " 总分:" << score_total << " 通关分数:5000                 ";
            }
            while (1)
            {
                cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
                if (ma == 8 || key1 == 'q' || key1 == 'Q')
                    return 0;
                if (key1 == 13)
                    break;
            }
            return 1;
        }
        mx_pre = mx;
        my_pre = my;
        key1 = 0;
        key2 = 0;
        mx = 0;
        my = 0;
        ma = 0;
        cct_enable_mouse();
        cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
        if ((mx_pre - 2) % 8 == 0 || (mx_pre - 2) % 8 == 1 || (my_pre - 2) % 4 == 0 || mx_pre<4 || (mx_pre - 2) / 8>y - 1 || my_pre < 3 || (my_pre - 2) / 4  > +x - 1)
        {
            if (!((mx - 2) % 8 == 0 || (mx - 2) % 8 == 1 || (my - 2) % 4 == 0 || mx<4 || (mx - 2) / 8>y - 1 || my < 3 || (my - 2) / 4  > +x - 1))
                flag = 1;
        }
        else
            if ((mx - 2) % 8 == 0 || (mx - 2) % 8 == 1 || (my - 2) % 4 == 0 || mx<4 || (mx - 2) / 8>y - 1 || my < 3 || (my - 2) / 4  > +x - 1)
                flag = 1;
        if (ma == 8 || key1 == 'q' || key1 == 'Q')
            return 0;

        if (key1 == 13 || (ma == 2 && !((mx - 2) % 8 == 0 || (mx - 2) % 8 == 1 || (my - 2) % 4 == 0 || mx<4 || (mx - 2) / 8>y - 1 || my < 3 || (my - 2) / 4  > +x - 1)))
        {
            score = 0;
            cct_gotoxy(0, 3 + 4 * x);
            if (input == 5)
                cout << "选中了" << (char)y1 << "行" << x1 << "列                                              ";
            else
            {
                change_color_pro(x1, y1, array, 2);
                if (distroy_pro(x, y, array, x1, y1, score))
                {
                    score_total += score;
                    cct_gotoxy(0, 0);
                    if (score != 0)
                        cout << "本次得分:" << score << " 总分:" << score_total << " 通关分数:5000                        ";
                    if (score_total >= 5000)
                        return 0;
                    continue;
                }
                else
                    return 0;
            }
            return 0;
        }
        else if (key1 == 224)
        {
            int array1[10][10] = { 0 };
            key_move(x, y, x1, y1, array, array1, key2, 5);
        }
        else if (ma == 1 && flag)
            mouse_move(x, y, x1, y1, array, my, mx, 5);
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int distroy_pro(int x, int y, int array[][10], int& x1, int& y1, int& score)
{
    cct_gotoxy(0, 3 + 4 * x);
    cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成                         ";
    int mx, my, ma, key1, key2, array1[10][10] = { 0 };
    check_around(x, y, y1, x1, array, array1);
    if (!check_star(x, y, array1))
    {
        change_color_pro(x1, y1, array, 1);
        cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
        cct_gotoxy(0, 3 + 4 * x);
        cout << "周围无相同值，";
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        cout << "箭头键/鼠标移动，回车键/单击左键选择，Q/单击右键结束";
        while (1)
        {
            cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
            if (ma == 8 || key1 == 'q' || key1 == 'Q')
                return 0;
            else if ((my - 3 >= (y1 - 'A') * 4 && my - 3 <= (y1 - 'A') * 4 + 2 && mx - 4 >= x1 * 8 && mx - 4 <= x1 * 8 + 5) && key1 != 224)
                continue;
            else  if (key1 == 224 || !(my - 3 >= (y1 - 'A') * 4 && my - 3 <= (y1 - 'A') * 4 + 2 && mx - 4 >= x1 * 8 && mx - 4 <= x1 * 8 + 5))
            {
                key_move(x, y, x1, y1, array, array1, key2, 7);
                return 1;
            }
        }
    }
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (array1[i][j] == '*' && !(j == x1 && i + 'A' == y1))
                change_color_pro(j, i + 'A', array, 1);
    while (1)
    {
        cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
        if (ma == 8 || key1 == 'q' || key1 == 'Q')
            return 0;
        if (((my - 3 >= (y1 - 'A') * 4 && my - 3 <= (y1 - 'A') * 4 + 2 && mx - 4 >= x1 * 8 && mx - 4 <= x1 * 8 + 5) || key1 == 13) && key1 != 224)
        {
            if (ma == 2 || key1 == 13)
            {
                int sum = 0;
                for (int i = 0; i < x; i++)
                    for (int j = 0; j < y; j++)
                        if (array1[i][j] == '*')
                        {
                            sum++;
                            array[i][j] = 0;
                            change_color_pro(j, i + 'A', array, 3);
                        }
                score = sum * sum * 5;
                drop(x, y, array, 7);
                cct_gotoxy(0, 3 + 4 * x);
                cout << "                                                                 ";
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                if (key1 == 13)
                    for (int j = 0; j < y; j++)
                        for (int i = 0; i < x; i++)
                        {
                            if (array[i][j] != 0)
                            {
                                x1 = j;
                                y1 = i + 'A';
                                change_color_pro(x1, y1, array, 1);
                                return 1;
                            }
                        }
                else if (ma == 2)
                    mouse_move(x, y, x1, y1, array, my, mx, 5);
                return 1;
            }
            else
                continue;
        }
        else if (key1 == 224 || !(my - 3 >= (y1 - 'A') * 4 && my - 3 <= (y1 - 'A') * 4 + 2 && mx - 4 >= x1 * 8 && mx - 4 <= x1 * 8 + 5))
        {
            key_move(x, y, x1, y1, array, array1, key2, 7);
            return 1;
        }
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void read_mouse_and_key(int x, int y, int array[][10], int input)
{
    int x1 = 0, y1 = 'A';
    cct_gotoxy(0, 4 + 3 * x);
    cout << "箭头键/鼠标移动，回车键/单击左键选择并结束";
    int mx = 0, my = 0, ma, key1, key2, mx_pre, my_pre;
    change_color(x1, y1, array, 1);
    while (1)
    {
        bool flag = 0;
        mx_pre = mx;
        my_pre = my;
        key1 = 0;
        key2 = 0;
        mx = 0;
        my = 0;
        ma = 0;
        cct_enable_mouse();
        cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
        if (mx_pre<4 || (mx_pre - 4) / 6>y - 1 || my_pre < 3 || (my_pre - 3) / 3> +x - 1)
        {
            if (!(mx<4 || (mx - 4) / 6>y - 1 || my < 3 || (my - 3) / 3> +x - 1))
                flag = 1;
        }
        else
            flag = 1;

        if (ma == 8 || key1 == 'q' || key1 == 'Q')
            return;
        if (key1 == 13 || (ma == 2 && !(mx<4 || (mx - 4) / 6>y - 1 || my < 3 || (my - 3) / 3> +x - 1)))
        {
            cct_gotoxy(0, 4 + 3 * x);
            if (input == 4)
                cout << "选中了" << (char)y1 << "行" << x1 << "列                                              ";
            else
            {
                change_color(x1, y1, array, 2);
                if (distroy(x, y, array, x1, y1))
                    continue;
                else
                    return;
            }
            return;
        }
        if (key1 == 224)
        {
            int array1[][10] = { 0 };
            key_move(x, y, x1, y1, array, array1, key2, 4);
        }
        else if (ma == 1 && flag)
            mouse_move(x, y, x1, y1, array, my, mx, 4);
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int distroy(int x, int y, int array[][10], int& x1, int& y1)
{
    cct_gotoxy(0, 4 + 3 * x);
    cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成                         ";
    int mx, my, ma, key1, key2, array1[10][10] = { 0 };
    check_around(x, y, y1, x1, array, array1);
    if (!check_star(x, y, array1))
    {
        change_color(x1, y1, array, 1);
        cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
        cct_gotoxy(0, 4 + 3 * x);
        cout << "周围无相同值，";
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        cout << "箭头键/鼠标移动，回车键/单击左键选择，Q/单击右键结束";
        while (1)
        {
            cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
            if (ma == 8 || key1 == 'q' || key1 == 'Q')
                return 0;
            else if (my - 3 >= (y1 - 'A') * 3 && my - 3 <= (y1 - 'A') * 3 + 2 && mx - 4 >= x1 * 6 && mx - 4 <= x1 * 6 + 5)
                continue;
            else if (key1 == 224 || !(y1 == (my - 3) / 3 + 'A' && x1 == (mx - 4) / 6) && key1 != 13)
            {
                key_move(x, y, x1, y1, array, array1, key2, 6);
                return 1;
            }
        }
    }
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (array1[i][j] == '*' && !(j == x1 && i + 'A' == y1))
                change_color(j, i + 'A', array, 1);
    while (1)
    {
        cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
        if (ma == 8 || key1 == 'q' || key1 == 'Q')
            return 0;
        if ((my - 3 >= (y1 - 'A') * 3 && my - 3 <= (y1 - 'A') * 3 + 2 && mx - 4 >= x1 * 6 && mx - 4 <= x1 * 6 + 5) || key1 == 13)
        {
            if (ma == 2 || key1 == 13)
            {
                for (int i = 0; i < x; i++)
                    for (int j = 0; j < y; j++)
                        if (array1[i][j] == '*')
                        {
                            array[i][j] = 0;
                            change_color(j, i + 'A', array, 3);
                        }
                cct_gotoxy(0, 4 + 3 * x);
                cout << "合成完成，回车键/单击左键下落                            ";
                while (1)
                {
                    cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
                    if (ma == 8 || key1 == 'q' || key1 == 'Q')
                        return 0;
                    if (ma == 2 || key1 == 13)
                        break;
                }
                drop(x, y, array, 6);
                cct_gotoxy(0, 4 + 3 * x);
                cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
                cout << "本次合成结束，按C/单击左键继续新一次的合成                   ";
                while (1)
                {
                    cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
                    if (ma == 8 || key1 == 'q' || key1 == 'Q')
                        return 0;
                    if (ma == 2 || key1 == 'C' || key1 == 'c')
                        break;
                }
                cct_gotoxy(0, 4 + 3 * x);
                cout << "                                                                 ";
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                return 0;
            }
            else
                continue;
        }
        else if (key1 == 224 || !(y1 == (my - 3) / 3 + 'A' && x1 == (mx - 4) / 6))
        {
            key_move(x, y, x1, y1, array, array1, key2, 6);
            return 1;
        }
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void key_move(int x, int y, int& x1, int& y1, int array[][10], int array1[][10], int key2, int input)
{
    if (input == 4 || input == 6)
    {
        change_color(x1, y1, array, 0);
        cct_gotoxy(0, 4 + 3 * x);
    }
    else if (input == 5 || input == 7)
    {
        if (array[y1 - 'A'][x1] == 0)
            change_color_pro(x1, y1, array, 3);
        else
            change_color_pro(x1, y1, array, 0);
        cct_gotoxy(0, 3 + 4 * x);
    }
    cout << "[当前键盘]                                                   ";
    key_result(x, y, x1, y1, key2, array);
    if (input == 4 || input == 6)
    {

        cct_gotoxy(11, 4 + 3 * x);
        cout << (char)(y1) << "行" << x1 << "列                                                      ";
        change_color(x1, y1, array, 1);
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (array1[i][j] == '*' && !(j == x1 && i + 'A' == y1))
                    change_color(j, i + 'A', array, 0);
    }
    else if (input == 5 || input == 7)
    {

        cct_gotoxy(11, 3 + 4 * x);
        cout << (char)(y1) << "行" << x1 << "列                                                      ";
        if (array[y1 - 'A'][x1] == 0)
            change_color_pro(x1, y1, array, 3);
        else
            change_color_pro(x1, y1, array, 1);
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (array1[i][j] == '*' && !(j == x1 && i + 'A' == y1))
                    change_color_pro(j, i + 'A', array, 0);
    }
    return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void key_result(int x, int y, int& x1, int& y1, int key2, int array[][10])
{
    switch (key2)
    {
        case KB_ARROW_UP:
            while (1)
            {
                y1--;
                if (y1 < 'A')
                    y1 = 'A' + x - 1;
                if (array[y1 - 'A'][x1] != 0)
                    break;
            }
            break;
        case KB_ARROW_DOWN:
            while (1)
            {
                y1++;
                if (y1 > 'A' + x - 1)
                    y1 = 'A';
                if (array[y1 - 'A'][x1] != 0)
                    break;
            }
            break;
        case KB_ARROW_LEFT:
            while (1)
            {
                x1--;
                if (x1 < 0)
                    x1 = y - 1;
                if (array[y1 - 'A'][x1] != 0)
                    break;
            }
            break;
        case KB_ARROW_RIGHT:
            while (1)
            {
                x1++;
                if (x1 > y - 1)
                    x1 = 0;
                if (array[y1 - 'A'][x1] != 0)
                    break;
            }
            break;
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mouse_move(int x, int y, int& x1, int& y1, int array[][10], int my, int mx, int input)
{
    if (input == 4)
    {
        if (my - 3 >= (y1 - 'A') * 3 && my - 3 <= (y1 - 'A') * 3 + 2 && mx - 4 >= x1 * 6 && mx - 4 <= x1 * 6 + 5)
            return;
        change_color(x1, y1, array, 0);
        y1 = (my - 3) / 3 + 'A';
        x1 = (mx - 4) / 6;
        cct_gotoxy(0, 4 + 3 * x);
        cout << "[当前鼠标]                                                     ";
        if (mx<4 || (mx - 4) / 6>y - 1 || my < 3 || (my - 3) / 3> +x - 1)
        {
            cct_gotoxy(11, 4 + 3 * x);
            cout << "位置非法";
            if (x1 < 0)
                x1 = 0;
            if (x1 > y - 1)
                x1 = y - 1;
            if (y1 < 'A')
                y1 = 'A';
            if (y1 > 'A' + x - 1)
                y1 = 'A' + x - 1;
        }
        else
        {
            change_color(x1, y1, array, 1);
            cct_gotoxy(11, 4 + 3 * x);
            cout << (char)(y1) << "行" << x1 << "列                                                   ";
        }
    }
    else if (input == 5)
    {
        if (array[y1 - 'A'][x1] == 0)
            change_color_pro(x1, y1, array, 3);
        else
            change_color_pro(x1, y1, array, 0);
        cct_gotoxy(0, 3 + 4 * x);
        cout << "[当前鼠标]                                         ";
        if ((mx - 2) % 8 == 0 || (mx - 2) % 8 == 1 || (my - 2) % 4 == 0)
        {
            cct_gotoxy(11, 3 + 4 * x);
            cout << "位置非法";
            return;
        }
        y1 = (my - 2) / 4 + 'A';
        x1 = (mx - 2) / 8;
        if (mx<4 || (mx - 2) / 8>y - 1 || my < 3 || (my - 2) / 4  > +x - 1)
        {
            cct_gotoxy(11, 3 + 4 * x);
            cout << "位置非法";
            if (x1 < 0)
                x1 = 0;
            else if (x1 > y - 1)
                x1 = y - 1;
            if (y1 < 'A')
                y1 = 'A';
            else if (y1 > 'A' + x - 1)
                y1 = 'A' + x - 1;
        }
        else
        {
            if (array[y1 - 'A'][x1] == 0)
            {
                change_color_pro(x1, y1, array, 3);
                cct_gotoxy(11, 3 + 4 * x);
                cout << "位置非法";
            }
            else
            {
                change_color_pro(x1, y1, array, 1);
                cct_gotoxy(11, 3 + 4 * x);
                cout << (char)(y1) << "行" << x1 << "列";
            }
        }
    }
    return;
}