struct Node_{
	int value;
	struct Node_ *next;
};
struct List_{
	int count;
	struct Node_ *first;
};
typedef struct Node_ Node;
typedef struct List_ List;

void ADD(int item,List* list);
int CHECK(int item,List* list);
void PRINT(List* list);
int TESTWINNER(List* list);
void PRINTCALLLIST(List* listCard,List*listCall);
List*  INITIALIZE(int max,List* list);
void PRINTMARKED(List* listCard,List*listMarked);
int GET(int j,int i,List* list);
void SET(int j,int i,List* list,int item);
int getUnMarkedCount(List* list);
int setXUnMarked(List* list,int x);