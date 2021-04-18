#include <stdio.h>
#include <stdlib.h>

#define INSERT 1
#define DELETE 2
#define PRINT 3
#define EXIT 0
#define TRUE 1
#define FALSE 0

struct node{
    int value;
    struct node *_next;
};

typedef struct node NODE;
typedef struct node *_PtrNode;

/*
 * La funzione "insert" è la PUSH;
 * La funzione "delete" è la POP;
 * La funzione "emptyStack" verifica se lo stack è vuoto;
 */
void menu(void);
void insert(_PtrNode*, int);
void delete(_PtrNode*);
void print(_PtrNode*);
int emptyStack(_PtrNode*);

int main() {
    int choice, value;
    _PtrNode root = NULL;

    do {
        menu();
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice){
            case INSERT:
                printf("Dimmi il valore da inserire: ");
                scanf("%d",&value);

                insert(&root, value);
                break;
            case DELETE:
                if(emptyStack(&root)) {
                    delete(&root);
                } else {
                    printf("Stack vuoto!\n");
                }
                break;
            case PRINT:
                print(&root);
                break;
            case EXIT:
                printf("Ciao!\n");
                break;
            default: printf("Scelta non valida!\n");
        }
    } while (choice != 0);
    return 0;
}

void menu(void){
    printf("1.Inserisci un valore\n");
    printf("2.Elimina il valore in coda\n");
    printf("3.Stampa stack\n");
    printf("0.Esci\n");
}

void insert(_PtrNode *root, int value){
    _PtrNode new_node, index;

    new_node = malloc(sizeof(NODE));

    if(new_node != NULL){
        new_node->_next = NULL;
        new_node->value = value;
        if(*root == NULL){
            *root = new_node;
        } else {
            index = *root;

            while(index->_next != NULL){
                index = index->_next;
            }
            index->_next = new_node;
        }
    } else {
        printf("Memoria insufficiente per allocare un nuovo nodo!\n");
    }
}

void delete(_PtrNode *_root){
    _PtrNode index;
    index = *_root;

    if(index->_next == NULL) {
        *_root = NULL;
        free(index);
    } else {
        *_root = index->_next;
        free(index);
    }
}


void print(_PtrNode *_root){
    _PtrNode index;

    if(*_root == NULL){
        printf("Non è presente alcun elemento nello stack!\n");
    } else {
        index = *_root;
        while(index->_next != NULL){
            printf("%d -> ", index->value);
            index = index->_next;
        }
        printf("%d -> NULL\n", index->value);
    }
}

int emptyStack(_PtrNode *_root){
    if(*_root != NULL)
        return TRUE;
    return FALSE;
}