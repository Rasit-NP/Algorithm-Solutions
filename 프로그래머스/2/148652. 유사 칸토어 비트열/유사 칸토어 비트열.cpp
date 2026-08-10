# include <vector>
using namespace std;
typedef long long llong;

int get(int n, llong l, llong r){
    int res = 0;
    if (n == 1){
        for (int i=l; i<=r; i++){
            res += ("11011"[i] - '0');
        }
        return res;
    }
    else if (l > r){
        return 0;
    }
    else if (l == r){
        while (l){
            if (l%5 == 2)
                return 0;
            l /= 5;
        }
        return 1;
    }
    
    int modL = l%5, modR = r%5;
    l /= 5, r/= 5;
    int tl = l, tr = r;
    while (tl%5 != 2){
        tl /= 5;
        if (tl == 0)
            break;
    }
    while (tr%5 != 2){
        tr /= 5;
        if (tr == 0)
            break;
    }
    if (l < r){
        if (tl == 0){
            for (int i=modL; i<5; i++){
                res += ("11011"[i] - '0');
            }
        }
        if (tr == 0){
            for (int i=0; i<=modR; i++){
                res += ("11011"[i] - '0');
            }
        }
    }
    else {
        if (tl == 0){
            for (int i=modL; i<=modR; i++){
                res += ("11011"[i] - '0');
            }
        }
    }

    ++l, --r;
    
    return res + 4*get(n-1, l, r);
}

int solution(int n, llong l, llong r) {
    --l, --r;
    
    return get(n, l, r);
}