#include <stdio.h>
#include <stdlib.h>

#define INSERT 1
#define DELETE 2
#define PRINT_ 3
#define EXIT 0
#define IN 1
#define PRE 2
#define POST 3
#define TRUE 1
#define FALSE 0
#define MIN_MAX 4
#define NON_CRESCENTE 4

struct node{
    int value;
    struct node *_left_son;
    struct node *_right_son;
    struct node *_parent;
};

typedef struct node NODE;
typedef struct node *_PtrNode;

void menu(void);
void insert(_PtrNode*,int,_PtrNode);
void in_order(_PtrNode);
void pre_order(_PtrNode);
void post_order(_PtrNode);
int is_empty(_PtrNode*);
_PtrNode search_node(_PtrNode,int);
_PtrNode minimum(_PtrNode);
_PtrNode maximum(_PtrNode);
void delete(_PtrNode,_PtrNode);
void transplant(_PtrNode*,_PtrNode,_PtrNode);
void non_crescent_order(_PtrNode _root);
_PtrNode delete_root(_PtrNode, _PtrNode);

int main() {
    int choice, value, choice_2;
    _PtrNode root = NULL, node_found;

    do{
        menu();
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case INSERT:
                printf("Insert a value: ");
                scanf("%d", &value);
                insert(&root,value,NULL);
                break;

            case DELETE:
                if(is_empty(&root)){
                    printf("Empty tree!\n");
                } else {
                    printf("Insert a value to delete: ");
                    scanf("%d", &value);

                    node_found = search_node(root,value);

                    if(node_found == NULL) {
                        printf("There isn't a node with value %d!\n", value);

                    } else {
                        if(node_found->_parent == NULL){
                            root = delete_root(root, node_found);
                        } else {
                            delete(root, node_found);
                        }
                    }
                }
                break;

            case PRINT_:
                if(is_empty(&root)){
                    printf("Empty tree!\n");
                } else {
                    printf("1.In-order\n");
                    printf("2.Pre-order\n");
                    printf("3.Post-order\n");
                    printf("4.Non crescent\n");
                    printf("Choice: ");
                    scanf("%d", &choice_2);

                    switch (choice_2) {
                        case IN:
                            in_order(root);
                            printf("\n");
                            break;
                        case PRE:
                            pre_order(root);
                            printf("\n");
                            break;
                        case POST:
                            post_order(root);
                            printf("\n");
                            break;
                        case NON_CRESCENTE:
                            non_crescent_order(root);
                            printf("\n");
                            break;
                    }
                }
                break;
            case MIN_MAX:
                if(is_empty(&root)){
                    printf("Empty tree!\n");
                } else {
                    node_found = minimum(root);
                    printf("The minimum is: %d\n", node_found->value);
                    node_found = maximum(root);
                    printf("The maximum is: %d\n", node_found->value);
                }
                break;
            case EXIT:
                printf("Bye bye!\n");
                break;
            default:
                printf("Invalid choice!\n");

        }
    } while (choice != 0);
    return 0;
}

void menu(void){
    printf("1.Insert new node\n");
    printf("2.Delete a node\n");
    printf("3.Print: IN-ORDER, PRE-ORDER, POST-ORDER\n");
    printf("4.Print minimum and maximum\n");
    printf("0.Exit\n");
}

void insert(_PtrNode *_root, int value, _PtrNode parent){
    _PtrNode index, new_node;
    index = *_root;

    if(index == NULL) {
        new_node = malloc(sizeof(NODE));

        if(new_node != NULL) {
            new_node->_parent = parent;
            new_node->_left_son = NULL;
            new_node->_right_son = NULL;
            new_node->value = value;

            *_root = new_node;
        } else {
            printf("Memory not available!\n");
        }
    } else {
        parent = index;

        if(value < index->value) {
            return insert(&index->_left_son,value,parent);
        } else /*if( value > index->value)*/ {
            return insert(&index->_right_son,value,parent);
        }
    }
}

void in_order(_PtrNode _index){
    if(_index != NULL){
        in_order(_index->_left_son);
        printf("%d ", _index->value);
        in_order(_index->_right_son);
    }
}

void pre_order(_PtrNode _index){
    if(_index != NULL){
        printf("%d ", _index->value);
        pre_order(_index->_left_son);
        pre_order(_index->_right_son);
    }
}

void post_order(_PtrNode _root){
    _PtrNode _index = _root;
    if(_index != NULL){
        post_order(_index->_left_son);
        post_order(_index->_right_son);
        printf("%d ", _index->value);
    }
}

void non_crescent_order(_PtrNode _root){
    _PtrNode _index = _root;
    if(_index != NULL){
        non_crescent_order(_index->_right_son);
        printf("%d ", _index->value);
        non_crescent_order(_index->_left_son);
    }
}

int is_empty(_PtrNode *_root){
    if(*_root == NULL)
        return TRUE;
    return FALSE;
}

_PtrNode minimum(_PtrNode _index){
    while(_index->_left_son != NULL){
        _index = _index->_left_son;
    }
    return _index;
}

_PtrNode maximum(_PtrNode _index){
    while(_index->_right_son != NULL){
        _index = _index->_right_son;
    }
    return _index;
}

_PtrNode search_node(_PtrNode _root, int value){
    _PtrNode index = _root;

    if((index == NULL) || (index->value == value)){
        return index;
    } else {
        if(value < index->value) {
            return search_node(index->_left_son, value);
        } else {
            return search_node(index->_right_son, value);
        }
    }
}

void transplant(_PtrNode *_root, _PtrNode u, _PtrNode v){
    if(u->_parent == NULL) {
        *_root = v;
    } else if(u == u->_parent->_left_son) {
        u->_parent->_left_son = v;
    } else {
        u->_parent->_right_son = v;
    }
    if (v != NULL) {
        v->_parent = u->_parent;
    }
}

void delete(_PtrNode index, _PtrNode node_found) {
    _PtrNode take_pos;

    if(node_found->_left_son == NULL){
        transplant(&index,node_found,node_found->_right_son);
    } else if(node_found->_right_son == NULL){
        transplant(&index,node_found,node_found->_left_son);
    } else {
        take_pos = minimum(node_found->_right_son);

        if (take_pos->_parent != node_found) {
            transplant(&index, take_pos, take_pos->_right_son);
            take_pos->_right_son = node_found->_right_son;
            take_pos->_right_son->_parent = take_pos;
        }
        transplant(&index, node_found, take_pos);
        take_pos->_left_son = node_found->_left_son;
        take_pos->_left_son->_parent = take_pos;
    }
}

_PtrNode delete_root(_PtrNode root, _PtrNode node_found) {
    //_PtrNode index = root, index_;
    if (node_found->_left_son == NULL && node_found->_right_son == NULL) {
        return NULL;
    }
}