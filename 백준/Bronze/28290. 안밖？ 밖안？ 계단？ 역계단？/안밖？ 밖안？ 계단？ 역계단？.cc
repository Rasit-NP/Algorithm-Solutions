# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    if (word == "fdsajkl;" || word == "jkl;fdsa"){
        cout << "in-out";
    }
    else if (word == "asdf;lkj" || word == ";lkjasdf"){
        cout << "out-in";
    }
    else if (word == "asdfjkl;"){
        cout << "stairs";
    }
    else if (word == ";lkjfdsa"){
        cout << "reverse";
    }
    else {
        cout << "molu";
    }
}