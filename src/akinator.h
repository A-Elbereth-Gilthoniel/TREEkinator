#include "libr.h"

//Stack.c
void StackConstructor(Stack *st, const size_t length);
void StackPush(Stack* st, stack_t value);
void StackDestructor(Stack* st);
stack_t StackPop(Stack* st);
void PrintStack(Stack* st);
void StackRealloc (Stack *st, const int new_capacity);
char* StackVerification(Stack *st);
void StackDump(Stack *st, const char* file, const char* func);
int TreeSearch(Node* root, Stack* stack, char* desired);
//tree.c
void PrintTree(Node* root, FILE* file);
void TreeDesructor(Tree* deleted_tree);
void DeleteNode(Node* deleted_node);
Node* InsertIntoTree(Tree* tree, char* new_val, Node* current_node, int indicator);
Tree* TreeConstructor();
Node* CreateNode(char* value);
//file.c
void convert_file_to_tree(Tree* tree, char* file_name);
size_t find_file_size(FILE* fp);
char* buf_reading(char* buf);
//game.c
void choose_operating_mode(Tree* tree, Stack* stack, char* file_name);
void guessing(Tree* tree, char* file_name);
void cmp_final_answer(Tree* tree, Node* current_node, char* file_name);
void add_new_elem(Tree* tree, Node* current_node);
void save_request(Tree* tree, char* file_name);
void definition(Tree* tree, Stack* stack);
void difference(Tree* tree, Stack* stack1);
//input.c
void clear_input_buffer();
//graph.c
void draw_graph(Tree* tree);
void print_node_in_graph(FILE* fp, Node* node);
void print_edge_in_graph(FILE* fp, Node* node);
