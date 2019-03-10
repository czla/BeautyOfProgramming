//@Problem: 给定一个整数N，求N的阶乘N！末尾有多少个0，以及N！的二进制表示中最低位1的位置
//@Author：	zlchen
//@Date：	3/10/2019
#include<iostream>

using namespace std;

// 问题1解法一：每对2和5相乘得10，即求N！的因式分解中5的指数
void solution_1(int N)
{
	int ret = 0;
	for(int i=1; i != N+1; ++i)
	{
		int j = i;
		while(j % 5 == 0)
		{
			ret++;
			j /= 5;
		}
	}

	cout << "The number of zeros in the tail of " << N << "! is: " << ret << endl;
}

// 问题1解法二：ret=[N/5] + [N/(5^2)] + [N/(5^3)] + ...即5的倍数贡献，25的倍数又贡献一个，125的倍数依次类推
void solution_2(int N)
{
	int ret = 0;
	while(N)
	{
		ret += N / 5;
		N /= 5;
	}

	cout << "The number of zeros in the tail of " << N << "! is: " << ret << endl;
}

// 问题2：因为二进制每除以2右移一位，即题目所求为N！中含有质因数2的个数，当然位置要加1
void solution_3(int N)
{
	cout << "The location of lowest one in the binary format of " << N << "! is: ";
	int ret = 0;
	while(N)
	{
		N >>= 1;
		ret += N;
	}

	cout << ret + 1 << endl;
}
int main()
{
	int N = 6;

	//solution_1(N);
	//solution_2(N);
	solution_3(N);

	return 0;
}