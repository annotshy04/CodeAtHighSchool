#include <iostream>
using namespace std;
int mod = 1e9+7;
struct Matrix{
    int x, y;
    int **m = NULL;
    Matrix(int _x, int _y, int **_m){
        x = _x;
        y = _y;
        m = new int*[x];
        for(int i = 0; i < x; ++i) m[i] = new int[y];
        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j) m[i][j] = _m[i][j];
    }
    Matrix operator *(const Matrix& other){
        int **ans = new int*[x];
        for(int i = 0; i < x; ++i) ans[i] = new int[other.y];
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < other.y; ++j){
                ans[i][j] = 0;
                for(int p = 0; p < y; ++p){
                    ans[i][j] += (1ll * m[i][p] * other.m[p][j]) % mod;
                    ans[i][j] %= mod;
                }
            }
        }
        return Matrix(x, int(other.y), ans);
    }
    Matrix& operator =(const Matrix& other){
        x = other.x;
        y = other.y;
        m = new int*[x];
        for(int i = 0; i < x; ++i) m[i] = new int[y];
        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j) m[i][j] = other.m[i][j];
        return *this;
    }
    void print(){
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < y; ++j) cout << m[i][j] << " ";
            cout << '\n';
        }
    }
};
Matrix _pow(Matrix a, long long b, int size){
    int **temp = new int*[size];
    for(int i = 0; i < size; ++i) temp[i] = new int[size];
    for(int i = 0; i < size; ++i) temp[i][i] = 1;
    Matrix c = Matrix(size, size, temp);
    for(; b; b /= 2, a = a * a)
    if(b & 1) c = c * a;
    return c;
}
int main(int argc, char **argv){
    freopen("notfib.inp","r",stdin);
    freopen("notfib.out","w",stdout);
    int n, k;
    cin >> n >> k;
    int *f = new int[k];
    int *a = new int[k];
    for(int i = 0; i < k; ++i) cin >> f[i];
    for(int i = 0; i < k; ++i) cin >> a[i];

    int **T = new int*[k];
    for(int i = 0; i < k; ++i) T[i] = new int[k];
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) T[i][j] = 0;
    for(int i = 0; i < k; ++i) T[0][i] = a[i];
    for(int i = 0; i < k-1; ++i){
        T[i+1][i] = 1;
    }
    int **b = new int*[k];
    for(int i = 0; i < k; ++i) b[i] = new int[1]{f[k-i-1]};

    Matrix _T = Matrix(k, k, T);
    Matrix _b = Matrix(k, 1, b);
    _T = _pow(_T, n-k+1, k);
    _T = _T * _b;
    cout << _T.m[0][0];
}
