#include <stdio.h>
void meow(int n);

int main() {

    meow(10);
}

void meow(int n){
    for (int i = n; i > 0; i--) {
        printf("meow\n");
}
}
