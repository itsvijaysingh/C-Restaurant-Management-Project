#include <stdio.h>
#include <string.h>

typedef struct MenuItem {
    int id;
    char name[50];
    int price;
} MenuItem;

MenuItem item;

int addMenuItem();
int updateMenuItem();
int removeMenuItem();
int searchMenuItem();

int manageMenu() {
    int choice;
    
    while (1) {
        printf("\n\n\t----- Manage Menu -----");
        printf("\n\n\t1. Add a Menu Item");
        printf("\n\t2. Update a Menu Item");
        printf("\n\t3. Remove a Menu Item");
        printf("\n\t4. Search a Menu Item");
        printf("\n\t5. Exit");
        printf("\n\n\tEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected: Adding a Menu Item\n");
                addMenuItem();
                break;
            case 2:
                printf("\nYou selected: Updating a Menu Item\n");
                updateMenuItem();
                break;
            case 3:
                printf("\nYou selected: Removing a Menu Item\n");
                removeMenuItem();
                break;
            case 4:
                printf("\nYou selected: Searching a Menu Item\n");
                searchMenuItem();
                break;
            case 5:
                printf("\n\n\tExiting Menu Management Window...\n");
                return 0;
            default:
                printf("\n\n\tInvalid choice! Please select a valid option (1-5).\n");
        }
    }
    return 0;
}

int addMenuItem() {
    return 0;
}

int updateMenuItem() {
    return 0;
}

int removeMenuItem() {
    return 0;
}

int searchMenuItem() {
    return 0;
}
