#include <iostream>

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

void felepit(struct node* current)
{
    int csomo;
    cout << "Kerem az " << current->index << " elemnek a bal oldali szomszedjat [0 ha nincs]";
    cin >> csomo;
    if (csomo != 0)
    {
        node *uj = letrehoz(csomo);
        current->bal = uj;
        felepit(current->bal);
    }

    cout << "Kerem az " << current->index << " elemnek a jobb oldali szomszedjat [0 ha nincs]";
    cin >> csomo;
    if (csomo != 0)
    {
        node *uj = letrehoz(csomo);
        current->jobb = uj;
        felepit(current->jobb);
    }


};

void bejar(struct node* current)
{

    if (current->bal != NULL )
    {
        bejar(current->bal);
    }


    if (current->jobb!=NULL){

        bejar(current->jobb);
    }
    cout << current->index;

}

int main()
{
    int i, n, csomo;

    node *first = letrehoz(1);
    node *current = first;
    felepit(first);
    bejar(first);


    return 0;
}
