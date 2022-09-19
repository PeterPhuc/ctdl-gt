#include <iostream>
using namespace std;

//int reverseNumber(int k){
//	int div = 0;
//	while(k > 0){
//		div = (k % 10) + div*10;
//		k = (int)k/10;
//	}
//	return div;
//}

float TinhTong(int N){
	float s = 0;
	for(int i = 0; i <= N; i++){
		s += (float)1/(2*i + 1);
	}
	return s;
}

float TinhTongDeQuy(int N){
	if(N == 0) return 1;
	return TinhTongDeQuy(N-1) + (float)1/(2*N + 1);
}

int main(){
//	int a, *b;
//	a = 10;
//	b = &a;
//	cout<<a<<endl;
//	cout<<b<<endl;
//	cout<<*b<<endl;
//	
//	*b = 30;
//	cout<<a<<endl;
//	cout<<*b<<endl;
//	
//	return 0;	

//	int N;
//	cout<<"Nhap so N: ";
//	cin>>N;
//	
//	if(N >= 0) cout<<reverseNumber(N);
//	else cout<<-1*reverseNumber(-1*N);

	int N;
	do {
		cout<<"Nhap so N: ";
		cin>>N;
	}while(N < 0);
	
	cout<<TinhTong(N)<<endl;
	cout<<TinhTongDeQuy(N);
	return 0;
}































