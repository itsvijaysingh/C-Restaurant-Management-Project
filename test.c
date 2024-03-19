#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char loader[] = { '/', '-', '\\', '|' };
    int i = 0;

    while (1) {
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\tEntering to Program %c\n", loader[i]);
        fflush(stdout);
        usleep(100000);
        i = (i + 1) % 4;
    }

    return 0;
}

