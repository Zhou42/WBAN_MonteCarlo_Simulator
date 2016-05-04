#include"DataProcess.h"
#include<stdio.h>

void DataProcess(Node* a1, Node* a2, Node* a1_GTS, Node* a2_GTS, Node* a1_BodyMAC, Node* a2_BodyMAC) {

	
	double AvgDelay_a1[PowerLevelNum];
	double AvgDelay_a2[PowerLevelNum];
	double Throughput_a1[PowerLevelNum];
	double Throughput_a2[PowerLevelNum];
	double Power_a1[PowerLevelNum]; // mW
	double Power_a2[PowerLevelNum]; // mW
									// double PDR_coor;

	double AvgDelay_a1_GTS[PowerLevelNum];
	double AvgDelay_a2_GTS[PowerLevelNum];
	double Throughput_a1_GTS[PowerLevelNum];
	double Throughput_a2_GTS[PowerLevelNum];
	double Power_a1_GTS[PowerLevelNum]; // mW
	double Power_a2_GTS[PowerLevelNum]; // mW

	double AvgDelay_a1_BodyMAC[PowerLevelNum];
	double AvgDelay_a2_BodyMAC[PowerLevelNum];
	double Throughput_a1_BodyMAC[PowerLevelNum];
	double Throughput_a2_BodyMAC[PowerLevelNum];
	double Power_a1_BodyMAC[PowerLevelNum]; // mW
	double Power_a2_BodyMAC[PowerLevelNum]; // mW

	// data processing
	for (int k = 0;k < PowerLevelNum;k++) {
		// data for my design
		AvgDelay_a1[k] = a1->AvgDelay_Sum[k] / a1->SucPkt[k];
		AvgDelay_a2[k] = a2->AvgDelay_Sum[k] / a2->SucPkt[k];
		Throughput_a1[k] = a1->Throughput_Sum[k] / RoundNum / BI;
		Throughput_a2[k] = a2->Throughput_Sum[k] / RoundNum / BI;
		Power_a1[k] = a1->EnergyConsumption[k] / RoundNum / BI; // mW
		Power_a2[k] = a2->EnergyConsumption[k] / RoundNum / BI; // mW
		//data for IEEE 802.15.4 GTS
		AvgDelay_a1_GTS[k] = a1_GTS->AvgDelay_Sum[k] / a1_GTS->SucPkt[k];
		AvgDelay_a2_GTS[k] = a2_GTS->AvgDelay_Sum[k] / a2_GTS->SucPkt[k];
		Throughput_a1_GTS[k] = a1_GTS->Throughput_Sum[k] / RoundNum / BI;
		Throughput_a2_GTS[k] = a2_GTS->Throughput_Sum[k] / RoundNum / BI;
		Power_a1_GTS[k] = a1_GTS->EnergyConsumption[k] / RoundNum / BI; // mW
		Power_a2_GTS[k] = a2_GTS->EnergyConsumption[k] / RoundNum / BI; // mW

		//data for BodyMAC

		AvgDelay_a1_BodyMAC[k] = a1_BodyMAC->AvgDelay_Sum[k] / a1_BodyMAC->SucPkt[k];
		AvgDelay_a2_BodyMAC[k] = a2_BodyMAC->AvgDelay_Sum[k] / a2_BodyMAC->SucPkt[k];
		Throughput_a1_BodyMAC[k] = a1_BodyMAC->Throughput_Sum[k] / RoundNum / BI;
		Throughput_a2_BodyMAC[k] = a2_BodyMAC->Throughput_Sum[k] / RoundNum / BI;
		Power_a1_BodyMAC[k] = a1_BodyMAC->EnergyConsumption[k] / RoundNum / BI; // mW
		Power_a2_BodyMAC[k] = a2_BodyMAC->EnergyConsumption[k] / RoundNum / BI; // mW
	}

	// write the results to file

	FILE* fd;
	errno_t err;

	char numBuffer[256];
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male2_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M,alpha,beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Female6_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male3_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male1_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male9_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male8_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	//sprintf(numBuffer, "./ResultsAnalysis/results_Male4_3Star_N_a_b/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);
	sprintf(numBuffer, "./ResultsAnalysis/results_Male10_3Star_N_a_b_adjustment/WBAN_output_C_BO%d_N%d_M%d_a%1.1lf_b%1.1lf.txt", BO, N, M, alpha, beta);

	err = fopen_s(&fd, numBuffer, "w");

	if (err == 0)
	{
		// data of my design
		//printf("The data file WBAN_output_C was opened\n");

		writeToFile(AvgDelay_a1, fd);
		writeToFile(AvgDelay_a2, fd);
		writeToFile(Throughput_a1, fd);
		writeToFile(Throughput_a2, fd);
		writeToFile(Power_a1, fd);
		writeToFile(Power_a2, fd);
		
		// data of IEEE 802.15.4 GTS
		writeToFile(AvgDelay_a1_GTS, fd);
		writeToFile(AvgDelay_a2_GTS, fd);
		writeToFile(Throughput_a1_GTS, fd);
		writeToFile(Throughput_a2_GTS, fd);
		writeToFile(Power_a1_GTS, fd);
		writeToFile(Power_a2_GTS, fd);
		
		
		// data of BodyMAC
		writeToFile(AvgDelay_a1_BodyMAC, fd);
		writeToFile(AvgDelay_a2_BodyMAC, fd);
		writeToFile(Throughput_a1_BodyMAC, fd);
		writeToFile(Throughput_a2_BodyMAC, fd);
		writeToFile(Power_a1_BodyMAC, fd);
		writeToFile(Power_a2_BodyMAC, fd);


		fclose(fd);
	}
	else
	{
		printf("The data file ChannelMatrix_coor_a1 was not opened\n");
	}
}