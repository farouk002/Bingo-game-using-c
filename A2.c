//Farouk Kotob 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"

int testIsNumber(const char* str){
	int i=0;
	int number=0;
	for(i=0;i<strlen(str);i++){
		if(str[i] >= '0' && str[i] <= '9') 
			number++;
	}
	if(number!=strlen(str)){
		return 0;
	}else return 1;

}
int main(int argc,char**argv)
{
	int i=0;
	char row[1024];
	int j=0;
	int number=0;
	int seed=0;
	FILE* file=NULL;
	int failed=0;
	List*card=INITIALIZE(25,NULL);
	List*marked=INITIALIZE(25,NULL);
	List*CallList=INITIALIZE(0,NULL);
	SET(2,2,marked,1);
	
	if(argc!=3)
	{
		fprintf(stderr,"Usage: A2 seed cardFile\n");
		exit(1);
		error("Usage: A2 seed cardFile\n");
	}
	
	if(testIsNumber(argv[1])==0)
	{
		fprintf(stderr,"Expected integer seed, but got %s\n",argv[1]);
		exit(2);
	}
	seed=atoi(argv[1]);
	srand(seed);
	file=fopen(argv[2],"r");
	if(file==NULL){
		fprintf(stderr,"%s is nonexistent or unreadable\n",argv[2]);
		exit(3);
	}
	
	i=0;j=0;failed=0;
	while (fgets(row, 1024, file) && strlen(row)>0) {
		if(row[strlen(row)-1]=='\n')row[strlen(row)-1]=0;

		char *t;
		t=strtok(row, " ");
		while( t != NULL ) {
			if(testIsNumber(t)==1)
				SET(i,j,card,atoi(t));
			else
				failed=1;
			t = strtok(NULL, " ");
			j++;
		}
		
		if(j!=5)failed=1;
		j=0;
		i++;
	}	
	if(i!=5)failed=1;
	

	if(failed==1)
	{
		fprintf(stderr,"%s has bad format\n",argv[2]);
		exit(4);
	}

	fclose(file);
	char cmd[255];
	strcpy(cmd,"");
	
	while(1){
		
		
		system("clear");
		printf("CallList: ");
		PRINTCALLLIST(card,CallList);
		printf("\n\n");
		PRINTMARKED(card,marked);
		if(TESTWINNER(marked)==1){
			printf("WINNER\n");
			exit(0);
		}
		printf("Enter any non-enter key for Call (q to quit): ");
		fflush(stdout);	
		
		char ch=fgetc(stdin);
		

		if(ch!=0x0A){
			strncat(cmd, &ch, 1);
			printf("%s\n",cmd);
		}else{
			if(strcmp(cmd,"q")==0)exit(0);
			int v=0;
			for(v=0;v<strlen(cmd);v++){
				int total=getUnMarkedCount(marked);
				int x=(rand() %(total - 1 + 1)) + 1;
				int ret=setXUnMarked(marked,x);		
				ADD(ret,CallList);
			}
				
			strcpy(cmd,"");
		}
		
	}
}
