#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int N = 19;
int amount = 250;
int ermek[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
int kontor = 0;


void kiir(vector<int>hasznaltermek){
     if (hasznaltermek.size() == 4) {
            int csokkeno = true;
         for(int i=0; i<3; i++){
            if (hasznaltermek[i] <= hasznaltermek[i+1]) {
                csokkeno = false;
            }
         }
         if (csokkeno){
            for(int i=0; i<4; i++){
                cout << hasznaltermek[i] << " ";
         }
         cout << endl;
     }
     }

}

bool lehet(int osszeg, int erme, int temposszeg){
    if (temposszeg + erme > osszeg){
        return false;
    }
    return true;
}

void backtrack(vector<int>hasznaltermek, int osszeg, int eddigiosszeg, int lepes){
    if (eddigiosszeg == osszeg) {
        kiir(hasznaltermek);
        return;
    }

    for(int i=lepes; i<N; i++){
        if (lehet(osszeg, ermek[i], eddigiosszeg) && hasznaltermek.size() < 4){
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
    backtrack(hasznaltermek, amount, 0, 0);
    return 0;
}
