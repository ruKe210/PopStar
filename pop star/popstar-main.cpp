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
void menu()
{
	cout << "--------------------------------------------" << endl
		<< "A.命令行找出可消除项并标识" << endl
		<< "B.命令行完成一次消除（分步骤显示）" << endl
		<< "C.命令行完成一关（分步骤显示）" << endl
		<< "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl
		<< "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl
		<< "F.伪图形界面完成一次消除（分步骤）" << endl
		<< "G.伪图形界面完整版" << endl
		<< "Q.退出" << endl
		<< "--------------------------------------------" << endl
		<< "[请选择:] ";
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar(char input)
{
	cct_cls();
	int x = 0, y = 0, array[10][10] = { 0 }, array1[10][10] = { 0 }, lie = 0, score_total = 0;;
	char hang = 0;
	input_x_y(x, y);
	creat_array(x, y, array);
	if (input - 'A' == 0 || input - 'A' == 1 || input - 'A' == 2)
	{
		cout << endl << "当前数组：" << endl;
		print_popstar(x, y, array, array, 2);
		popstar_1(x, y, array, array1, hang, lie);
		if (input - 'A' == 1)
			popstar_2(x, y, array, array1, hang, lie, score_total);
	}
	if (input - 'A' == 2)
		popstar_3(x,y,array,array1,hang,lie,score_total);
	if (input - 'A' == 3)
		popstar_4(x, y, array);
	if (input - 'A' == 4)
		popstar_5(x, y, array);
	if (input - 'A' == 5)
		popstar_6(x, y, array);
	if (input - 'A' == 6)
		while (1)
		{
			creat_array(x, y, array);
			if (popstar_7(x, y, array, score_total))
				continue;
			else
			{
				cct_gotoxy(0, 3 + 4 * x);
				if (score_total >= 5000)
				{
					cct_setcolor(COLOR_HYELLOW, COLOR_RED);
					cout << "恭喜通关！！！";
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout<<"                                                      ";
				}
				else
				cout << "                                                                      ";
				break;
			}
		}
	check_end();
	return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar_1(int& x, int& y, int array[][10], int array1[][10], char& hang, int& lie)
{
	while (1)
	{
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				array1[i][j] = 0;
		input_location(lie, hang, x, y);
		check_around(x, y, hang, lie, array, array1);
		cout << "输入为" << hang << "行" << lie << "列" << endl;
		if (!check_star(x, y, array1))
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		else
			break;
	}
	cout << endl << "查找结果数组：" << endl;
	print_popstar(x, y, array1, NULL, 0);
	cout << endl << "当前数组(不同色标识)：" << endl;
	print_popstar(x, y, array, array1, 1);
	return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int popstar_2(int& x, int& y, int array[][10], int array1[][10], char hang, int lie,int& score_total)
{
	int score = 0, num = 0;
	char input = 0;
	cout << "请确认是否把" << hang << lie << "及周围的相同值消除(Y/N/Q)：";
	while (1)
	{
		input = _getch();
		if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
			cout << input;
		if (input == 'q' || input == 'Q')
			return 0;
		else if (input == 'n' || input == 'N')
		{
			cout << endl<<endl << "当前数组：" << endl;
			print_popstar(x, y, array, array, 2);
			popstar_1(x, y, array, array1, hang, lie);
			popstar_2(x, y, array, array1, hang, lie,score_total);
			return 1;
		}
		else if (input == 'y' || input == 'Y')
		{
			for (int i = 0; i < x; i++)
				for (int j = 0; j < y; j++)
					if (array1[i][j] == '*')
					{
						num++;
						array[i][j] = 0;
					}
			score = num * num * 5 + (10 - gift(x, y, array)) * 180;
			score_total += score;
			cout << endl << endl << "相同值归并后的数组(不同色标识)：" << endl;
			print_popstar(x, y, array, array1, 1);
			cout << endl << "本次得分：" << score << " 总得分：" << score_total << endl;
			cout << endl << "按回车键进行数组下落操作...";
			huiche();
			cout << endl << "下落后的数组：" << endl;
			downput_and_rightput(x, y, array);
			print_popstar(x, y, array, array, 2);
			return 1;
		}
		else
			continue;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar_3(int& x, int& y, int array[][10], int array1[][10], char& hang, int& lie,int &score_total)
{
	while (1)
	{
		int array2[10][10] = { 0 };
		check_around(x, y, hang, lie, array, array2);
		if (popstar_2(x, y, array, array2, hang, lie, score_total) == 0)
			return;
		cout << "本次消除结束，按回车键继续新一次的消除..." << endl;
		huiche();
		cout << endl << "当前数组：" << endl;
		print_popstar(x, y, array, array, 2);
		if (check_left(x, y, array) == 0)
			break;
		popstar_1(x, y, array, array2, hang, lie);
	}
	int sum = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (array[i][j] != 0)
				sum++;
	cout << endl;
	cct_setcolor(COLOR_HYELLOW, COLOR_RED);
	cout << "剩余" << sum << "个不可消除项，本关结束!";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar_4(int x, int y, int array[][10])
{
	cct_setcursor(CURSOR_INVISIBLE);
	cct_setconsoleborder(7 + 6 * y, 8 + 3 * x, 7 + 6 * y, 8 + 3 * x);
	print_border(x, y, array);
	print_star(x, y, array);
	read_mouse_and_key(x, y, array, 4);
	cct_gotoxy(0, 4 + 3 * x);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar_5(int x, int y, int array[][10])
{
	int t;
	cct_setcursor(CURSOR_INVISIBLE);
	cct_setconsoleborder(5 + 8 * y, 7 + 4 * x, 5 + 8 * y, 7 + 4 * x);
	print_border_pro(x, y, array);
	print_star_pro(x, y, array);
	read_mouse_and_key_pro(x, y, array, 5, t);
	cct_gotoxy(0, 3 + 4 * x);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void popstar_6(int x, int y, int array[][10])
{
	cct_setcursor(CURSOR_INVISIBLE);
	cct_setconsoleborder(7 + 6 * y, 8 + 3 * x, 7 + 6 * y, 8 + 3 * x);
	print_border(x, y, array);
	print_star(x, y, array);
	read_mouse_and_key(x, y, array, 6);
	cct_gotoxy(0, 4 + 3 * x);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int popstar_7(int x, int y, int array[][10], int& score_total)
{
	int t;
	cct_setcursor(CURSOR_INVISIBLE);
	cct_setconsoleborder(5 + 8 * y, 7 + 4 * x, 5 + 8 * y, 7 + 4 * x);
	print_border_pro(x, y, array);
	print_star_pro(x, y, array);
	t = read_mouse_and_key_pro(x, y, array, 7, score_total);
	cct_gotoxy(0, 3 + 4 * x);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return t;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	char input = 0;
	while (1)
	{
		cct_cls();
		menu();
		while (1)
		{
			input = _getch();
			if (input == 'Q' || input == 'q')
			{
				cout << input;
				Sleep(500);
				return 0;
			}
			else if ((input >= 'A' && input <= 'G') || (input >= 'a' && input <= 'g'))
			{
				cout << input;
				Sleep(500);
				if (input >= 'a' && input <= 'g')
					input -= 32;
				popstar(input);
				break;
			}
		}
	}
}
