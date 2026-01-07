#include<iostream>
using namespace std;
void InsertSort(int a[], int n){
    //关注序列头部，从第2个元素开始遍历(j = 1)
    for(int j = 1; j < n; j++){
        int x = a[j]; //把要排序的元素取出来赋值给x
        int i = j - 1; //从该元素的前一位元素开始向前比较，并选择合适位置插入
        //i>=0保证最多比到第1个元素a[0]
        while(i >= 0 && x < a[i]){
            //如果a[j]小于a[j-1]，需要将a[j-1]向后腾一位
            a[i+1] = a[i];
            i--; //继续向前比较，不急着插入
        }
        //对于上面的while循环，一旦在向前比较时发现x大于此时i对应的a[i]，那么循环就地结束，不再向前
        //但是i已经自减，因此需要加回1，并插入x=a[j]
        a[i+1] = x;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    InsertSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}