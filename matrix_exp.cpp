#define ll long long
int MOD = 1e9+7;
void multiply(ll a[2][2], ll b[2][2]) {
    ll res[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] % MOD + (a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

ll matrix_exponentiation(ll n) {
    if(n==0)
    return 0;
    n--;
    ll matrix[2][2] = {{1, 1}, {1, 0}};
    ll A[2][2] = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) multiply(A, matrix);
        multiply(matrix, matrix);
        n >>= 1;
    }
    return A[0][0];
}
