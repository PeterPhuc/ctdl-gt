#include <iostream>
using namespace std;

struct Node{ 
   int info;
   Node *next; 
};
typedef struct Node Stack;


void Stack_Initialize(Stack *&top){    //Khoi tao stack
    top = NULL;
}


int StackEmpty(Stack *&top){           //Kiem tra stack rong
	if(top == NULL) 
	   return 0;
	return 1;
}


void Push(Stack *&top, int x){
	Stack *s = new Stack; 	
	   s->info = x;
	   s->next = top;
	   top = s;
}

int Pop(Stack *&top){
	if(StackEmpty(top) == 0){ exit(1); }
	
	else{
		Stack *s = top;
		int x = s->info;
		top = top->next;
		delete s;
		return x;
	}
}

void CreatStack(Stack*&top){
	int n;
	cout<<"Nhap so luong node can them vao stack: ";
	cin>>n;
	
	int i = 1;
	int data;
	while( i <= n ){
	   cout<<"Nhap gia tri data: ";
	   cin>>data;
	   
	   Push(top,data);
	   i++;
	}
}

void PopAll(Stack*&top){
	
	while(top != NULL){
	   cout<<Pop(top)<<" ";	
	}
	
}

int PopLast(Stack*&top){
	if(StackEmpty(top) == 1) {
	   return Pop(top);
	}
}

int main(){
	Stack *top;
	int a = 5;
	int b = 3;
	int c = 7;
	//CreatStack(top);
	
	Push(top, a);
	
	Push(top, c*c);
	
	b = PopLast(top);
	
	Push(top, b+a);
	
	a = PopLast(top);
	
	b = PopLast(top);
	
	cout<<a<<" "<<b<<" "<<c;
	
	return 0;
}


















