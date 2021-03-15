#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double Sum(const double first, const double second) {
    return first + second;
}

int main(int argc, const char** argv) {
    if (argc < 3) {
        fprintf(stdout, "Not enough args to complete this program\n");
        return EXIT_SUCCESS;
    }

    char* error;
    const double first  = strtod(argv[1], &error);
    const double second = strtod(argv[2], &error);

    if (*error != 0 && !isspace((unsigned char)*error)) {
        fprintf(stdout, "Parse error...\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "%f + %f = %f\n", first, second, Sum(first, second));
    return EXIT_SUCCESS;
}
