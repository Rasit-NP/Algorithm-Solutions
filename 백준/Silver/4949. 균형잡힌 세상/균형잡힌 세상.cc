# include <iostream>
# include <queue>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		deque<char> stack;
		string s;
		getline(cin, s);
		if (s == ".") {
			break;
		}
		for (int i = 0; i < s.length(); i++) {
			char x = s[i];
			if (x == '[' || x == '(') {
				stack.push_back(x);
			}
			else if (x == ']' && stack.size() && stack.back() == '[') {
				stack.pop_back();
			}
			else if (x == ')' && stack.size() && stack.back() == '(') {
				stack.pop_back();
			}
			else if (x == ']' || x == ')') {
				stack.push_back(x);
			}
			else if (x == '.') {
				break;
			}
		}
		if (stack.size()) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}
}