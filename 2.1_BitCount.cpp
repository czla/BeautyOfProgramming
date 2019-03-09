//@Problem: ����һ���ֽ�(8bit)���޷������ͱ�������������Ʊ�ʾ�С�1�����ĸ�����
//@Author��	zlchen
//@Date��	3/9/2019
#include<iostream>

using namespace std;

// �ⷨһ��������������2��ԭ���ֻ����һ��0��������Ĺ������࣬��ǰλ����һ��1
void solution_1(unsigned char v)
{
	int num = 0;
	while(v)
	{
		if(v % 2 == 1)
		{
			num++;
			v = v / 2;
		}
	}
	cout << "The number of 1 in v is: " << num << endl;
}

// �ⷨ����ʹ��λ������ÿ���ж����һλ�Ƿ�Ϊ1��ͨ����0x01�������������Ȼ������һλ
// ʱ�临�Ӷ�O(log_2v)��log_2vΪ����������λ��
void solution_2(unsigned char v)
{
	int num = 0;
	while (v)
		{
			num += v & 0x01;
			v >>= 1;
		}
	cout << "The number of 1 in v is: " << num << endl;
}

// �ⷨ������ĩβ��ʼֱ�Ӷ�λ1��Ȼ������v&(v-1)������1�����Ӷ�O(M)��MΪv��1�ĸ���
void solution_3(unsigned char v)
{
	int num = 0;
	while(v)
	{
		v &= (v - 1);
		num++;
	}
	cout << "The number of 1 in v is: " << num << endl;
}

// �ⷨ�ģ��������0-255�С�1���ĸ���ֱ�Ӵ洢�������У�v��Ϊ������±꣬countTable[v]����v��1�ĸ�����
// �ռ任ʱ�䣬ʱ�临�ӶȽ�ΪO(1),����ҪƵ��ʹ������㷨��Ӧ���к�ʵ�á�
void solution_4(unsigned char v)
{
	int countTable[256] = {
	0,1,1,2,1,2,2,3,1,2,3,1,2,2 };	//�˴�������ʾ��ʡ�Ժ�������

	cout << "The number of 1 in v is: " << countTable[v] << endl;
}

int main()
{
	unsigned char num = 0x03;

	//solution_1(num);
	//solution_2(num);
	//solution_3(num);
	solution_4(num);

	return 0;
}