#include "HuffmanTree.h"

void menu();

int main()
{
    cout << "Please enter a file to build the HuffmanTree:";
    string file;
    cin >> file;
    cout << "Processing..." << endl;
    HuffmanTree *huffmanTree = new HuffmanTree(file);
    cout << "Process end." << endl;
    while (true)
    {
        menu();
        string choice;
        cin >> choice;
        if (choice == "1" || choice == "2")
        {
            if (choice == "1")
            {
                cout << "Please input source file name(size less than 4GB): ";
                string in_filename;
                cin >> in_filename;
                cout << "Please input code file name: ";
                string out_filename;
                cin >> out_filename;
                cout << "Processing..." << endl;
                huffmanTree->compress(in_filename, out_filename);
                cout << "Process end." << endl;
            }
            else
            {
                cout << "Please input code file name: ";
                string in_filename;
                cin >> in_filename;
                cout << "Please input target file name: ";
                string out_filename;
                cin >> out_filename;
                cout << "Processing..." << endl;
                huffmanTree->decompress(in_filename, out_filename);
                cout << "Process end." << endl;
            }
        }
        else if (choice == "3")
            break;
    }
    return 0;
}

void menu()
{
    cout << endl
         << "1.Huffman compress."
         << endl
         << "2.Huffman decompress."
         << endl
         << "3.Exit."
         << endl
         << "Please select: ";
}