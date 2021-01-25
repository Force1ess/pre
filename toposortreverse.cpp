#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
const int maxn = 30100;
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		_asm{
			mov eax, dword ptr[n]
			add eax, 40
			mov dword ptr[n], eax
		}
		cout << n << " " << m << endl;
	}
}
//HDU和POJ一定要用scanf