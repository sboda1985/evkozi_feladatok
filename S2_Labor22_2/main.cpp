#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int index;
    node *bal;
    node *jobb;
};

struct node* letrehoz(int index)
{
    node *elem = new node;
    elem->bal = NULL;
    elem->jobb = NULL;
    elem->index = index;
    return elem;

};

struct node* felepit (struct node* node, int ertek)
{
    // Ha a fa üres, akkor szurja be
    if (node == NULL)
        return letrehoz(ertek);

    // kulonben kezdjuk el bejarni, s megnezni, hogy hova is kellene beszurni
    if (ertek < node->index)
        node->bal = felepit(node->bal, ertek);
    else if (ertek > node->index)
        node->jobb = felepit(node->jobb, ertek);

    return node;
}

bool bejar(struct node* node, int ertek){
    if (node == NULL){
        return false;
    }

    if (node->index == ertek) {
        return true;
    }
    if (ertek < node->index){
        return bejar(node->bal, ertek);
    }
    if (ertek > node->index) {
        return bejar(node->jobb, ertek);
    }
}

int main()
{

    ifstream in("input.txt");
    int N, x;
    in >> N;
    in >> x;
    node *elso = letrehoz(x);
    for(int i=1; i<N; i++)
    {
        in >> x;
        felepit(elso, x);

    }
    for(int i=0; i<10000; i++)
    {

        if (bejar(elso, i))
        {
           cout << i << " - igen " << endl;
        }
        else
        {
            cout << i << " - nem " << endl;
        }
    }

    return 0;
}
