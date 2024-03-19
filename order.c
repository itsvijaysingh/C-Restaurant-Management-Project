//[---------------------- : Custom Structures : ----------------------]
// Define the Order structure
typedef struct Order {
    int id;
    int menuItemId;
    int quantity;
    char customerName[50];
    int menuItemIds[10]; // Assuming maximum 10 menu items per order
    int quantities[10]; // Corresponding quantities for each menu item
    int numMenuItems; // Number of menu items in the order
    float totalPrice;
    char dateAndTime[20]; // Date and time of the order
} Order;
Order order;

//[---------------------- : Function Declarations : ----------------------]
int addOrder();            // add order
int updateOrder();         // update order
int displayOrders();       // display all orders
int removeOrder();         // remove order
int searchOrder();         // search order

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
    int i, size, j;
    int uniqueId = 0;

    // Open order data file
    fp = fopen("orderData.txt", "a+");
    if (fp == NULL) {
        printf("\n\tFile Opening Failed.....");
        return 0;
    }

    // Retrieve the last ID from the file and skip name, menu item id, quantity, and total price
    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "%d", &uniqueId) == 1) {
        fscanf(fp, "%*[^\n]"); // Skip the rest of the line
    }
    uniqueId++;

    // Print header if the file is empty
    if (ftell(fp) == 0) {
        fprintf(fp, "---------------------------------------------------------------------------------------------------------\n");
        fprintf(fp, "| ID\t| Customer Name\t\t\t| Menu Item IDs (Quantity)\t\t\t| Total Price\t| Date & Time\t|\n");
        fprintf(fp, "---------------------------------------------------------------------------------------------------------\n");
    }

    system("clear");
    printf("\n\t\t =========================================================================================================================== \n");
    printf("\n\t\t *                                   ---: P R O V I D E  - O R D E R - D E T A I L S :---                                  * \n");
    printf("\n\t\t =========================================================================================================================== \n");

    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t | Enter Total Orders You Want To Add? : --> ");
    printf(ANSI_COLOR_RESET);
    validateNumInput(&size);
    
    for (i = 0; i < size; i++) {

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf("\n\t\t Order %d Details : ", i+1);

        order.id = uniqueId++;

        printf("\n\n\t\t\t | Enter Customer Name for Order %d: ", order.id);
        scanf("%s", order.customerName);

        printf("\n\n\t\t\t | Enter Number of Menu Items for Order %d: ", order.id);
        scanf("%d", &order.numMenuItems);

        printf("\n\n\t\t\t | Enter Details for Menu Items (ID Quantity) for Order %d:\n", order.id);
        for (j = 0; j < order.numMenuItems; j++) {
            printf("\n\n\t\t\t\t | Menu Item %d: ", j + 1);
            scanf("%d %d", &order.menuItemIds[j], &order.quantities[j]);
            order.totalPrice += order.quantities[j] * getPrice(order.menuItemIds[j]);
        }

        // Get current date and time
        getCurrentDateTime(order.dateAndTime);

        // Print order details to file
        fprintf(fp, "| %d\t| %s\t\t\t|", order.id, order.customerName);
        for (j = 0; j < order.numMenuItems; j++) {
            fprintf(fp, " %d(%d) ", order.menuItemIds[j], order.quantities[j]);
            if (j < order.numMenuItems - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "\t\t\t| %.2f\t| %s\t|\n", order.totalPrice, order.dateAndTime);
    }

    fclose(fp);
    printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
    printf(ANSI_COLOR_GREEN);
    printf("\n\t\t %d Orders Added Successfully!", size); Loading();
    printf(ANSI_COLOR_RESET);
    system("clear");
    return 0;
}


//[---------------------- : Update - Order (S) - Function : ----------------------]
int updateOrder() {
    int idToUpdate, j, c;
    int found = 0;

    system("clear");
    printf("\n\t\t =========================================================================================================================== \n");
    printf("\n\t\t *                                   ---: P R O V I D E  - O R D E R - D E T A I L S :---                                  * \n");
    printf("\n\t\t =========================================================================================================================== \n");

    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t | Enter the ID of the order you want to update: --> ");
    printf(ANSI_COLOR_RESET);
    scanf("%d", &idToUpdate);

    FILE *fp = fopen("orderData.txt", "r+");
    if (fp != NULL) {
        Order temp;

        // Skip the first 5 lines if the file is not empty
        rewind(fp); // Move the file pointer to the beginning
        for (j = 0; j < 5; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d%s%d%d%f", &temp.id, temp.customerName, &temp.menuItemId, &temp.quantity, &temp.totalPrice) == 5) {
            if (temp.id == idToUpdate) {
                printf("\n\n\t\t\t | Enter the new customer name: ");
                scanf("%s", temp.customerName);
                printf("\n\n\t\t\t | Enter the new menu item ID: ");
                scanf("%d", &temp.menuItemId);
                printf("\n\n\t\t\t | Enter the new quantity: ");
                scanf("%d", &temp.quantity);
                // Calculate new total price based on the updated quantity
                temp.totalPrice = temp.quantity * getPrice(temp.menuItemId); // Assume getPrice() retrieves the price of the menu item from somewhere
                // Move the file pointer to the beginning of the line
                fseek(fp, -1 * (strlen(temp.customerName) + sizeof(temp.menuItemId) + sizeof(temp.quantity) + sizeof(temp.totalPrice) + 4), SEEK_CUR);
                fprintf(fp, "%s\t\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%.2f\n", temp.customerName, temp.menuItemId, temp.quantity, temp.totalPrice);
                found = 1;
                break;
            }
        }
        fclose(fp);
        if (!found) {
            printf(ANSI_COLOR_RED);
            printf("\n\tOrder with ID %d not found.\n", idToUpdate);
            printf(ANSI_COLOR_RESET);
        }else{
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\t\t Order %d updated successfully!", idToUpdate); Loading();
            printf(ANSI_COLOR_RESET);
            system("clear");
        }
    } else {
        printf("\n\tFile Not Found...");
    }
    return 0;
}

//[---------------------- : Display - All Orders - Function : ----------------------]
int displayOrders() {
    int j;
    int c;
    FILE *fp = fopen("orderData.txt", "r");
    if (fp != NULL) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║   O R D E R S   ║                         ");
        printf("\n\t\t\t\t\t\t                   ╚═════════════════╝                         \n\n");
        printf(ANSI_COLOR_RESET);

        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n:               ---: O R D E R - D A T A (S) :---              :");
        printf("\n-----------------------------------------------------------------");
        printf("\nId\t\t\t\t\t\tCustomer Name\t\t\t\t\t\tMenu Item ID\t\t\t\t\tQuantity\t\t\tTotal Price");
        printf("\n-----------------------------------------------------------------\n");

        // Skip the first 5 lines if the file is not empty
        rewind(fp); // Move the file pointer to the beginning
        for (j = 0; j < 5; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d%s%d%d%f", &order.id, order.customerName, &order.menuItemId, &order.quantity, &order.totalPrice) == 5) {
            printf("%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d\t\t\t\t\t%.2f\n", order.id, order.customerName, order.menuItemId, order.quantity, order.totalPrice);
        }
        fclose(fp);
    } else {
        printf("\n\tFile Not Found...");
    }
    return 0;
}

//[---------------------- : Remove - Order (S) - Function : ----------------------]
int removeOrder() {
    int idToRemove, j;
    char line[100];
    int found = 0;
    
    printf("\n\tEnter the ID of the order you want to remove: ");
    scanf("%d", &idToRemove);

    FILE *fpIn = fopen("orderData.txt", "r");
    FILE *fpOut = fopen("tempOrderData.txt", "w");

    if (fpIn == NULL || fpOut == NULL) {
        printf("Error opening file.");
        return 1;
    }

    

    // Preserve the first 5 lines of formatting
    for (j = 0; j < 5; ++j) {
        if (fgets(line, sizeof(line), fpIn) == NULL) {
            printf("Error reading file.");
            return 1;
        }
        fprintf(fpOut, "%s", line);
    }

    // Copy lines from fpIn to fpOut, except the line with idToRemove
    while (fgets(line, sizeof(line), fpIn) != NULL) {
        Order temp;
        if (sscanf(line, "%d %49s %d %d %f", &temp.id, temp.customerName, &temp.menuItemId, &temp.quantity, &temp.totalPrice) == 5) {
            if (temp.id == idToRemove) {
                found = 1;
                continue; // Skip this line
            }
            fprintf(fpOut, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%.2f\n", temp.id, temp.customerName, temp.menuItemId, temp.quantity, temp.totalPrice);
        }
    }

    fclose(fpIn);
    fclose(fpOut);

    if (!found) {
        printf("Order with ID %d not found.\n", idToRemove);
        remove("tempOrderData.txt"); // Delete the temporary file
        return 1;
    }

    remove("orderData.txt"); // Remove the original file
    rename("tempOrderData.txt", "orderData.txt"); // Rename the temporary file

    printf("Order with ID %d removed successfully.\n", idToRemove);
    return 0;
}

//[---------------------- : Search - Order (S) - Function : ----------------------]
int searchOrder() {
    FILE *fp;
    Order order;
    int idToSearch, j, c;
    int found = 0;

    fp = fopen("orderData.txt", "r");
    if (fp != NULL) {
        system("clear");
        printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\t    ---: P R O V I D E  - O R D E R - D E T A I L S :--- ");
        printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        printf("\n\t\t Enter the ID of the order you want to search  :--> ");
        scanf("%d", &idToSearch);

        // Skip the first 5 lines if the file is not empty
        rewind(fp);
        for (j = 0; j < 5; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        // Read each order from the file
        while (fscanf(fp, "%d%s%d%d%f", &order.id, order.customerName, &order.menuItemId, &order.quantity, &order.totalPrice) == 5) {
            if (idToSearch == order.id) {
                system("clear");
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf("\n:               ---: O R D E R - D E T A I L :---               :");
                printf("\n-----------------------------------------------------------------");
                printf("\n\t Order Id           :  %d", order.id);
                printf("\n\t Customer Name      :  %s", order.customerName);
                printf("\n\t Menu Item Id       :  %d", order.menuItemId);
                printf("\n\t Quantity           :  %d", order.quantity);
                printf("\n\t Total Price        :  %.2f", order.totalPrice);
                printf("\n-----------------------------------------------------------------\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n\t Order with ID %d not found.\n", idToSearch);
        }

        fclose(fp);
    } else {
        printf("\n\tFile Not Found...");
    }

    return 0;
}
