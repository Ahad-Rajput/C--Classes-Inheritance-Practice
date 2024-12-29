#include <iostream>
using namespace std;

class Hero{
private:
    int health;
    char level;
public:
    // Parametrized Constructor
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }
    // Copy Constructor
    Hero(Hero& temp){
        cout << "Copy Constructor Called." << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    // Member function to display value
    void PrintClass(){
        cout << "Health : " << health << endl;
        cout << "Level : " << level << endl;
    }
};

int main()
{
    Hero h1(70,'$');
    h1.PrintClass();
    Hero h2(h1);
    h2.PrintClass();
    return 0;
}