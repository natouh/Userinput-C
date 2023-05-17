//Nathan Hababou 
//this program called newshell  allows the user to choose from a menu of options. 
//you run this program by hitting make and then ./newshell 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 100

// Function to execute a command passed as a string argument
void executeCommand(char *command) {
    char *args[MAX_COMMAND_LEN];
    int argIndex = 0;

    // Tokenize the command string into arguments
    char *arg = strtok(command, " ");
    while (arg != NULL) {
        args[argIndex++] = arg;
        arg = strtok(NULL, " ");
    }
    args[argIndex] = NULL;

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        fprintf(stderr, "Failed to execute command %s.\n", command);
        exit(1);
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    int commandNum = 0;
    char command[MAX_COMMAND_LEN];

    while (1) {
        // Print the menu options
        printf("\nMenu:\n");
        printf("1. letters\n");
        printf("2. numbers\n");
        printf("3. firstname\n");
        printf("4. userinput\n");
        printf("5. letters > outfile\n");
        printf("6. letters | userinput\n");
        printf("7. firstname | userinput\n");
        printf("8. exit\n");

        // Read the user's choice of command
        printf("Enter a command number: ");
        scanf("%d", &commandNum);

        // Execute the appropriate command based on the user's choice
        switch (commandNum) {
            case 1:
                executeCommand("./letters");
                break;
            case 2:
                executeCommand("./numbers");
                break;
            case 3:
                printf("Enter first name: ");
                scanf("%s", command);
                sprintf(command, "./firstname %s", command);
                executeCommand(command);
                break;
            case 4:
                executeCommand("./userinput");
                break;
            case 5:
                printf("Enter filename: ");
                scanf("%s", command);
                sprintf(command, "./letters > %s", command);
                executeCommand(command);
                break;
            case 6:
                executeCommand("./letters | ./userinput");
                break;
            case 7:
                printf("Enter first name: ");
                scanf("%s", command);
                sprintf(command, "./firstname %s | ./userinput", command);
                executeCommand(command);
                break;
        
            case 8:
                // Exit the program
                return 0;
            
            default:
                printf("Wrong number.\n");
                break;
        }
    }
}

