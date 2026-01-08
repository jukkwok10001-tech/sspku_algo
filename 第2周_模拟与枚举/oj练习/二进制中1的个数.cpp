#include<iostream>
using namespace std;
//需要用到位运算符，即不需转化为二进制就可以进行二进制的运算
int main(){
    int n;
    int ans = 0; //初始化计数结果
    cin >> n;
    while(n > 0){
        //对n和1做位与运算，只有最后一位为1时计数自增
        if(n & 1 == 1) ans += 1;
        //判断完最后一位，n的二进制整体右移一位继续判断
        n = n >> 1;
    }
    cout << ans << endl;
}