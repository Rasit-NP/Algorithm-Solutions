# include <stdio.h>

int sort(int nums[], int n){
    int i, j;
    for (i=n-1; i>0; i--){
        for (j=0; j<i; j++){
            if (nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++){
        int n, cnt=0, nums[1000];
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            scanf("%d", &nums[i]);
        }
        sort(nums, n);
        for (int i=0; i<n-2; i++){
            int xa = nums[i];
            for (int j=i+2; j<n; j++){
                int xc = nums[j];
                if ((xa+xc)&1)
                    continue;
                int l = i, r = j, xb = (xa+xc)/2;
                while (r-l>1){
                    int mid = (l+r)/2;
                    if (nums[mid] > xb)
                        r = mid;
                    else if (nums[mid] < xb)
                        l = mid;
                    else {
                        cnt += 1;
                        break;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
}