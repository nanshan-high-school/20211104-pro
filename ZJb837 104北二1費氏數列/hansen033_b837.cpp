#include <iostream>
using namespace std;

int DP[10000000];

void fe(int til){
	static int end=1;//儲存現在費式數列處理到哪一格
	if(DP[end]>=til){//如果已經夠了就不用計算
		return;//void函式可以用這個來終止
	}

	while(DP[end]<til){//計算費式數列直到達到或超過需求
		end++;
		DP[end]=DP[end-1]+DP[end-2];
	}

}

int main() {
	int times, start, end;
	cin >> times;
	DP[0]=0;
	DP[1]=1;
	for(int t0=0; t0<times; t0++){
		cin >> start >> end;
		if(start>end){
			int temp=start;
			start=end;
			end=temp;
		}
		fe(end);//DP到至少大於等於結束
	
		int DPstart=0, DPend;
		while(DP[DPstart]<start){
			DPstart++;
		}
		DPend=DPstart;
		while(DP[DPend]<end){
			DPend++;
		}


		for(int t1=DPstart; t1<DPend; t1++){
			cout << DP[t1] << "\n";
		}
		int length=DPend-DPstart;
		if(DP[DPend]==end){
			cout << DP[DPend] << "\n";
			length++;
		}
		cout << length << "\n";
		if(t0!=times-1)
			cout << "------\n";
	}
} 