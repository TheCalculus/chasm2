#include <stdio.h>
#include <stdlib.h>

#include "nodemode/node.h"
#include "templator.h"
#include "chasm.h"

// TODO: default *.ch buffer name as argv[1]
int main(void) {
    printf("chasm.c copies\n");

    struct Parser parser = {
        .nodes = (NODE*)malloc(sizeof(NODE) * PARSER_BUFFER_SIZE),
        .root  = newRootNODE(),
    };

    parser.root->children = parser.nodes;
    
    const char* buffName = "../src/chasm.ch";

    if ((parser.buffer = fopen(buffName, "rb")) == NULL) {
        fprintf(stderr, "%s", "buffName path cannot be found\n");
        exit(1);
    }

    parse(parser.buffer);

    traverse(parser.root, 0);
    
    fclose(parser.buffer);
    free(parser.nodes);
    free(parser.root);

    return 0;
}
