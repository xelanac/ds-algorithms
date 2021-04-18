#include <stdio.h>
#include <stdlib.h>

#define INSERT 1
#define DELETE 2
#define PRINT 3
#define EXIT 0
#define TRUE 1
#define FALSE 0

struct node{
    struct node *_next;
    int value;
};

typedef struct node *_PtrNode;
typedef struct node NODE;

void menu(void);
void insert(_PtrNode*,int);
void print(_PtrNode*);
int isEmpty(_PtrNode*);
void delete(_PtrNode*);

int main() {
    int choice, value;
    _PtrNode root;

    do{
        menu();
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice){
            case INSERT:
                printf("Inserisci un valore: ");
                scanf("%d", &value);
                insert(&root,value);
                break;
            case DELETE:
                if(isEmpty(&root)){
                    printf("Lista vuota!\n");
                } else {
                    delete(&root);
                }
                break;
            case PRINT:
                if(isEmpty(&root)) {
                    printf("Lista vuota!\n");
                } else {
                    print(&root);
                }
                break;
            case EXIT:
                printf("Ciao!\n");
                break;
            default:printf("Scelta non valida!\n");
        }
    } while(choice != 0);
    return 0;
}

void menu(void){
    printf("1.Inserisci un nuovo nodo\n");
    printf("2.Elimina il primo nodo\n");
    printf("3.Stampa la coda\n");
    printf("0.Esci dal programma\n");
}

void insert(_PtrNode *_root, int value){
    _PtrNode new_node, index;

    new_node = malloc(sizeof(NODE));

    if(new_node != NULL){
        new_node->_next = NULL;
        new_node->value = value;

        if(*_root == NULL){
            *_root = new_node;
        } else {
            index = *_root;
            while(index->_next != NULL){
                index = index->_next;
            }
            index->_next = new_node;
        }
    } else {
        printf("Memoria insufficiente!\n");
    }
}

void print(_PtrNode *_root){
    _PtrNode index;

    index = *_root;

    while(index->_next != NULL){
        printf("%d -> ", index->value);
        index = index->_next;
    }

    printf("%d -> NULL\n", index->value);

}

int isEmpty(_PtrNode *_root){
    if(*_root == NULL)
        return TRUE;
    return FALSE;
}

void delete(_PtrNode *_root){
    _PtrNode index, previous;
    index = *_root;

    if((*_root)->_next == NULL){
        *_root = NULL;
        free(index);
    } else {
        while(index->_next != NULL){
            previous = index;
            index = index->_next;
        }
        previous->_next = NULL;
        free(index);
    }
}