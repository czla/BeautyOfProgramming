//@Problem: �����������������Լ��
//@Author��	zlchen
//@Date��	3/12/2019
#include<iostream>

using namespace std;

// �ⷨһ��շת�����������f(x,y)=f(y,x%y)��֪��һ����Ϊ0����һ������Ϊ���ߵ����Լ��
int solution_1(int x, int y)
{
	return (!y) ? x : solution_1(y, x%y);
}

// �ⷨ�����������ǳ���ʱ��ȡ�����㿪���Ƚϰ��󣬸���f(x,y)=f(x-y,y)�����Խ�ȡ������ת���ɼ���
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
	cout << solution_1(42, 30) << endl;		// �ⷨһ
	cout << solution_2(42, 30) << endl;		// �ⷨ��


	return 0;
}