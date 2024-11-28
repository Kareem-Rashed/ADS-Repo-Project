#include <iostream>
#include "Huffman.h"
using namespace std;



int main()
{

    Huffman zipping("../Code_lib/testingfile.txt");

    zipping.Compress("Normal");

    Huffman Unzip("Compressed.txt");
    Unzip.Decompress("Normal");




    return 0;
}
