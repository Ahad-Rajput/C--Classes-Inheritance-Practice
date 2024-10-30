#include <iostream>
using namespace std;

class Time
{
private:
    int hour, minute, second;
public:
    Time(){
        hour = 9;
        minute = second = 0;
    }
    void show(){
        cout << "Time : \n" << hour << " : " << minute << " : " << second << endl;
    }
    Time operator ++ (int){
        Time temp;
        minute += 1;
        temp.minute = minute;
        return temp;
    }
    Time operator -- (int){
        Time temp;
        minute -= 1;
        temp.minute = minute;
        return temp;
    }
};

main()
{
    Time t;
    t.show();
    cout << "-----------------\n";
    t++;
    t.show();
    cout << "-----------------\n";
    t--;
    t.show();
}
