//Farouk Kotob 
#include<stdio.h>
#include"list.h"
#include<stdlib.h>

void ADD(int item,List* list){
	if(list==NULL)return;
	Node* current=list->first;
	Node* last=current;
	while(current!=NULL){
		last=current;
		current=current->next;
	}
		
	Node* node=(Node*)malloc(sizeof(Node));
		node->next=NULL;
		node->value=item;
	if(last!=NULL){
		last->next=node;
		list->count++;
	}else{
		list->first=node;
		list->count=1;
	}
	
	
}
int CHECK(int item,List* list){
	if(list==NULL)return;
	Node* current=list->first;
	while(current!=NULL){
		if(current->value==item)return 1;
		current=current->next;
	}
	return 0;
	
}
void PRINT(List* list){
	int i=0;

	if(list==NULL)return;
	Node* current=list->first;
	while(current!=NULL){
		if(i%5==0)printf("L");
		if(i%5==1)printf("I");
		if(i%5==2)printf("N");
		if(i%5==3)printf("U");
		if(i%5==4)printf("X");
		printf("%02d\n",current->value);
		current=current->next;
		i++;
	}

}
List* INITIALIZE(int max,List* list){
	int i=0;
	if(max==0){
		List* a=(List*)malloc(sizeof(List));
		a->count=0;
		a->first=NULL;
		return a;
	}
	if(list==NULL){
		
		List* a=(List*)malloc(sizeof(List));
		a->count=max;
		Node* firstNode=(Node*)malloc(sizeof(Node));
			firstNode->next=NULL;
			firstNode->value=0;
		a->first=firstNode;
		Node* prevNode=firstNode;
		for(i=1;i<max;i++)
		{
			Node* node=(Node*)malloc(sizeof(Node));
				node->next=NULL;
				node->value=0;
			prevNode->next=node;
			prevNode=node;
		}
		return a;
		
	}else {
		List* a=list;
		
		a->count=max;
		Node* firstNode=(Node*)malloc(sizeof(Node));
			firstNode->next=NULL;
			firstNode->value=0;
		a->first=firstNode;
		Node* prevNode=firstNode;
		for(i=1;i<max;i++)
		{
			Node* node=(Node*)malloc(sizeof(Node));
				node->next=NULL;
				node->value=0;
			prevNode->next=node;
			prevNode=node;
		}
		return a;
		
	}
	
}
void PRINTMARKED(List* listCard,List*listMarked){
	int i=1;

	if(listCard==NULL || listMarked==NULL)return;
	if(listCard->count!=listMarked->count)return;
	Node* current1=listCard->first;
	Node* current2=listMarked->first;
	printf("L   I   N   U   X\n");
	while(current1!=NULL && current2!=NULL){
		if(current2->value==0)
			printf("%02d  ",current1->value);
		else
			printf("%02dm ",current1->value);
		if(i%5==0) printf("\n");

		current1=current1->next;
		current2=current2->next;
		i++;
	}

}
void PRINTCARD(List* listCard,int card){
	int i=0;

	if(listCard==NULL)return;
	Node* current=listCard->first;
	while(current!=NULL){
		if(i==card-1){
			if(i%5==0)printf("L");
			if(i%5==1)printf("I");
			if(i%5==2)printf("N");
			if(i%5==3)printf("U");
			if(i%5==4)printf("X");
			printf("%02d ",current->value);
		}
		current=current->next;
		i++;
	}

}

int GET(int j,int i,List* list){
	if(list==NULL)return;
	Node* current=list->first;
	int ii=0;int jj=0;
	while(current!=NULL){
		if(i==ii && j==jj)
			return current->value;
		ii++;
		if(ii==5){
			ii=0;
			jj++;
		}
		current=current->next;
	}
	
}
void SET(int j,int i,List* list,int item){
	if(list==NULL)return;
	Node* current=list->first;
	int ii=0;int jj=0;
	while(current!=NULL){
		if(i==ii && j==jj)
			current->value=item;
		ii++;
		if(ii==5){
			ii=0;
			jj++;
		}
		current=current->next;
	}
	
}
int getUnMarkedCount(List* list){
	if(list==NULL)return;
	Node* current=list->first;
	int i=0;
	while(current!=NULL){
		if(current->value==0)i++;
		current=current->next;
	}
	return i;
	
}
int setXUnMarked(List* list,int x){
	if(list==NULL)return;
	Node* current=list->first;
	int i=0;
	while(current!=NULL){
		if(current->value==0)i++;
		if(i==x){current->value=1;return i;}
		current=current->next;
	}
	return i;
	
}

void PRINTCALLLIST(List* listCard,List*listCall){
	
	if(listCard==NULL || listCall==NULL)return;
	Node* current=listCall->first;
	
	while(current!=NULL){
		PRINTCARD(listCard,current->value);
		current=current->next;
	}
	

}

int TESTWINNER(List* list){
	if(list==NULL)return 0;
	if(list->count<25)return 0;

	if(GET(4,0,list)==1 && GET(0,4,list)==1 && GET(0,0,list)==1 && GET(4,4,list)==1)	
		return 1;
	int i=0;
	
	for(i=0;i<5;i++){
		if(GET(i,0,list)==1 && GET(i,1,list)==1 && GET(i,2,list)==1 && GET(i,3,list)==1
		  && GET(i,4,list)==1) return 1;	
		
		if(GET(0,i,list)==1 && GET(1,i,list)==1 && GET(2,i,list)==1 && GET(3,i,list)==1
		  && GET(4,i,list)==1) return 1;	
		
	}
	
	
	return 0;
}