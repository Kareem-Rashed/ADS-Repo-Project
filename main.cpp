#include <iostream>
#include "Huffman.h"
using namespace std;



int main()
{

    cout<<"Hello, would you like to compress or decompress? "<<endl;
    cout<<"1. Compress"<<endl;
    cout<<"2. Decompress"<<endl;
    cout<<"3. Exit"<<endl;

    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;

    if(choice == 1)
    {
        cout<<"Enter the file name: ";
        string filename;
        cin>>filename;
        Huffman zipping(filename);
        cout<<"How would you like to encrypt it? "<<endl;
        cout<<"1. Normal"<<endl;
        cout<<"2. Ceaser"<<endl;
        int choice2;
        cin>>choice2;
        if(choice2 == 1)
        {
            zipping.Compress("Normal");
        }
        else if(choice2 == 2)
        {
            zipping.Compress("Ceaser");
        }
    }
    else if(choice == 2)
    {
        cout<<"Enter the file name: ";
        string filename;
        cin>>filename;
        cout<<"How was it encrypted? "<<endl;
        cout<<"1. Normal"<<endl;
        cout<<"2. Ceaser"<<endl;
        int choice2;
        cin>>choice2;
        if(choice2 == 1)
        {
            Huffman Unzip(filename);
            Unzip.Decompress("Normal");
        }
        else if(choice2 == 2)
        {
            Huffman Unzip(filename);
            Unzip.Decompress("Ceaser");
        }
    }
    else if(choice == 3)
    {
        exit(0);
    }









    return 0;
}
