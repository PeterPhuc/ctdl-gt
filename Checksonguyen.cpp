#include <iostream>
using namespace std;

int isNumberCheck(char s[]){
	int i = 0;
	if(s[0] == '-' && s[1] == NULL){
		return 0;
	}
	if(s[0] == '-' && s[1] != NULL){
		i++;
	}
	while(s[i] != '\0'){
		if( (int)s[i] < 48 || 57 < (int)s[i] ) 
			return 0;
		i++;
	}
	return 1;
}

int main(){
	int getResult = isNumberCheck("2422a5");
	cout<<getResult;
	
	int arr[100] = {1,2,3,4,5,6,7};
	int i = 0;
	while(arr[i] != NULL){
		//cout<<arr[i]<<" ";
		i++;
	}
	cout<<"\n"<<i<<endl;
	if(arr[7] == NULL){
		cout<<"ok";
	}
	return 0;
}


























