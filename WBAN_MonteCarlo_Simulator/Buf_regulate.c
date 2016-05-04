#include"Buf_regulate.h"
void Buf_regulate(Node* a, int Power_Index) {
	for (int i = 0;i < a->BufTail + 1;i++) {
		a->Buf[i]++;
	}
	AnalyzeBuf(a,Power_Index);
}