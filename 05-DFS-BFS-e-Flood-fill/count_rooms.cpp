#include <iostream>
#define MAX 1003
using namespace std;

int n, m;
char grid[MAX][MAX];
bool visited[MAX][MAX];

void floodfill(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	if (grid[i][j] != '.' || visited[i][j])
		return;
	visited[i][j] = true;
	floodfill(i, j + 1);
	floodfill(i, j - 1);
	floodfill(i + 1, j);
	floodfill(i - 1, j);
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == '.' && !visited[i][j])
			{
				floodfill(i, j);
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}