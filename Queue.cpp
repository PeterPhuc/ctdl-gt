#include <iostream>
using namespace std;

struct node{ 
	int data;
	node * next; 
};
typedef struct node NODE;


struct QUEUE { 
	NODE * First; 
	NODE * Last; 
};
typedef struct QUEUE queue;


void Initialize_Queue(queue &q){    //Khoi tao list queue
	q.First = q.Last = NULL;
}

int QueueEmpty(queue q) {           //Kiem tra queue rong
    if(q.First == NULL)
       return 0;
    return 1;
}

NODE*Create_Node(){    //Ham tao nut moi
	NODE * node;
    node = new NODE;
	
	int data;
	cout<<"Nhap data node: ";
    cin>>data;
     
	if(node == NULL){
	   return NULL;
    }else{
		node->data = data;
		node->next = NULL;
	}
    return node;
}



void Push(queue &q, NODE*p){       //Them vao queue
	if( QueueEmpty(q) == 0 ){              
    	q.First = q.Last = p;
    }else{
		q.Last -> next = p;
		q.Last = p;
	}
}


void CreatQueue(queue &q, NODE*&p){
	int n;
	cout<<"Nhap so luong node can them vao queue: ";
	cin>>n;
	
	int i = 1;
	while( i <= n ){
	   p = Create_Node();
	   Push(q, p);
	   i++;
	}
}

int sizeQueue(queue q){
	if(QueueEmpty(q) == 0) return 0;
	
	NODE*temp = q.First;
	int length = 0;
	while(temp != NULL){
		length++;
		temp = temp->next;
    }
	return length;	
}


void Pop(queue &q){
	if(QueueEmpty(q) == 0)  cout<<("\nQueue is Empty!");
	
	else{
	   NODE * temp = q.First;    // Node temp de luu tru node q.First
	   q.First = q.First -> next;  //Cap nhat gia tri moi cho node q.First
	   delete temp;                //Xoa node temp
	}
}

void Top(queue q){
	if(QueueEmpty(q) == 0)  cout<<"Queue rong";
	
	else{
	   cout<<q.First->data;
	}
}

void ShowQueue(queue q){
	if(QueueEmpty(q) == 0){
		cout<<"\nQueue rong!!!";
	}
	
	else{
		NODE*i = q.First;
		while(i){
			cout<<i->data<<" ";
			i = i->next;
        }
	}
}

int main(){
	NODE * p;
    queue q;
	CreatQueue(q, p);
	int luachon;
	do{
		cout<<"\n-------------------MENU-------------------"<<endl;
		cout<<"1. Them phan tu"<<endl;
		cout<<"2. Xoa phan tu"<<endl;
		cout<<"3. Xem phan tu dau tien"<<endl;
		cout<<"4. In queue ra man hinh"<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"Nhap lua chon: ";
		cin>>luachon;
		
		switch(luachon){
			case 1:
				p = Create_Node();
				Push(q,p);
				break;
		    case 2:
		    	Pop(q);
		    	break;
		    case 3:
		    	Top(q);
		    	break;
		    case 4:
		    	ShowQueue(q);
		    	break;
		    case 0:
		    	break;
		    default:
		    	cout<<"Nhap sai du lieu!!!";
		}
	}while(luachon!=0);
	
	return 0;	
}











