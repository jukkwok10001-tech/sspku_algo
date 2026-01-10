#include<iostream>
using namespace std;
int n;
int w[20];
int a[20];
int count = 0;
void dfs(int step){
    if(step > n-1){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += w[i] * a[i];
        }
        if(sum == 0){
            count += 1;
        } 
        return ;
    }
    a[step] = 1;
    dfs(step + 1);
    a[step] = -1;
    dfs(step + 1);
    a[step] = 0;
    dfs(step + 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    dfs(0);
    cout << count << endl;
}