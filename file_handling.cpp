#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream onFile;
    ifstream inFile ; char srr;
    onFile.open("D:\\College\\Semester 2\\OOP\\file2.txt");
    inFile.open("D:\\College\\Semester 2\\OOP\\file.txt");
    while (inFile.get(srr))
    {
        onFile.put(srr);
    }
    
    cout << "Everything is right :)" << endl;
    onFile.close();
    inFile.close();

}