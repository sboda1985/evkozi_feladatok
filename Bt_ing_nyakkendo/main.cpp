#include <iostream>
#include <vector>
using namespace std;
int N = 6;
string virag[] = {"ing", "nyakkendo", "nadrag", "zako", "zokni", "cipo"};

bool lehet(vector<string> ruhak, string ujruha)
{
    for(int i = 0; i<ruhak.size(); i++)
    {
        if (ruhak[i] == ujruha)
        {
            return false;
        }
    }
    if (ujruha == "nyakkendo")
    {
        bool felvettem = false;
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "ing")
            {
                felvettem = true;
            }
        }
        if (felvettem == false) { //!felvettem
            return false;
        }
    }

    if (ujruha == "zako")
    {
        bool felvettem = false;
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "nyakkendo")
            {
                felvettem = true;
            }
        }
        if (felvettem == false) { //!felvettem
            return false;
        }
    }

    if (ujruha == "cipo")
    {
        int szamlalo = 0;
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "nadrag")
            {
                szamlalo++;
            }
            if (ruhak[i] == "zokni")
            {
                szamlalo++;
            }
        }
        if (szamlalo < 2 ) {
            return false;
        }
    }

    return true;
}
void kiir(vector<string> csokor)
{
    for(int i = 0; i<csokor.size(); i++)
    {
        cout << csokor[i] << " " ;
    }
    cout << endl;
    return;
}
void backtrack(vector<string> csokor, int index)
{
    if (csokor.size() == N)
    {
        kiir(csokor);
        return;
    }
    for(int i = 0; i<6; i++)
    {
        if (lehet(csokor, virag[i]))
        {
            vector<string> tempcsokor;
            for(int j = 0; j<csokor.size(); j++)
            {
                tempcsokor.push_back(csokor[j]);
            }
            tempcsokor.push_back(virag[i]);
            backtrack(tempcsokor, i);
        }
    }
}

int main()
{
    vector<string> csokor;
    backtrack(csokor, 0);
    return 0;
}
