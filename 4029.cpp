#include<stack>
#include<iostream>
using namespace std;
#define Inf 0x3f3f3f3f

int main(){
    int N,M,mod,*a,*min;
    bool* done;
    stack<int> buffer;
    scanf("%d",&N);
    a = new int[N];
    for(int i = 0;i<N;i++) scanf("%d",&a[i]);
    mod = a[0];
    min = new int[mod];
    done = new bool[mod];
    for(int i = 0;i<mod;i++){
        done[i] = 0;
        min[i] = Inf;
    }
    min[0]=0;
    buffer.push(0);
    while(buffer.size()){
        int x=buffer.top();
        buffer.pop();
        if(done[x]) continue;
        done[x]=1;
        for(int i=1;i<N;i++){
            int y=(x+a[i])%mod;
            if(min[y]>min[x]+a[i]){
                min[y]=min[x]+a[i];
                done[y] = 0;
                buffer.push(y);
            }
        }
    }
    scanf("%d",&M);
    int aim;
    for(int i=0;i<M;i++){
        scanf("%d",&aim);
        if(aim>=min[aim%mod]) printf("YES\n");
        else printf("NO\n");
    }
}