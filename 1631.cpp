#include<iostream>
#include<cstring>
using namespace std;
char str1[501],str2[501],ans[501];
bool compare(char* s1,char* s2,int l1,int l2){//s1更大或等于则返回true
	int i1,i2;
	for(int i = 1; i <= l2 ; i++){
		if(str1[l1-i]<str2[l2-i]) return false;
		else if(str1[l1-i]>str2[l2-i]) return true;
	}
	return true;
}
void sub(char* s1,char* s2,int l1,int l2){
	int i1,i2;
	for(int i = 1; i <= l2 ; i++){
		str1[l1-i] -= (str2[l2-i]-'0');
		for(int j=0;str1[l1-i+j]<'0';j++){
			str1[l1-i+j] += 10;
			str1[l1-i+j+1] -= 1;
		}
	}
}
int main(){
	int len1,len2,lenans,ansp;
	cin>>str1>>str2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	ans[0] = '0';
	lenans = compare(str1,str2,len1,len2)?len1-len2+1:len1-len2;
	ansp = lenans-1;
	for(;ansp>=0;ansp--){
		ans[ansp] = '0';
		while(ansp+len2<len1){
			sub(str1,str2,ansp+len2,len2);
			ans[ansp]++;
			if(str1[len1-1] == '0') {
				str1[len1-1] = 0;
				len1--;
				}
		}
		while(compare(str1,str2,len1,len2)){
			sub(str1,str2,len1,len2);
			ans[ansp]++;
		}
		if(str1[len1-1] == '0') {
			str1[len1-1] = 0;
			len1--;
			}
	}
	cout<<ans;
}