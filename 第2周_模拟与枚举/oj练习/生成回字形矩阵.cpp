#include<iostream>
using namespace std;
//回字形矩阵的特点：
//(1)上半个三角满足 matrix[i][j]=min(i, j)
//(2)下半个三角满足 matrix[i][j]=min(n-i,n-j)
//不分类的话，可以直接使用公式 min(min(i,j),min(n-i,n-j))
int main(){
    int n;
    cin >> n;
    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            matrix[i][j] = min(i+1, j+1);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = n - i; j < n; j++){
            matrix[i][j] = min(n-i,n-j);
        }
    }
    //输出矩阵
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n-1){
                cout << matrix[i][j] << " ";
            }
            else{
                cout << matrix[i][j] << endl;
            }
        }
    }
}