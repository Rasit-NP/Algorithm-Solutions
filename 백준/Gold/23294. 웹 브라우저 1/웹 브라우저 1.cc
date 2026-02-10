# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int n, q, c;    
int memory = 0;
int now = 0;
vector<int> cache;
deque<int> past, future;

void B(void){
    if (past.size()){
        future.push_back(now);
        now = past.back();  past.pop_back();
    }
}

void F(void){
    if (future.size()){
        past.push_back(now);
        now = future.back();    future.pop_back();
    }
}

void A(int p){
    if (now){
        past.push_back(now);
    }
    now = p;
    memory += cache[now];
    while (future.size()){
        memory -= cache[future.back()];
        future.pop_back();
    }
    while (memory > c){
        memory -= cache[past.front()];
        past.pop_front();
    }
}

void C(void){
    deque<int> new_past;
    while (past.size()){
        int p = past.front();   past.pop_front();
        while (new_past.size() && new_past.back() == p){
            new_past.pop_back();
            memory -= cache[p];
        }
        new_past.push_back(p);
    }
    past = new_past;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> q >> c;
    cache.assign(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> cache[i];
    }

    for (int t=0; t<q; t++){
        char order; cin >> order;
        switch (order){
            case 'B':{
                B();
                break;
            }
            case 'F':{
                F();
                break;
            }
            case 'A':{
                int p;  cin >> p;
                A(p);
                break;
            }
            case 'C':{
                C();
                break;
            }
        }
    }
    cout << now << '\n';
    if (past.size()){
        while (past.size()){
            cout << past.back();   past.pop_back();
            if (past.size())    cout << ' ';
        }
    }else {
        cout << -1;
    }
    cout << '\n';
    if (future.size()){
        while (future.size()){
            cout << future.back();   future.pop_back();
            if (future.size())    cout << ' ';
        }
    }else {
        cout << -1;
    }
}