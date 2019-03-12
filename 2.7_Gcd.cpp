//@Problem: 求两个正整数的最大公约数
//@Author：	zlchen
//@Date：	3/12/2019
#include<iostream>

using namespace std;

// 解法一：辗转相除法。根据f(x,y)=f(y,x%y)，知道一个数为0，另一个数即为两者的最大公约数
int solution_1(int x, int y)
{
	return (!y) ? x : solution_1(y, x%y);
}

// 解法二：当整数非常大时，取余运算开销比较昂贵，根据f(x,y)=f(x-y,y)，可以将取余运算转换成减法
int solution_2(int x, int y)
{
	if(x < y)
		return solution_2(y, x);
	if (y == 0)
		return x;
	else
		return solution_2(x - y, y);
}
int main()
{
	cout << solution_1(42, 30) << endl;		// 解法一
	cout << solution_2(42, 30) << endl;		// 解法二


	return 0;
}