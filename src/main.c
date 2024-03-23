#include "akinator.h"

int main(int argc, char *argv[])
{
    char file_name[100] = FILE_REPOSITORY;
    strcat(file_name, argv[1]);
    printf("%s\n", file_name);
    Tree* tree = TreeConstructor();
    int capacity = 10;
    Stack* stk = (Stack*) calloc(1, sizeof(Stack));
    StackConstructor(stk, capacity);

    convert_file_to_tree(tree, file_name);

    choose_operating_mode(tree, stk, file_name);

    draw_graph(tree);

    StackDestructor(stk);

    return 0;
}
