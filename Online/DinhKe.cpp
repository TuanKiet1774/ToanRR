#include <iostream>
#define MAX 100
using namespace std;
            
int main() 
{
    int G[MAX][MAX];
    int n;
	//cout <<"So dinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    int kq[MAX];
    int k = 0;
    int u;
    //cout << "Nhap dinh u: ";
    cin >> u;
    for(int v = 0; v < n; v++)
    	if(G[u][v] != 0)
	    kq[k++] = v;
    		
    if(k != 0)
    {
    	//cout << "Cac dinh ke voi dinh " << u << ": ";
    	for(int i = 0; i < k; i++)
    		cout << kq[i] <<" ";
    }
    else 
	cout << "none";
}

//Ví dụ:
// So dinh: 4
// 0 1 0 0
// 1 0 1 1
// 0 1 0 0
// 0 1 0 0
// Nhap dinh u: 2
// Cac dinh ke voi dinh 2: 1
