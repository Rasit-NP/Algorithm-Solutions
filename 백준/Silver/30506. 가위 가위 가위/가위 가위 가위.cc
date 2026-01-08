# include <iostream>
# include <vector>
# define MAX 100
using namespace std;

void print(bool ans, vector<int> hands){
    if (ans){
        cout << "! ";
        for (int hand : hands){
            if (hand == 2){
                cout << 5;
            }
            else if (hand == 5){
                cout << 0;
            }
            else {
                cout << 2;
            }
        }
        cout << '\n' << flush;
    }
    else {
        cout << "? ";
        for (int hand : hands){
            cout << hand;
        }
        cout << '\n' << flush;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    vector<int> my_hand(MAX, 2);
    int cnt_game = 0;

    int correct_now;    cin >> correct_now;

    if (correct_now != MAX){
        my_hand[0] = 0;
        print(false, my_hand);
    }
    else {
        print(true, my_hand);
        return 0;
    }

    while (cnt_game <= MAX){
        // 이전 출력에 대한 응답을 적용
        int correct_test;   cin >> correct_test;
        if (correct_test < correct_now){
            my_hand[cnt_game] = 2;
        }
        else if (correct_test == correct_now){
            my_hand[cnt_game] = 5;
            correct_now++;
        }
        else {
            correct_now++;
        }
        cnt_game++;

        // 새로운 출력을 생성
        if (correct_now == MAX){
            print(true, my_hand);
            return 0;
        }
        else {
            my_hand[cnt_game] = 0;
            print(false, my_hand);
        }
    }
}