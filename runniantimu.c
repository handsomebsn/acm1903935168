#include<stdio.h>
#include<stdbool.h>

bool isleap(int Y){

return (Y%4==0 && Y%100!=0)||Y%400==0;
}

int getfromY(int Y,int N){
	int j=0;
while(true){
Y++;
if(isleap(Y))
j++;
if(j==N)break;
}
return Y;
}



int main(){
int Y,N;
int n;
scanf("%d",&n);
for(;n>0;n--){
scanf("%d %d",&Y,&N);
printf("%d\n", getfromY(Y,N)); 
}
	return 0;
}