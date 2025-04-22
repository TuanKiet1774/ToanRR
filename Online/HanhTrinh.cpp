#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

int G[MAX][MAX];           
int n;               

int DemHanhTrinh(int start, int end, int k) 
{
    if (k == 0) {
    	if(start == end) 
		return 1;
    	else 
		return 0;
    }

    int dem = 0;
    for (int v = 0; v < n; v++) {
        if (G[start][v]) 
		dem += DemHanhTrinh(v, end, k - 1);
    }
    return dem;
}


int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    int k, start, end;
    //cout << "Do dai hanh trinh k = ";
    cin >> k;
    //cout << "Dinh bat dau: ";
    cin >> start;
    //cout << "Dinh ket thuc: ";
    cin >> end;
    cout << DemHanhTrinh(start, end, k);
}
//Ví dụ:
// 2
// 1 1 1 0
// 1 0 1
//kết quả: 1
