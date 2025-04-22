#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int G[MAX][MAX];     
bool tham[MAX];      
int cha[MAX];        
int n;               

void BFS(int S) 
{
    queue<int> q;
    q.push(S);

    for (int i = 0; i < n; i++) 
    {
        tham[i] = false;
        cha[i] = -1;
    }

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        if (!tham[u]) 
        {
            tham[u] = true;
            cout << u << " ";

            for (int v = 0; v < n; v++) {
                if (G[u][v] && !tham[v]) {
                    q.push(v);
                    if (cha[v] == -1)
                        cha[v] = u;
                }
            }
        }
    }
}

int main() 
{
    cin >> n; 
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    int s;
    cin >> s; 

    BFS(s);
}

