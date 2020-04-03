#include<iostream>
using namespace std;

template <class elemType>
class stack{
	public:
		virtual bool isEmpty() const = 0; //ÅÐÕ»¿Õ
		virtual void push(const elemType&x) = 0; // ½øÕ»
		virtual elemType pop() = 0; // ³öÕ»
		virtual elemType top() const = 0; // È¡Õ»¶¥ÔªËØ
		virtual ~stack() {} //ÐéÎö¹¹º¯Êý
};
template <class elemType>
class seqStack: public stack<elemType>{
	private:
		elemType *elem;
		int top_p;
		int maxSize;
		void doubleSpace();
	public:
		seqStack(int initSize = 10);
		~seqStack();
		bool isEmpty() const;
		void push(const elemType &x);
		elemType pop();
		elemType top() const;
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize){
	elem = new elemType[initSize];
	maxSize = initSize ;
	top_p = -1;
}
template <class elemType>
seqStack<elemType>::~seqStack(){
	delete[] elem;
}
template <class elemType>
bool seqStack<elemType>::isEmpty() const{
	return top_p == -1;
}
template <class elemType>
void seqStack<elemType>::push(const elemType &x){
	if(top_p == maxSize -1) doubleSpace();
	elem[++top_p] = x;
}
template <class elemType>
elemType seqStack<elemType>::pop(){
	return elem[top_p--];
}
template <class elemType>
elemType seqStack<elemType>::top() const{
	return elem[top_p];
}
template <class elemType>
void seqStack<elemType>::doubleSpace(){
	elemType *tmp = elem;
	elem = new elemType[2 * maxSize ];
	for (int i = 0; i < maxSize; ++i) elem[i] = tmp[i];
	maxSize *= 2;
	delete [] tmp;
}
int main(){
	int N,op,num;
	seqStack<int> s;
	cin>>N;
	for(int i = 0;i<N;i++){
		cin>>op>>num;
		switch(op){
			case 1:
				s.push(num);
				cout<<"OK"<<endl;
				break;
			case 2:
				if(s.isEmpty()) cout<<"ERROR"<<endl;
				else{
					if(s.pop() == num) cout<<"YES"<<endl;
					else cout<<"NO"<<endl;
				}
		}
	}
}