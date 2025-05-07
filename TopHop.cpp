//To hop chap k cua n
#include <iostream>
#include <string>

using namespace std;

void DaoChuoi(string &s) 
{
    int l = 0;
    int r = s.size() - 1;
    while (l < r) 
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

string Nhan(string n1, int n2) 
{
    string kq = "";
    int du = 0;
    
    for (int i = n1.size() - 1; i >= 0; i--) 
    {
        int m = (n1[i] - '0') * n2 + du;
        kq += (m % 10) + '0';
        du = m / 10;
    }
    
    while (du) 
	{
        kq += (du % 10) + '0';
        du /= 10;
    }
    
    DaoChuoi(kq);
    return kq;
}

string ChinhHop(int n, int k) 
{
    string kq = "1";
    for (int i = 0; i < k; i++) 
	kq = Nhan(kq, n - i);
    return kq;
}

string Chia(string n1, int n2) 
{
    string kq = "";
    int du = 0;
    
    for (int i = 0; i < n1.size(); i++) 
    {
        du = du * 10 + (n1[i] - '0');
        kq += (du / n2) + '0';
        du %= n2;
    }
    
    while (kq.size() > 1 && kq[0] == '0') 
	kq.erase(0, 1); //Xóa 1 ký tự tại vị trí 0, tức là loại bỏ ký tự '0' đầu tiên của chuỗi
    return kq;
}

string ToHop(int n, int k)
{
    string kq = ChinhHop(n, k);
    for (int i = 2; i <= k; i++) 
	kq = Chia(kq, i);
    return kq;
}


int main() 
{
    int n, k;
    cin >> n >> k;
    
    if (k > n || n < 0 || k < 0) 
	cout << "none"; 
    else 
	cout << ToHop(n, k);
}
