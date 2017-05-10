#include<stdio.h>
#include<stdlib.h>
#define pi 3.1415927
typedef struct RNode
{
  float distance;
  float mph; 
  struct RNode *next;
}result;
typedef struct
{
 result *head;
 result *tail;
}resultlist;


int main(){
float d,distance,mph;
int r,t;
int i=0;
resultlist list;
result *p,*tmp;
list.head=list.tail=NULL;
while(scanf("%f %d %d",&d,&r,&t)!=EOF)
{
if(r==0)
  break;
d=d/12/5280;
distance=pi*d*r;
mph=distance/t*3600;
tmp=(result*)malloc(sizeof(result));
tmp->distance=distance;
tmp->mph=mph;
if(list.head==NULL)
list.head=list.tail=tmp;
  else{
  list.tail->next=tmp;
   list.tail=tmp;
  }
}//while end

list.tail->next=NULL;
p=list.head;
while(p){
  i++;
printf("Trip #%d %.2f %.2f\n",i,p->distance,p->mph);
tmp=p;
p=p->next;
free(tmp);
}

}




