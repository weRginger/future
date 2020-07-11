// A C++ program to find the largest subsquare
// surrounded by '1' in a given matrix of '0' and '1'
// different impl here at https://www.youtube.com/watch?v=vi_1eHCsR9A
#include<iostream>
using namespace std;

// Size of given matrix is N X N
#define N 6

bool isValid(int mat[N][N], int hor[N][N], int ver[N][N], int i, int j, int m) {
    int len = m - j;
    return mat[i][j] == 1 &&
           mat[i][m] == 1 &&
           mat[i + len][j] == 1 &&
           mat[i + len][m] == 1 &&
           hor[i + len][j] - hor[i][j] == len &&
           ver[i + len][m] - ver[i + len][j] == len &&
           hor[i + len][m] - hor[i][m] == len;
}

// Returns size of maximum size subsquare matrix surrounded by '1'
int findSubSquare(int mat[][N])
{
	int ans = 0; // Initialize result

	// Initialize the accumulative sum arrays in hor[][] and ver[][]
	int hor[N][N], ver[N][N];
	for (int i=0; i<N; i++) {
		for (int j = 0; j<N; j++) {
            ver[i][j] = (j == 0) ? mat[i][j] : ver[i][j - 1] + mat[i][j];
            hor[i][j] = (i == 0) ? mat[i][j] : hor[i - 1][j] + mat[i][j];
        }
	}
	
	for (int i = 0; i<N; i++) {
		for (int j = 0; j < N;) {
			if(mat[i][j] == 1) {
			    int m = j;
			    while(mat[i][m] == 1 && m < N) {
                    if(isValid(mat, hor, ver, i, j, m)) {
                        ans = max(ans, m - j + 1);
                    }
			        m++;
			    }
                j = m;
			} else {
			    j++;
			}
		}
	}
	return ans;
}

// Driver program to test above function
int main() {
    int mat[][N] = {{1, 0, 1, 1, 1, 1},
                    {1, 0, 1, 1, 0, 1},
                    {1, 1, 1, 0, 0, 1},
                    {0, 1, 1, 1, 1, 1},
                    {1, 1, 1, 0, 1, 0},
                    {0, 0, 1, 0, 0, 0},
    };
    cout << findSubSquare(mat) << endl;

    int mat2[][N] = {{0, 0, 0, 0, 0, 1},
                     {0, 1, 0, 1, 1, 1},
                     {0, 1, 0, 1, 0, 1},
                     {0, 1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
    };

    cout << findSubSquare(mat2) << endl;

    int mat3[][N] = {{ 1, 1, 0, 1, 0, 1 },
                     { 1, 1, 1, 1, 1, 1 },
                     { 1, 1, 1, 0, 1, 1 },
                     { 1, 1, 1, 1, 1, 1 },
                     { 1, 0, 0, 1, 1, 1 },
                     { 1, 1, 1, 1, 1, 0 },
    };

    cout << findSubSquare(mat3) << endl;

    return 0;
}
