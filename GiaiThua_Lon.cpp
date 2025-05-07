#include<iostream>
#include<string.h>
using namespace std;

void Nhan(char n1[], int n2, char kq[])
{
    int du = 0;
    int len = strlen(n1);
    char temp[1000] = {0};

    for (int i = 0; i < len; i++)
    {
        int m = (n1[i] - '0') * n2 + du;
        temp[i] = (m % 10) + '0';
        du = m / 10;
    }

    while (du > 0)
    {
        temp[len++] = (du % 10) + '0';
        du /= 10;
    }
    
    temp[len] = '\0'; 
    strcpy(kq, temp);
}


void GiaiThua(int n, char kq[])
{
    if (n == 0 || n == 1)
    {
        strcpy(kq, "1");
        return;
    }

    char temp[1000] = {0};
    GiaiThua(n - 1, temp);
    Nhan(temp, n, kq);
}

int main()
{
	int n;
	char kq[1000];
	cin >> n;
	GiaiThua(n,kq);
	
	int len = strlen(kq);
//	for (int i = 0; i < len; i++)
    for (int i = len - 1; i >= 0; i--)
        cout << kq[i]; 
}
