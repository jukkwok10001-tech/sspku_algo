#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int> counts;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    if(n == 1) cout << 1;
    else{
        for(int i = 0; i < a.size(); i++){
            int x = a[i];
            int j = i + 1;
            int count = 1;
            while(x < a[j] && j < a.size()){
                count++;
                j++;
            }
            counts.push_back(count);
        }
        for(int i = 0; i < counts.size(); i++){
            cout << counts[i] << " ";
        }
    }
}