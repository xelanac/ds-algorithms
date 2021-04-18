#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *_next;
    struct node *_parent;
};

typedef struct node NODE;
typedef struct node *_P_NODE;

void insert_node(_P_NODE*,int);
void print_list(_P_NODE);
void menu();
void reverse(_P_NODE*);

int main() {
    _P_NODE root = NULL;

    int choice = 0, value;

        do{
            menu();
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Valore: ");
                    scanf("%d", &value);

                    insert_node(&root,value);
                    break;
                case 2:
                    print_list(root);
                    break;

                case 3:
                    reverse(&root);
                    break;
                case 0:
                    printf("Ciao!\n");
                    break;

            }
        } while(choice != 0);
    return 0;
}

void insert_node(_P_NODE *root, int value){
    _P_NODE index, new_node;

    index = *root;

    new_node = malloc(sizeof(NODE));

    if(new_node != NULL){
        new_node->value = value;
        new_node->_next = NULL;
        if(*root != NULL){
            while(index->_next != NULL){
                index = index->_next;
            }
            new_node->_parent = index;
            index->_next = new_node;


        } else {
            new_node->_parent = NULL;
            *root = new_node;
        }
    } else {
        printf("Spazio insufficiente per allocare un nuovo nodo!\n");
    }
}

void print_list(_P_NODE root){
    _P_NODE index;

    index = root;

    while(index->_next != NULL){
        printf("%d -> ", index->value);
        index = index->_next;
    }
    printf("%d -> NULL\n", index->value);


}

void reverse(_P_NODE *root){
    _P_NODE index;

    if(*root == NULL){
        printf("Lista vuota!\n");
        return;
    } else if((*root)->_next == NULL) {
        printf("La coda rimane invariata poichè contiene solo un elemento!\n");
        return;
    } else {
        index = *root;

        while(index->_next != NULL){
            index = index->_next;
        }

        while(index->_parent != NULL) {
            printf("%d -> ", index->value);
            index = index->_parent;
        }
        printf("%d -> NULL\n", index->value);

    }
}

void menu(){
    printf("1.Inserici nodo\n");
    printf("2.Stampa lista\n");
    printf("3.Reverse lista\n");
    printf("0.Exit\n");

    printf("Scelta: ");
}