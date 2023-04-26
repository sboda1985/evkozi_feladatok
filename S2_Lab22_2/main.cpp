#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> x;
    int n, s;
    cout << "n=";
    cin >> n;
    for(int i=0; i<n; i++){
        x.push_back(i);
    }
    x.pop_back();
    for(int i=0; i<x.size(); i++){
        cout << x[i] << " ";
    }
    cout << endl;
    x.pop_back();
    for(int i=0; i<x.size(); i++){
        cout << x[i] << " ";
    }
    return 0;
}
