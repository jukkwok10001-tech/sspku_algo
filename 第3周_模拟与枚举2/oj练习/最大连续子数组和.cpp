#include<iostream>
#include<algorithm>
using namespace std;
int nums[1010];
int answers[1010];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++){
        //定义ans为答案更新变量
        //定义sum为求和变量
        //均初始化为当前首个元素
        int ans = nums[i];
        int sum = nums[i];
        int l = i + 1;
        while(l < n){
            sum += nums[l];
            ans = max(ans, sum);
            l++;
        }
        //当i=n-1时，l=n，无法进入while循环体
        //此时的ans就是nums[n-1]
        answers[i] = ans;
    }
    sort(answers, answers + n);
    cout << answers[n-1] << endl;
}