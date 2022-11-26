//编码

#include "HuffmanTree.h"

void HuffmanTree::compress(string in_filename, string out_filename)
{
    fstream infile;
    infile.open(in_filename, ios::in);
    if (!infile.is_open())
    {
        throw "Open infile failed, please enter correct filepath.\n";
        return;
    }
    string data;
    while (1)
    {
        char t;
        infile.get(t);
        if (infile.eof())
            break;
        data.push_back(t);
    }
    infile.close();

    fstream outfile;
    outfile.open(out_filename, ios::out);
    if (!outfile.is_open())
    {
        throw "Open outfile failed, please enter correct filepath.\n";
        return;
    }
    string Str;
    for (auto t : data)
    {
        Str += HuffmanCode[t];
    }
    outfile << Str << endl;
    outfile.close();
}