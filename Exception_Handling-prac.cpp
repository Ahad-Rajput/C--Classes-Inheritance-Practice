#include <iostream>
#include <string>

using namespace std;

float divid(float a , float b){
    if (b == 0)
    {
        throw string("Division by zero error!");
    }
    return a/b;
}

int main()
{
    float x , y;
    cout << "Enter 1st num : ";
    cin >> x;
    cout << "Enter 2nd num : ";
    cin >> y;

    try{
        float ans = divid(x,y);
        cout << "Division of " << x << " and " << y << " is " << ans << endl;
    }
    catch(string e){
        cout << "Exception caught : " << e << endl;
    }
    cout << "Program is continue...." << endl;
    return 0;
}