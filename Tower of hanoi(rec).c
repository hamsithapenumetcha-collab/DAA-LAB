#include <stdio.h>

// Recursive Function
void hanoiRecursive(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    // Step 1: Move n-1 disks from Source to Aux
    hanoiRecursive(n - 1, source, aux, dest);
    
    // Step 2: Move the nth disk from Source to Dest
    printf("Move disk %d from %c to %c\n", n, source, dest);
    
    // Step 3: Move n-1 disks from Aux to Dest
    hanoiRecursive(n - 1, aux, dest, source);
}

int main() {
    int n; 

    printf("Enter the number of disks: ");
    scanf("%d",&n);

    printf("\n--- Recursive Towers of Hanoi (%d disks) ---\n", n);
    hanoiRecursive(n, 'A', 'C', 'B');
    
    return 0;
}
