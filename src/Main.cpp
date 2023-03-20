#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include "HuffmanTree.h"
using namespace std;
int main(int argc, char *argv[]) {

    string type = argv[1];
    if (type == "-i") {
        ifstream input(argv[2]);
        string command = argv[3]; //encode or decode

        string text;//one line input
        if (!input.fail()) getline(input, text);


        if (command == "-encode") {
            ofstream out("tree.txt"); //to save the tree
            // convert string to lower case
            for_each(text.begin(), text.end(), [](char & c) {c = tolower(c);});

            // base case: empty string
            if (text == EMPTY_STRING) {
                return 0;
            }

            // count frequency of appearance of each character and store it in a map
            unordered_map<char, int> freq;
            for (char ch: text) {
                if(ch == ' '){
                    ch = '*';// to indicate the space
                }
                freq[ch]++;
            }

            // Create a priority queue to store live nodes of Huffman tree
            priority_queue<Node*, vector<Node*>, comp> queue;

            // Create a leaf node for each character and add it to the priority queue.
            for (auto pair: freq) {
                queue.push(newNode(pair.first, pair.second, nullptr, nullptr));
            }

            // do until there is more than one node in the queue
            while (queue.size() != 1)
            {
                // Remove the two nodes of the highest priority (the lowest frequency) from the queue

                Node *left = queue.top(); queue.pop();
                Node *right = queue.top(); queue.pop();

                // Create a new internal node with these two nodes
                int sum = left->freq + right->freq;
                queue.push(newNode('\0', sum, left, right));
            }

            Node* root = queue.top();

            // Traverse the Huffman Tree and store Huffman Codes in a map.
            unordered_map<char, string> huffmanCode;
            encode(root, EMPTY_STRING, huffmanCode);

            // Print encoded string
            string str;
            for (char ch: text) {
                if(ch == ' '){
                    ch = '*';
                }
                str += huffmanCode[ch];
            }

            cout << "\nEncoded string is:\n" << str << '\n';

            //save the tree to a file starting from the root
            writeBinaryTree(root, out);
            out.close();
        }

        //decoding
        else{
            ifstream tree("tree.txt");
            vector<string> tokens;
            string line;
            getline(tree, line) ;
            istringstream iss(line);
            string token;
            while(getline(iss, token, ' ')) tokens.push_back(token);
            Node *root;
            readBinaryTree(root, tokens);
            tree.close();
            cout << "\nDecoded string is:\n";
            if (isLeaf(root))
            {
                // Special case: For input like a, aa, aaa, etc.
                while (root->freq--) {
                    cout << root->ch;
                }
            }
            else
            {
                // Traverse the Huffman Tree again and this time, decode the encoded string
                int index = -1;
                while (index < (int)text.size() - 1) {
                    decode(root, index, text);
                }
                cout << endl;
            }
        }
    }

    //give the encoding for a particular char
    if(type == "-s"){
        string s = argv[2];
        const char *c = s.c_str();
        ifstream tree("tree.txt");
        vector<string> tokens;
        string line;
        getline(tree, line) ;
        istringstream iss(line);
        string token;
        while(getline(iss, token, ' ')) tokens.push_back(token);
        Node *root;
        readBinaryTree(root, tokens);
        tree.close();
        unordered_map<char, string> huffmanCode;
        encode(root, EMPTY_STRING, huffmanCode);
        cout << "\nHuffman code of " << c <<": ";
        for (auto pair: huffmanCode) {
            if(pair.first == *c){
                cout << pair.second << '\n';
            }
        }
    }

    //print the tree
    if(type == "-l"){
        ifstream tree("tree.txt");
        vector<string> tokens;
        string line;
        getline(tree, line) ;
        istringstream iss(line);
        string token;
        while(getline(iss, token, ' ')) tokens.push_back(token);
        Node *root;
        readBinaryTree(root, tokens);
        tree.close();
        printTree(root, -1);

    }
}

