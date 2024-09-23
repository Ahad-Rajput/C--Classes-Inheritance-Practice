#include <iostream>
using namespace std;

int main()
{

    /*
    int arr[10] = {3,5,1,7};
    int *p;
    p = &arr[0];
    cout << p << endl;
    cout << *p << endl;
    */

    int arr[5] = {5,22,8,54,1};
    int *ptr = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << "  ";
        ptr++;
    }

    
    return 0;
}