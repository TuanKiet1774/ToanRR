#include <iostream>
#include <algorithm> 
using namespace std;

int SinhHoanVi(int a[], int n) 
{
    int j = n - 2;
    while (j >= 0 && a[j] >= a[j + 1]) j--;
    if (j < 0) return false;

    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a[j], a[k]);

    //reverse(a + j + 1, a + n);
    int r = j + 1, s = n - 1;
    while (r < s)
    {
        swap(a[r], a[s]);
        r++;
        s--;
    }
    return 1;
}

int main() 
{
    int n;
    int a[1000];
    //cout << "Nhap n: ";
    cin >> n;    
    //cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    	//cin >> a[i];
        a[i] = i + 1;

    do 
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
            //cout << a[i] << " ";
        cout << endl;
    } while (SinhHoanVi(a, n));

}
//Ví dụ: n = 3
// 123
// 132
// 213
// 231
// 312
// 321
