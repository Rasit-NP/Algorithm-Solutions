# include <iostream>
# include <string>
using namespace std;

int main(void){
	string grade;
	float ans;
	cin >> grade;
	if (grade.length() == 1){
		cout << "0.0\n";
		return 0;
	}
	if (grade[0] == 'A'){
		ans = 4.0;
	}
	else if (grade[0] == 'B'){
		ans = 3.0;
	}
	else if (grade[0] == 'C'){
		ans = 2.0;
	}
	else if (grade[0] == 'D'){
		ans = 1.0;
	}
	if (grade[1] == '+'){
		ans += 0.3;
	}
	else if (grade[1] == '-'){
		ans -= 0.3;
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << endl;
}