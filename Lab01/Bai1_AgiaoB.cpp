#include<iostream>
#define max 1000
using namespace std;

void Nhap(int a[max], int n)
{
	cout << "Nhap mang: ";
	for(int i = 0; i<n; i++)
		cin >> a[i];
}

void Xuat(int a[max], int n)
{
	for(int i = 0; i<n; i++)
		cout << a[i] << " ";
}

int checkAinB(int pt, int b[max], int m)
{
	for(int i = 0; i<m; i++)
		if(b[i] == pt) return 1;
	return 0;
}

void AgiaoB(int a[max], int n, int b[max], int m)
{
	int kq[max], k=0;
	for(int i = 0; i<n; i++)
		if(checkAinB(a[i],b,m)) 
			kq[k++] = a[i];
	if(k != 0)
	{
		cout << "A giao B: ";
		Xuat(kq,k);
	}
	else cout << "A giao B la tap rong";
}

int main()
{
	int a[max], b[max], n, m;
	cout << "Do dai mang A: ";
	cin >> n;
	Nhap(a,n);
	cout << "Do dai mang B: ";
	cin >> m;
	Nhap(b,m);
	
	AgiaoB(a,n,b,m);
}
