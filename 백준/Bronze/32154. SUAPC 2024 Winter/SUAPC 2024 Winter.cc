# include <iostream>
# include <string>
using namespace std;

int main(void){
    string board[10][2] = {{"11", "A B C D E F G H J L M"},
					   {"9", "A C E F G H I L M"},
					   {"9", "A C E F G H I L M"},
					   {"9", "A B C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A B C F G H L M"}};
    int n; cin>>n;
    cout << board[n-1][0] << endl;
    cout << board[n-1][1] << endl;
}