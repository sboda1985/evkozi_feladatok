#include <iostream>
#include <vector>

using namespace std;
int N = 3;
int ermek[] = {10, 5, 1};
int kontor = 0;

void kiir(vector<int>hasznaltermek){
    for(int i=0; i<hasznaltermek.size(); i++){
        cout << hasznaltermek[i] << " ";
    }
    cout << endl;
}

bool lehet(int osszeg, int erme, int temposszeg){
    if (temposszeg + erme > osszeg){
        return false;
    }
    return true;
}

void backtrack(vector<int>hasznaltermek, int osszeg, int eddigiosszeg, int lepes){
    if (eddigiosszeg == osszeg) {
        kontor ++;
        kiir(hasznaltermek);
        return;
    }

    for(int i=lepes; i<N; i++){
        if (lehet(osszeg, ermek[i], eddigiosszeg)){
            vector<int> temphasznaltermek = hasznaltermek;
            temphasznaltermek.push_back(ermek[i]);
            int tempeddigiosszeg = eddigiosszeg + ermek[i];
            backtrack(temphasznaltermek, osszeg, tempeddigiosszeg, lepes);
        }

    }
}
int main()
{
    vector<int> hasznaltermek;
    backtrack(hasznaltermek, 10, 0, 0);
    cout << endl;
    cout << kontor;
    return 0;
}
