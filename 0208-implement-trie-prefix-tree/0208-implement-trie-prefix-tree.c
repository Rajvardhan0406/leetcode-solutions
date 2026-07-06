typedef struct Trie {
    struct Trie* children[26];
    bool isEnd;
} Trie;

Trie* trieCreate() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            curr->children[idx] = trieCreate();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}

Trie* trieWalk(Trie* obj, char* str) {
    Trie* curr = obj;
    for (int i = 0; str[i] != '\0'; i++) {
        int idx = str[i] - 'a';
        if (curr->children[idx] == NULL) {
            return NULL;
        }
        curr = curr->children[idx];
    }
    return curr;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* node = trieWalk(obj, word);
    return node != NULL && node->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* node = trieWalk(obj, prefix);
    return node != NULL;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}