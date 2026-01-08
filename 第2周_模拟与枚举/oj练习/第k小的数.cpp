#include<iostream>
using namespace std;
//思路：先将排序算法对序列排序，然后剔除重复值
//使用插入排序
void InsertSort(int a[], int n){
    for(int j = 1; j < n; j++){
        int x = a[j];
        int i = j - 1;
        while(i >= 0 && x < a[i]){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = x;
    }
}
int main(){
    int n, k;  
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    InsertSort(a, n);
    //考虑特殊情况，第1小的数直接返回a[0]
    //当k≥2时，才考虑使用指针计数器
    if(k == 1) cout << a[0] << endl;
    else{
        //l是左指针，负责计算非重复值个数
        //r是有指针，从第二位元素开始遍历；需要定义在循环外部，当跳出循环时作为新索引取数
        int l = 1;
        int r = 1;
        //循环初始条件在上面已经定义r = 1，因此可以不用写，但要用分号隔开
        for(; r < n; r++){
            //如果当前元素不等于前一个元素，左(计数)指针自增1
            if(a[r] != a[r-1]){
                l += 1;
            }
            //一旦计数指针触发阈值k，跳出循环
            if(l == k){
                break;
            }
        }
        //存在没有触发阈值遍历完循环的情况，这种情况下计数l必定小于k
        //例如[1,1,1], l≡1, 对∀k≥2，均不可能触发阈值
        if(l < k) cout << "NO RESULT" << endl;
        //排除掉上面的异常情况，剩下的必然是触发阈值跳出循环的情况
        //直接取a[r]即可；此时的r是首个触发阈值的元素的索引，也就是首个第k小的数
        else cout << r << " " << a[r] << endl;
    } 
}