//@Problem: 对于一个字节(8bit)的无符号整型变量，求其二进制表示中“1”。的个数。
//@Author：	zlchen
//@Date：	3/9/2019
#include<iostream>

using namespace std;

// 解法一：二进制数除以2，原数字会减少一个0，如果除的过程有余，则当前位置有一个1
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

// 解法二；使用位操作。每次判断最后一位是否为1（通过与0x01进行与操作），然后右移一位
// 时间复杂度O(log_2v)，log_2v为二进制数的位数
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

// 解法三；从末尾开始直接定位1。然后利用v&(v-1)消除该1。复杂度O(M)，M为v中1的个数
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

// 解法四：查表法。把0-255中“1”的个数直接存储在数组中，v作为数组的下标，countTable[v]就是v中1的个数。
// 空间换时间，时间复杂度仅为O(1),在需要频繁使用这个算法的应用中很实用。
void solution_4(unsigned char v)
{
	int countTable[256] = {
	0,1,1,2,1,2,2,3,1,2,3,1,2,2 };	//此处仅作演示，省略后面数字

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