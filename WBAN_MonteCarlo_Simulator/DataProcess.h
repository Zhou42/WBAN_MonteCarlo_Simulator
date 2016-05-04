#pragma once
#define PowerLevelNum 8
extern int RoundNum;
extern double BI;
extern int BO;
extern int N;
extern int M;
extern double alpha;
extern double beta;

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