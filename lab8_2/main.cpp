#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()

{
    int k=0;
    //input file deklaralasa
    ifstream file("input.txt");
    ifstream kov("kovetelmeny.txt");
    ofstream out("output.txt");
    string szavak[1000];
    int talalat[1000] = {0};
    int i = 0, n;


    if(kov.is_open())
    {
        while(kov >> szavak[i])
        {
            i++;
        }
        n = i;
        cout << n;
        if (file.is_open())
        {
            string line;
            while(getline(file, line))
            {
                transform(line.begin(), line.end(), line.begin(), ::tolower);
                for(i=0; i<n; i++)
                {
                    size_t found = line.find(szavak[i]);
                    while(found!=string::npos)
                    {
                        talalat[i]++;
                        found = line.find(szavak[i], found+1);
                    }
                }
            }
            for(i=0; i<n-1; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                     if(talalat[i] < talalat[j]){
                        swap(talalat[i], talalat[j]);
                        swap(szavak[i], szavak[j]);
                     }
                }
            }
            for(i=0; i<n; i++)
            {
                out << szavak[i] << "\t" << talalat[i] << endl;
            }
        }
        else
        {
            cout << "Nem sikerult megnyitni az input.txt filet";
        }
    }
    else
    {
        cout << "nem sikerult megnyitni a kovetelmeny filet";
    }

    return 0;

}
