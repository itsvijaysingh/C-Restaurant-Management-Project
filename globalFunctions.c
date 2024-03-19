//: Delay Function Using Usleep
void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Convert milliseconds to microseconds
}

//: Preloader Function (Inspired from: https://github.com/anirudhsharma8209)
int Loading() {
    int i;
    for (i = 1; i < 10; i++) {
        delay(150);  // Delay for 150 milliseconds
        printf(". ");
        fflush(stdout);  // Ensure the output is immediately visible
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