//[---------------------- : Function Declarations : ----------------------]

// Structure definition for Staff
typedef struct Staff {
    int id;
    char name[50];
    char position[50];
    float salary;
} Staff;

// Function declarations
int addStaff();
int updateStaff();
int displayStaff();
int removeStaff();
int getNextStaffId();

// Main function for staff management
int staffManagement() {
    int choice;
    
    while (1) {
        printf("\n\t <--: S T A F F - M A N A G E M E N T :--> ");
        printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\t * Enter : [1] --> A D D - S T A F F                       * ");
        printf("\n\t * Enter : [2] --> U P D A T E - S T A F F                 * ");
        printf("\n\t * Enter : [3] --> D I S P L A Y - A L L - S T A F F       * ");
        printf("\n\t * Enter : [4] --> R E M O V E - S T A F F                 * ");
        printf("\n\t * Enter : [5] --> B A C K - T O - M A I N                 * ");
        printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");

        printf("\n\t Enter Your Choice : --> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStaff();
                break;
            case 2:
                updateStaff();
                break;
            case 3:
                displayStaff();
                break;
            case 4:
                removeStaff();
                break;
            case 5:
                printf("\nExiting From Staff Management...\n");
                return 0;
            default:
                printf("\nError: Invalid Choice\n");
                printf("Please select a valid option from the choices.\n");
                break;
        }
    }
    return 0;
}

//[---------------------- : Function Definitions : ----------------------]

// Function to add a new staff member
int addStaff() {
    FILE *fp = fopen("staffData.txt", "a+");
    if (fp == NULL) {
        printf("\n\tFile Opening Failed.....");
        return 0;
    }

    Staff staff;
    staff.id = getNextStaffId();
    printf("\nEnter Staff Name: ");
    scanf("%s", staff.name);
    printf("Enter Staff Position: ");
    scanf("%s", staff.position);
    printf("Enter Staff Salary: ");
    scanf("%f", &staff.salary);

    fprintf(fp, "%d %s %s %.2f\n", staff.id, staff.name, staff.position, staff.salary);
    fclose(fp);

    printf("\nStaff added successfully.\n");
    return 0;
}

// Function to update an existing staff member
int updateStaff() {
    int idToUpdate;
    printf("\nEnter the ID of the staff member you want to update: ");
    scanf("%d", &idToUpdate);

    FILE *fp = fopen("staffData.txt", "r+");
    if (fp != NULL) {
        Staff temp;
        int found = 0;

        while (fscanf(fp, "%d%s%s%f", &temp.id, temp.name, temp.position, &temp.salary) == 4) {
            if (temp.id == idToUpdate) {
                printf("Enter the new staff name: ");
                scanf("%s", temp.name);
                printf("Enter the new staff position: ");
                scanf("%s", temp.position);
                printf("Enter the new staff salary: ");
                scanf("%f", &temp.salary);

                fseek(fp, -1 * (strlen(temp.name) + strlen(temp.position) + sizeof(temp.salary) + 3), SEEK_CUR);
                fprintf(fp, "%d %s %s %.2f\n", temp.id, temp.name, temp.position, temp.salary);
                found = 1;
                break;
            }
        }
        fclose(fp);
        if (!found) {
            printf("\nStaff member with ID %d not found.\n", idToUpdate);
        }
    } else {
        printf("\nFile Not Found...");
    }
    return 0;
}

// Function to display all staff members
int displayStaff() {
    FILE *fp = fopen("staffData.txt", "r");
    if (fp != NULL) {
        printf("\nStaff Members:\n");
        printf("ID\tName\tPosition\tSalary\n");
        Staff staff;
        while (fscanf(fp, "%d%s%s%f", &staff.id, staff.name, staff.position, &staff.salary) == 4) {
            printf("%d\t%s\t%s\t%.2f\n", staff.id, staff.name, staff.position, staff.salary);
        }
        fclose(fp);
    } else {
        printf("\nFile Not Found...");
    }
    return 0;
}

// Function to remove a staff member
int removeStaff() {
    int idToRemove;
    printf("\nEnter the ID of the staff member you want to remove: ");
    scanf("%d", &idToRemove);

    FILE *fpIn = fopen("staffData.txt", "r");
    FILE *fpOut = fopen("tempStaffData.txt", "w");

    if (fpIn == NULL || fpOut == NULL) {
        printf("Error opening file.");
        return 1;
    }

    Staff temp;
    int found = 0;

    while (fscanf(fpIn, "%d%s%s%f", &temp.id, temp.name, temp.position, &temp.salary) == 4) {
        if (temp.id == idToRemove) {
            found = 1;
            continue; // Skip this line
        }
        fprintf(fpOut, "%d %s %s %.2f\n", temp.id, temp.name, temp.position, temp.salary);
    }

    fclose(fpIn);
    fclose(fpOut);

    if (!found) {
        printf("Staff member with ID %d not found.\n", idToRemove);
        remove("tempStaffData.txt"); // Delete the temporary file
        return 1;
    }

    remove("staffData.txt"); // Remove the original file
    rename("tempStaffData.txt", "staffData.txt"); // Rename the temporary file

    printf("Staff member with ID %d removed successfully.\n", idToRemove);
    return 0;
}

// Function to get the next available staff ID
int getNextStaffId() {
    FILE *fp = fopen("staffData.txt", "r");
    if (fp == NULL) {
        return 1; // Start from ID 1 if file doesn't exist
    }

    int maxId = 0;
    int currentId;
    // Skip first 5 lines
    for (int i = 0; i < 5; ++i) {
        char line[100];
        fgets(line, sizeof(line), fp);
    }

    while (fscanf(fp, "%d", &currentId) == 1) {
        if (currentId > maxId) {
            maxId = currentId;
        }
        // Skip other fields
        fscanf(fp, "%*[^\n]\n");
    }

    fclose(fp);
    return maxId + 1;
}
