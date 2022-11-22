//通过HuffmanCode译码并输出至out_filename

#include "HuffmanTree.h"

void HuffmanTree::decompress(string in_filename, string out_filename)
{
    fstream infile;
    infile.open(in_filename,ios::in);
    if(!infile.is_open())
    {
        cout <<"读取文件失败"<<endl;
        return;
    }
    char data[1001];
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
    int index = 0;
    HuffmanNode* node = root;
    while(index <= max_Index)
    {
        while(node->left != NULL||node->right != NULL)
        {
            if(data[index++] == 0)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        Str += node->ch;
    }
    outfile << Str <<endl;
    outfile.close();
}