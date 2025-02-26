#include<iostream>
using namespace std;

long long GiaiThua(int n)
{
	if(n == 1 || n == 0) return 1;
	return n * GiaiThua(n-1);
}

long long ChinhHop(int n, int k)
{
	return GiaiThua(n) / (GiaiThua(n - k)); 
}

long long ToHop(int n, int k)
{
	return GiaiThua(n) / (GiaiThua(k)*GiaiThua(n - k));
}

int main()
{
	int n, k;
	cin >> n;
	cout << n <<"! = " << GiaiThua(n) << endl;
	cin >> k;
	cout <<"Chinh hop chap " << k << " cua "<< n <<": " << ChinhHop(n,k);
	cout <<"To hop chap " << k << " cua "<< n <<": " << ChinhHop(n,k);
}
