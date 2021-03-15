#include <iostream>

using std::cout;
using std::endl;

double Sum(const double first, const double second) {
    return first + second;
}

int main(int argc, const char** argv) {
    if (argc < 3) {
        cout << "Not enough args to complete this program" << endl;
        return EXIT_SUCCESS;
    }

    char* error;
    const auto first  = strtod(argv[1], &error);
    const auto second = strtod(argv[2], &error);


    if (*error != 0 && !isspace((unsigned char)*error)) {
        cout <<  "Parse error..." << endl;
        return EXIT_FAILURE;
    }

    cout << first << " + " << second << " = " << Sum(first, second) << endl;
    return EXIT_SUCCESS;
}
