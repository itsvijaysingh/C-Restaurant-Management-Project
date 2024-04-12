//[---------------------- : Custom Structures : ----------------------]
typedef struct Order {
    int id;
    int menuItemId;
    int quantity;
    char customerName[50];
    int menuItemIds[10];
    int quantities[10];
    int numMenuItems;
    float totalPrice;
    char dateAndTime[20];
} Order;
Order order;

//[---------------------- : Function Declarations : ----------------------]
int addOrder();            
int updateOrder();        
int displayOrders();     
int removeOrder();        
int searchOrder();         

//[---------------------- : ANSI Color Codes  : ----------------------]
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//[---------------------- : Order Managing - Main Program  : ----------------------]
int orderManagement() {
    int choice;
    
    while (1) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║  M E N U S  ║                             ");
        printf("\n\t\t\t\t\t\t                   ╚═════════════╝                             \n\n");
        printf(ANSI_COLOR_RESET);
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [1] --> A D D - O R D E R (S)                                                                                   * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [2] --> U P D A T E - O R D E R (S)                                                                             * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [3] --> D I S P L A Y - A L L - O R D E R (S)                                                                   * \n");	
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [4] --> R E M O V E - O R D E R (S)                                                                             * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [5] --> S E A R C H - O R D E R (S)                                                                             * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [6] --> R E T U R N - TO - D A S H B O A R D                                                                    * \n");			
        printf("\n\t\t =========================================================================================================================== \n"); 
        printf("\n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter Your Choice : --> ");
        printf(ANSI_COLOR_RESET);

        scanf("%d", &choice);
        switch (choice) {
            //[---------------------- : Add - Order (S) : ----------------------]
            case 1:
                addOrder();
                break;

            //[---------------------- : Update - Order (S) : ----------------------]
            case 2:
                updateOrder();
                break;

            //[---------------------- : Display - All Orders : ----------------------]
            case 3:
                displayOrders();
                break;

            //[---------------------- : Remove - Order (S) : ----------------------]
            case 4:
                removeOrder();
                break;

            //[---------------------- : Search - Order (S) : ----------------------]
            case 5:
                searchOrder();
                break;

            //[---------------------- : Exit From Order Management Window : ----------------------]
            case 6:
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\tReturning Back to Dashboard"); Loading();
                system("clear");
                return 0;
                break;

            //[---------------------- : Re-Enter Into Order Management Window : ----------------------]
            default:
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf(ANSI_COLOR_RED);
                printf("\t\t\t\t\t\t\t\tError: Invalid Choice\n\n");
                printf(ANSI_COLOR_RESET);
                printf("\t\t\t\t\t\t\tPlease select a valid option from the choices.\n\n");		
                sleep(1);		
                printf("\t\t\t\t\t\t\tRe-Enter The Valid Choice"); Loading();
                system("clear");
                continue;
        }
    }
    return 0;
}

//[---------------------- : Add - Order (S) - Function : ----------------------]
int addOrder() {
    FILE *fp = NULL;
    int size = 0, i = 0, j = 0;
    int line_count = 0;
    int c = 0;
    int uniqueId = 0;
    char choice;
    float totalPrice = 0, CGST=0, SGST=0, GST = 0, subTotal = 0;

    float itemPrice = -1.0;
    int menuItemId = 0;
    int quantity = 0;
    char* itemName = NULL;
    float pricePerItem = 0;
    float totalPricePerItem = 0;


    // Open the file to read the last used ID
    fp = fopen("orderData.txt", "r");
    if (fp != NULL) {
        // Skip the first 3 lines in the file
        while (line_count < 3) {
            c = fgetc(fp);
            if (c == '\n' || c == EOF) {
                line_count++;
                if (c == EOF) break;
            }
        }

        // Read the last ID from the file
        while (fscanf(fp, "| %d", &uniqueId) == 1) {
            // Read until the end of the line to move to the next line
            while ((c = fgetc(fp)) != '\n' && c != EOF);
        }

        fclose(fp);
        printf("starting id in file: %d\n", uniqueId);

        // Increment the last used ID to generate a new unique ID
        uniqueId++;
        printf("after increment id in file: %d\n", uniqueId);

    } else {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_RED);
        printf("\n\n\t\t Error: Data file not found!");  
        Loading();
        printf(ANSI_COLOR_RESET);
        return 1;
    }

    do {
        fp = fopen("orderData.txt", "a+");
        if (fp == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Data file not found!");  
            Loading();
            printf(ANSI_COLOR_RESET);
            return 1;
        }

        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) {
            fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
            fprintf(fp, "ID\t Customer Name\t\t\t\t Menu Item IDs (Quantity)\t\t\t\t Total Price (\u20B9 +GST)\t\t Date & Time\t\t\t\t\t\n");
            fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
        }

        fseek(fp, 0, SEEK_END);
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                   ---: P R O V I D E  - O R D E R - D E T A I L S :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter Total Orders Do You Want To Add? : --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&size);

        for (i = 0; i < size; i++) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf("\n\t\t Order %d Details : ", i + 1);

            order.id = uniqueId++;

            printf("\n\n\t\t\t | Enter Customer Name  :--> ");
            validateStringInput(order.customerName);

            printf("\n\n\t\t\t | How many menu items do you want to order? ");
            validateNumInput(&order.numMenuItems);

            for (j = 0; j < order.numMenuItems; j++) {
                printf("\n\n\t\t\t\t | Enter Menu Item ID for Item %d  :--> ", j + 1);
                validateNumInput(&order.menuItemIds[j]);

                // Validate the menu item ID
                itemPrice = getPrice(order.menuItemIds[j]);
                if (itemPrice == -1.0) {
                    printf(ANSI_COLOR_RED);
                    printf("\n\t\t\t\t Invalid Menu Item ID. Please enter a valid ID.\n");
                    printf(ANSI_COLOR_RESET);
                    j--;
                    continue;
                }

                printf("\n\t\t\t\t | Enter Quantity for Menu Item %d  :--> ", j + 1);
                validateNumInput(&order.quantities[j]);
                order.totalPrice += order.quantities[j] * itemPrice;
            }

            subTotal = order.totalPrice;
            CGST = (order.totalPrice * 9) / 100;
            SGST = (order.totalPrice * 9) / 100;
            GST = CGST + SGST;
            totalPrice = subTotal + GST;

            // Get current date and time
            getCurrentDateTime(order.dateAndTime);

            // Print order details to file
            fprintf(fp, "%d\t %s\t\t\t\t", order.id, order.customerName);
            for (j = 0; j < order.numMenuItems; j++) {
                fprintf(fp, " %d(%d) ", order.menuItemIds[j], order.quantities[j]);
                if (j < order.numMenuItems - 1) {
                    fprintf(fp, ",");
                }
            }
            fprintf(fp, "\t\t\t\t %.2f\t\t %s\t\t\t\t\t\n", totalPrice, order.dateAndTime);

            system("clear");
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t *                                            ---: O R D E R - D E T A I L S :---                                          * \n");
            printf("\n\t\t =========================================================================================================================== \n");

            printf("\n\t\t\t\t\t\t|*********************************************************|\n");
            printf("\t\t\t\t\t\t|                THE MIDDAY RESTRO - BILL                 |\n");
            printf("\t\t\t\t\t\t|*********************************************************|\n");
            printf("\t\t\t\t\t\t|     Date & Time:                %s     |\n", order.dateAndTime);
            printf("\t\t\t\t\t\t|     Table No: 01        |       Server:    Dummy Don    |\n");
            printf("\t\t\t\t\t\t|     Customer:                   %s                   |\n",order.customerName);
            printf("\t\t\t\t\t\t|---------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t|     Item           Qty      Price/Unit    Total Price   |\n");
            printf("\t\t\t\t\t\t|---------------------------------------------------------|\n");

            // Print order details to file and console
            for (j = 0; j < order.numMenuItems; j++) {
                menuItemId = order.menuItemIds[j];
                quantity = order.quantities[j];
                itemName = getMenuItemName(menuItemId);
                pricePerItem = getPrice(menuItemId);
                totalPricePerItem = pricePerItem * quantity;
                printf("\t\t\t\t\t\t| %d  %s           %d       \u20B9%.2f         \u20B9%.2f        |\n", j + 1, itemName, quantity, pricePerItem, totalPricePerItem);
            }

            printf("\t\t\t\t\t\t|---------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t|    Subtotal:                             Rs. %.2f      |\n",subTotal);
            printf("\t\t\t\t\t\t|    CGST (9%%):                            Rs. %.2f       |\n",CGST);
            printf("\t\t\t\t\t\t|    SGST (9%%):                            Rs. %.2f       |\n",SGST);
            printf("\t\t\t\t\t\t|    Total (incl. GST):                    Rs. %.2f      |\n",totalPrice);
            printf("\t\t\t\t\t\t|---------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t|                    Have a Good Day!                     |\n");
            printf("\t\t\t\t\t\t|*********************************************************|\n");
        }
        
        fclose(fp);


        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- ");
        printf(ANSI_COLOR_GREEN);
        printf("\n\t\t %d Orders Successfully Placed", size); Loading();
        printf(ANSI_COLOR_RESET); 

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to add another order? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');
    return 0;
}


//[---------------------- : Update - Order (S) - Function : ----------------------]

int updateOrder() {
//     int i, j, idToUpdate;
//     char choice;
//     Order temp;
//     FILE *fpIn;
//     FILE *fpOut;
//     char line[500];
//     int found = 0;
//     char menuItems[500];

//     do {
//         system("clear");
//         printf("\n\t\t =========================================================================================================================== \n");
//         printf("\n\t\t *                                   ---: U P D A T E  - O R D E R :---                                                  * \n");
//         printf("\n\t\t =========================================================================================================================== \n");
//         printf(ANSI_COLOR_BLUE);
//         printf("\n\t\t | Enter the ID of the order you want to update: --> ");
//         printf(ANSI_COLOR_RESET);
//         validateNumInput(&idToUpdate);

//         fpIn = fopen("orderData.txt", "r");
//         fpOut = fopen("tempOrderData.txt", "w");

//         if (fpIn == NULL || fpOut == NULL) {
//             printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
//             printf(ANSI_COLOR_RED);
//             printf("\n\n\t\t Error: opening file"); Loading();
//             printf(ANSI_COLOR_RESET);
//             return 1;
//         }

//         // Preserve the formatting lines
//         for (j = 0; j < 3; ++j) {
//             if (fgets(line, sizeof(line), fpIn) == NULL) {
//                 printf("Error reading file."); Loading();
//                 return 1;
//             }
//             fprintf(fpOut, "%s", line);
//         }

//         while (fgets(line, sizeof(line), fpIn) != NULL) {
//             int numRead = sscanf(line, "%d %[^\t\n]\t %[^\t\n], %f\t %[^\t\n]", &temp.id, temp.customerName, menuItems, &temp.totalPrice, temp.dateAndTime);
//             if (numRead == 5) {
//                 if (temp.id == idToUpdate) {
//                     found = 1;
//                     printf("\n\n\t\t\t | Current Order Details:");
//                     printf("\n\t\t\t | Customer Name: %s", temp.customerName);
//                     printf("\n\t\t\t | Menu Items:");
//                     for (int i = 0; i < temp.numMenuItems; ++i) {
//                         printf("\n\t\t\t |   - Item ID: %d, Quantity: %d", temp.menuItemIds[i], temp.quantities[i]);
//                     }
//                     printf("\n\n\t\t\t | What do you want to update for this order?");
//                     printf("\n\t\t\t | 1. Customer Name");
//                     printf("\n\t\t\t | 2. Menu Items and Quantities");
//                     printf("\n\t\t\t | Enter your choice: ");
//                     int updateChoice;
//                     validateNumInput(&updateChoice);

//                     switch(updateChoice) {
//                         case 1:
//                             printf("\n\n\t\t\t | Enter the new customer name: ");
//                             validateStringInput(temp.customerName);
//                             break;
//                         case 2:
//                             printf("\n\n\t\t\t | Enter the ID of the item to update or -1 to finish: ");
//                             int newItemId;
//                             validateNumInput(&newItemId);
//                             while (newItemId != -1) {
//                                 printf("\n\n\t\t\t | Enter the new quantity for item %d: ", newItemId);
//                                 int newQuantity;
//                                 validateNumInput(&newQuantity);
//                                 // Update or add the item and quantity
//                                 int index = -1;
//                                 for (int i = 0; i < temp.numMenuItems; ++i) {
//                                     if (temp.menuItemIds[i] == newItemId) {
//                                         index = i;
//                                         break;
//                                     }
//                                 }
//                                 if (index != -1) {
//                                     temp.quantities[index] = newQuantity;
//                                 } else {
//                                     temp.menuItemIds[temp.numMenuItems] = newItemId;
//                                     temp.quantities[temp.numMenuItems] = newQuantity;
//                                     temp.numMenuItems++;
//                                 }
//                                 printf("\n\n\t\t\t | Enter the ID of the next item to update or -1 to finish: ");
//                                 validateNumInput(&newItemId);
//                             }
//                             break;
//                         default:
//                             printf("\n\t\t\t | Invalid choice. Please enter a valid option.");
//                             break;
//                     }
//                 }
//                 // Write the updated order to the output file
//                 fprintf(fpOut, "%d\t %s\t %s, %.2f\t %s\n", temp.id, temp.customerName, menuItems, temp.totalPrice, temp.dateAndTime);
//             } else {
//                 fprintf(fpOut, "%s", line);
//             }
//         }

//         fclose(fpIn);
//         fclose(fpOut);

//         if (!found) {
//             printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
//             printf(ANSI_COLOR_RED);
//             printf("\n\t\t Order with ID %d not found", idToUpdate); 
//             printf(ANSI_COLOR_RESET);
//             remove("tempOrderData.txt");
//         } else {
//             remove("orderData.txt");
//             rename("tempOrderData.txt", "orderData.txt");
//             printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
//             printf(ANSI_COLOR_GREEN);
//             printf("\n\t\t Order %d updated successfully!", idToUpdate);
//             printf(ANSI_COLOR_RESET);
//         }

//         printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
//         printf(ANSI_COLOR_BLUE);
//         printf("\n\t\t | Do you want to update another order? (Y/N): --> ");
//         printf(ANSI_COLOR_RESET);
//         scanf(" %c", &choice);
//         while (getchar() != '\n');
//     } while (choice == 'Y' || choice == 'y');

    return 0;
}


//[---------------------- : Display - All Orders - Function : ----------------------]
int displayOrders() {
    int j, c;
    char menuItems[500];
    FILE *fp = fopen("orderData.txt", "r");
    if (fp != NULL) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t\t                   ║   O R D E R S   ║                         ");
        printf("\n\t\t\t\t\t\t\t                   ╚═════════════════╝                         \n\n");
        printf(ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN);
        printf("\n\t\t\t ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t ║ %-10s ║ %-30s ║ %-30s ║ %-17s   ║ %-19s  ║", "ID", "Customer Name", "Menu Item (Quantity)", "Total Price (\u20B9)", "Date & Time");
        //printf("\n\t\t\t ╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf(ANSI_COLOR_RESET);

        // Skip the first 3 lines if the file is not empty
        rewind(fp);
        for (j = 0; j < 3; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }
        

        while (fscanf(fp, "%d\t %[^\t\n]\t %[^\t\n]\t %f\t %[^\t\n]", &order.id, order.customerName, menuItems, &order.totalPrice, order.dateAndTime) == 5) {
            printf("\n\t\t\t ║=========================================================================================================================║");
            printf("\n\t\t\t ║ %-10d | %-30s | %-30s | %-17.2f | %-19s  ║", order.id, order.customerName, menuItems, order.totalPrice, order.dateAndTime);
        }

        printf("\n\t\t\t ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        fclose(fp);
        printf(ANSI_COLOR_BLUE);
        printf("\n\n\t\t\t | Press any key to go back...");
        printf(ANSI_COLOR_RESET);
        getchar();
        getchar();
    } else {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_RED);
        printf("\n\n\t\t Error: no data files exists");  Loading();
        printf(ANSI_COLOR_RESET);
        return 1;
    }
return 0;
}


//[---------------------- : Remove - Order (S) - Function : ----------------------]
int removeOrder() {
    int idToRemove;
    char choice;
    Order temp;
    FILE *fpIn;
    FILE *fpOut;
    char line[100];
    int newID = 1;
    int found = 0;
    int j;
    char menuItems[500];

    do {
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                 ---: P R O V I D E  - O R D E R - I D :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter the ID of the order you want to remove: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToRemove);

        fpIn = fopen("orderData.txt", "r");
        fpOut = fopen("tempOrderData.txt", "w");

        if (fpIn == NULL || fpOut == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: opening file");  Loading();
            printf(ANSI_COLOR_RESET);
            fclose(fpIn);
            fclose(fpOut);
            return 1;
        }

        // Preserve the formatting lines
        for (j = 0; j < 3; ++j) {
            if (fgets(line, sizeof(line), fpIn) == NULL) {
                printf("Error reading file.");
                return 1;
            }
            fprintf(fpOut, "%s", line);
        }

        while (fgets(line, sizeof(line), fpIn) != NULL) {
            if (sscanf(line, "%d %[^\t\n]\t %[^\t\n]\t %f\t %[^\t\n]", &temp.id, temp.customerName, menuItems, &temp.totalPrice, temp.dateAndTime) == 5) {                
                if (temp.id == idToRemove) {
                    found = 1;
                    continue;
                }
                // Update the ID to start from 1
                temp.id = newID++;
                fprintf(fpOut, "%d\t\t%s\t\t%s\t\t%.2f\t%s\n", temp.id, temp.customerName, menuItems, temp.totalPrice, temp.dateAndTime);
            } else {
                // Write non-order lines (like formatting lines) unchanged
                fprintf(fpOut, "%s", line);
            }
        }

        fclose(fpIn);
        fclose(fpOut);

        if (!found) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\t\t Order with ID %d not found", idToRemove); 
            printf(ANSI_COLOR_RESET);
            remove("tempOrderData.txt");
        } else {
            remove("orderData.txt");
            rename("tempOrderData.txt", "orderData.txt");
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\t\t Order %d removed successfully!", idToRemove);
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to remove another order? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


//[---------------------- : Search - Order (S) - Function : ----------------------]
int searchOrder() {
    FILE *fp;
    int idToSearch;
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
        printf("\n\t\t | Enter the ID of the order you want to search: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToSearch);

        fp = fopen("orderData.txt", "r");
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
            if (idToSearch == order.id) {
                system("clear");
                printf(ANSI_COLOR_GREEN);
                printf("\n\n\n\n\n\t\t\t ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
                printf("\n\t\t\t ║                                      F O U N D  -  O R D E R  -  D E T A I L S                                          ║");
                printf("\n\t\t\t ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════║");
                printf(ANSI_COLOR_RESET);
                printf("\n\t\t\t ║ %-10s ║ %-30s ║ %-30s ║ %-17s   ║ %-19s  ║", "ID", "Customer Name", "Menu Item (Quantity)", "Total Price (\u20B9)", "Date & Time");
                printf("\n\t\t\t ║=========================================================================================================================║");
                printf("\n\t\t\t ║ %-10d | %-30s | %-30s | %-17.2f | %-19s  ║", order.id, order.customerName, menuItems, order.totalPrice, order.dateAndTime);
                printf("\n\t\t\t ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
                found = 1;
                break;
            }
         }
        fclose(fp);

        if (!found) {
            printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t\t Error: Order with ID %d not found", idToSearch);  Loading();
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t\t | Do you want to search for another order? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}