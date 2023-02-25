/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Trie
 * Time: O(length of words)
 * Status: 
 */

struct Node {
    Node *child[MAX];
    int countWord;
};

Node* newNode(){
    Node* node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

// add a new word to the trie structure
void addWord(Node* root, string s){
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL){
            temp->child[ch] = newNode(); // add the ch character to the trie
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}

// find a particular word in the trie structure
bool findWord(Node* root, string s){
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL){
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}

//delete a word from a trie
bool isWord(Node* node){
    return (node->countWord != 0);
}
    // To check whether there are words at deeper levels
bool isEmpty(Node* node){
    for (int i = 0; i < MAX; i++){
        if (node->child[i] != NULL){
            return false;
        }
    }
    return true;
}

bool removeWord(Node* root, string s, int level = 0){
    if (!root){
        return false;
    }

    if (level == s.length()){
        if (root->countWord > 0){
            root->countWord--;
            return true;
        }
        return false;
    }

    int ch = s[level] - 'a';
    int flag = removeWord(root->child[ch], s, level + 1);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])){
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, weight;
    string word, t;
    Node* root = newNode();

    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> word >> weight;
        addWord(root, word, weight);
    }

    for (int i = 0; i < q; i++){
        cin >> t;
        cout << find(root, t) << endl;
    }
    return 0;
}