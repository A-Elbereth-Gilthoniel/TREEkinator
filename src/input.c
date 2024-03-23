#include "akinator.h"

void clear_input_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
