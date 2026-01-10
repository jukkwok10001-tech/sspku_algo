#include<iostream>
using namespace std;
//要求：不使用for、while循环，使用递归思想
//定义阶乘函数
//需要根据输出结果的大小适当地改变数据类型为long long 
int factorial(int n){
    if(n == 1) return 1;
    else return n * factorial(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
}