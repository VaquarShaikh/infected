#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

// 3 4
// 1 0 2 4
// 5 6 7 8
// 9 10 11 12

void markRows(vector<vector<int>> &matrix, int row, int col, int val = -100)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (matrix[0][j] == 0)
                {
                    matrix[i][0] = val;
                }
                else if (matrix[i][0] == 0)
                {
                    matrix[0][j] = val;
                }
                else
                {
                    matrix[i][0] = val;
                    matrix[0][j] = val;
                }
            }
        }
    }
}

void setRows(vector<vector<int>> &matrix, int row, int col, int val = -100)
{
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == val)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] != 0)
                {
                    matrix[i][j] = val;
                }
            }
        }
    }
}

// void markRows(vector<vector<int>> &matrix, int row, int col, int val = -100)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if (matrix[i][0] == 0)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 if (matrix[i][j] != 0)
//                     matrix[i][j] = val;
//             }
//         }
//     }
// }

// void makeColZeros(vector<vector<int>> &matrix, int row, int col)
// {
//     for (int j = 0; j < col; j++)
//     {
//         if (matrix[0][j] == 0)
//         {
//             for (int i = 0; i < row; i++)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

void setZeros(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    markRows(matrix, rows, cols);
    cout << endl
         << "Marked matrix : " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    setRows(matrix, rows, cols);
    cout << endl
         << "Row zero matrix : " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // makeColZeros(matrix, rows, cols);
}

int main()
{
    // cout << "Hello world !";

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> rowInput;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            rowInput.push_back(temp);
        }
        matrix.push_back(rowInput);
    }
    setZeros(matrix);
    cout << endl;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}