#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int countLength(int n)
{
    int nr = 0;
    while(n>0)
    {
        n/=10;
        nr++;
    }
    return nr;
}

int main()
{
    ifstream in("input.txt");
    unordered_map<int, int> prefixes;
    int n, m, a[1000], b[1000];
    in >> n;
    for(int i = 0; i<n; i++)
    {
        in >> a[i];
        int temp = a[i];
        int length = countLength(temp);
        prefixes[temp] = length;
        while(temp > 0)
        {
            length--;
            temp /= 10;
            prefixes[temp] = length;
        }

    }
    int longest = 0;
    in >> m;
    for(int i = 0; i<m; i++)
    {
        in >> b[i];
        int temp = b[i];
        while(temp > 0 && prefixes.count(temp)==0 )
        {
            temp /= 10;
        }
        if (prefixes.count(temp) > 0)
        {
            if (longest < prefixes[temp])
            {
                longest = prefixes[temp];
            }
        }
    }
    cout << longest << endl;
    return 0;
}
