#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1000000007;

class Solution {
public:
    vector<vector<int>> matmul(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int n = A.size();
        vector<vector<int>> C(n, vector<int>(n, 0));
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<int>> pow(const vector<vector<int>>& A, int n) {
        int size = A.size();
        vector<vector<int>> result(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1; // Initialize result as identity matrix
        }

        vector<vector<int>> base = A;
        while (n > 0) {
            if (n % 2 == 1) {
                result = matmul(result, base);
            }
            base = matmul(base, base);
            n /= 2;
        }

        return result;
    }

    int checkRecord(int n) {
        vector<vector<int>> baseMatrix = {
            {1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0}
        };

        vector<vector<int>> resultMatrix = pow(baseMatrix, n);

        int result = 0;
        for (int i = 0; i < 6; ++i) {
            result = (result + resultMatrix[i][0]) % MOD;
        }
        return result;
    }
};
