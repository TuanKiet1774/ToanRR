#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

int a[MAX][MAX];
bool tham[MAX];     
int n;

void DFS(int S, int a[MAX][MAX]) {
    stack<int> stk;
    stk.push(S);

    for (int i = 0; i < n; i++) 
        tham[i] = false;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        if (!tham[u]) {
            tham[u] = true;

            for (int v = n - 1; v >= 0; v--) {
                if (a[u][v] && !tham[v]) {
                    stk.push(v);
                }
            }
        }
    }
}

int check_LienThong(int a[MAX][MAX]) {
    DFS(0, a);  
    for (int i = 0; i < n; i++) {
        if (!tham[i]) return 0;  
    }

    int ngc[MAX][MAX];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ngc[i][j] = a[j][i];  

    DFS(0, ngc); 
    for (int i = 0; i < n; i++) {
        if (!tham[i]) return 0;  
    }

    return 1; 
}

int checkGraph(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != a[j][i])
                return 0; // Có 
    return 1; // Vô 
}

int checkEuler(int a[MAX][MAX], int n) {
    int isVoHuong = checkGraph(a, n);
    
    int soCanh = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) soCanh++;
    if (soCanh == 0) return 0;
    
    if (isVoHuong) {
        if (!check_LienThong(a)) return 0;

        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++)
                degree += a[i][j];
            if (degree % 2 != 0) return 0;
        }
        return 1;
    } 
	else {
        if (!check_LienThong(a)) return 0;

        for (int i = 0; i < n; i++) {
            int inDegree = 0, outDegree = 0;
            for (int j = 0; j < n; j++) {
                outDegree += a[i][j];
                inDegree += a[j][i];
            }
            if (inDegree != outDegree) return 0;
        }
        return 1;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    if (checkEuler(a, n))
        cout << "do_thi_Euler";
    else 
        cout << "khong_phai_do_thi_Euler";
}
