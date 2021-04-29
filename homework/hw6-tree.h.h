#define TREE_H_INCLUDED

/* contiene un stuct adecuado para los nodos */
#define MAX_LENGHT 10

/* structure for nodes*/
typedef struct treenode {
  char *username;
  char *password;
  
  unsigned int depth;
  struct treenode* leftChild;
  struct treenode* rightChild;
} node;

void erase(node* pos);
node* insert(char *u, char *p, node *pos, int d);
void show(node* position, char prefix);
void alpha(node* position);



