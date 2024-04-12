//[---------------------- : Header & Custom Files Linking  : ----------------------]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include<ctype.h>
#include "globalFunctions.c"
#include "menu.c"
#include "order.c"
#include "staff.c"

//[---------------------- : ANSI Color Codes  : ----------------------]
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLORBLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m" 

//[---------------------- : Welcome Screen  : ----------------------]
void welcomeScreen() {
    printf("\n\n\n\n\n\n");
    printf(ANSI_COLOR_YELLOW);
    printf("\n\t\t\t\t\t╔═══════════════════════════════════════════════════════════════════════════════╗");
    printf("\n\t\t\t\t\t║\t                                                                   \t║");
    printf("\n\t\t\t\t\t║\t███╗   ███╗    ██╗    ██████╗     ██████╗      █████╗     ██╗   ██╗\t║");
    printf("\n\t\t\t\t\t║\t████╗ ████║    ██║    ██╔══██╗    ██╔══██╗    ██╔══██╗    ╚██╗ ██╔╝\t║");
    printf("\n\t\t\t\t\t║\t██╔████╔██║    ██║    ██║  ██║    ██║  ██║    ███████║     ╚████╔╝ \t║");
    printf("\n\t\t\t\t\t║\t██║╚██╔╝██║    ██║    ██║  ██║    ██║  ██║    ██╔══██║      ╚██╔╝  \t║");
    printf("\n\t\t\t\t\t║\t██║ ╚═╝ ██║    ██║    ██████╔╝    ██████╔╝    ██║  ██║       ██║   \t║");
    printf("\n\t\t\t\t\t║\t╚═╝     ╚═╝    ╚═╝    ╚═════╝     ╚═════╝     ╚═╝  ╚═╝       ╚═╝   \t║");
    printf("\n\t\t\t\t\t║\t                                                                   \t║");
    printf("\n\t\t\t\t\t╚═══════════════════════════════════════════════════════════════════════════════╝");
    printf(ANSI_COLOR_RESET);
                                                                               
}

//[---------------------- : Login Screen & Function  : ----------------------]
int login() {
    char username[20];
    char password[20];
    printf("\n\t\t\t\t\t\t\t\t\tWELCOMES YOU! \n\n");
    printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
    printf("\n\t\t\t\t\t\t║                <-- LOGIN NOW TO ACCESS -->                  ║");
    printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
    printf(ANSI_COLOR_BLUE);
    printf("\n\n\t\t\t\t\t\t | Enter Username : --> ");
    printf(ANSI_COLOR_RESET);
    scanf("%s", username);
    printf(ANSI_COLOR_BLUE);
    printf("\n\t\t\t\t\t\t | Enter Password : --> ");
    printf(ANSI_COLOR_RESET);
    scanf("%s", password);
    if (strcmp(username, "manager") == 0 && strcmp(password, "password") == 0) {
        return 1;
    } else {
        return 0;
    }
}



//[---------------------- : Main Program  : ----------------------]
int main() {
    int choice;
    int loggedIn = 1; 

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);                 // Get the current time in seconds
    timeinfo = localtime(&rawtime);

    while (1) {
        if (!loggedIn) {
            system("clear");
            welcomeScreen();
            if (login()) {
                        loggedIn = 1;
                        printf("\n\t\t\t\t\t  ------------------------------------------------------------------------------\n");   
                        printf(ANSI_COLOR_GREEN);                                                                             
                        printf("\n\t\t\t\t\t\t\t\tLogin successful! Welcome back.\n");
                        sleep(2);
                        printf(ANSI_COLOR_RESET);
                        system("clear"); printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); printf("\t\t\t\t\t\t\tLoading Dashboard"); Loading(); system("clear");
                    } else {
                        printf("\n\t\t\t\t\t  ------------------------------------------------------------------------------\n");   
                        printf(ANSI_COLOR_RED);         
                        printf("\n\t\t\t\t\t\t\t\tLogin failed! Please try again.\n");
                        sleep(2);
                        printf(ANSI_COLOR_RESET);
            }
        } else {
            printf(ANSI_COLOR_YELLOW);
            printf("\n\t\t\t\t\t\t╔═════════════════════════════════════════════════════════════╗");
            printf("\n\t\t\t\t\t\t║                                                             ║");
            printf("\n\t\t\t\t\t\t║          <--: T H E  M I D D A Y  R E S T R O :-->          ║");
            printf("\n\t\t\t\t\t\t║                                                             ║");
            printf("\n\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════╝");
            printf("\n\t\t\t\t\t\t                   ║  D A S H B O A R D  ║                    ");
            printf("\n\t\t\t\t\t\t                   ╚═════════════════════╝\n");
            printf("\n\t\t\t\t\t\t                  %s\n", asctime(timeinfo));
            printf(ANSI_COLOR_RESET);
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t * Enter : [1] --> M E N U - M A N A G E M E N T                                                                           * \n");
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t * Enter : [2] --> O R D E R - M A N A G E M E N T                                                                         * \n");
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t * Enter : [3] --> S T A F F - M A N A G E M E N T                                                                         * \n");	
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t * Enter : [4] --> C U S T O M E R - M A N A G E M E N T                                                                   * \n");
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n\t\t * Enter : [5] --> L O G O U T                                                                                             * \n");			
            printf("\n\t\t =========================================================================================================================== \n");
            printf("\n");
            printf(ANSI_COLOR_BLUE);
            printf("\n\t\t | Enter Number To Start Your Work : --> ");
            printf(ANSI_COLOR_RESET);
            scanf("%d", &choice);
            switch (choice) {
                //[---------------------- : Manage Menus  : ----------------------]
                case 1:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); printf("\t\t\t\t\t\t\tEntering Into Menu Management"); Loading(); system("clear");
                    menuManagement();
                    break;

                //[---------------------- : Manage Orders  : ----------------------]
                case 2:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); printf("\t\t\t\t\t\t\tEntering Into Order Management"); Loading(); system("clear");
                    orderManagement();
                    break;

                //[---------------------- : Manage Staffs  : ----------------------]
                case 3:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); printf("\t\t\t\t\t\t\tEntering Into Staff Management"); Loading(); system("clear");
                    staffManagement();
                    break;

                //[---------------------- : Manage Customers  : ----------------------]
                case 4:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); printf("\t\t\t\t\t\t\tEntering Into Customer Management"); Loading(); system("clear");
                    break;

                //[---------------------- : Logout  : ----------------------]
                case 5:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    // Logout
                    loggedIn = 0;
                    printf("\t\t\t\t\t\t\tLogged out successfully!"); Loading();
                    sleep(2);
                    break;
                
                //[---------------------- : Invalid Choice  : ----------------------]
                default:
                    system("clear");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    printf(ANSI_COLOR_RED);
                    printf("\t\t\t\t\t\t\t\tError: Invalid Choice\n\n");
                    printf(ANSI_COLOR_RESET);
                    printf("\t\t\t\t\t\t\tPlease select a valid option from the choices.\n\n");		
                    sleep(1);		
                    printf("\t\t\t\t\t\t\tReturning back to Dashboard"); Loading();
            }
            system("clear");
        }
    }
    return 0;
}

