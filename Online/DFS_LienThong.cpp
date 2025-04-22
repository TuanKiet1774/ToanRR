#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

int G[MAX][MAX];     
bool tham[MAX];            
int n;               

void DFS(int S) 
{
    stack<int> stk;
    stk.push(S);

    for (int i = 0; i < n; i++) 
	tham[i] = false;

    while (!stk.empty()){
        int u = stk.top();
        stk.pop();

        if (!tham[u]) {
            tham[u] = true;
            //cout << u << " ";

            for (int v = n - 1; v >= 0; v--) {
                if (G[u][v] && !tham[v]) {
                    stk.push(v);
                }
            }
        }
    }
}

int check_LienThong()
{
	DFS(0);
    bool flag = 1;
    for (int i = 0; i < n; i++) 
	{
        if (!tham[i]) 
		{
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    if (check_LienThong())
        cout << "lien thong";
    else
        cout << "khong lien thong";

}

