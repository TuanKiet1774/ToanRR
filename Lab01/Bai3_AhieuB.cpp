#include <iostream>
#include<string.h>
#include <algorithm> 
using namespace std;

bool Check(string a[], int n, string x) 
{
    for (int i = 0; i < n; i++) 
	if (a[i] == x) return true;
    return false;
}

void Hieu(string A[], int n, string B[], int m) 
{
    string kq[100];
    int k = 0;
    for (int i = 0; i < n; i++) 
	if (!Check(B, m, A[i])) 
        	kq[k++] = A[i];
        	
    if (k == 0) 
	cout << "none";
    else 
    {
       	sort(kq, kq + k); 
       	for (int i = 0; i < k; i++) 
	{
		if(i==k-1) cout << kq[i];
		else cout << kq[i] << " ";
        }
    }
}

int main() 
{
    int n, m;
    
    cin >> n;
    string A[100];
    for (int i = 0; i < n; i++) 
    	cin >> A[i];
    	
    cin >> m;
    string B[100];
    for (int i = 0; i < m; i++) 
    	cin >> B[i];
    	
    Hieu(A, n, B, m);
    return 0;
}
