#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int arr[1001];
vector<pair<int, int>> v;
int N;
bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.second > b.second)
		return true;
	return false;
}

int main(void)
{
	cin >> N;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N; i++)
	{
		int d, w;
		cin >> d >> w;
		v.push_back(make_pair(d, w));
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < N; i++)
	{
		for (int j = v[i].first; j > 0; j--)
		{
			if (arr[j] == 0)
			{
				arr[j] = v[i].second;
				break;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= 1000; i++)
		res += arr[i];
	cout << res;
}