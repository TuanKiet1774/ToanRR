#include<iostream>
using namespace std;

void Nhap(int a[], int n)
{
	if(n != 0)
	{
		cout << "Nhap mang: ";
		for(int i = 0; i<n; i++)
			cin >> a[i];
	}
}

void Descartes(int a[], int n, int b[], int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << "(" << a[i] <<","<< b[j] << ") ";
		cout << endl;
	}
}

int main()
{
	int a[100], b[100];
	int n, m;
	
	cout << "Tap A: ";
	cin >> n;
	Nhap(a,n);
	cout << "Tap B: ";
	cin >> m;
	Nhap(b,m);
	
	cout << "Tich Descartes cua A va B: " << endl;
	Descartes(a,n,b,m);
}
