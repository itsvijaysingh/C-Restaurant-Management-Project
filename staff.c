//[---------------------- : Custom Structures : ----------------------]
typedef struct {
    int id;
    char name[100];
    char phone[11];
    char aadhar[13];
    char address[200];
    char position[50];
    int salary;
    char joinDate[20];
    char status[4];
} Staff;

Staff staff;

//[---------------------- : Function Declarations : ----------------------]
int addStaff();
int updateStaff();
int displayStaff();
int removeStaff();
int searchStaff();

//[---------------------- : ANSI Color Codes  : ----------------------]
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//[---------------------- : Staff Management - Main Program  : ----------------------]
int staffManagement() {
    int choice;
    
    while (1) {
        system("clear");
        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║  S T A F F S  ║                             ");
        printf("\n\t\t\t\t\t\t                   ╚═══════════════╝                             \n\n");
        printf(ANSI_COLOR_RESET);
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [1] --> A D D - S T A F F                                                                               * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [2] --> U P D A T E - S T A F F                                                                         * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [3] --> D I S P L A Y - S T A F F                                                                       * \n");    
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [4] --> R E M O V E - S T A F F                                                                         * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [5] --> S E A R C H - S T A F F                                                                         * \n");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t * Enter : [6] --> R E T U R N - TO - D A S H B O A R D                                                            * \n");            
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter Your Choice : --> ");
        printf(ANSI_COLOR_RESET);
        scanf("%d", &choice);
        switch (choice) {
            //[---------------------- : Add - Staff : ----------------------]
            case 1:
                addStaff();
                break;

            //[---------------------- : Update - Staff : ----------------------]
            case 2:
                updateStaff();
                break;

            //[---------------------- : Display - Staff : ----------------------]
            case 3:
                displayStaff();
                break;

            //[---------------------- : Remove - Staff : ----------------------]
            case 4:
                removeStaff();
                break;

            //[---------------------- : Search - Staff : ----------------------]
            case 5:
                searchStaff();
                break;

            //[---------------------- : Exit From Staff Management Window : ----------------------]
            case 6:
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\tReturning Back to Dashboard"); // Loading();
                system("clear");
                return 0;
                break;

            //[---------------------- : Re-Enter Into Staff Management Window : ----------------------]
            default:
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf(ANSI_COLOR_RED);
                printf("\t\t\t\t\t\t\t\tError: Invalid Choice\n\n");
                printf(ANSI_COLOR_RESET);
                printf("\t\t\t\t\t\t\tPlease select a valid option from the choices.\n\n");      
                //sleep(1);     
                printf("\t\t\t\t\t\t\tRe-Enter The Valid Choice"); // Loading();
                system("clear");
                continue;
        }
    }
    return 0;
}

//[---------------------- : Add - Staff : ----------------------]
int addStaff() {
    int i;
    char choice;
    int totalStaff = 0;
    int lastId = 0;
    FILE *fp = NULL;

    do {
        fp = fopen("staffData.txt", "a+");
        if (fp == NULL) {
            printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
            printf(ANSI_COLOR_RED);
            printf("\n\n\t\t Error: Data file not found!"); Loading();
            printf(ANSI_COLOR_RESET);
            return 1;
        }

        system("clear");
        printf("\n\t\t =========================================================================================================================== \n");
        printf("\n\t\t *                                ---: P R O V I D E  - S T A F F - D E T A I L S :---                                    * \n");
        printf("\n\t\t =========================================================================================================================== \n");

        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Enter Total Staff Do You Want To Add? : --> ");
        printf(ANSI_COLOR_RESET);
        validateNumInput(&totalStaff);

        // Read the last ID from the file
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) != 0) {
            rewind(fp);
            while (fscanf(fp, "%d", &lastId) == 1) {
                fscanf(fp, "%*[^\n]");
            }
        }

        for (i = 0; i < totalStaff; i++) {

            staff.id = lastId + i + 1; // Increment last ID

            printf("\n\t\t | Enter Staff Name            :--> ");
            scanf("%s", staff.name);
            printf("\n\t\t | Enter Staff Phone           :--> ");
            validateInputLength(staff.phone, 10);
            printf("\n\t\t | Enter Staff Aadhar          :--> ");
            validateInputLength(staff.phone, 12);
            printf("\n\t\t | Enter Staff Address         :--> ");
            validateStringInput2(staff.address);
            printf("\n\t\t | Enter Staff Position        :--> ");
            validateStringInput(staff.position);
            printf("\n\t\t | Enter Staff Salary          :--> ");
            validateNumInput(&staff.salary);
            printf("\n\t\t | Enter Staff Join Date(DD/MM/YYYY)       :--> ");
            validateStringInput2(staff.joinDate);
            printf("\n\t\t | Enter Staff Status (Busy/Free):--> ");
            validateStringInput(staff.status);
            
            fprintf(fp, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", 
                staff.id, staff.name, staff.phone, staff.aadhar, staff.address, staff.position, 
                staff.salary, staff.joinDate, staff.status);
        }

        fclose(fp);

        printf("\n\t\t---------------------------------------------------------------------------------------------------------------------------\n");
        printf(ANSI_COLOR_GREEN);
        printf("\n\t\t%d staff added successfully!", totalStaff); Loading();
        printf(ANSI_COLOR_RESET);
        printf("\n\t\t---------------------------------------------------------------------------------------------------------------------------\n");
        printf(ANSI_COLOR_BLUE);
        printf("\n\t\t | Do you want to add more staff? (Y/N): ");
        printf(ANSI_COLOR_RESET);
        scanf(" %c", &choice);
        while (getchar() != '\n');
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


//[---------------------- : Update - Staff : ----------------------]
int updateStaff() {
    // Implement the update staff function here
    return 0;
}

//[---------------------- : Display - Staff : ----------------------]
//[---------------------- : Display - Staff : ----------------------]
int displayStaff() {
    FILE *fp = NULL;
    fp = fopen("staffData.txt", "r");
    if (fp != NULL) {
        system("clear");

        printf(ANSI_COLOR_YELLOW);
        printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
        printf("\n\t\t\t\t\t\t║                                                             ║");
        printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
        printf("\n\t\t\t\t\t\t                   ║  S T A F F S  ║                             ");
        printf("\n\t\t\t\t\t\t                   ╚═════════════════╝ \n");
        printf(ANSI_COLOR_RESET);

        printf("\n\t\t\t\t\t ╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗");
        printf("\n\t\t\t\t\t ║ %-10s | %-20s | %-15s | %-15s | %-20s | %-10s | %-20s | %-10s |\n", "ID", "Name", "Phone", "Aadhar", "Address", "Position", "Join Date", "Status");
        printf("\t\t\t\t\t ║════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════║");
        
        while (fscanf(fp, "%d %s %s %s %s %s %d %s %s", &staff.id, staff.name, staff.phone, staff.aadhar, staff.address, staff.position, &staff.salary, staff.joinDate, staff.status) == 9) {
            printf("\n\t\t\t\t\t ║ %-10d | %-20s | %-15s | %-15s | %-20s | %-10s | %-20s | %-10s |", staff.id, staff.name, staff.phone, staff.aadhar, staff.address, staff.position, staff.joinDate, staff.status);
        }

        printf("\n\t\t\t\t\t ╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        fclose(fp);
        printf(ANSI_COLOR_BLUE);
        printf("\n\n\t\t\t\t\t | Press any key to go back...");
        printf(ANSI_COLOR_RESET);
        getchar();
        getchar();
    } else {
        printf("\n\t\t --------------------------------------------------------------------------------------------------------------------------- \n");
        printf(ANSI_COLOR_RED);
        printf("\n\n\t\t Error: no data files exist"); Loading();
        printf(ANSI_COLOR_RESET);
        return 1;
}
    return 0;
}



//[---------------------- : Remove - Staff : ----------------------]
int removeStaff() {
    // Implement the remove staff function here
    return 0;
}

//[---------------------- : Search - Staff : ----------------------]
int searchStaff() {
    // Implement the search staff function here
    return 0;
}
