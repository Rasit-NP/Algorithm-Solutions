# include <stdio.h>
# define MAX 1000005

int score[MAX] = {0};
int able[MAX] = {0};

int main(void){
    int n;
    int nums[100001];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &nums[i]);
        able[nums[i]] = 1;
    }
    for (int i=0; i<n; i++){
        int num = nums[i];
        int test = 2 * num;
        while (test <= 1000000){
            if (able[test] && !(test%num)){
                score[num] += 1;
                score[test] -= 1;
            }
            test += num;
        }
    }
    for (int i=0; i<n; i++){
        printf("%d ", score[nums[i]]);
    }
}