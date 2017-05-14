/**
百步穿杨
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 5714 Accepted Submission(s): 1938

Problem Description
时维九月,序属三秋,辽军大举进攻MCA山,战场上两军正交锋.辽军统帅是名噪一时的耶律-James,而MCA方则是派出了传统武将中草药123.双方经过协商,约定在十一月八日正午十分进行射箭对攻战.中草药123早早就开始准备,但是他是武将而不是铁匠,造弓箭的活就交给聪明能干的你了,现在告诉你每种弓箭规格,即箭身的长度,以及每种规格弓箭所需要的数目,要求你把需要的弓箭都输出.
弓箭的基本样子为 ">+---+>",其中"+---+"为箭身,数据保证箭身长度 > 2
 

Input
首先输入一个t,表示有t组数据，跟着t行：
每行一个N (N < 50 ),接下去有N行,第i行两个整数Ai , Bi,分别代表需要箭身长度为Ai的弓箭Bi枝. (Ai < 30 , Bi < 10 )
输入数据保证每一个Ai都是不同的.
 

Output
按照箭身的长度从小到大的顺序依次输出所有需要的弓箭,"每一种"弓箭后输出一个空行.
 

Sample Input

1
4
3 4
4 5
5 6
6 7

 

Sample Output

>+-+>
>+-+>
>+-+>
>+-+>

>+--+>
>+--+>
>+--+>
>+--+>
>+--+>

>+---+>
>+---+>
>+---+>
>+---+>
>+---+>
>+---+>

>+----+>
>+----+>
>+----+>
>+----+>
>+----+>
>+----+>
>+----+>

 

Author
Teddy
 

Source
2008“缤纷下沙校园文化活动月”之大学生程序设计竞赛暨新生专场
 

**/
#include<stdio.h>
#include<stdbool.h>
typedef struct{
int AI;
int BI;
}node;
node array[50];
void print(int AI,int BI){
for(int i=0;i<BI;i++){
	printf(">+");
	for(int j=0;j<AI-2;j++)
	printf("-");
	printf("+>");
   printf("\n");
 }

}


void sort(node array[],int n){
	node tmp;
	int i;
for(int p=1;p<n;p++){
  	tmp=array[p];
    for(i=p;i>=1&&tmp.AI<array[i-1].AI;i--)
      array[i]=array[i-1];
array[i]=tmp;
}


}

int main(){
int t,n,ai,bi;
scanf("%d",&t);
//printf("%d\n", t);
for(;t>0;t--)
 {
   scanf("%d",&n);
     for(int i=0;i<n;i++){
       scanf("%d %d",&array[i].AI,&array[i].BI);
     }
     //
     sort(array,n);
      
     for(int i=0;i<n;i++)
     	{print(array[i].AI,array[i].BI);printf("\n");}
     //print(array[n-1].AI,array[n-1].BI);

 }


	return 0;
}