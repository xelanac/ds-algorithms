#include <stdio.h>
#include <stdlib.h>

#define INSERT 1
#define DELETE 2
#define PRINT 3
#define EXIT 0

struct node{
    struct node *_next;
    int value;
};

typedef struct node _node;
typedef struct node *_PtrNode;

void menu(void);
void insert(_PtrNode*,int);
void print(_PtrNode);
void delete(_PtrNode*,int);

int main() {

    int choice = 0, num = 0;
    _PtrNode root = NULL;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case INSERT:
                printf("Dammi un numero: ");
                scanf("%d", &num);
                insert(&root, num);
                break;
            case DELETE:
                printf("Quale valore della lista vuoi eliminare?");
                scanf("%d", &num);
                delete(&root,num);
                break;
            case PRINT:
                print(root);
                break;
            case EXIT:
                printf("Ciao!\n");
                break;
                default:
                printf("Scelta non valida!\n");
        }
    } while (choice != 0);
}

void menu(){
    printf("\n1.Aggiungi un nuovo nodo\n");
    printf("2.Elimina un nodo\n");
    printf("3.Stampa la lista\n");
    printf("Scelta: ");
}

void insert(_PtrNode *root, int value){
    _PtrNode index, new_node;

    new_node = malloc(sizeof(_node));

    if(new_node != NULL){
        new_node->value = value;
        new_node->_next = NULL;
        if(*root != NULL){
            index = *root;
            while(index->_next != NULL){
                index = index->_next;
            }
            index->_next = new_node;
        } else {
             *root = new_node;
        }
    } else {
        printf("Spazio insufficiente per allocare un nuovo nodo!\n");
    }
}

void print(_PtrNode root){
    _PtrNode index;
    index = root;
    if(index != NULL) {
        while (index->_next != NULL) {
            printf("%d -> ", index->value);
            index = index->_next;
        }
        printf("%d -> NULL", index->value);
    } else {
        printf("Non è presente alcun elemento nella lsta!\n");
    }
}

void delete(_PtrNode *root, int value){
    _PtrNode index, previous;
    index = *root;

    if(value == index->value){
        *root = index->_next;
        free(index);
    } else {
        while ((index->_next != NULL) && (index->value != value)) {
            previous = index;
            index = index->_next;
        }

        if (index->value == value) {
            previous->_next = index->_next;
            free(index);
        } else {
            printf("Non è presente alcun elemento nella lista con questo valore!\n");
        }
    }
}