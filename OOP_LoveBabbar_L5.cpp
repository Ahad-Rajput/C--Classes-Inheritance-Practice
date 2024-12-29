#include <iostream>
#include <cstring>
using namespace std;

class demo{
private:
    int num;
public:
    char *name;
public:
    demo(){
        name = new char[10];
    }
    // Copy constructor (Deep Copy)
    demo(const demo& temp) {
        num = temp.num; // Copy `num` directly
        name = new char[strlen(temp.name) + 1]; // Allocate new memory for `name`
        strcpy(name, temp.name); // Copy the string
    }

    // Destructor to free memory
    ~demo() {
        delete[] name;
    }
    void setNum(int num){
        this->num = num;
    }
    void setName(char name[]){
        strcpy(this->name, name);
    }
    void display(){
        cout << "[ " << this->name << " , "
        << this->num << " ]"<< endl;
        cout << endl;
    }
};

int main()
{
    demo d1;
    d1.setNum(90);
    char name[10] = "Babbar";
    d1.setName(name);
    d1.display();

    demo d2 = d1;
    d2.display();

    d1.name[0] = 'G';
    d1.display();

    d2.display();

    return 0;
}