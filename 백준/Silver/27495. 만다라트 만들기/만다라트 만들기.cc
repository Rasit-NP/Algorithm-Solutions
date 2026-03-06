# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

struct Target{
    string name;
    vector<string> small;

    bool operator<(const Target& target) const {
        if (this->name < target.name){
            return true;
        }
        else {
            return false;
        }
    }

    void print(int i){
        cout << "#" << i << ". " << this->name << '\n';
        sort(this->small.begin(), this->small.end());
        int j = 1;
        for (const auto& small_target : small){
            cout << "#" << i << "-" << j++ << ". " << small_target << '\n';
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string table[9][9];
    vector<Target> targets;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> table[i][j];
        }
    }

    for (int i=0; i<9; i++){
        if (i == 4) continue;
        Target target;
        int x = i/3, y = i%3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                string data = table[3*x + i][3*y + j];
                if (i == 1 && j == 1){
                    target.name = data;
                    continue;
                }
                target.small.push_back(data);
            }
        }
        targets.push_back(target);
    }

    sort(targets.begin(), targets.end());
    for (int i=1; i<9; i++){
        targets[i-1].print(i);
    }
}