/*以欧几里得算法为例
        输入：非负整数m,n,其中m和n不全为0
        输出：m与n的最大公约数
        1. while m > 0 do:
        2.   r ← n mod m
        3.   n ← m
        4.   m ← r
        5. return n
*/
#include<iostream>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    while(m > 0){
        int r = n % m;
        n = m;
        m = r;
    }
    cout << n << endl;
}
//为何这里不需要判断m和n的大小？
/*(1)当n>m时：
    此时正常进行辗转相除法
  (2)当n<m时：
    循环第一步：r = n mod m ≡ n
    赋值：n ← m，m ← r ≡ n
    循环第二步：m mod n
    所以在这种情况下迭代的第一步会自动调换两者先后顺序，保证大数对小数辗转相除
*/
