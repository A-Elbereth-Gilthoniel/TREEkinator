#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 100            // max number of symbols that user can input on one line
#define stack_t Node            // data type of stack's elements

#define green(str) "\033[32m"#str"\033[0m"
#define red(str) "\033[31m"#str"\033[0m"

#define FILE_REPOSITORY "./files/"

#define LEFT -1             // 'YES' in graph
#define FOUND 0             // Element is found in graph
#define RIGHT 1             // 'NO' in graph

#define VALUE_IS_NOT_FOUND -2   // Element is not found in graph

#define stack_assert(expr) if (expr != "NO_ERRORS"){\
    fprintf(stderr, red(There is error) ": File: %s, Function: %s, Line: %d, Error :  \"%s\"\n", __FILE__, __func__, __LINE__, expr);\
    exit(1);\
}


typedef struct node {
    char* val;
    struct node* left;
    struct node* right;
    struct node* prev;
    int path_to_def;
} Node;



typedef struct tree {
    Node* root;
    int size;
} Tree;


typedef struct stack {
    stack_t* data;
    int size;
    int capacity;
} Stack;
