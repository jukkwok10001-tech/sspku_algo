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
    if(k == 1) cout << a[0] << endl;
    else{
        int l = 1;
        int r = 1;
        for(; r < n; r++){
            if(a[r] != a[r-1]){
                l += 1;
            }
            if(l == k){
                break;
            }
        }
        if(l < k) cout << "NO RESULT" << endl;
        else cout << a[r] << endl;
    } 
}