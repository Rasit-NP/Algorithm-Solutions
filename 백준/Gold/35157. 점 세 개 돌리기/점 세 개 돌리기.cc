# include <iostream>
# include <vector>
# include <string>
# include <cmath>
using namespace std;

struct Position{
    int x, y, z;
    
    Position(int x, int y, int z): x(x), y(y), z(z){}

    void assign(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print(){
        cout << this->x << ' ' << this->y << ' ' << this->z << '\n';
    }
};

struct Matrix{
    int matrix[3][3];

    Matrix(){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(vector<vector<int>> vec){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                this->matrix[i][j] = vec[i][j];
            }
        }
    }

    Position trans(Position p){
        return Position(p.x*matrix[0][0] + p.y*matrix[1][0] + p.z*matrix[2][0], p.x*matrix[0][1] + p.y*matrix[1][1] + p.z*matrix[2][1], p.x*matrix[0][2] + p.y*matrix[1][2] + p.z*matrix[2][2]);
    }

    Matrix operator*(Matrix& b){
        Matrix res = Matrix();
    
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                for (int l=0; l<3; l++){
                    res.matrix[i][j] += this->matrix[i][l] * b.matrix[l][j];
                }
            }
        }
        return res;
    }
};

int n, q;
Matrix x, y, z, xx, yy, zz, xy, yz, zx;
vector<Position> baseVectors;
vector<vector<Matrix>> matrixes;

void define(void);
void input(void);
void get(int l, int r);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    define();
    input();
    int q;  cin >> q;
    while (q--){
        int l, r;   cin >> l >> r;
        get(l, r);
    }
}

void get(int l, int r){
    int len = r - l + 1;
    int now = l;

    int idx = 0;
    Matrix mat = Matrix({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});

    while (len){
        if (len&1){
            mat = mat * matrixes[now][idx];
            now = now + (1<<idx);
        }
        len >>= 1;
        ++idx;
    }

    for (Position& baseVec : baseVectors){
        mat.trans(baseVec).print();
    }
}

void input(void){
    cin >> n;
    int len = ceil(log2(n)) + 1;
    matrixes.assign(n+1, vector<Matrix>(len));
    for (int i=1; i<=n; i++){
        string o;   cin >> o;
        Matrix& mat = matrixes[i][0];
        if (o == "X"){
            mat = x;
        }
        else if (o == "Y"){
            mat = y;
        }
        else if (o == "Z"){
            mat = z;
        }
        else if (o == "XX"){
            mat = xx;
        }
        else if (o == "YY"){
            mat = yy;
        }
        else if (o == "ZZ"){
            mat = zz;
        }
        else if (o == "XY" || o == "YX"){
            mat = xy;
        }
        else if (o == "YZ" || o == "ZY"){
            mat = yz;
        }
        else if (o == "ZX" || o == "XZ"){
            mat = zx;
        }
    }
    for (int j=1; j<len; j++){
        for (int i=1; i<=n; i++){
            int idx = i + (1<<(j-1));
            if (idx <= n){
                matrixes[i][j] = matrixes[i][j-1] * matrixes[idx][j-1];
            }
        }
    }
}

void define(void){
    baseVectors.emplace_back(1, 0, 0);
    baseVectors.emplace_back(0, 1, 0);
    baseVectors.emplace_back(0, 0, 1);

    x = Matrix({{1, 0, 0}, {0, 0, 1}, {0, -1, 0}});
    y = Matrix({{0, 0, -1}, {0, 1, 0}, {1, 0, 0}});
    z = Matrix({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
    xx = Matrix({{1, 0, 0}, {0, -1, 0}, {0, 0, -1}});
    yy = Matrix({{-1, 0, 0}, {0, 1, 0}, {0, 0, -1}});
    zz = Matrix({{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}});
    xy = Matrix({{1, 0, 0}, {0, 1, 0}, {0, 0, -1}});
    yz = Matrix({{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    zx = Matrix({{1, 0, 0}, {0, -1, 0}, {0, 0, 1}});
}