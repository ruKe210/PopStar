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
void huiche()
{
    int mx=0, my=0, ma=0, key1=0, key2=0;
    while (1)
    {
        cct_read_keyboard_and_mouse(mx, my, ma, key1, key2);
        if (key1 == 13)
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
void input_x_y(int& x, int& y)
{
    int x1 = 0, y1 = 0;
    while (1)
    {
        cout << "请输入行数(8-10)：" << endl;
        cin >> x;
        if (cin.fail() || x < 8 || x>10)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
            break;
    }
    while (1)
    {
        cout << "请输入列数(8-10)：" << endl;
        cin >> y;
        if (cin.fail() || y < 8 || y>10)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
            break;
    }
    cin.ignore(1024, '\n');
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void check_end()
{
    cout << endl << "本小题结束，请输入End继续...";
    int i, j, i1, j1;
    cct_getxy(i, j);
    while (1)
    {
        int t = 0;
        char str[128] = { 0 };
        while ((str[t] = getchar()) != '\n')
            t++;
        if (!tj_strcasencmp(str, "end", 3))
            return;
        else
        {
            cct_getxy(i1, j1);
            cout << "输入错误，请重新输入.";
            Sleep(1000);
            cct_gotoxy(i1, j1);
            cout << "                        ";
            cct_gotoxy(i, j);
            cout << "                        ";
            cct_gotoxy(i, j);
            continue;
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
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    int t = 0, i = 1;
    while (1)
    {
        if (*s1 != *s2)
        {
            if (*s1 <= 'Z' && *s1 >= 'A')
            {
                if (*s2 <= 'Z' && *s2 >= 'A')
                {
                    t = *s1 - *s2;
                    break;
                }
                else
                {
                    t = *s1 - *s2 + 32;
                    if (t)
                        break;
                }
            }
            else
            {
                if (*s2 <= 'Z' && *s2 >= 'A')
                {
                    t = *s1 - *s2 - 32;
                    if (t)
                        break;
                }
                else
                {
                    t = *s1 - *s2;
                    break;
                }
            }
        }
        if (*s1 == 0 || *s2 == 0 || i == len)
            break;
        s1++;
        s2++;
        i++;
    }
    return t;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_location(int& lie, char& hang, int x, int y)
{
    int  i, j;
    cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
    while (1)
    {
        int t = 0;
        char str[128] = { 0 };
        while ((str[t] = getchar()) != '\n')
            t++;
        hang = str[0];
        lie = str[1] - '0';
        if (((hang >= 'a' && hang <= 'a' + x - 1) || (hang >= 'A' && hang <= 'A' + x - 1)) && (lie >= 0 && lie <= y - 1))
        {
            if (hang >= 'a' && hang <= 'a' + x - 1)
                hang -= 32;
            return;
        }
        else
        {
            cct_getxy(i, j);
            cout << "输入错误，请重新输入.";
            Sleep(1000);
            cct_gotoxy(i, j);
            cout << "                        ";
            cct_gotoxy(i + 39, j - 1);
            cout << "                        ";
            cct_gotoxy(i + 39, j - 1);
            continue;
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
void creat_array(int x, int y, int array[][10])
{
    srand((int)time(NULL));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            array[i][j] = rand() % 5 + 1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void check_around(int x, int y, char hang, int lie, int  array[][10], int  array1[][10])
{
    array1[hang - 'A'][lie] = (int)'*';
    int t = 0;
    if ((t = array[hang - 'A'][lie]) == 0)
        return;
    if (hang - 'A' - 1 >= 0 && array1[hang - 'A' - 1][lie] == 0)
    {
        if (array[hang - 'A' - 1][lie] == t)
        {
            array1[hang - 'A' - 1][lie] = (int)'*';
            check_around(x, y, char(hang - 1), lie, array, array1);
        }
    }
    if (hang - 'A' + 1 <= x - 1 && array1[hang - 'A' + 1][lie] == 0)
    {
        if (array[hang - 'A' + 1][lie] == t)
        {
            array1[hang - 'A' + 1][lie] = (int)'*';
            check_around(x, y, char(hang + 1), lie, array, array1);
        }
    }
    if (lie - 1 >= 0 && array1[hang - 'A'][lie - 1] == 0)
    {
        if (array[hang - 'A'][lie - 1] == t)
        {
            array1[hang - 'A'][lie - 1] = (int)'*';
            check_around(x, y, hang, lie - 1, array, array1);
        }
    }
    if (lie + 1 <= y - 1 && array1[hang - 'A'][lie + 1] == 0)
    {
        if (array[hang - 'A'][lie + 1] == t)
        {
            array1[hang - 'A'][lie + 1] = (int)'*';
            check_around(x, y, hang, lie + 1, array, array1);
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
int check_star(int x, int y, int array1[][10])
{
    int sum = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (array1[i][j] == (int)'*')
                sum++;
    if (sum == 1)
        return 0;
    else
        return 1;
}
