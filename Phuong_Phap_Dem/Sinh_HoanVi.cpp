#include <iostream>
using namespace std;

int SinhHoanVi(int a[], int n)
{
    int j = n - 2;
    while (j >= 0 && a[j] > a[j + 1]) j--;
    if (j < 0) return 0;

    int k = n - 1;
    while (a[j] > a[k]) k--;
    swap(a[j], a[k]);

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
    int a[1000], n;
    cout << "Kich thuoc: "; cin >> n;
    cout << "Nhap day: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    do
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    } while (SinhHoanVi(a, n));

    return 0;
}

