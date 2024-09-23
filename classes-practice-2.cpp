#include <iostream>
#include <string>

using namespace std;

// class Person{
// private:
//     int x , y;
// public:
//     Person(int a , int b){
//         x = a;
//         y = b;
//     };

//     void print(){
//         cout << x << endl << y << endl;
//     };
// };

// int main()
// {

//     Person obj(7,5);
//     obj.print();
//     return 0;

// }

class Student{
private:
    int idcard;
    string address;
public:
    int set_id_card();
    int get_id_card();
};

int Student :: set_id_card(int a){
    idcard = a;
}
int Student :: get_id_card(){
    return idcard; 
}