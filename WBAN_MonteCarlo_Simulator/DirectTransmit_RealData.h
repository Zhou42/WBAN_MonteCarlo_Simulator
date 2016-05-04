#pragma once
extern double T_data;
extern double T_overhead;
extern double T_ACK;
extern double L_data;
extern double BI;
extern int M;
extern double E_failed_transmitter;
extern double E_suc_transmitter;

#define PowerLevelNum 8

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

extern double GenerateRandomNum();