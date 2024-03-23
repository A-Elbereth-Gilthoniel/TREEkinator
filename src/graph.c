#include "akinator.h"

void draw_graph(Tree* tree)
{
    char full_file_name[100] = FILE_REPOSITORY;
    strcat(full_file_name, "Tree_graph.dot");
    FILE* fp = fopen(full_file_name, "w");

    fprintf(fp, "digraph G {\
                \n  tree [shape=box ; stryle=rounded ; label=\"size : %d\"];\
                \n  edge [color=black];\
                \n  node [shape=record ; style=rounded ; color=green];\n", tree->size);

    print_node_in_graph(fp, tree->root);
    print_edge_in_graph(fp, tree->root);

    fprintf(fp, "}");
    fclose(fp);
}

//============================================================

void print_node_in_graph(FILE* fp, Node* node)
{
    if (!node->left && !node->right)
    {
        fprintf(fp, "%d [label=\"{%s}\"];\n", node, node->val);
        return;
    }
    fprintf(fp, "%d [label=\"{%s|{<YES> YES|<NO> NO}}\"];\n", node, node->val);
    if (node->left)
        print_node_in_graph(fp, node->left);
    if (node->right)
        print_node_in_graph(fp, node->right);
}

//===========================================================

void print_edge_in_graph(FILE* fp, Node* node)
{
    if (node->left)
    {
        fprintf(fp, "%d:<YES> -> %d [color=green];\n", node, node->left);
        print_edge_in_graph(fp, node->left);
    }
    if (node->right)
    {
        fprintf(fp, "%d:<NO> -> %d [color=red];\n", node, node->right);
        print_edge_in_graph(fp, node->right);
    }
}
