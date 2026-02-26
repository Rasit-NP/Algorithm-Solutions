# include <iostream>
using namespace std;

int main(void){
    int data[6] = {1, 1, 2, 2, 2, 8};
    for (int num : data){
        int v;  cin >> v;
        cout << num - v << ' ';
    }
}