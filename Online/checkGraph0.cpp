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
		cout << "vo_huong";
	else cout << "co_huong";
}

//Khong doi xung => Co huong
//Doi xung => Vo huong
