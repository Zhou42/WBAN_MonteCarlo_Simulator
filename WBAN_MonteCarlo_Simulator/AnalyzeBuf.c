#include"AnalyzeBuf.h"

void AnalyzeBuf(Node* a, int Power_Index) {
	    // REGULATEBUF Summary of this function goes here
		// Detailed explanation goes here


		// if exceed the max retransmission time, delete it from
		// the buffer
		// count is used to count how many packets exceed the retransmission limit
		// length of buffer is at least one

	int tail = -1;
	int N = a->BufTail + 1;
	int x[bufSize];  // the longest buf is bufSize
	int Failed_Num = 0;

	for(int i = 0;i < N;i++) {
		if ((a->Buf[i]>0) || (a->Buf[i] == 0)) {
			if ((a->Buf[i]<M) || ((a->Buf[i] == M))) { //packets that are still need to be retransmitted
				tail = tail + 1;  //get into the queue
				x[tail] = a->Buf[i];
			}
			else {
				a->FailedPkt[Power_Index]++;
			}
		}
		else {
			a->SucPkt[Power_Index]++;
		}
	}

	

	if (tail > -1) { //when queue is not empty
		for (int j = 0;j < tail + 1;j++) {
			a->Buf[j] = x[j];
		}
	}
	else { //tail is -1 and queue is empty
		;
	}
	
	a->BufTail = tail;

}
