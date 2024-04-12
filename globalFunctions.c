//: Delay Function Using Usleep
void delay(int milliseconds) {
    usleep(milliseconds * 1000);
}

//: Preloader Function (Inspired from: https://github.com/anirudhsharma8209)
int Loading() {
    int i;
    for (i = 1; i < 10; i++) {
        delay(150);
        printf(". ");
        fflush(stdout);
    }    
    return 0;
}

// Function to get current date and time
void getCurrentDateTime(char dateTime[]) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(dateTime, 20, "%Y-%m-%d %H:%M:%S", tm);
}

// Validate whether the number is positive or not
int validateNumInput(int *num) {
    int valid = 0;
    do {
        if (scanf("%d", num) == 1 && *num > 0) {
            valid = 1;
        } else {
            printf("\n\n\t\t | Invalid input. Please enter a valid number: ");
            while (getchar() != '\n');
        }
    } while (!valid);
    return 0;
}


// Validate whether the string meets the specified criteria
int validateStringInput(char *str) {
    int valid = 0;
    do {
        scanf("%s", str);
        int len = strlen(str);
        if (len >= 3 && len <= 14) { 
            int hasNonAlpha = 0;
            for (int i = 0; i < len; i++) {
                if (!isalpha(str[i])) {
                    hasNonAlpha = 1;
                    break;
                }
            }
            if (!hasNonAlpha) {
                valid = 1;
            } else {
                printf("\n\n\t\t | String must contain only alphabetic characters. Please enter again: ");
            }
        } else {
            printf("\n\n\t\t | String length must be between 3 and 14 characters. Please enter again: ");
        }
        // Clear input buffer
        while (getchar() != '\n');
    } while (!valid);
    return 0;
}

// Validate whether the string meets the specified criteria
int validateStringInput2(char *str) {
    int valid = 0;
    do {
        scanf("%s", str);
        int len = strlen(str);
        if (len >= 3 && len <= 14) { 
            int hasNonAlpha = 0;
            for (int i = 0; i < len; i++) {
                if (!isalpha(str[i])) {
                    hasNonAlpha = 1;
                    break;
                }
            }
            if (!hasNonAlpha) {
                valid = 1;
            }
        } else {
            printf("\n\n\t\t | String length must be between 3 and 14 characters. Please enter again: ");
        }
    } while (!valid);
    // Clear input buffer
        while (getchar() != '\n');
    return 0;
}


// Validate whether the string meets the specified criteria
int validateInputLength(char *str, int length) {
    int valid = 0;
    do {
        printf("\n| Enter input (%d characters): ", length);
        scanf("%s", str);
        int len = strlen(str);
        if (len == length) {
            // Check if all characters are digits
            int allDigits = 1;
            for (int i = 0; i < len; i++) {
                if (!isdigit(str[i])) {
                    allDigits = 0;
                    break;
                }
            }
            if (allDigits) {
                valid = 1;
            } else {
                printf("\n\t\t\t | Input must contain only digits. Please enter again.");
            }
        } else {
            printf("\n\t\t\t | Input must be %d characters long. Please enter again.", length);
        }
        // Clear input buffer
        while (getchar() != '\n');
    } while (!valid);
    return 0;
}