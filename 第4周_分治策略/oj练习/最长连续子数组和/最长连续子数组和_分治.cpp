#include<iostream>
using namespace std;
int n;
int nums[1010];
//专门定义一个函数，用于计算横跨2个二分数组的最大和
//必须包括nums[mid]和nums[mid+1]两个元素
//单看任何一个元素都已经包括在[l,mid]或[mid+1,r]的情况下(不属于数组之间)
long long fun2(int l, int r, int mid){
    long long left_sum = 0;
    long long left_result = nums[mid];
    for(int i = mid; i >= l; i--){
        left_sum += nums[i];
        left_result = max(left_result, left_sum);
    }
    long long right_sum = 0;
    long long right_result = nums[mid+1];
    for(int i = mid+1; i <= r; i++){
        right_sum += nums[i];
        right_result = max(right_result, right_sum);
    }
    return left_result + right_result;
}
long long fun(int l, int r){
    //终止条件
    if(l >= r) return nums[l];
    //分
    int mid = (l + r) / 2;
    long long ans = max(fun(l, mid), fun(mid+1, r)); //后续还要考虑2个二分数组之间可能形成更大的和
    //治
    ans = max(ans, fun2(l, r, mid));
    return ans;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << fun(0, n-1) << endl;
}