#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

void print_usage() {
    printf("Usage: ./calc operand1 operator operand2 ... -k key\n");
    printf("Operators: +, -, *, %%\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    int key = 0;
    int results[argc];
    int result_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-k") == 0) {
            if (i + 1 >= argc || !isdigit(argv[i + 1][0])) {
                printf("Error: Missing or invalid key after -k\n");
                return 1;
            }
            key = atoi(argv[i + 1]);
            break;
        }

        if (i + 2 < argc) {
            int operand1 = atoi(argv[i]);
            char operator = argv[i + 1][0];
            int operand2 = atoi(argv[i + 2]);
            results[result_count++] = calculate(operand1, operator, operand2);
            printf("answer №%d: %d\n", result_count, results[result_count - 1]);
            i += 2;
        } else {
            printf("Error: Insufficient arguments for an expression\n");
            return 1;
        }
    }

    char decrypted[result_count + 1];
    decrypt_results(results, result_count, key, decrypted);
    printf("Result string: %s\n", decrypted);

    return 0;
}
