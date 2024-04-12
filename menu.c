//[---------------------- : Custom Structures : ----------------------]
typedef struct MenuItem {
    int id;
    char name[50];
    int price;
} MenuItem;
MenuItem item;
MenuItem temp;

//[---------------------- : Function Declarations : ----------------------]
int addMenuItem();
int updateMenuItem();
int displayMenuItems();
int removeMenuItem();
int searchMenuItem();
float getPrice(int menuItemId);
char* getMenuItemName(int menuItemId);

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
    int uniqueId = 0;
    int line_count = 0;
    int c;
    char choice;

    // Open the file to read the last used ID
    fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        // Skip the first 5 lines in the file
        while (line_count < 5) {
            c = fgetc(fp);
            if (c == '\n' || c == EOF) {
                line_count++;
                if (c == EOF) break;
            }
        }

        // Retrieve the last ID from the file and skip name & price
        while (fscanf(fp, "%d", &uniqueId) == 1) {
            fscanf(fp, "%*[^\n]");
        }

        fclose(fp);

        // Increment the last used ID to generate a new unique ID
        uniqueId++;
    } else {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_RED);
        printf("\n\n\t\t Error: Data file not found!");  Loading();
        printf(ANSI_COLOR_RESET);
        return 1;
    }

    do {
        fp = fopen("menuData.txt", "a+");
        if (fp == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Data file not found!");  Loading();
            printf(ANSI_COLOR_RESET);
            return 1;
        }

        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) {
            fprintf(fp, "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            fprintf(fp, "\n:                  ---: M E N U S - D A T A (S) :---            :");
            fprintf(fp, "\n-----------------------------------------------------------------");
            fprintf(fp, "\nId\t\t\t\t\t\tName\t\t\t\t\t\tPrice");
            fprintf(fp, "\n-----------------------------------------------------------------\n");
        }

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
        for (i = 0; i < size; i++) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf("\n\t\t Item %d Details : ", i + 1);

            item.id = uniqueId++;

            printf("\n\n\t\t\t | Enter Item Name  :--> ");
            validateStringInput(item.name);

            printf("\n\n\t\t\t | Enter Item Price :--> ");
            validateNumInput(&item.price);

            fprintf(fp, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\n", item.id, item.name, item.price);
        }

        fclose(fp);

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_GREEN);
        printf("\n\t\t %d items added successfully!", size); Loading();
        printf(ANSI_COLOR_RESET);

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to add another item? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

//[---------------------- : Update - Menu Item (S) - Function : ----------------------]
int updateMenuItem() {
    int idToUpdate;
    char choice;
    MenuItem temp;
    FILE *fpIn;
    FILE *fpOut;
    char line[100];
    int found = 0;
    int j;

    do {
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter the ID of the item you want to update: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToUpdate);


        fpIn = fopen("menuData.txt", "r");
        fpOut = fopen("tempMenuData.txt", "w");

        if (fpIn == NULL || fpOut == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: opening file");  Loading();
            printf(ANSI_COLOR_RESET);
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

        while (fgets(line, sizeof(line), fpIn) != NULL) {
            if (sscanf(line, "%d %[^\t\n] %d", &temp.id, temp.name, &temp.price) == 3) {
                
                if (temp.id == idToUpdate) {
                    found = 1;
                    printf("\n\n\t\t\t | Enter the new name for the item: ");
                    validateStringInput(temp.name);
                    printf("\n\n\t\t\t | Enter the new price for the item: ");
                    validateNumInput(&temp.price);
                }
                fprintf(fpOut, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\n", temp.id, temp.name, temp.price);
            }
        }

        fclose(fpIn);
        fclose(fpOut);

        if (!found) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\t\t Item with ID %d not found", idToUpdate); 
            printf(ANSI_COLOR_RESET);
            remove("tempMenuData.txt");
        } else {
            remove("menuData.txt");
            rename("tempMenuData.txt", "menuData.txt");
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\t\t Item %d updated successfully!", idToUpdate);
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to update another item? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


//[---------------------- : Display - Menu Item (S) - Function : ----------------------]
int displayMenuItems() {
    FILE *fp = NULL;
    int j, c;
    float price_with_gst;
    fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
		printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║   M E N U   ║                             ");
        printf("\n\t\t\t\t\t\t                   ╚═════════════╝                             \n");
        printf(ANSI_COLOR_RESET);

        printf("\n\t\t\t\t\t ╔═════════════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t ║ %-10s ║ %-30s ║ %-23s ║", "ID", "Name", "Price (\u20B9 +GST)");
        // Skip the first 5 lines if the file is not empty
        rewind(fp);
        for (j = 0; j < 5; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d %[^\t\n] %d", &item.id, item.name, &item.price) == 3) {
            price_with_gst = item.price * (1 + 0.18);
            printf("\n\t\t\t\t\t ║=====================================================================║");
            printf("\n\t\t\t\t\t ║ %-10d | %-30s | %-21.2f ║", item.id, item.name, price_with_gst);
        }
        printf("\n\t\t\t\t\t ╚═════════════════════════════════════════════════════════════════════╝\n");
        fclose(fp);
        printf(ANSI_COLOR_BLUE);
        printf("\n\n\t\t\t\t\t | Press any key to go back...");
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



//[---------------------- : Remove - Menu Item (S) - Function : ----------------------]
int removeMenuItem() {
    int idToRemove;
    char choice;
    MenuItem temp;
    FILE *fpIn;
    FILE *fpOut;
    char line[100];
    int newID = 1;
    int found = 0;
    int j;

    do {
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter the ID of the item you want to remove: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToRemove);


        fpIn = fopen("menuData.txt", "r");
        fpOut = fopen("tempMenuData.txt", "w");

        if (fpIn == NULL || fpOut == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: opening file");  Loading();
            printf(ANSI_COLOR_RESET);
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

        while (fgets(line, sizeof(line), fpIn) != NULL) {
            if (sscanf(line, "%d %[^\t\n] %d", &temp.id, temp.name, &temp.price) == 3) {
                
                if (temp.id == idToRemove) {
                    found = 1;
                    continue;
                }
                temp.id = newID++;
                fprintf(fpOut, "%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\n", temp.id, temp.name, temp.price);
            }
        }

        fclose(fpIn);
        fclose(fpOut);

        if (!found) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\t\t Item with ID %d not found", idToRemove); 
            printf(ANSI_COLOR_RESET);
            remove("tempMenuData.txt");
        } else {
            remove("menuData.txt");
            rename("tempMenuData.txt", "menuData.txt");
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_GREEN);
            printf("\n\t\t Item %d removed successfully!", idToRemove);
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to remove another item? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


//[---------------------- : Search - Menu Item (S) - Function : ----------------------]
int searchMenuItem() {
    FILE *fp;
    int idToSearch;
    int found = 0;
    char choice;
    int j, c;
    float price_with_gst;

    do {
        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                   ---: P R O V I D E  - I T E M S - D E T A I L S :---                                  * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter the ID of the item you want to search: --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&idToSearch);

        fp = fopen("menuData.txt", "r");
        if (fp == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Data file not found!");  Loading();
            printf(ANSI_COLOR_RESET);
            return 1;
        }

        // Skip the first 5 lines if the file is not empty
        for (j = 0; j < 5; ++j) {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }

        while (fscanf(fp, "%d %[^\t\n] %d", &item.id, item.name, &item.price) == 3) {
            if (idToSearch == item.id) {
                system("clear");
                price_with_gst = item.price * (1 + 0.18);
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
            fgetc(fp);
        }

        fclose(fp);

        if (!found) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Item with ID %d not found", idToSearch);  Loading();
            printf(ANSI_COLOR_RESET);
        }

        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to search for another item? (Y/N): --> ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');
    return 0;
}

//[---------------------- : Get Price Function : ----------------------]
float getPrice(int menuItemId) {
    FILE *fp;
    MenuItem item;
    int j;
    float price = -1.0;
    char line[100];

    fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        rewind(fp);
        for (j = 0; j < 5; ++j) {
            fgets(line, sizeof(line), fp); // Skip the formatting lines
        }

        while (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%d %[^\t\n] %d", &item.id, item.name, &item.price) == 3) {
                if (item.id == menuItemId) {
                    price = (float)item.price;
                    break;
                }
            }
        }
        fclose(fp);
    } else {
        printf("Error: Could not open menu data file.\n");
    }

    return price;
}


//[---------------------- : Get Menu Item Name Function : ----------------------]
char* getMenuItemName(int menuItemId) {
    FILE *fp;
    char line[50];
    static char name[100];

    fp = fopen("menuData.txt", "r");
    if (fp != NULL) {
        // Skip the header lines
        for (int i = 0; i < 5; ++i) {
            fgets(line, sizeof(line), fp);
        }

        // Read each menu item entry and compare IDs
        while (fgets(line, sizeof(line), fp) != NULL) {
            MenuItem item;
            if (sscanf(line, "%d %[^\t\n] %d", &item.id, item.name, &item.price) == 3) {
                if (item.id == menuItemId) {
                    strcpy(name, item.name);
                    fclose(fp);
                    return name;
                }
            }
        }

        fclose(fp);
    } else {
        fprintf(stderr, "Error: Could not open menu data file.\n");
    }

    return NULL;
}