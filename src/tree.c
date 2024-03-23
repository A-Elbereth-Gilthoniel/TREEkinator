#include "akinator.h"

//===============================================

Node* CreateNode(char* value)
{
    Node* new_node = (Node*) calloc(1, sizeof(Node));
    new_node->val = (char*) calloc(STR_SIZE, sizeof(char));

    strcpy(new_node->val, value);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->prev = NULL;
}

//===============================================

Tree* TreeConstructor()
{
    Tree* new_tree = (Tree*) calloc(1, sizeof(Tree));
    new_tree->size = 0;

    return new_tree;
}

//===============================================

Node* InsertIntoTree(Tree* tree, char* new_val, Node* current_node, int indicator)
{
    Node* new_node = CreateNode(new_val);

    tree->size++;

    if (tree->size == 1)
    {
        tree->root = new_node;
        return new_node;
    }

    new_node->prev = current_node;

    if (indicator == RIGHT)
    {
        current_node->right = new_node;
    }
    else if (indicator == LEFT)
    {
        current_node->left = new_node;
    }

    return new_node;
}

//=======================================================

void DeleteNode(Node* deleted_node)
{
    if (!deleted_node)
        return;

    if (deleted_node->left)
        DeleteNode(deleted_node->left);

    if (deleted_node->right)
        DeleteNode(deleted_node->right);

    free(deleted_node);
}

//==============================================

void TreeDesructor(Tree* deleted_tree)
{
    if (!deleted_tree)
        return

    DeleteNode(deleted_tree->root);
}

//===============================================

void PrintTree(Node* root, FILE* file)
{
    if (!root)
    {
        fprintf(file, "null ");
        return;
    }

    fprintf(file, "( ");
    fprintf(file, "\"%s\" ",root->val);
    PrintTree(root->left, file);
    PrintTree(root->right, file);
    fprintf(file, " )");
}

//===============================================


int TreeSearch(Node* root, Stack* stack, char* desired)         // return deep of the element
{
    if (!root)
    {
        return VALUE_IS_NOT_FOUND;
    }

    if (strcmp(root->val, desired) == 0)
    {
        root->path_to_def = FOUND;
        StackPush(stack, *root);
        return 1;
    }

    int deep_left = TreeSearch(root->left, stack, desired);
    if (deep_left != VALUE_IS_NOT_FOUND)
    {
        root->path_to_def = LEFT;
        StackPush(stack, *root);
        return deep_left + 1;
    }

    int deep_right = TreeSearch(root->right, stack, desired);
    if (deep_right != VALUE_IS_NOT_FOUND)
    {
        root->path_to_def = RIGHT;
        StackPush(stack, *root);
        return deep_right + 1;
    }

    return VALUE_IS_NOT_FOUND;
}

//=====================================================================
