#include <stdio.h>

int main() {
    
    int a[] = {9, 6, 2, 11, 0, 12};
    int i = 1;
    int temp = 0;
    
    for(i; i < sizeof(a)/sizeof(int); i++) {
        int j = i;
        if(a[j] < a[j - 1]) {
            for(j; j > 0; j--) {
                temp = a[j];
                a[j] = a[j - 1];
                a[ j - 1] = temp;
            }
        }
    }
    
    printf("\n");
    for(i = 0; i < sizeof(a)/sizeof(int); i++) {
        printf("%i\n", a[i]);
    }
    return 0;
}
