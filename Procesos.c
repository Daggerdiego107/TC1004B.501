#include <stdio.h>
#include <unistd.h>

int main() {
    int a = 5;

    int pid = fork();
    if (pid == 0) {
        printf("Soy el proceso hijo de = %d, PID = %d\n", a, pid);
        execl("./Hola", "Hola", "7w7", ":D", (char*) NULL);
        printf("Esto no se imprimira");
        return 0;
    }

    printf("Soy el proceso padre, de = %d, PID = %d\n", a, pid);
    sleep(20);
    return 0;
}