#include<iostream>
using namespace std;
int n;
int k;
int a[13];
void dfs(int step){
    if(step > k-1){
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += a[i];
        }
        if(sum == n){
            for(int i = 0; i < k; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return ;
    }
    for(int i = 0; i < n; i++){
        a[step] = i+1;
        dfs(step+1);
    }
}

int main(){
    cin >> n >> k;
    dfs(0);
}