#include <stdio.h>
#define max 50

int queue_array[max];
int rear = -1;
int front = -1;

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is \n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}

void insert() {
    int odd_item;
    if (rear == max - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Insert the element in queue: ");
        scanf("%d", &odd_item);
        rear = rear + 1;
        queue_array[rear] = odd_item;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    } else {
        printf("Deleted element is %d\n", queue_array[front]);
        front = front + 1;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
