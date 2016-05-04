#pragma once
#define PowerLevelNum 8
#define bufSize 6
extern int M;

typedef struct Node
{
	double EnergyConsumption[PowerLevelNum];
	double AvgDelay_Sum[PowerLevelNum];
	double Throughput_Sum[PowerLevelNum];
	int BufTail;
	int SucPkt[PowerLevelNum];
	int FailedPkt[PowerLevelNum];
	double PDR_coor_previous;
	int sleepTimer;
	int Buf[4];
}Node;