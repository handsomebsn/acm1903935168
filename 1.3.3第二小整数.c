/**
第二小整数
Time Limit: 3000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3149 Accepted Submission(s): 1992

Problem Description
求n个整数中倒数第二小的数。
每一个整数都独立看成一个数，比如，有三个数分别是1，1，3，那么，第二小的数就是1。
 

Input
输入包含多组测试数据。
输入的第一行是一个整数C，表示有C测试数据；
每组测试数据的第一行是一个整数n，表示本组测试数据有n个整数（2<=n<=10），接着一行是 n个整数 (每个数均小于100);
 

Output
请为每组测试数据输出第二小的整数，每组输出占一行。
 

Sample Input

2
2
1 2
3
1 1 3

 

Sample Output

2
1

 

**/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void sort(int array[],int n){
	int tmp;
	int i;
for(int p=1;p<n;p++){
  	tmp=array[p];
    for(i=p;i>=1&&tmp<array[i-1];i--)
      array[i]=array[i-1];
array[i]=tmp;
}


}

int main(){
int t,n,*array;
scanf("%d",&t);

//printf("%d\n", t);
for(;t>0;t--)
 {
   scanf("%d",&n);
   array=(int *)malloc(sizeof(int)*n);
     for(int i=0;i<n;i++){
      scanf("%d",array+i);
     }
     //
     sort(array,n);
      
   
     printf("%d\n",array[1]);
     
 }


	return 0;
}