/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(vector<string>& mat, int n, int row, int col)
    {
        // col
        for (int i = 0; i < row; i++)
        {
            if (mat[i][col] == 'Q') return false;
        }
        for (int i = -n; i <= n; i++)
        {
            // 45
            int r = row - i, c = col + i;
            if (r >= 0 && r < n && c >= 0 && c < n)
            {
                if (mat[r][c] == 'Q') return false;
            }
            // 135
            r = row + i, c = col + i;
            if (r >= 0 && r < n && c >= 0 && c < n)
            {
                if (mat[r][c] == 'Q') return false;
            }
        }
        return true;
    }
    void backTrace(vector<vector<string> >& results, vector<string>& mat, int n, int row,
             vector<int> &column,  vector<int>& r_dia, vector<int>& l_dia)
    {
        if (row == n) 
        {
            results.push_back(mat);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            //if(isValid(mat, n, row, col))
            if (column[col] || r_dia[row + col] || l_dia[n - 1 - row + col])
            {
                continue;
            }
            mat[row][col] = 'Q';
            column[col] = r_dia[row + col] = l_dia[n - 1 - row + col] = 1;
            backTrace(results, mat, n, row + 1, column, r_dia, l_dia);
            mat[row][col] = '.';
            column[col] = r_dia[row + col] = l_dia[n - 1 - row + col] = 0;
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        if (!n) return results;
        vector<string> mat(n, string(n, '.'));
        vector<int> column(n, 0);
        vector<int> r_dia(2 * n - 1, 0);
        vector<int> l_dia(2 * n - 1, 0);
        backTrace(results, mat, n, 0, column, r_dia, l_dia);
        return results;
    }

        
    void traceback( 
        vector<vector<string> >& result, 
        vector<string>& mat, 
        int row, 
        int n, 
        vector<int>& column, 
        vector<int>& left_dia, 
        vector<int>& right_dia)
    {   
        if (row == n) 
        {
            result.push_back(mat);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (!(column[col] || right_dia[col + row] || left_dia[n - 1 - row + col]))
            {
                mat[row][col] = 'Q';
                column[col] = right_dia[col + row] = left_dia[n - 1 - row + col] = 1;
                
                traceback(result, mat, row + 1, n, column, left_dia, right_dia);

                mat[row][col] = '.';
                column[col] = right_dia[col + row] = left_dia[n - 1 - row + col] = 0;
            }
        }
    }
    vector<vector<string> > solveNQueens_(int n) {
        vector<vector<string> > result;
        if (n < 1) return result;
        vector<string> mat(n, string(n, '.'));

        vector<int> column(n, 0);
        vector<int> left_dia(2 * n - 1, 0);
        vector<int> right_dia(2 * n - 1, 0);
        traceback(result, mat, 0, n, column, left_dia, right_dia);
    }

};
// @lc code=end

