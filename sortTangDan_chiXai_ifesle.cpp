#include <iostream>
using namespace std;

int main(){
	int a = 1, b = 8, c = 0, d = 3;
	
	int max = a;                              //Tim max
	if(max < b) max = b;
	if(max < c) max = c;
	if(max < d) max = d;
	
	int max2 = a;                             //Tim max2 khi da co max
	if((max2 < b)&&(b < max)) max2 = b;
	if((max2 < c)&&(c < max)) max2 = c;
	if((max2 < d)&&(d < max)) max2 = d;
	
	int min = a;                              //Tim min
	if(min > b) min = b;
	if(min > c) min = c;
	if(min > d) min = d;
	
	int max3 = a;                             //Tim max3 khi da co max2 va min
	if((min < b)&&(b < max2)) max3 = b;
	if((min < c)&&(c < max2)) max3 = c;
	if((min < d)&&(d < max2)) max3 = d;
	
	cout<<max<<" ";
	cout<<max2<<" ";
	cout<<max3<<" ";
    cout<<min<<" ";
	return 0;	
}
