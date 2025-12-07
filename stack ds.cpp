#include <stdio.h>
#include <string.h>

#define MAX 5   // maximum actions stored

char stack[MAX][50];  // stack to store actions
int top = -1;

// Push operation
void push(char action[]) {
    if (top == MAX - 1) {
        printf("Undo stack is full! Cannot store more actions.\n");
    } else {
        top++;
        strcpy(stack[top], action);
        printf("Action saved: %s\n", action);
    }
}

// Pop operation (Undo)
void pop() {
    if (top == -1) {
        printf("No actions left to UNDO.\n");
    } else {
        printf("Undoing: %s\n", stack[top]);
        top--;
    }
}

int main() {
    int choice;
    char action[50];

    printf("=== Text Editor Undo Example Using Stack ===\n");

    while (1) {
        printf("\n1. Perform Action\n2. Undo\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        switch (choice) {
            case 1:
                printf("Enter action (ex: Typed Hello, Deleted word): ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = 0; // remove newline
                push(action);
                break;

            case 2:
                pop();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
