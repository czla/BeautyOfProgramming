//@Problem: 写一个程序，让用户决定Windows任务管理器的CPU占用率，如以下3种情况：
//			1.CPU占用率固定在50%，为一条直线；
//			2.CPU占用率为一条直线，具体值由命令行参数决定，范围[1 100]；
//			3.CPU占用率状态是一条正弦曲线。
//@Author：	zlchen
//@Date：	2/20/2019
#include<iostream>
#include"windows.h"
#define _USE_MATH_DEFINES	//to use M_PI
#include<math.h>

using namespace std;

// 解法一：简单解法
// 思路：让CPU在一段时间内跑busy和idle两个不同的循环，通过不同的时间比例，来调节CPU占用率
// Busy loop通过执行空循环实现，idle通过头文件"Windows.h"中Sleep()实现。
void solution_1()
{
	for (;;)
	{
		for (int i = 0; i != 13600000 * 8; ++i)		//i的终止条件需要手动调整
			;
		Sleep(10);
	}
}

// 解法二：使用GetTickCount()和Sleep()
// 解法一不能适应机器差异性，GetTickCount()可以得到“系统启动到现在”所经历的时间的毫秒值，
// 可以判断busy loop要循环多久。
void solution_2()
{
	const DWORD busyTime = 10;		//DWORD即双字，unsigned long
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

// 解法三：正弦曲线
// 把每一条正弦曲线0~2Π之间的弧度等分成200份进行抽样，计算每个抽样点的振幅，
// 然后每隔300ms取下一个抽样点，并让CPU工作对应振幅的时间
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
	//solution_1();	//简单解法
	//solution_2();	//使用GetTickCount()和Sleep()
	solution_3();	//正弦曲线解法
	return 0;
}