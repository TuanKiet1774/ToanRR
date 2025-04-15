//Tính số cạnh của đồ thị
//Nếu đồ thị vô hướng thì ==> Số cạnh = (Tổng số cạnh - Số cạnh khuyên) / 2 + Số cạnh khuyên
//Nếu đồ thị có hướng thì ==> Số cạnh = Tổng số cạnh 
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

void SoCanh(int a[][100], int n)
{	
	int tong = 0, ck = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
		{
			tong += a[i][j];
			if(i == j) ck += a[i][j];
		}
		
	if(checkGraph(a, n))
		cout << (tong - ck)/2 + ck;
	else
		cout << tong;
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

	SoCanh(a,n);	
}
