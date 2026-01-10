#include<iostream>
#include<cmath> //引入求幂函数pow(x, n)计算x的n次方
using namespace std;
int main(){
    int n;
    cin >> n;
    int x = n; //定义一个中间变量，不直接对n做操作
    int m = 0; //定义m为回文数，并初始化为0
    int i = 0; //定义i为10的次幂，并初始化为个位数制(0次方)
    if(n < 0) cout << "false";
    else{
        while(x > 0){
            // x % 10 得到的是x的最后一位数
            // x / 10 删去x的最后一位数
            //以x=1234为例，1234=123×10+4，1234%10=4(取最后一位)，1234/10=123(删最后一位)  
            m = m * 10 + (x % 10);
            x = x / 10;
            i = i + 1;
        }
        if(n == m) cout << "true";
        else cout << "false";
    }
}