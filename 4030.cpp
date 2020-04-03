/*
一道数学题
*/
#include<iostream>
using namespace std;
int main(){
	double damage = 0;
	double last_hit_pro = 0,last_damage_avg = 0;
	double this_hit_pro = 0,this_damage_avg = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lf",&this_hit_pro);
		this_damage_avg = (last_damage_avg+2 * last_hit_pro) * this_hit_pro + (1-last_hit_pro) * this_hit_pro;
		last_hit_pro = this_hit_pro;
		last_damage_avg = this_damage_avg;
		damage += this_damage_avg;
	}
	printf("%f",damage);
}