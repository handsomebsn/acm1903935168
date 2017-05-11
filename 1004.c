/*
Let the Balloon Rise
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 119971    Accepted Submission(s): 47019


Problem Description
Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you.
 

Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.

A test case with N = 0 terminates the input and this test case is not to be processed.
 

Output
For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 

Sample Input

5
green
red
blue
red
red
3
pink
orange
pink
0

 

Sample Output

red
pink

*/








#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
char key[16];
char like[20];
int num;
struct Node *next;
}*ptrnode;
typedef struct Node Element;
typedef ptrnode Postion;
typedef struct{
ptrnode head;
ptrnode tail;
}List;
typedef List hashtable[26];

int hash(const char key[]){
return key[0]-'a';
}

void Init(hashtable htable){
for(int i=0;i<26;i++)
{
htable[i].head=htable[i].tail=NULL;
}
}


void insertvalue(hashtable htable,const Element *val)
{
ptrnode tmp=(ptrnode)malloc(sizeof(struct Node));
tmp->next=NULL;
strcpy(tmp->key,val->key);
strcpy(tmp->like,val->like);
tmp->num=1;
int p=hash(val->key);
if(!(htable[p].head))
htable[p].head=htable[p].tail=tmp;
else{

htable[p].tail->next=tmp;
htable[p].tail=tmp;
}

}

Postion find(hashtable htable,const Element *val){
int p=hash(val->key);
Postion P=htable[p].head;
while(P&&strcmp(P->key,val->key)){
P=P->next;
//printf("xia yi chu\n" );
}
return P;
}

Postion findmax(hashtable htable){
int max=0;
Postion P=NULL;
Postion PMAX=NULL;
for(int i=0;i<26;i++)
{
	if(!htable[i].head)continue;
P=htable[i].head;

  while(P){
  if(P->num>max)   
  {max=P->num;PMAX=P;}
  
  P=P->next;
  }
htable[i].head=htable[i].tail=NULL;
}

return PMAX;
}



void insertvalueandcount(hashtable htable,const Element *val){
	Postion p=find(htable,val);
if(p)
{
p->num++;
}else{


insertvalue(htable,val);
}

}

void reset(hashtable htable){
	ptrnode P,TMP;
for(int i=0;i<26;i++)
{
if(!htable[i].head)continue;
 while(P){
   TMP=P;
   P=P->next;
   free(TMP);
  }

}


}



int main(int argc, char const *argv[])
{
	/* code */
	int n;
	char color[16];
	Element val;
	hashtable htable;
	Postion pmax=NULL;
	Init(htable);
while(scanf("%d",&n),n){
for(;n>0;n--){
scanf("%s",color);
strcpy(val.key,color);
insertvalueandcount(htable,&val);
}
pmax=findmax(htable);
if(pmax)
printf("%s\n", pmax->key);
//printf("---------------------------------------\n");
reset(htable);
}


	return 0;
}