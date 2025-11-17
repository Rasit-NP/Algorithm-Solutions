# include <stdio.h>

int main(void) {
	char x;
	int used[26], idx = 0;
	for (int i = 0; i < 26; i++) {
		used[i] = -1;
	}
	while ((x=getchar()) != EOF) {
		if (used[x-'a'] == -1)
			used[x - 'a'] = idx;
		idx++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", used[i]);
	}
}