#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
    printf("Exploit succeeded! ASLR bypassed or disabled.\n");
}

int main(int argc, char **argv) {
    // Print addresses to observe randomization
    int stack_var = 42;
    void *heap_alloc = malloc(10);
    printf("Stack address: %p\n", &stack_var);
    printf("Heap address: %p\n", heap_alloc);
    printf("libc printf address: %p\n", &printf);
    printf("Win function address: %p\n\n", &win);

    // Vulnerable buffer overflow section
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    char buffer[32];  // Small buffer
    strcpy(buffer, argv[1]);  // Unsafe copy – overflow to hijack return addr
    printf("Buffer content: %s\n", buffer);

    free(heap_alloc);
    return 0;
}