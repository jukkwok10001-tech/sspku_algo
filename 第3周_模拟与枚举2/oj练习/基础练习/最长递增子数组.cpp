#include<iostream>
#include<algorithm> //sort排序函数的头文件
using namespace std;
int main(){
    int n;
    cin >> n;
    int nums[n];
    int counts[n-1];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    //不考虑nums的最后一个元素，其长度必定为1
    for(int i = 0; i < n - 1; i++){
        int l = i;
        int count = 1;
        while(nums[l] < nums[l+1]){
            l++;
            count++;
        }
        counts[i] = count;
    }
    sort(counts, counts + n - 1);
    cout << counts[n-2] << endl;
}