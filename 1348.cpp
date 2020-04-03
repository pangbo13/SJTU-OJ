#include<queue>
#include<iostream>
using namespace std;
int main(){
	int N,M;
	int maleNum = 0,femaleNum = 0;
	priority_queue <int,vector<int>,greater<int>> male;
	priority_queue <int,vector<int>,greater<int>> female;
	scanf("%d",&N);
	int* song = new int[N];
	for(int i = 0;i<N;i++) scanf("%d",&song[i]);
	scanf("%d",&M);
	int sex,time;
	for(int i = 0;i<M;i++){
		scanf("%d%d",&sex,&time);
		switch(sex){
			case 1:
				male.push(time);
				maleNum++;
				break;
			case 2:
				female.push(time);
				femaleNum++;
				break;
		}
	}
	long currentTime = 0;
	long femaleWaitTime = 0,maleWaitTime = 0;
	for(int i = 0;i<N-1;i++){
		if(female.empty()||male.empty()){
			currentTime += song[i];
			continue;
		}
		while(female.top()<=currentTime&&male.top()<=currentTime){
			femaleWaitTime += currentTime - female.top();
			maleWaitTime += currentTime - male.top();
			female.pop();
			male.pop();
			if(female.empty()||male.empty()) break;
		}
		currentTime += song[i];
	}
	while(!female.empty()){
		femaleWaitTime += (currentTime - female.top());
		female.pop();
	}
	while(!male.empty()){
		maleWaitTime += (currentTime - male.top());
		male.pop();
	}
	double femaleAvgWaitTime,maleAvgWaitTime;
	maleAvgWaitTime = (double)maleWaitTime/maleNum;
	femaleAvgWaitTime = (double)femaleWaitTime/femaleNum;
	delete[] song;
	printf("%.2lf %.2lf",maleAvgWaitTime,femaleAvgWaitTime);
}