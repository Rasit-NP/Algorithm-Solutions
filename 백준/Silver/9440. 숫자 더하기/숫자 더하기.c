# include <stdio.h>

int nums[14] = {0};

int init(int n){
    int i, min1=10, min2=10;
    for (i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
}

int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int nums[], int n){
    for (int i=n-1; i>0; i--){
        for (int j=0; j<i; j++){
            if (nums[j] > nums[j+1]){
                swap(nums+j, nums+j+1);
            }
        }
    }
}

int main(void){
    while (1){
        int n, ans = 0, digit = 1, i;
        int cnt_1 = 0;
        scanf("%d", &n);
        if (!n)
            break;
        init(n);
        sort(nums, n);
        for (i=0; i<n; i++){
            if (nums[i])
                break;
        }
        swap(nums, nums+i);
        swap(nums+1, nums+i+1);
        while (n>1){
            ans += digit*nums[n-1];
            ans += digit*nums[n-2];
            n -= 2;
            digit *= 10;
        }
        if (n){
            ans += digit*nums[n-1];
        }
        printf("%d\n", ans);
    }
}