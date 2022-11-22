//编码

#include "HuffmanTree.h"

void HuffmanTree::compress(string in_filename, string out_filename)
{
    fstream infile;
    infile.open(in_filename,ios::in);
    if(!infile.is_open())
    {
        cout <<"读取文件失败"<<endl;
        return;
    }
    char data[101];
    int i = 0;
    while(!infile.eof())
        infile>>data[i++];
        infile.close();
    i--;
    int max_Index = i;

    fstream outfile;
    outfile.open(out_filename,ios::out);
    if(!outfile.is_open())
    {
        cout <<"读取文件失败"<<endl;
        return;
    }
    string Str;
    for(int index = 0;index <= max_Index;index++)
    {
        Str += HuffmanCode[data[index]];
    }
    outfile << Str <<endl;
    outfile.close();
}