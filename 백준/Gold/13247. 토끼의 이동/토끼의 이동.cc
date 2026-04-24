# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

struct Rabbit{
private:
    int now, before;

public:
    Rabbit(): Rabbit(-1, -1){}

    Rabbit(int now, int before): now(now), before(before){}

    int getNow(){
        return now;
    }

    int goRight(){
        before = now;
        return ++now;
    }

    int goLeft(){
        before = now;
        return --now;
    }

    int go(char color){
        if (color == 'W'){
            goLeft();
        }
        else if (color == 'B'){
            goRight();
        }
        else if (color == 'R'){
            if (before == -1){
                goLeft();
            }
            else {
                swap(now, before);
            }
        }
        return now;
    }
};

int r, n;
string board;

void init();
int countRabbits(int);
int run(vector<Rabbit>);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();
    int total = 0;
    int count = 0;

    for (int i=0; i<(1<<n); i++){
        if (countRabbits(i) != r)
            continue;
        
        vector<Rabbit> rabbits;
        for (int idx = 0; idx<n; idx++){
            if (i & (1<<idx)){
                rabbits.emplace_back(idx, -1);
            }
        }
        ++total;
        count += run(rabbits);
    }

    long double ans = (long double)count / total;
    cout.precision(15);
    cout << fixed << ans;
}

int run(vector<Rabbit> rabbits){
    int size = n;
    while (size > 2){
        vector<Rabbit> newVec;
        vector<int> countRabbit(size, 0);
        for (Rabbit& rabbit : rabbits){
            int now = rabbit.getNow();
            char let = board[now];

            if (now == 0){
                now = rabbit.goRight();
            }
            else if (now > size-3){
                now = rabbit.goLeft();
            }
            else {
                now = rabbit.go(let);
            }
            ++countRabbit[now];
        }
        for (Rabbit& rabbit : rabbits){
            if (countRabbit[rabbit.getNow()] == 1){
                newVec.push_back(rabbit);
            }
        }
        rabbits = newVec;
        --size;
    }
    return rabbits.size();
}

int countRabbits(int num){
    int res = 0;
    while (num){
        res += num&1;
        num >>= 1;
    }

    return res;
}

void init(){
    cin >> board >> r;

    n = board.size();
}