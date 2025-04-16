#include <iostream>
#include <stack>
#include <algorithm> 
using namespace std;

int G[100][100];
bool tham[100];
int cha[100];
int n;


void DFS(int S) 
{
    stack<int> stk;
    stk.push(S);

    for (int i = 0; i < n; i++) 
	{
        tham[i] = false; 
        cha[i] = -1;
    }

    while (!stk.empty()) 
	{
        int u = stk.top();
        stk.pop();

        if (!tham[u]) 
		{
            tham[u] = true;
            for(int v = n - 1; v >= 0; v--) 
			{
                if (G[u][v] && !tham[v]) 
				{
                    stk.push(v);
                    if (cha[v] == -1) cha[v] = u;
                }
            }
        }
    }
}

void findWay(int S, int T, int kq[], int k) {
    DFS(S);

    if (!tham[T]) cout << "Khong tim thay duong di tu " << S << " den " << T << ".\n";
    else
    {
    	int ht = T;
	    while (ht != -1) 
		{
	        kq[k++] = ht;
	        ht = cha[ht];
	    }
	
	    reverse(kq, kq + k);
	    
	    cout << "Duong di tu " << S << " den " << T << " la: ";
	    for (int i = 0; i < k; i++)
	        cout << kq[i] << " ";
	    cout << endl;
	}
		
}

int main() 
{
	int S, T;
    int kq[100];
    int k = 0;

    cout << "Dinh: ";
    cin >> n;

    cout << "Nhap ma tran ke (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    
    cout << "Nhap S: ";
    cin >> S;
    cout << "Nhap T: ";
    cin >> T;
	
	findWay(S,T,kq,k);
}

