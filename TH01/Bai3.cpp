#include<iostream>
using namespace std;

long long GiaiThua(int n)
{
	if(n == 1 || n == 0)
	return 1;
	return n * GiaiThua(n-1);	
}

int main()
{
	int k;
	int x1, x2, x3, x4;
	cout << "x1 + x2 + x3 + x4 = ";
	cin >> k;
	cout << "x1 >= "; cin >> x1;
	cout << "x2 >= "; cin >> x2;
	cout << "x3 >= "; cin >> x3;	
	cout << "x4 >= "; cin >> x4;
	
	k = k - x1 - x2 - x3 - x4;
	cout << k << endl;
	
	long long kq = GiaiThua(k + 4 - 1) / (GiaiThua(k) * GiaiThua(4 - 1)); 
	cout << "So nghiem khong am: " <<  kq;
}
