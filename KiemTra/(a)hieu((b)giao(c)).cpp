#include<iostream>
#include<algorithm>
#include<string.h>
#define max 1000
using namespace std;

int checkAinB(string pt, string b[max], int m)
{
	for(int i = 0; i<m; i++)
		if(b[i] == pt) return 1;
	return 0;
}

int AgiaoB(string a[max], int n, string b[max], int m, string kq[max])
{
	int k=0;
	for(int i = 0; i<n; i++)
		if(checkAinB(a[i],b,m)) 
			kq[k++] = a[i];
			
	if(k != 0) 
		sort(kq,kq+k);
	return k;
}

void Hieu(string a[max], int n, string b[max], int m, string kq[max]) 
{
    int k = 0;
    for (int i = 0; i < n; i++) 
	if (!checkAinB(a[i], b, m)) 
        	kq[k++] = a[i];
        	
    if (k == 0) 
	cout << "none";
    else 
    {
       	sort(kq, kq + k); 
       	for (int i = 0; i < k; i++) 
	{
		if(i == k-1) cout << kq[i];
		else cout << kq[i] << " ";
        }
    }
}

int main()
{
	string a[max], b[max], c[max], giao[max], hieu[max];
	int n, m, x;
	cout << "Nhap n: "; cin >> n;
	for (int i = 0; i < n; i++) 
	cin >> a[i];
	
	cout << "Nhap m: "; cin >> m;
	for (int i = 0; i < m; i++) 
	cin >> b[i];
	
	cout << "Nhap x: "; cin >> x;
	for (int i = 0; i < x; i++) 
	cin >> c[i];
    
	int k = AgiaoB(b,m,c,x,giao);
	Hieu(a,n,giao,k,hieu);
}
//(a)hieu((b)giao(c))
