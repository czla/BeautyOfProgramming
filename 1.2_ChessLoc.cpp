//@Problem: 中国象棋中“将”A和“帅”B在3x3的格子里运动，输出A、B所有合法位置。
//			要求在代码中只能使用一个字节存储变量。
//@Author：	zlchen
//@Date：	2/27/2019
#include<iostream>

using namespace std;

// 解法一：不考虑变量长度限制，暴力求解
void solution_1()
{
	short xa, ya, xb, yb, i=0;
	for (ya = -1; ya != 2; ++ya)
		for (xa = -1; xa != 2; ++xa)
			for (yb = -1; yb != 2; ++yb)
				for (xb = -1; xb != 2; ++xb)
				{
					if (xb != xa) {
						++i;
						cout << "Case " << i<<":" << endl;
						cout << "\t\t" << "A(" << xa <<","<< ya << ") " 
							<< "B(" << xb << "," << yb << ")" << endl;
					}
				}
}

// 解法二：位置对应为1-9
void solution_2()
{
	char i = 81;
	while(i--)
	{
		if (i / 9 % 3 == i % 9 % 3)
			continue;
		printf("A=%d, B=%d\n", i / 9 + 1, i % 9 + 1);
	}
}

// 解法三：类似二，但效率高
void solution_3()
{
	struct {
		unsigned char a : 4;
		unsigned char b : 4;
	} i;

	for (i.a = 1; i.a <= 9; i.a++)
		for (i.b = 1; i.b <= 9; i.b++)
			if (i.a % 3 != i.b % 3)
				printf("A=%d, B=%d\n", i.a, i.b);
}
int main()
{
	//solution_1();
	//solution_2();
	solution_3();

}