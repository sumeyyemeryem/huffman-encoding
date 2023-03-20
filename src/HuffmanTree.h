#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;
#define EMPTY_STRING ""

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node* newNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }


    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{

    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        if(root->ch == '*'){
            cout << " ";
        }
        else{
            cout << root->ch;
        }
        return;
    }

    index++;

    if (str[index] == '0') {
        decode(root->left, index, str);
    }
    else {
        decode(root->right, index, str);
    }
}

void writeBinaryTree(Node *root, ostream &out) {
    if (!root) {
        out << "# ";
    }
    else {
        // found a leaf node
        if (isLeaf(root)) {
            out << root->ch << " ";
            return;
        }
        else{
            out << root->freq << " ";
            writeBinaryTree(root->left, out);
            writeBinaryTree(root->right, out);
        }
    }
}

void readBinaryTree(Node *&p, vector<string> &tokens) {
    if(tokens.empty()){
        return;
    }
    if ((tokens.at(0) >= "A" && tokens.at(0) <= "Z") || (tokens.at(0) >= "a" && tokens.at(0) <= "z") || (tokens.at(0) == "*")){
        p = new Node();
        p->ch = tokens.at(0)[0];
        tokens.erase(tokens.begin());
        return;
    }
    else {
        p = new Node();
        p->freq = stoi(tokens.at(0));
        tokens.erase(tokens.begin());
        readBinaryTree(p->left, tokens);
        readBinaryTree(p->right, tokens);
    }
}

void printTree(Node* root, int number){
    number++;
    for(int i = 0; i < number; i++){
        cout << " | ";
    }

    if (!root) {
        return;
    }
    else {
        // found a leaf node
        if (isLeaf(root)) {
            cout << "-" << root->ch << endl;
            return;
        }
        else{
            cout << "-" << root->freq << endl;
            printTree(root->right, number);
            printTree(root->left, number);
        }
    }
}

#endif // HUFFMANTREE_H