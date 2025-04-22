#include <iostream>
#include <algorithm>
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
    	sort(kq, kq + k);
    	//cout << "Cac dinh ke voi dinh " << u << ": ";
    	for(int i = 0; i < k; i++)
    		cout << kq[i] <<" ";
	}
	else 
		cout << "none";
}
