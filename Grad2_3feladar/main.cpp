#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//szomszedossagi matrix
int m[10][10];
int szamlalo=0;
int min1=999;
int n;
int start;
int stop;
vector<int> v1;

/**
Leallasi feltetel a backtracking fuggvenynek

Megvizsgalja, hogy a mar bejart varosok tarolasara letrehozott v vektorban hany csomopont van
s ha ez egyenlo n-1, akkor leallhatunk.

Azert kell n-1, s nem n, mert a szomszedossagi matrixnal
azt szeretnenk, ha az 1 es csomopont az 1 es sornak, a 2 es a 2es sornak illetve oszlopnak,
stb felelne meg, s nem a 0 s nak, illetve 1 esnek.
Emiatt vettunk csomopont+1 x csomopont + 1 es szomszeodossagi matrixot,
s a 0 indexu sort es oszlopot nem vesszuk figyelembe
*/
bool leall(vector<int> v)
{

    int n=v.size();
    if (v[n-1] == stop)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
Logikai fuggveny, mely megvizsgalja, hogy a jelenlegi csomopontbol lehetseges e a kovetkezo csompontba jutni

Parameterkent atadjuk a jelenlegi, a kovetkezo csomopontokat,
illetve a vektort, ahol az eddig bejart csomopontokat taroljuk.

Ha van osszekottetes a jelenlegi s a kovetkezo csomopont kozott,
illetve meg nem jartunk a kovetkezo csomopontban, akkro igazat terit vissza,
maskepp hamisat
*/
bool lehet(int jelenlegi, int kovetkezo, vector<int> v)
{
    //van-e osszekottestes a ket csomopont kozott
    if (m[jelenlegi][kovetkezo] == 0)
    {
        return false;
    }
    //jartunk e mar kovetkezo csomopontban
    for (int i=0; i<v.size(); i++)
    {
        if (v[i] == kovetkezo)
        {
            return false;
        }
    }
    return true;
}
/**
Fuggveny a vector kiirasara
*/
void kiir(vector<int> v)
{

    for(int i=0; i<v.size(); i++)
    {
        szamlalo=szamlalo+v[i];


    }
    if(szamlalo<min1){
      min1=szamlalo;
     while(v1.size()){
       v1.pop_back();
     }
     for(int i:v){
        v1.push_back(i);
     }
    }
    cout << endl;
}

/**
backtrack fuggveny, amely a jelenlegi csomopontbol kiindulva megprobal
majd minden egyeb csomopontba menni, ha lehetseges.

Ha az osszes csomopontot bejartuk, a fuggveny meghivja a kiiras fuggvenyt
*/
void backtrack(int jelenlegi, vector<int> v)
{
    // ha bejartunk mindent, irjuk ki a megoldast
    if (leall(v))
    {
        kiir(v);
        return;
    }
    //probaljunk meg az osszes lehetseges
    //csomopontba atmenni, ha lehet
    for(int i = 0; i<n; i++)
    {
        //csak akkor probaljunk tovabblepni,
        //ha nem a jelenlegi be szeretnenk lepni
        if (i!=jelenlegi)
        {
            if (lehet(jelenlegi, i, v))
            {
                //ha lehetseges tovabblepni,
                //lepjunk tovabb, s mentsuk le a kovetkezo csomopontot egy ideiglenes vektorban
                vector<int> tempv = v;
                tempv.push_back(i);
                backtrack(i, tempv);
            }
        }
    }

}


int main()
{
    //szomszedossagi matrix inicializalasa
    int i, j;
    cout << "Start=";
    cin >> start;
    cout <<"Stop=";
    cin >> stop;
    ifstream in("input.txt");
    in >>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            in >> m[i][j];
        }
    }


    //probaljuk meg minden elbol bejarni a grafot

        vector<int> v;
        v.push_back(start);
        backtrack(start, v);
        for(int i:v1){
            cout << i<< " ";
        }


    return 0;
}
