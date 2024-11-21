#include <stdio.h>

int main(int argc, char** argv) {

    for (int i = 1; i < argc; i++) {
        printf("Hola Mundo!", argv[i]);
    }

    return 0;
}