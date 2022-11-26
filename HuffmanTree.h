#include <iostream>
#include <deque>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class HuffmanTree
{
public:
    bool operator<(const HuffmanTree *t1)
    {
        return t1->root->frequency < this->root->frequency;
    }

private:
    // Huffman树节点
    struct HuffmanNode
    {
        int frequency;      //节点的频率值
        char ch;            //节点的字符
        HuffmanNode *left;  //节点左儿子
        HuffmanNode *right; //节点右儿子

        HuffmanNode(int f, HuffmanNode *l = nullptr, HuffmanNode *r = nullptr)
            : frequency(f), left(l), right(r) {}
        ~HuffmanNode(){};
    };
    HuffmanNode *root;                    //根节点
    priority_queue<HuffmanTree *> forest; //森林
    string HuffmanCode[130];              //记录某字符的哈夫曼编码如 A的ASCII码为65, 哈夫曼编码101 则HuffmanCode[65]=101

public:
    HuffmanTree(){};
    HuffmanTree(string in_filename); // 生成哈夫曼树,并调用orderHuffmanTree写入HuffmanCode
    void func(HuffmanNode *cur, string t);

    void compress(string in_filename, string out_filename);   //通过HuffmanCode编码并输出至out_filename
    void decompress(string in_filename, string out_filename); //通过HuffmanCode译码并输出至out_filename
};