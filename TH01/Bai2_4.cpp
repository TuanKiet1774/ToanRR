#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int z = 0; z < n; z++)
			{
				if(i + j + z == n) 
					cout << i << " " << j << " " << z << endl; 
			}
		}
	}	
}
