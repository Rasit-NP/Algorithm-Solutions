# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<vector<int>> words;
	vector<int> word;
	int char_to_int[26] = { 0, 1, -1, 3, 4, -1, 5, 6, 7, -1, 2, 8, 9, 10, 12, 13, -1, 14, 15, 16, 17, -1, 18, -1, 19, -1 };
	string int_to_char[20] = { "a", "b", "k", "d", "e", "g", "h", "i", "l", "m", "n", "ng", "o", "p", "r", "s", "t", "u", "w", "y" };
	cin >> n;
	for (int i = 0; i < n; i++) {
		word.clear();
		string input;
		cin >> input;
		int idx = 0;
		while (idx < input.length()) {
			char letter = input[idx];
			if (letter != 'n') {
				word.push_back(char_to_int[letter-'a']);
			}
			else if (input[idx + 1] == 'g') {
				word.push_back(11);
				idx++;
			}
			else {
				word.push_back(char_to_int[letter - 'a']);
			}
			idx++;
		}
		words.push_back(word);
	}
	sort(words.begin(), words.end());
	for (vector<int> word : words) {
		for (int letter : word) {
			cout << int_to_char[letter];
		}
		cout << '\n';
	}
}