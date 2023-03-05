#include <iostream>
#include <math.h>
using namespace std;

struct node{ 
	int data;
	node * next; 
};
typedef struct node NODE;


struct list { 
	NODE * First; 
	NODE * Last; 
};
typedef struct list LIST;


void Initialize_List(LIST &l){    //Khoi tao danh sach lien ket
	l.First = l.Last = NULL;
}


NODE*Create_Node(){    //Ham tao nut moi
	NODE * p;
	p = new NODE;
	
	int data;
	cout<<"Nhap data node: ";
    cin>>data;
     
	if(p == NULL){
	   return NULL;
    }else{
		p->data = data;
		p->next = NULL;
	}
    return p;
}


void Insert_First(LIST &l, NODE*p){       //Them vao dau danh sach
	if( l.First == NULL ){              
    	l.First = l.Last = p;
    }else{
		p->next = l.First;     
		l.First = p;
	}
}


void Insert_After(LIST &l, NODE*q, NODE*p){ 

	for(NODE*i = l.First; i!=NULL; i=i->next){
		
		if( i->data == q->data ){

			if(i->next != NULL){
			   p->next = i->next;
			   i->next = p;
			}else{
			   i->next = p;
			}
			
			break;
	    }
	    
    }
    
}




void Insert_Last(LIST &l, NODE*p){       //Them vao cuoi danh sach
	if( l.First == NULL ){              
    	l.First = l.Last = p;
    }else{
		l.Last -> next = p;
		l.Last = p;
	} 
}

void Delete_First(LIST &l){
	if(l.First == NULL){
	   return;
	}else{
		NODE * temp = l.First;
		l.First = l.First -> next;
		delete temp; 
	}
}

void Delete_Last(LIST &l){
	if(l.First == NULL){
	   return;
	}else{
		for(NODE*i = l.First; i!=NULL; i=i->next){
			if(i -> next == l.Last){
			   NODE*temp = l.Last;
			   l.Last = i;
			   l.Last->next = NULL;
			   delete temp;
			   break;
			}
		} 
	}
}




void DeleteNode(LIST &l, int x){
	
	if(l.First->data == x){     //Node can xoa nam o dau danh sach
	   Delete_First(l);
	   return;	
	}
	
	/*if(l.Last->data == x){		//Node can xoa nam o cuoi danh sach
	   Delete_Last(l);
	   return;
	}*/
	
	NODE*temp = new NODE;		//Node can xoa nam o giua danh sach
	for(NODE*i = l.First; i!=NULL; i=i->next){
		
		if(i->data == x){
			temp->next = i->next;
			delete i;
			return;
	    }
	    temp = i;
	    
    }
    
}




NODE*FindNode(LIST l, int data){
	for(NODE*i = l.First; i!=NULL; i=i->next){
		if( i->data == data ){
			return i;	
		}
	} 
	return NULL;
}

void ShowList(LIST l){
	NODE * i = l.First;     //Gan Node i la node dau trong danh sach
	while(i != NULL){       //Vong while de duyet qua tat ca cac node trong danh sach
		cout<<i->data<<" ";
		i = i -> next;
 	}
}

void deletelist(LIST &l){
	NODE * i = NULL;
	while( l.First != NULL ){
		i = l.First;
		l.First = l.First -> next;
		delete i;
	}
}


void Creat_List(LIST &l, NODE*p){   //Tao moi danh sach//Nhap danh sach co N nut
	int n;
    cout<<"Nhap so luong node can them: ";
    cin>>n;
    
    for(int i = 1; i <= n; i++){
       p = Create_Node();
       //Insert_First(l, p);
       Insert_Last(l, p);
    }
}

void ChenNode(LIST &l, NODE*p){
	
	if(l.First->data < p->data){
	   Insert_First(l, p);
	   return;
	}
	
	if(l.Last->data > p->data){
	   Insert_Last(l, p);
	   return;
	}
	
	for(NODE*i = l.First; i!=NULL; i=i->next){
		
		if( (i->next)->data < p->data ){
			
           Insert_After(l, i, p);
           break;
           
	    }
	    
    }
	
}

int sohoanhao(int x){
	int sum = 0;
	for(int i = 1; i < x; i++){
	   if(x%i==0) sum+=i;
	}
	if(sum == x) 
		return 1;
	return 0;
}

void Timsohoanhaonhohona(LIST l){
	int a;
    cout<<"Nhap a: ";
    cin>>a;
	
	for(NODE*i = l.First; i!=NULL; i=i->next){
		
		if( (sohoanhao(i->data)==1) && (i->data < a) ){
			cout<<i->data<<" ";
		}
		
    }
}


/*int Timsobenhatchiahetchotatcacacnut(LIST l){

	int a[100], k = 0;
	
	for(NODE*i = l.First; i!=NULL; i=i->next){
		
		int check = 1;
		for(NODE*j = l.First; j!=NULL; j=j->next){
			
		   if(i->data % j->data != 0){
		   	  check = 0;
		   	  break;
		   }
		   
        }
        
        if(check == 1){
           a[k] = i->data;
           k++;
        }
    }
    
    int min = a[0];
    for (int h = 1; h < k; h++)
        if (min > a[i]){
            min = a[i];
        }
    }
    return min;
}*/

int KTSNT(int x){
	if(x < 2){
		return 0;
	}else{
		for(int i = 2; i <= sqrt(x); i++){
			if(x % i == 0){
				return 0;
			}
		}
		return 1;
	}
}

float TinhTBC(LIST l, int a, int b){
	NODE * i = l.First;     
	int sum = 0;
	int demsnt = 0;
	while(i != NULL){       
		if((KTSNT(i->data) == 1) && (a < i->data) && (i->data < b)){
			sum = sum + i->data;
			demsnt++;
			cout<<i->data<<"  ";
		}
		i = i -> next;
 	}
 	cout<<(float)sum/demsnt;
 	return float(sum/demsnt);
}

int MaxSNT(LIST l){
	NODE * i = l.First;   
	int max = INT_MIN;
	while(i != NULL){ 
		if(KTSNT(i->data) == 1 && i->data > max){
			max = i->data;
		}      
		i = i->next;
 	}
 	return max;
}

int main(){
	
	
    NODE * p;
    LIST l;
    
    Creat_List(l,p);
    ShowList(l);
    
//    int maxs = MaxSNT(l);
//    cout<<"\n"<<maxs;
    
   /* NODE*nut = Create_Node();
    
    Insert_After(l,nut);*/
    
    //DeleteNode(l,2);
    
   /* NODE*q = Create_Node();
    
    ChenNode(l, q);*/
   /* int a;
    cout<<"\nNhap a: ";
    cin>>a;
    
    Timsohoanhaonhohona(l, a);*/
   // cout<<Timsobenhatchiahetchotatcacacnut(l);
    
    /*ShowList(l);*/
    
    /*cout<<endl;
    float s = TinhTBC(l, 1, 8);
    cout<<s;*/
    
    deletelist(l);

	return 0;	
}


