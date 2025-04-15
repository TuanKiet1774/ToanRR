//Liệt kê bán bậc hoặc bậc của từng đỉnh
//Nếu đồ thị vô hướng thì số bậc = số cạnh
//Nêu đồ thị có hướng thì:
//+ Số bậc ra = Số cạnh từ đỉnh đó đi ra đỉnh khác
//+ Số bậc vào = Số cạnh từ đỉnh khác đi vào đỉnh đó
#include<iostream>
using namespace std;

int checkGraph(int a[][100], int n)
{
	int flag = 1;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(a[i][j] != a[j][i])
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

void Bac(int a[][100], int n)
{
	for(int i = 0; i<n; i++)
	{
		int kq = 0;
		for(int j = 0; j<n; j++)
			kq += a[i][j];
		cout << kq;
		if(i != n - 1) cout << ";";	
	}
}

void BacRaVao(int a[][100], int n)
{
	for(int i = 0; i<n; i++)
	{
		int bbr = 0;
		for(int j = 0; j<n; j++)
			bbr += a[i][j];
		cout << bbr;
		if(i != n - 1) cout << ";";	
	}
	
	cout << endl;
	
	for(int i = 0; i<n; i++)
	{
		int bbv = 0;
		for(int j = 0; j<n; j++)
			bbv += a[j][i];
		cout << bbv;
		if(i != n - 1) cout << ";";	
	}	
}

int main()
{
	int a[100][100];
	int n;
	//cout << "Nhap n: ";
	cin >> n;
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin >> a[i][j];
	
	if(checkGraph(a,n) == 1)
		Bac(a,n);
	else BacRaVao(a,n);
}
