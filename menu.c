//[---------------------- : Custom Structures : ----------------------]
typedef struct MenuItem {
    int id;
    char name[50];
    int price;
} MenuItem;
MenuItem item;

//[---------------------- : Function Declarations : ----------------------]
int addMenuItem();     // add menu item
int updateMenuItem();  // update menu item
int displayMenuItems();  // display menu item
int removeMenuItem();  // remove menu item
int searchMenuItem();  // search menu item
float getPrice(int menuItemId); // Declare getPrice() function

//[---------------------- : ANSI Color Codes  : ----------------------]
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


//[---------------------- : Menu Managing - Main Program  : ----------------------]
int menuManagement() {
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
        printf("\n\t\t * Enter : [1] --> A D D - M E N U - I T E M (S)                                                                           * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [2] --> U P D A T E - M E N U - I T E M (S)                                                                     * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [3] --> D I S P L A Y - M E N U - I T E M (S)                                                                   * \n");	
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [4] --> R E M O V E - M E N U - I T E M (S)                                                                     * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [5] --> S E A R C H - M E N U - I T E M (S)                                                                     * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [6] --> R E T U R N - TO - D A S H B O A R D                                                                    * \n");			
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter Your Choice : --> ");
        printf(ANSI_COLOR_RESET);
        scanf("%d", &choice);
        switch (choice) {
            //[---------------------- : Add - Menu Item (S) : ----------------------]
            case 1:
                addMenuItem();
                break;

            //[---------------------- : Update - Menu Item (S) : ----------------------]
            case 2:
                updateMenuItem();
                break;

            //[---------------------- : Display - Menu Item (S) : ----------------------]
            case 3:
                displayMenuItems();
                break;

            //[---------------------- : Remove - Menu Item (S) : ----------------------]
            case 4:
                removeMenuItem();
                break;

            //[---------------------- : Search - Menu Item (S) : ----------------------]
            case 5:
                searchMenuItem();
                break;

            //[---------------------- : Exit From Menu Management Window : ----------------------]
            case 6:
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\tReturning Back to Dashboard"); Loading();
                system("clear");
                return 0;
                break;

            //[---------------------- : Re-Enter Into Menu Management Window : ----------------------]
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



//[---------------------- : Add - Menu Item (S) - Function : ----------------------]
int addMenuItem() {
    FILE *fp = NULL;
    int size, i;
    int itemId;
    int uniqueId = 0;

    // Open menu data file
    fp = fopen("menuData.txt", "a+");
    if (fp == NULL) {
        printf("\n\tFile Opening Failed.....");
        return 0;
    }

    // Check if the file is empty
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
        // Add formatting lines
        fprintf(fp, "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        fprintf(fp, "\n:                  ---: M E N U S - D A T A (S) :---            :");
        fprintf(fp, "\n-----------------------------------------------------------------");
        fprintf(fp, "\nId\t\t\t\t\t\tName\t\t\t\t\t\tPrice");
        fprintf(fp, "\n-----------------------------------------------------------------\n");
    } else {
        // Skip the first 5 lines if file is not empty
        rewind(fp); // Move the file pointer to the beginning
        for (int j = 0; j < 5; ++j) {
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }
    }

    // Retrieve the last ID from the file and Skip name & price
    while (fscanf(fp, "%d", &uniqueId) == 1) {
        fscanf(fp, "%*s %*d");
    }

    uniqueId++;

    fseek(fp, 0, SEEK_END);
    system("clear");
    printf("\n\t\t =========================================================================================================================== \n");
    printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
    printf("\n\t\t =========================================================================================================================== \n");

    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t | Enter Total Items Do You Want To Add? : --> ");
    printf(ANSI_COLOR_RESET);
    validateNumInput(&size);

    // Read item details and write to file
    for(i = 0; i < size; i++) {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf("\n\t\t Item %d Details : ", i+1);

        item.id = uniqueId++;

        printf("\n\n\t\t\t | Enter Item Name  :--> ");
        scanf("%s", item.name); // Read item name

        printf("\n\n\t\t\t | Enter Item Price :--> ");
        scanf("%d", &item.price); // Read item price

        fprintf(fp, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\n", item.id, item.name, item.price);
    }

    fclose(fp);
    printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
    printf(ANSI_COLOR_GREEN);
    printf("\n\t\t %d items added successfully!", size); Loading();
    printf(ANSI_COLOR_RESET);
    system("clear");
    return 0;
}


//[---------------------- : Update - Menu Item (S) - Function : ----------------------]
int updateMenuItem() {
    int idToUpdate;
    system("clear");
    printf("\n\t\t =========================================================================================================================== \n");
    printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
    printf("\n\t\t =========================================================================================================================== \n");
    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t | Enter the ID of the item you want to update: --> ");
    printf(ANSI_COLOR_RESET);
    scanf("%d", &idToUpdate);

    FILE *fp = fopen("menuData.txt", "r+");
    if (fp != NULL) {
        MenuItem temp;
        int found = 0;

        // Skip the first 5 lines if the file is not empty
        rewind(fp); // Move the file pointer to the beginning
        for (int j = 0; j < 5; ++j) {
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d%s%d", &temp.id, temp.name, &temp.price) == 3) {
            if (temp.id == idToUpdate) {
                printf("\n\n\t\t\t | Enter the new name for the item :--> ");
                scanf("%s", temp.name);
                printf("\n\n\t\t\t | Enter the new price for the item :--> ");
                scanf("%d", &temp.price);
                // Move the file pointer to the beginning of the line
                fseek(fp, -1 * (strlen(temp.name) + sizeof(temp.price) + 5), SEEK_CUR);
                // Write the updated name and price
                fprintf(fp, "%s\t\t\t\t\t\t%d\n", temp.name, temp.price);
                found = 1;
                break;
            }
        }
        fclose(fp);
        if (!found) {
            printf(ANSI_COLOR_RED);
            printf("\n\tItem with ID %d not found.\n", idToUpdate);
            printf(ANSI_COLOR_RESET);
        }else{
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\t\t Item %d updated successfully!", idToUpdate); Loading();
            printf(ANSI_COLOR_RESET);
            system("clear");
        }
    } else {
        printf("\n\tFile Not Found...");
    }
    return 0;
}

//[---------------------- : Display - Menu Item (S) - Function : ----------------------]
int displayMenuItems() {
    FILE *fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║   M E N U   ║                             ");
        printf("\n\t\t\t\t\t\t                   ╚═════════════╝                             \n\n");
        printf(ANSI_COLOR_RESET);

        printf("\n\t\t\t\t\t ╔═════════════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t ║ %-10s ║ %-30s ║ %-23s ║", "ID", "Name", "Price (\u20B9 +GST)");
        // Skip the first 5 lines if the file is not empty
        rewind(fp); // Move the file pointer to the beginning
        for (int j = 0; j < 5; ++j) {
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d%s%d", &item.id, item.name, &item.price) == 3) {
            float price_with_gst = item.price * (1 + 0.18);
            printf("\n\t\t\t\t\t ║=====================================================================║");
            printf("\n\t\t\t\t\t ║ %-10d | %-30s | %-21.2f ║", item.id, item.name, price_with_gst);
        }
        printf("\n\t\t\t\t\t ╚═════════════════════════════════════════════════════════════════════╝\n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\n\t\t\t\t\t | Press any key to go back...");
        printf(ANSI_COLOR_RESET);
        getchar();
        getchar();
        fclose(fp);
    } else {
        printf("\n\tFile Not Found...");
    }
    return 0;
}



//[---------------------- : Remove - Menu Item (S) - Function : ----------------------]
int removeMenuItem() {
    int idToRemove;
    system("clear");
    printf("\n\t\t =========================================================================================================================== \n");
    printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
    printf("\n\t\t =========================================================================================================================== \n");
    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t | Enter the ID of the item you want to remove: --> ");
    printf(ANSI_COLOR_RESET);
    scanf("%d", &idToRemove);

    FILE *fpIn = fopen("menuData.txt", "r");
    FILE *fpOut = fopen("tempMenuData.txt", "w");

    if (fpIn == NULL || fpOut == NULL) {
        printf("Error opening file.");
        return 1;
    }

    char line[100];
    int newID = 1; // To track the new IDs
    int found = 0;

    // Preserve the first 5 lines of formatting
    for (int j = 0; j < 5; ++j) {
        if (fgets(line, sizeof(line), fpIn) == NULL) {
            printf("Error reading file.");
            return 1;
        }
        fprintf(fpOut, "%s", line);
    }

    // Copy lines from fpIn to fpOut, except the line with idToRemove
    while (fgets(line, sizeof(line), fpIn) != NULL) {
        MenuItem temp;
        if (sscanf(line, "%d %49s %d", &temp.id, temp.name, &temp.price) == 3) {
            if (temp.id == idToRemove) {
                found = 1;
                continue; // Skip this line
            }
            // Update ID if not removed
            temp.id = newID++;
            fprintf(fpOut, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\n", temp.id, temp.name, temp.price);
        }
    }

    fclose(fpIn);
    fclose(fpOut);

    if (!found) {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_RED);
        printf("\n\t\t Item with ID %d not found", idToRemove); Loading();;
        remove("tempMenuData.txt");
        printf(ANSI_COLOR_RESET);
        return 1;
    }else{
        remove("menuData.txt"); // Remove the original file
        rename("tempMenuData.txt", "menuData.txt"); // Rename the temporary file
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_GREEN);
        printf("\n\t\t Item %d removed successfully!", idToRemove); Loading();
        printf(ANSI_COLOR_RESET);
        system("clear");
    }
    return 0;
}

//[---------------------- : Search - Menu Item (S) - Function : ----------------------]
int searchMenuItem() {
    FILE *fp;
    int idToSearch;
    int found = 0;
    char choice;

    do {
        fp = fopen("menuData.txt", "r");
        if (fp != NULL) {
            system("clear");
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
            printf("\n\t\t =========================================================================================================================== \n");
            printf(ANSI_COLOR_BLUE);
            printf("\n\t\t | Enter the ID of the item you want to search: --> ");
            printf(ANSI_COLOR_RESET);
            scanf("%d", &idToSearch);

            // Skip the first 5 lines if the file is not empty
            for (int j = 0; j < 5; ++j) {
                int c;
                while ((c = fgetc(fp)) != EOF && c != '\n');
            }

            // Read each item from the file
            while (fscanf(fp, "%d%s%d", &item.id, item.name, &item.price) == 3) {
                if (idToSearch == item.id) {
                    system("clear");
                    float price_with_gst = item.price * (1 + 0.18);
                    printf("\n\n\n\t\t\t\t\t ╔═════════════════════════════════════════════════════════════════════╗");
                    printf("\n\t\t\t\t\t ║               F O U N D  -  I T E M  -  D E T A I L S               ║");
                    printf("\n\t\t\t\t\t ║═════════════════════════════════════════════════════════════════════║");
                    printf("\n\t\t\t\t\t ║ %-10s ║ %-30s ║ %-23s ║", "ID", "Name", "Price (\u20B9 +GST)");
                    printf("\n\t\t\t\t\t ║=====================================================================║");
                    printf("\n\t\t\t\t\t ║ %-10d | %-30s | %-21.2f ║", item.id, item.name, price_with_gst);
                    printf("\n\t\t\t\t\t ╚═════════════════════════════════════════════════════════════════════╝\n");
                    found = 1;
                    break;
                }
                // Read and discard the newline character
                fgetc(fp);
            }

            if (!found) {
                printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
                printf(ANSI_COLOR_RED);
                printf("\n\n\t\t\tError: ");
                printf(ANSI_COLOR_RESET);
                printf("Item with ID %d not found.\n\n", idToSearch);
            }

            fclose(fp);
        } else {
            printf("\n\tFile Not Found...");
            return 0;
        
        }

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to search for another item? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);

        // Convert the choice to uppercase for simplicity
        choice = choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

//[---------------------- : Get Price Function : ----------------------]
float getPrice(int menuItemId) {
    FILE *fp;
    MenuItem item;
    float price = -1.0; // Default value if item not found

    fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        rewind(fp);
        for (int j = 0; j < 5; ++j) {
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d%s%d", &item.id, item.name, &item.price) == 3) {
            if (item.id == menuItemId) {
                price = (float)item.price;
                break;
            }
        }
        fclose(fp);
    } else {
        printf("Error: Could not open menu data file.\n");
    }

    return price;
}