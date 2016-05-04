#include"DirectTransmit_RealData.h"

void DirectTransmit_RealData(Node* a,double PDR_coor, int Power_Index) {
	for (int i = 0; i < a->BufTail + 1; i++) { // the new packet is at the tail of the queue
		// generate random number in[0, 1]
		double randomNum = GenerateRandomNum();
		if (randomNum < PDR_coor) {
			// the transmission of node a2 to coordinator is successful
			a->EnergyConsumption[Power_Index] = a->EnergyConsumption[Power_Index] + E_suc_transmitter;
			a->AvgDelay_Sum[Power_Index] = a->AvgDelay_Sum[Power_Index] + a->Buf[i]*BI + (T_overhead + T_data + T_ACK);
			a->Throughput_Sum[Power_Index] = a->Throughput_Sum[Power_Index] + L_data;
			a->Buf[i] = -1;
		}
		else {
			a->EnergyConsumption[Power_Index] = a->EnergyConsumption[Power_Index] + E_failed_transmitter;
			a->Buf[i] = a->Buf[i] + 1;
		}
	}
	AnalyzeBuf(a, Power_Index);
}