#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define TAMANHO 13


struct TrieNode
{
 struct TrieNode *children[TAMANHO];
 bool isEndOfWord;
}; 

struct *TrieNode createKey()
{
  TrieNode *No=(TrieNode*)malloc(sizeof(TrieNode));
    No->isEndOFWord=False;

      for (int i = 0; i < ; i++) {
        node->children[i] = NULL;

    }
  return No;
};
bool trieinsert(TrieNode *root, char *signedtext){
  if(root==NULL){
    root = createKey();
  }
  unsigned char *text = (unsigned char *)signedtext;
  TrieNode *tmp = *root;
  int lenght =strlen(signedtext);

  for(int i=0; i<lenght; i++){
    if(tmp->children[text[i]]==NULL){
      tmp->children[text[i]] = createKey();
    }
    tmp=tmp->children[text[i]];
  }
  if(tmp->isEndOfWord){
    return false;
  }
  else{
    tmp->isEndOfWord =true;
    return true;
  }
}
 void prinTrie_Trie(TrieNode *Node, unsigned char *prefix, int lenght){
  unsigned char newprefix[lenght +2];
  memcpy(newprefix, prefix, lenght);
  newprefix[lenght+1]=0;

  if(Node->isEndOfWord){
    printf("Palavra %s\n", prefix);

  }
  for(int i=0; i<TAMANHO; i++){
    if(Node->children[i]!=NULL);
    newprefix[lenght] =i;
    prinTrie_Trie(Node->children[i], newprefix, lenght+1)
  }
 }




void printTrie(TrieNode* root){
  if(root==NULL){
    printf("Trie Vazia");
    return ;

  }
  printTrie_Trie(root,NULL,0);
}

int main(){
  TrieNode *root=NULL;
}