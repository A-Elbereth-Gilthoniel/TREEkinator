#include "akinator.h"


void choose_operating_mode(Tree* tree, Stack* stack, char* file_name)
{
    printf("\n"green(What game do you want to play?)"\nGuessing - press 'g'\nDefinition - press 'd'\nDifferences - press 'f'\n");
    char chr = getch();

    if (chr == 'g')
    {
        fprintf(stdout, "\n"green(Let s guessing!)"\n");
        guessing(tree, file_name);
        return;
    }

    if (chr == 'd')
    {
        fprintf(stdout, "\n"green(Let s definition)"\n");
        definition(tree, stack);
        return;
    }

    if (chr == 'f')
    {
        fprintf(stdout, "\n"green(Let s search difference!)"\n");
        difference(tree, stack);
        return;
    }
    else
    {
        fprintf(stdout, "\n"red(Error!)" Please, press right buttons\n");
        choose_operating_mode(tree, stack, file_name);
    }
}

//=======================================================

void guessing(Tree* tree, char* file_name)
{
    Node* current_node = tree->root;

    while (1)
    {
        printf("\nIt is %s?\n", current_node->val);
        char chr = getch();
        if (chr == 'y')
        {
            printf(green(YES)"\n");
            current_node = current_node->left;

            if (!current_node->left)
            {
                cmp_final_answer(tree, current_node, file_name);
                break;
            }
        }
        else if (chr == 'n')
        {
            printf(red(NO)"\n");
            current_node = current_node->right;

            if (!current_node->right)
            {
                cmp_final_answer(tree, current_node, file_name);
                break;
            }
        }
        else
        {
            printf("\n"red(Error!)" Please, push 'y'(Yes) or 'N'(no)\n");
        }
    }
}

//========================================================

void cmp_final_answer(Tree* tree, Node* current_node, char* file_name)
{
    printf("\nIt is %s?\n", current_node->val);
    char chr = getch();
    if (chr == 'y')
    {
        printf(green(YES)"\n");
        printf("\n"green(WIN!!!)"\n");
        return;
    }
    else if (chr == 'n')
    {
        printf(red(NO)"\n");
        add_new_elem(tree, current_node);
        save_request(tree, file_name);
    }
}

//========================================================

void add_new_elem(Tree* tree, Node* current_node)
{
    char* answer = (char*) calloc(STR_SIZE, sizeof(char));
    char* dif = (char*) calloc(STR_SIZE, sizeof(char));

    size_t str_len = STR_SIZE;
    printf("\nWho/What is it ?\n");
    getline(&answer, &str_len, stdin);
    answer[strlen(answer) - 1] = '\0';

    InsertIntoTree(tree, answer, current_node, LEFT);
    InsertIntoTree(tree, current_node->val, current_node, RIGHT);

    printf("\nWhat feature does a %s possess that %s lacks?\n", answer, current_node->val);
   // clear_input_buffer();

    getline(&dif, &str_len, stdin);
    dif[strlen(dif) - 1] = '\0';

    current_node->val = dif;
}

//=========================================================

void save_request(Tree* tree, char* file_name)
{
    printf("\nDo you want to save changes?\n");
    char chr = getch();

    if (chr == 'y')
    {
        printf(green(YES)"\n");
        FILE* fp = fopen(file_name, "wb");
        PrintTree(tree->root, fp);
        fclose(fp);
        printf("\n"green(Changes are saved!!!)"\n");
    }
    else if (chr == 'n')
    {
        printf(red(NO)"\n");
        printf("\nOK\n");
        return;
    }
    else
    {
        printf("\n"red(Error!)" Please, push 'y'(Yes) or 'N'(no)\n");
        save_request(tree, file_name);
    }
}

//===========================================================

void definition(Tree* tree, Stack* stack)
{
    printf("\nWhat definition do you want to look for?\n");
    char* answer = (char*) calloc(STR_SIZE, sizeof(char));
    Node* current_node = (Node*) calloc(1, sizeof(Node));
    int str_len = STR_SIZE;
    getline(&answer, &str_len, stdin);
    answer[strlen(answer) - 1] = '\0';
    if (TreeSearch(tree->root, stack, answer) == VALUE_IS_NOT_FOUND)
    {
        printf("\n"red(this definition is not found=)"\n");
        return;
    }

    while (1)
    {
        *current_node = StackPop(stack);
        if (current_node->path_to_def == LEFT)
        {
            printf("It is %s-->\n", current_node->val);
        }
        else if (current_node->path_to_def == RIGHT)
        {
            printf("It is NOT %s-->\n", current_node->val);
        }
        else
        {
            printf(green(It is end!!!)"\n");
            break;
        }
    }
}

//==========================================================

void difference(Tree* tree, Stack* stack1)
{
    Node* stack1_node = (Node*) calloc(1, sizeof(Node));
    Node* stack2_node = (Node*) calloc(1, sizeof(Node));
    char* def1 = (char*) calloc(STR_SIZE, sizeof(char));
    char* def2 = (char*) calloc(STR_SIZE, sizeof(char));
    int str_len = STR_SIZE;
    printf("\nInput definition 1:\n");
    getline(&def1, &str_len, stdin);
    def1[strlen(def1) - 1] = '\0';

    printf("\nInput definition 2:\n");
    getline(&def2, &str_len, stdin);
    def2[strlen(def2) - 1] = '\0';

    int capacity = 10;
    Stack* stack2 = (Stack*) calloc(1, sizeof(Stack));
    StackConstructor(stack2, capacity);

    int deep1 = TreeSearch(tree->root, stack1, def1);
    int deep2 = TreeSearch(tree->root, stack2, def2);

    if (deep1 == VALUE_IS_NOT_FOUND)
    {
        printf("\n"red(this definition 1 doesn t exists)"\n");
        return;
    }
    if (deep2 == VALUE_IS_NOT_FOUND)
    {
        printf("\n"red(this definition 2 doesn t exists)"\n");
        return;
    }

    do {
        *stack1_node = StackPop(stack1);
        *stack2_node = StackPop(stack2);
    } while (stack1_node->path_to_def == stack2_node->path_to_def);

    if (stack1_node->path_to_def == LEFT)
        printf("\n%s is %s\t%s is NOT %s\n", def1, stack1_node->val, def2, stack2_node->val);
    else
        printf("\n%s is %s\t%s is NOT %s\n", def2, stack2_node->val, def1, stack1_node->val);

    StackDestructor(stack2);
}

//==============================================================
