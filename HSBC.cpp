/*
Q1 贪心算法：相邻房子的最远距离
[input]
    5 2
    3 7
    1 9
    2 0
    5 15
    4 30
[output]
    4 5

Q2 DFS： 岛屿的数量
[input]
    5 5
    0 0 0 0 0 
    0 1 1 0 0
    0 0 1 1 0
    0 0 0 0 0
    0 0 0 0 0
[output]
    1
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> largestLand (vector<vector<int> > houses)
{
    vector<int> answer(2, 0);
	if (!houses.size()) return answer;
	sort(houses.begin(), houses.end(), [](vector<int> & a, vector<int> & b){
		return a[1] < b[1];
	});

	int prev = 0, cur = 1;
	int max = houses[cur][1] - houses[prev][1];
    answer[0] = prev;
	answer[1] = cur;
    for (int i = cur + 1; i < houses.size(); i++)
	{
		prev = cur;
		cur = i;
		int temp = houses[cur][1] - houses[prev][1];
		if (temp > max)
		{
			max = temp;
			answer[0] = houses[prev][0];
			answer[1] = houses[cur][0];
		}
	}
    sort(answer.begin(), answer.end());
    return answer;
}

void dfs(vector<vector<int> > & grid, int m, int n)
{
	if (m < 0 || m >= grid.size()) return;
	if (n < 0 || n >= grid[0].size()) return;
	if (grid[m][n] == 1) 
	{
		grid[m][n] = 2;
		dfs(grid, m - 1, n);
		dfs(grid, m + 1, n);
		dfs(grid, m, n - 1);
		dfs(grid, m, n + 1);
	}
}

int countHouses (vector<vector<int> > grid)
{
    int answer = 0;
	if (grid.empty() || grid[0].empty()) return answer;
	int m = grid.size(), n = grid[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
			{
				answer += 1;
				dfs(grid, i, j);
			}
		}
	}
    
    return answer;
}

void q1()
{
	int houses_row;
	int houses_col;
	cin >> houses_row;
	cin >> houses_col;
	
	vector<vector<int> > houses;
	for ( int idx = 0; idx < houses_row; idx++ )
	{
		vector<int> temp_vector;
		for ( int jdx = 0; jdx < houses_col; jdx++ )
		{
			int temp;
			cin >> temp;
			temp_vector.push_back(temp);
		}
		houses.push_back(temp_vector);
	}
	
    //output
	vector<int> result = largestLand(houses);
	for ( int idx = 0; idx < result.size() - 1; idx++ )
	{
		cout << result[idx] << " ";
	}
	cout << result[result.size() - 1];
}

void q2()
{
    //input for grid
	int grid_row;
	int grid_col;
	cin >> grid_row;
	cin >> grid_col;
	
	vector<vector<int> > grid;
	for ( int idx = 0; idx < grid_row; idx++ )
	{
		vector<int> temp_vector;
		for ( int jdx = 0; jdx < grid_col; jdx++ )
		{
			int temp;
			cin >> temp;
			temp_vector.push_back(temp);
		}
		grid.push_back(temp_vector);
	}
	
	
    int result = countHouses(grid);
	cout << result;
}

int main()
{
    q1();
    q2();
}

