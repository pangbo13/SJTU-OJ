#include<iostream>
#include<queue>
#include<map>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
class naive_queue{
    map<int,queue<int>> pos;
    queue<int> group;
    public:
        naive_queue(){};
        void push(int group_id,int person_id){
            auto p = pos.find(group_id);
            if(p == pos.end()){
                p = pos.insert(pair<int,queue<int>>(group_id,{})).first;
            }
            queue<int>& q = (*p).second;
            if(q.empty()){
                group.push(group_id);
            }
            q.push(person_id);
        }
        int pop(){
            auto q = pos.find(group.front());
            int ans = (*q).second.front();
            (*q).second.pop();
            if((*q).second.empty()){
                group.pop();
            }
            return ans;
        }
        int front(){
            auto q = pos.find(group.front());
            return (*q).second.front();
        }
        bool empty(){
            return group.empty();
        }
};

int main(){
    int* buffer;
    naive_queue nq;
    int n,q,front = 0,person_id = 1;
    n = read();
    buffer = new int[n];
    for(int i = 0;i<n;i++){
        buffer[i] = read();
    }
    q = read();
    for(int i = 0;i<q;i++){
        int choice;
        choice = read();
        switch(choice){
            case 0:
                if(front < n){
                    nq.push(buffer[front],person_id);
                    ++ front;
                    ++ person_id;
                }
                break;
            case 1:
                if(nq.empty()){
                    printf("-1\n");
                }else{
                    printf("%d\n",nq.pop());
                }
                break;
        }
    }
    delete[] buffer;
}