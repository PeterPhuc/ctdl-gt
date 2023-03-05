#include <iostream>
using namespace std;

int main(){
	int a = 1, b = 7, c = 9, d = 0;
	
	int max = a;
	if(max < b) max = b;
	if(max < c) max = c;
	if(max < d) max = d;

	int min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	if(min > d) min = d;

	int max2 = min;
	if(max2 < a && a < max) max2 = a;
	if(max2 < b && b < max) max2 = b;
	if(max2 < c && c < max) max2 = c;
	if(max2 < d && d < max) max2 = d;

	int max3 = min;
	if(max3 < a && a < max2) max3 = a;
	if(max3 < b && b < max2) max3 = b;
	if(max3 < c && c < max2) max3 = c;
	if(max3 < d && d < max2) max3 = d;
	
	cout<<max<<" ";
	cout<<max2<<" ";
	cout<<max3<<" ";
    cout<<min<<" ";
	return 0;	
}
