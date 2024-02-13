#include <stdio.h>
#include "menu.c"

int main() {
    int choice;

    while (1) {
        printf("\n\n\t----- Restaurant Management System -----");
        printf("\n\n\t1. Display Menu");
        printf("\n\t2. Manage Menu");
        printf("\n\t3. Place Order");
        printf("\n\t4. Manage Order");
        printf("\n\t5. Manage Customers");
        printf("\n\t6. View Order Status");
        printf("\n\t7. Manage Staff");
        printf("\n\t8. Manage Customer Feedback");
        printf("\n\t9. Exit");
        printf("\n\n\tEnter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected: Display Menu\n");
                break;
            case 2:
                printf("\nYou selected: Manage Menu (Add/Remove/Edit Menu Items)\n");
                manageMenu();
                break;
            case 3:
                printf("\nYou selected: Place Order\n");
                break;
            case 4:
                printf("\nYou selected: Manage Order (View/Edit/Cancel)\n");
                break;
            case 5:
                printf("\nYou selected: Manage Customers (View/Edit/Delete, check orders)\n");
                break;
            case 6:
                printf("\nYou selected: View Order Status\n");
                break;
            case 7:
                printf("\nYou selected: Manage Staff (Add/Remove/Edit/View)\n");
                break;
            case 8:
                printf("\nYou selected: Manage Customer Feedback (Add/Remove)\n");
                break;
            case 9:
                printf("\n\n\tExiting Restaurant Management System. Goodbye!\n");
                return 0;
            default:
                printf("\n\n\tInvalid choice! Please select a valid option (1-9).\n");
        }
    }

    return 0;
}
