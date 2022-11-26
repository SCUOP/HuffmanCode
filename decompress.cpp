//通过HuffmanCode译码并输出至out_filename

#include "HuffmanTree.h"

void HuffmanTree::decompress(string in_filename, string out_filename)
{
    fstream infile;
    infile.open(in_filename, ios::in);
    if (!infile.is_open())
    {
        throw "Open infile failed, please enter correct filepath.\n";
        return;
    }
    string data;
    while (true)
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
    HuffmanNode *node = root;
    for (auto t : data)
    {
        if (node->left != NULL || node->right != NULL)
        {
            if (t == '0')
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        if (node->left == NULL && node->right == NULL)
        {
            Str += node->ch;
            node = root;
        }
    }
    outfile << Str << endl;
    outfile.close();
}