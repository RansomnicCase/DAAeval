#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return l->freq > r->freq;
    }
};

void storeCodes(MinHeapNode* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->data] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

void huffmanCoding(vector<char> &chars, vector<int> &freq) {
    
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < chars.size(); i++) {
        minHeap.push(new MinHeapNode(chars[i], freq[i]));
    }

    
    while (minHeap.size() != 1) {
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();

        
        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    
    unordered_map<char, string> huffmanCode;
    storeCodes(minHeap.top(), "", huffmanCode);

    
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << '\n';
    }

    string test = "abc";
    string encoded = "";
    for (char c : test)
        encoded += huffmanCode[c];

    cout << "\nOriginal string: " << test << "\nEncoded string: " << encoded << endl;
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCoding(chars, freq);
    return 0;
}
