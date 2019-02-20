//@Problem: дһ���������û�����Windows�����������CPUռ���ʣ�������3�������
//			1.CPUռ���ʹ̶���50%��Ϊһ��ֱ�ߣ�
//			2.CPUռ����Ϊһ��ֱ�ߣ�����ֵ�������в�����������Χ[1 100]��
//			3.CPUռ����״̬��һ���������ߡ�
//@Author��	zlchen
//@Date��	2/20/2019
#include<iostream>
#include"windows.h"
#define _USE_MATH_DEFINES	//to use M_PI
#include<math.h>

using namespace std;

// �ⷨһ���򵥽ⷨ
// ˼·����CPU��һ��ʱ������busy��idle������ͬ��ѭ����ͨ����ͬ��ʱ�������������CPUռ����
// Busy loopͨ��ִ�п�ѭ��ʵ�֣�idleͨ��ͷ�ļ�"Windows.h"��Sleep()ʵ�֡�
void solution_1()
{
	for (;;)
	{
		for (int i = 0; i != 13600000 * 8; ++i)		//i����ֹ������Ҫ�ֶ�����
			;
		Sleep(10);
	}
}

// �ⷨ����ʹ��GetTickCount()��Sleep()
// �ⷨһ������Ӧ���������ԣ�GetTickCount()���Եõ���ϵͳ���������ڡ���������ʱ��ĺ���ֵ��
// �����ж�busy loopҪѭ����á�
void solution_2()
{
	const DWORD busyTime = 10;		//DWORD��˫�֣�unsigned long
	const DWORD idleTime = busyTime;

	DWORD startTime;
	while(true)
	{
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busyTime)
			;
		Sleep(idleTime);
	}
}

// �ⷨ������������
// ��ÿһ����������0~2��֮��Ļ��ȵȷֳ�200�ݽ��г���������ÿ��������������
// Ȼ��ÿ��300msȡ��һ�������㣬����CPU������Ӧ�����ʱ��
void solution_3()
{
	const int SAMPLING_COUNT = 200;
	const int TOTAL_AMPLITUDE = 100;

	DWORD busySpan[SAMPLING_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double radianIncrement = 2.0 / (double)SAMPLING_COUNT;
	for(int i=0; i != SAMPLING_COUNT; ++i)
	{
		busySpan[i] = (DWORD)(amplitude + (sin(M_PI*radian) * amplitude));
		radian += radianIncrement;
	}
	DWORD startTime = 0;
	for(int j=0;;j=(j + 1)%SAMPLING_COUNT)
	{
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE - busySpan[j]);
	}
}
int main()
{
	//solution_1();	//�򵥽ⷨ
	//solution_2();	//ʹ��GetTickCount()��Sleep()
	solution_3();	//�������߽ⷨ
	return 0;
}