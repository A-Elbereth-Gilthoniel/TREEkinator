#include "akinator.h"

void convert_file_to_tree(Tree* tree, char* file_name)
{
    FILE* file = fopen(file_name, "rb");

    int brackets_dif = 0;                                // difference between open and closed brackets
    size_t file_size = find_file_size(file);

    int indicator = LEFT;

    char *string = (char*) calloc(file_size + 1, sizeof(char));
    fread(string, sizeof(char), file_size, file);

    int str_i = 0;
    Node* current_node = tree->root;
    Node* temp = NULL;

    while (1)
    {
        if (string[str_i] == '(')
        {
            brackets_dif++;
            temp = current_node;

            char* new_value = buf_reading(&string[str_i+3]);

            current_node = InsertIntoTree(tree, new_value, current_node, indicator);

            indicator = LEFT;

            current_node->prev = temp;
        }
        else if (string[str_i] == ')')
        {
            brackets_dif--;
            current_node = current_node->prev;
            indicator = RIGHT;
        }

        else if (strncmp(&string[str_i], "null", 4) == 0)
        {
            indicator = indicator * LEFT;
            str_i = str_i + 3;
        }

        if (brackets_dif == 0)
        {
            break;
        }
        str_i++;
    }
    fclose(file);
}

//====================================================

size_t find_file_size(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    size_t n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return n;
}

//====================================================

char* buf_reading(char* buf)
{
    char* new_value = (char*) calloc(STR_SIZE, sizeof(char));
    char* first_forging = strchr(buf, '\"');
    strncpy(new_value, buf, (first_forging - buf));

    return new_value;
}

//====================================================
