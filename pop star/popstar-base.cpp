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
void print_popstar(int x, int y, int array[][10], int array1[][10], int choice)
{
	for (int i = 0; i <= x + 1; i++)
	{
		for (int j = 0; j <= y + 1; j++)
		{
			switch (j)
			{
				case 0:
					if (i == 0)
						cout << " ";
					else if (i == 1)
						cout << "-";
					else
						cout << char('A' + i - 2);
					break;
				case 1:
					if (i == 1)
						cout << "-+-";
					else
						cout << " | ";
					break;
				default:
					if (i == 0)
						cout << " " << j - 2 << " ";
					else if (i == 1)
						cout << "---";
					else
					{
						if (array1 == NULL)
							if (array[i - 2][j - 2] == '*')
								cout << " " << (char)array[i - 2][j - 2] << " ";
							else
								cout << " " << array[i - 2][j - 2] << " ";
						else
							if (array1[i - 2][j - 2] == '*' && choice == 1)
							{
								cout << " ";
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << array[i - 2][j - 2];
								cct_setcolor(COLOR_BLACK, COLOR_WHITE);
								cout << " ";
							}
							else if (array[i - 2][j - 2] == 0 && choice == 2)
							{
								cout << " ";
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << array[i - 2][j - 2];
								cct_setcolor(COLOR_BLACK, COLOR_WHITE);
								cout << " ";
							}
							else
								cout << " " << array[i - 2][j - 2] << " ";
					}
					break;
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void downput_and_rightput(int x, int y, int array[][10])
{
	int t = 1;
	for (int j = 0; j <= y - t; j++)
	{
		int flag = 0;
		for (int i = 0; i < x; i++)
		{
			if (array[i][j] == 0)
			{
				if (i != 0)
					for (int k = i; k > 0; k--)
					{
						if (array[k - 1][j] != 0)
						{
							array[k][j] = array[k - 1][j];
							array[k - 1][j] = 0;
						}
					}
			}
			else
				flag++;
		}
		if (flag == 0)
		{
			for (int m = 0; m < x; m++)
				for (int n = j; n < y - t; n++)
				{
					array[m][n] = array[m][n + 1];
					array[m][n + 1] = 0;
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
int check_left(int x, int y, int array[][10])
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			int array1[10][10] = { 0 };
			int sum = 0;
			check_around(x, y, char('A' + i), j, array, array1);
			if (check_star(x, y, array1))
				return 1;
		}
	return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int gift(int x, int y, int array[][10])
{
	int sum = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (array[i][j] != 0)
				sum++;
	if (sum >= 10)
		return 10;
	else
		return sum;
}