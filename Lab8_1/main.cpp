#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n;
    string v[100][100];
    input >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            input >> v[i][j];
            if (i<j) {
                transform(v[i][j].begin(), v[i][j].begin()+2, v[i][j].begin(), ::toupper);
            }
            if (i>j) {
                transform(v[i][j].end()-2, v[i][j].end(), v[i][j].end()-2, ::toupper);
            }
            output << v[i][j] << " ";
        }
        output << endl;
    }

    return 0;
}
