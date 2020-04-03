/*
这道题用cin&cout会超时
*/
#include<iostream>
using namespace std;

template <class elemType>
class stack{
	public:
		virtual bool isEmpty() const = 0; //判栈空
		virtual void push(const elemType&x) = 0; // 进栈
		virtual elemType pop() = 0; // 出栈
		virtual elemType top() const = 0; // 取栈顶元素
		virtual ~stack() {} //虚析构函数
};
template <class elemType>
class seqStack: public stack<elemType>{
	private:
		elemType *elem;
		int top_p;
		int maxSize;
		void doubleSpace();
	public:
		seqStack(int initSize = 1000);
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
//顺序栈定义结束
class BracketsStack{
	private:
		seqStack<char> input,brackets;
		int char_since_unblance;	//保存距离第一个未配对闭括号的字符数
	public:
		BracketsStack();
		void push(const char &x);
		void pop();
		char top() const;
		bool isEmpty() const;
		bool CheckBalance() const;
};

BracketsStack::BracketsStack():char_since_unblance(0){}

void BracketsStack::push(const char &x){
	input.push(x);
	if(char_since_unblance > 0) char_since_unblance++;	//如果前面存在未配对闭括号，后面无论如何都不可能配对，因此不用操作括号栈
	else{
		switch(x){
			case '(': case '[': case '{':
				brackets.push(x);
				break;
			//判断新入栈的闭括号是否配对
			case ')':
				if(brackets.isEmpty()||brackets.top()!='(') char_since_unblance = 1;
				else brackets.pop();
				break;
			case ']':
				if(brackets.isEmpty()||brackets.top()!='[') char_since_unblance = 1;
				else brackets.pop();
				break;
			case '}':
				if(brackets.isEmpty()||brackets.top()!='{') char_since_unblance = 1;
				else brackets.pop();
				break;
			
		}
	}
}
char BracketsStack::top() const{
	if(input.isEmpty()) return 0;
	else return input.top();
}
bool BracketsStack::CheckBalance() const{
	return (char_since_unblance == 0 && brackets.isEmpty());
}
void BracketsStack::pop(){
	if(input.isEmpty()) return;
	if(char_since_unblance > 0) char_since_unblance--;
	else{
		switch(input.top()){
			case '(': case '{': case '[':
				brackets.pop();
				break;
			//删除已经配对的闭括号时，需要重新入栈一个未配对的开括号
			case ')':
				brackets.push('(');
				break;
			case ']':
				brackets.push('[');
				break;
			case '}':
				brackets.push('{');
				break;
		}
	}
	input.pop();
}
bool BracketsStack::isEmpty() const{
	return input.isEmpty();
}
int main(){
	int n,choice;
	BracketsStack bracketsstack;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&choice);
		switch(choice){
			case 1:
				char x;
				scanf(" %c",&x);
				bracketsstack.push(x);
				break;
			case 2:
				bracketsstack.pop();
				break;
			case 3:
				if(!bracketsstack.isEmpty()) printf("%c\n",bracketsstack.top());
				break;
			case 4:
				if(bracketsstack.CheckBalance()) printf("YES\n");
				else printf("NO\n");
				break;
		}
	}
}