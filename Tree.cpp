#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct NODE {
    int data; 
	NODE* left;
	NODE* right;	
};
typedef struct NODE Node;
typedef Node * Tree;


void Initialize_tree(Tree &root){    
	root = NULL;
}

int Tree_IsEmpty(Tree root){   
	if(root == NULL)            //Neu cay rong -> tra ve 0
	   return 0;
	return 1;
}

void InsertNode(Tree &root, int x){
	if(Tree_IsEmpty(root) == 0){       //Neu cay rong   
	   Node * p = new Node;	           //Tao node moi
	   p->data = x;
	   p->left = p->right = NULL;
	   root = p;                       //Neu cay rong thi node moi vao cay
	}
	
	else{                              //Neu cay da co phan tu
	   if(root->data > x){             
	   	  InsertNode(root->left, x);
	   }
	   else if(root->data <= x){
	      InsertNode(root->right, x);
	   }
	}
}



void CreateTree(Tree &root) { 
    int n, x;
	cout<<"Nhap so luong node can them vao cay: ";
	cin>>n;
	
    for(int i=1; i<=n;i++){
    	cout<<"Nhap data: ";
    	cin>>x;
    	
    	InsertNode(root, x);
    }
}

void LNR(Tree &root){            //6 ph�p duyet c�y
	if(root != NULL){
		LNR(root->left);
		cout<<root->data<<" ";
		LNR(root->right);
	}
}

void RNL(Tree &root){            
	if(root != NULL){
		RNL(root->right);
		cout<<root->data<<" ";
		RNL(root->left);
	}
}

void NLR(Tree &root){            
	if(root != NULL){
		cout<<root->data<<" ";
		NLR(root->left);
		NLR(root->right);
	}
}

void NRL(Tree &root){            
	if(root != NULL){
		cout<<root->data<<" ";
		NRL(root->right);
		NRL(root->left);
	}
}

void LRN(Tree &root){            
	if(root != NULL){
		LRN(root->left);
		LRN(root->right);
		cout<<root->data<<" ";
	}
}

void RLN(Tree &root){            
	if(root != NULL){
		RLN(root->right);
		RLN(root->left);
		cout<<root->data<<" ";
	}
}

int SearchNode(Tree root, int x){          
    if(root != NULL){
	   
	   if(root->data == x){
	   	  return 1;
	   }
	   else if(root->data > x){
	   	  return SearchNode(root->left, x);
	   }
	   else{
	   	  return SearchNode(root->right, x);
	   }
	   
	}	
	return 0;
}

void SearchNodeLa(Tree root){         //Tim nhung node la node l�
	if(root != NULL){
		
	   if(root->left == NULL && root->right == NULL ){
	   	  cout<<root->data<<" ";
	   }
	   	  SearchNodeLa(root->left);
	   	  SearchNodeLa(root->right);
	  
	}
}

int SHH(int x){
	int s = 0;
	for(int i = 1; i < x; i++){
		if(x % i == 0){
			s = s + i;
		}
	}
	if(s == x) {
		return 1;
	}
	return 0;
}

void SearchNodeMotCon(Tree root){       
	if(root != NULL){
		
	    if( (root->left == NULL && root->right != NULL) || 
	       (root->left != NULL && root->right == NULL)){
	       	
	   	    if(SHH(root->data) == 1){
	   	  	  cout<<root->data<<" ";
	   	  	  return;
	   	    }
	   	  
	    }
	   	SearchNodeMotCon(root->left);
	   	SearchNodeMotCon(root->right);
	 
	}
}

void SearchNodeHaiCon(Tree root){        //Tim nhung node co 2 con
	if(root != NULL){
		
	   if((root->left != NULL) && (root->right != NULL)){
	   	  cout<<root->data<<" ";
	   }
	   	  SearchNodeHaiCon(root->left);
	   	  SearchNodeHaiCon(root->right);
	   
	}
}

void DelNodeLa(Tree &root, int x){      //Xoa node la
	if(root == NULL){
	   return;
	}
	
	else{

	   if(root->data > x){
	   	  DelNodeLa(root->left, x);
	   }
	   else if(root->data < x){
	   	  DelNodeLa(root->right, x);
	   }
	   else{
	   	  if(root->left == NULL && root->right == NULL){
	   	  	 Node * temp = root;
	   	  	 root = NULL;
	   	  	 delete temp;
	   	  }
	   }
	}	
}

void DelNodeMotCon(Tree &root, int x){      //Xoa node 1 con
	if(root == NULL){
	   return;
	}
	
	else{

	   if(root->data > x){
	   	  DelNodeMotCon(root->left, x);
	   }
	   else if(root->data < x){
	   	  DelNodeMotCon(root->right, x);
	   }
	   else{
	   	  Node * temp = root;
	   	  
	   	  if(root->left == NULL){
	   	  	 root = root->right;
	   	  }
	   	  else if(root->right == NULL){
	   	  	 root = root->left;
	   	  }
	   	  
	   	  delete temp;
	   }
	}	
}


void searchStandFor(Node *&temp, Node *&q){	    
	
	if(q->left){
		searchStandFor(temp, q->left);
	}
	else{ 
		temp->data = q->data;
		temp = q;
		q = q->right;
	} 

}

void DelNode(Tree &root, int x){       
	if(root == NULL){
	   return;
	}
	
	else{

	   if(root->data > x){
	   	  DelNode(root->left, x);
	   }
	   else if(root->data < x){
	   	  DelNode(root->right, x);
	   }
	   else{
	   	
	   	    Node* temp = root;
			if(root->left == NULL){
			   root = root->right;
			}
			else{
				if(root->right == NULL) {
				   root = root->left;
				}
				else {
				   searchStandFor(temp, root->right);
				}
		    }
		    
	   }
	}	
}

void DuyetCayLNR(Tree root, string &temp){
	if(root != NULL){
		DuyetCayLNR(root->left, temp);
		
		stringstream ss;
		ss<<root->data;
		string temp1 = ss.str();
		temp = temp + temp1 + " ";
		
		DuyetCayLNR(root->right, temp);
	}
}

void KiemTraBST(string temp){
	int dodaichuoi = temp.size() + 1;
	char * c = new char[dodaichuoi];
	copy(temp.begin() , temp.end() , c);
	c[dodaichuoi - 1] = '\0';
	

	char * w = strtok(c, " ");
	int r = atoi(w);
	
	int i = 0, check = 0;
	while(1){
		
		w = strtok(NULL, " ");
		if(w == NULL){
			break;
		}
		
		if( r <= atoi(w)){
			r = atoi(w);
		}else{
			check = 1;
			break;
		}
		
	}
	
	if(check == 0){
		cout<<"\nDay la cay BST!!!";
	}else{
		cout<<"\nDay ko la cay BST!!!";
	}
}


void removeTree(Tree &root){             //Huy toan bo cay
	if(root) {
		removeTree(root->left);
		removeTree(root->right);
		delete(root);
	}
}





int main(){
	
	//cout<<SHH(6);
	Tree root;
	
	Initialize_tree(root);
	
	CreateTree(root);
	
	/*LNR(root);
	cout<<endl;
	*/
	
	
	LNR(root);	
	
	DelNode(root, 12);
	cout<<endl;
	RNL(root);
	
	removeTree(root);

//Code xo� node 2 con th� he qua cua n� c� the xoa node 1 con hoac node la luon
//---> ket luan: de bai keu xoa node m� ko noi xoa node may con thi cu quat thang xoa node 2 con la duoc
	
	return 0;
}










































