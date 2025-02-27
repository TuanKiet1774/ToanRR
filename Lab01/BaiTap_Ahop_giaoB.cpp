#include<iostream>
#include <algorithm>
#define max 1000
using namespace std;

int checkAinB(int pt, int b[max], int m)
{
	for(int i = 0; i<m; i++)
		if(b[i] == pt) return 1;
	return 0;
}

void Nhap(int a[max], int n)
{
	if(n != 0)
	{
		for(int i = 0; i<n; i++)
			do cin >> a[i];
			while (checkAinB(a[i],a,i));
	}
}
 
void Xuat(int a[max], int n)
{
	for(int i = 0; i<n; i++)
	{
		if(i == n - 1) cout << a[i];
		else cout << a[i] << " "; 
	}
}

void AgiaoB(int a[max], int n, int b[max], int m)
{
	int kq[max], k=0;
	for(int i = 0; i<n; i++)
		if(checkAinB(a[i],b,m)) kq[k++] = a[i];
			
	if(k != 0) 
	{
		sort(kq,kq+k);
		Xuat(kq,k);
	}
	else cout << "none";
}

void AhopB(int a[max], int n, int b[max], int m)
{
	int kq[max], k = 0;
	for(int i = 0; i < n; i++)
		if(checkAinB(a[i],kq,k) == 0)
			kq[k++] = a[i];
	
	for(int i = 0; i < m; i++)
		if(checkAinB(b[i],kq,k) == 0)
			kq[k++] = b[i];
	if(k != 0)
	{
		sort(kq,kq+k);
		Xuat(kq,k);
	}
	else cout << "none";
}

int main()
{
	int a[max], b[max], n, m;
	cin >> n;
	Nhap(a,n);
	cin >> m;
	Nhap(b,m);
	
	AgiaoB(a,n,b,m);
	cout << endl;
	AhopB(a,n,b,m);
}
