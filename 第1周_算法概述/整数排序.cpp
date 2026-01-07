#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m;
    cin >> m;
    int array[m];
    for(int i = 0; i < m; i++){
        cin >> array[i];
    }
    //algorithm头文件包含了一个内置的排序函数sort
    //sort(数组，数组n)相当于对数组从索引0-(n-1)的元素进行顺排
    sort(array, array+m);
    for(int j = 0; j < m; j++){
        cout << array[j] << " ";
    }
}