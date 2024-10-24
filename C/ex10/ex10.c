#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas",NULL
    };
    int num_states = 4;

    argv[1] = states[1];

        // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    int j;
    for(i = 0, j = 0; i < num_states + 1; i++, j++) {
        printf("state i:%d j:%d %s\n", i, j, states[i]);
    }

    return 0;
}