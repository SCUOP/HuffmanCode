// 生成哈夫曼树,并调用orderHuffmanTree写入HuffmanCode

#include "HuffmanTree.h"
#include <map>
#include <stack>

void HuffmanTree::func(HuffmanNode *cur, string t)
{
    if (cur->left != NULL)
    {
        func(cur->left, t + "0");
        func(cur->right, t + "1");
    }
    else
    {
        HuffmanCode[cur->ch] = t;
    }
};

HuffmanTree::HuffmanTree(string in_filename)
{
    ifstream infile(in_filename);
    if (infile.fail())
    {
        cout << "open file failed" << endl;
        return;
    }
    string s;
    while (!infile.eof())
    {
        char t;
        infile.get(t);
        s.push_back(t);
    }
    infile.close();
    int a[130];
    fill(a, a + 130, 0);
    for (auto t : s)
    {
        a[t]++;
    }
    for (int i = 0; i < 130; i++)
    {
        if (a[i])
        {
            HuffmanTree *t0 = new HuffmanTree;
            HuffmanNode *t = new HuffmanNode(a[i]);
            t->frequency = a[i];
            t->ch = i;
            t0->root = t;
            forest.push(t0);
        }
    }
    while (forest.size() != 1)
    {
        int t11 = forest.top()->root->frequency;
        HuffmanTree *t12 = forest.top();
        forest.pop();
        int t21 = forest.top()->root->frequency;
        HuffmanTree *t22 = forest.top();
        forest.pop();
        HuffmanTree *t = new HuffmanTree;
        HuffmanNode *t0 = new HuffmanNode(t11 + t21, t12->root, t22->root);
        t->root = t0;
        forest.push(t);
    }
    string t;
    root = forest.top()->root;
    func(root, t);
}