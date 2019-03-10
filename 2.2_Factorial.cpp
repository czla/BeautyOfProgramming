//@Problem: ����һ������N����N�Ľ׳�N��ĩβ�ж��ٸ�0���Լ�N���Ķ����Ʊ�ʾ�����λ1��λ��
//@Author��	zlchen
//@Date��	3/10/2019
#include<iostream>

using namespace std;

// ����1�ⷨһ��ÿ��2��5��˵�10������N������ʽ�ֽ���5��ָ��
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

// ����1�ⷨ����ret=[N/5] + [N/(5^2)] + [N/(5^3)] + ...��5�ı������ף�25�ı����ֹ���һ����125�ı�����������
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

// ����2����Ϊ������ÿ����2����һλ������Ŀ����ΪN���к���������2�ĸ�������Ȼλ��Ҫ��1
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