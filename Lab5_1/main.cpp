#include <iostream>

using namespace std;

int main()
{
    int N, i,j;
    cout << "N=";
    cin >> N;

    int matrix[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << "matrix[" << i << "][" << j << "]=";
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << matrix[i][j] << " " ;
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if (matrix[i][j]%2 == 0)
            {
                cout << matrix[i][j] << " " ;
            }
        }
    }


    return 0;
}
