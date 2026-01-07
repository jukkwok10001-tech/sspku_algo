#include<iostream>
using namespace std;
int main(){
    //暴力算法，逐个枚举
    int a, b;
    cin >> a >> b;
    //c++内置函数min取两者较小值开始遍历
    for(int i = min(a, b); i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            cout << i << endl;
            break;
        }
    }
}