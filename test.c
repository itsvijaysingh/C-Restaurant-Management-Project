//[---------------------- : Header & Custom Files Linking  : ----------------------]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include<ctype.h>
#include "globalFunctions.c"
#include "menu.c"
#include "staff.c"

float getPrice(int menuItemId);
char* getMenuItemName(int menuItemId);

#define ANSI_COLOR_RED   "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct {
    int id;
    char customerName[100];
    int menuItemIds[10];
    int quantities[10];
    int numMenuItems;
    float totalPrice;
    char dateAndTime[20];
} Order;

Order order;

//[---------------------- : Update - Order (S) - Function : ----------------------]
int updateOrder() {
    FILE *fp;
    int idToUpdate;
    int found = 0;
    char choice;
    int j, c;
    float totalPrice;
    char menuItems[500];

    do {
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                 ---: P R O V I D E  - O R D E R - I D :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter the ID of the order you want to update: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToUpdate);

        fp = fopen("orderData.txt", "r+");
        if (fp == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Data file not found!");  Loading();
            printf(ANSI_COLOR_RESET);
            return 1;
        }

        // Skip the first 3 lines if the file is not empty
        for (j = 0; j < 3; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d\t %[^\t\n]\t %[^\t\n]\t %f\t %[^\t\n]", &order.id, order.customerName, menuItems, &order.totalPrice, order.dateAndTime) == 5) {
            if (idToUpdate == order.id) {
                system("clear");
                printf(ANSI_COLOR_GREEN);
                printf("\n\n\n\n\n\t\t\t ╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
                printf("\n\t\t\t ║                                      U P D A T E  -  O R D E R  -  D E T A I L S                                          ║");
                printf("\n\t\t\t ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════║");
                printf("\n\t\t\t ║ Current Order Details:");
                printf("\n\t\t\t ║ Customer Name: %s", order.customerName);
                printf("\n\t\t\t ║ Menu Items:");
                for (int i = 0; i < temp.numMenuItems; ++i) {
                    printf("\n\t\t\t |   - Item ID: %d, Quantity: %d", temp.menuItemIds[i], temp.quantities[i]);
                }
                printf("\n\t\t\t ║=========================================================================================================================║");
                printf("\n\t\t\t ║ What do you want to update for this order?");
                printf("\n\t\t\t ║ 1. Customer Name");
                printf("\n\t\t\t ║ 2. Menu Items and Quantities");
                printf("\n\t\t\t ║ Enter your choice: ");
                printf("\n\t\t\t ║=========================================================================================================================║");

                int updateChoice;
                scanf("%d", &updateChoice);
                while (getchar() != '\n');

                switch (updateChoice) {
                    case 1:
                        printf("\n\t\t\t ║ Enter new customer name: ");
                        validateStringInput(order.customerName);
                        break;
                    case 2:
                        printf("\n\t\t\t ║ Enter the new number of menu items: ");
                        validateNumInput(&order.numMenuItems);
                        printf("\n\t\t\t ║ Enter new menu items and quantities:");
                        for (int i = 0; i < order.numMenuItems; ++i) {
                            printf("\n\t\t\t ║   - Enter Menu Item ID for Item %d: ", i + 1);
                            validateNumInput(&order.menuItemIds[i]);
                            printf("\n\t\t\t ║   - Enter Quantity for Menu Item %d: ", i + 1);
                            validateNumInput(&order.quantities[i]);
                        }
                        break;
                    default:
                        printf("\n\t\t\t ║ Invalid choice. Please try again.");
                        break;
                }
                printf("\n\t\t\t ║=========================================================================================================================║");
                found = 1;
                break;
            }
         }
        fclose(fp);

        if (!found) {
            printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t\t Error: Order with ID %d not found", idToUpdate);  Loading();
            printf(ANSI_COLOR_RESET);
        } else {
            // Update the order details in the file
            fp = fopen("orderData.txt", "r+");
            if (fp == NULL) {
                printf("\n\t\t\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
                printf(ANSI_COLOR_RED);
                printf("\n\n\t\t\t Error: Data file not found!");  Loading();
                printf(ANSI_COLOR_RESET);
                return 1;
            }

            // Skip the first 3 lines if the file is not empty
            for (j = 0; j < 3; ++j) {
                while ((c = fgetc(fp)) != EOF && c != '\n');
            }

            FILE *tempFile = fopen("tempOrderData.txt", "w");
            if (tempFile == NULL) {
                printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
                printf(ANSI_COLOR_RED);
                printf("\n\n\t\t\t Error: Opening temporary file for writing");  Loading();
                printf(ANSI_COLOR_RESET);
                fclose(fp);
                return 1;
            }

            fprintf(tempFile, "---------------------------------------------------------------------------------------------------------------------------\n");
            fprintf(tempFile, "ID\t Customer Name\t\t\t\t Menu Item IDs (Quantity)\t\t\t\t Total Price (\u20B9 +GST)\t\t Date & Time\t\t\t\t\t\n");
            fprintf(tempFile, "---------------------------------------------------------------------------------------------------------------------------\n");

            while (fscanf(fp, "%d\t %[^\t\n]\t %[^\t\n]\t %f\t %[^\t\n]", &order.id, order.customerName, menuItems, &order.totalPrice, order.dateAndTime) == 5) {
                if (idToUpdate == order.id) {
                    fprintf(tempFile, "%d\t %s\t\t\t\t", order.id, order.customerName);
                    for (int i = 0; i < order.numMenuItems; ++i) {
                        fprintf(tempFile, " %d(%d) ", order.menuItemIds[i], order.quantities[i]);
                        if (i < order.numMenuItems - 1) {
                            fprintf(tempFile, ",");
                        }
                    }
                    fprintf(tempFile, "\t\t\t\t %.2f\t\t %s\t\t\t\t\t\n", order.totalPrice, order.dateAndTime);
                } else {
                    fprintf(tempFile, "%d\t %s\t %s\t %.2f\t %s\n", order.id, order.customerName, menuItems, order.totalPrice, order.dateAndTime);
                }
            }

            fclose(fp);
            fclose(tempFile);

            remove("orderData.txt");
            rename("tempOrderData.txt", "orderData.txt");

            printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\n\t\t\t Order %d updated successfully!", idToUpdate);  Loading();
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t\t | Do you want to update another order? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


int main() {
    // Testing updateOrder function
    updateOrder();
    return 0;
}
