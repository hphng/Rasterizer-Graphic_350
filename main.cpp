#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout << 100 + 100;
    vector<int> a(5, 10);

    for(auto i : a)
        cout << i << " ";
}