#include<iostream>
#include<climits>
using namespace std;

int n;
int G[100][100];
int truoc[100];
int d[100];
bool tham[100];
int vc = INT_MAX;

void Dijkstra(int G[100][100], int s)
{
    for (int i = 0; i < n; i++) {
        if (G[s][i] == 0 && s != i) d[i] = vc;
        else d[i] = G[s][i];

        if (G[s][i] < vc && s != i) truoc[i] = s;
        else truoc[i] = -1;

        tham[i] = false;
    }

    d[s] = 0;
    tham[s] = true;

    for (int i = 1; i < n; i++) {
        int u = -1, Min = vc;
        for (int j = 0; j < n; j++) {
            if (!tham[j] && d[j] < Min) {
                Min = d[j];
                u = j;
            }
        }

        if (u == -1) break;
        tham[u] = true;

        for (int v = 0; v < n; v++) {
            if (!tham[v] && G[u][v] != 0 && G[u][v] < vc && d[u] != vc && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
                truoc[v] = u;
            }
        }
    }
}

void InDuong(int s, int v)
{
    if (v == s) {
        cout << s;
        return;
    }
    if (truoc[v] == -1) {
        cout << "none";
        return;
    }
    InDuong(s, truoc[v]);
    cout << "->" << v;
}

int main()
{
    int s;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
//            if (G[i][j] == 0 && i != j)
//                G[i][j] = vc;  // Không có c?nh thì gán b?ng vô c?c
        }

    cin >> s;
    Dijkstra(G, s);

    for (int i = 0; i < n; i++) 
	{
        if (d[i] != vc)
        {
        	cout << i << "|";
            cout << d[i] << "|";
            InDuong(s, i);
            cout << endl;
        }
    }
}

