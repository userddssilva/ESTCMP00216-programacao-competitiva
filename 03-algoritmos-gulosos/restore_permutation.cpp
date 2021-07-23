#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{

	long long t, n, p;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<long long> v(n * 2);
		vector<long long> o;

		for (int i = 0; i < n * 2; i++)
		{
			cin >> p;
			v[i] = p;
		}

		o.pb(v[0]);
		for (int i = 1; i < n * 2; i++)
		{
			long long cont = 0;
			for (int j = 0; j < o.size(); j++)
			{
				if (v[i] != o[j])
					cont++;
				else
					break;
				if (cont == o.size())
					o.pb(v[i]);
			}
			if (o.size() == n)
				break;
		}

		for (int i = 0; i < o.size(); i++)
		{
			cout << o[i] << " ";
		}
		cout << endl;
		o.clear(), v.clear();
	}

	return 0;
}