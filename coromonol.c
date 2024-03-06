#include <stdio.h>
#include <string.h>

#define MAX_VARIABLES 100
char variables[MAX_VARIABLES][20];
char values[MAX_VARIABLES][100];
int num_variables = 0;

// Function prototypes for clarity
void execute_printy_statement(char *statement);
void execute_variable_assignment(char *statement);
int evaluate_expression(char *expression);

int main() {
    char code[100];

    while (1) {
        printf("Enter your code: ");
        fgets(code, 100, stdin);

        // Remove trailing newline (if present)
        code[strcspn(code, "\n")] = '\0';

        // Parse and execute code
        if (strncmp(code, "printy", 6) == 0) {
            execute_printy_statement(code + 7);  // Skip "printy "
        } else if (strchr(code, '=') != NULL) {
            execute_variable_assignment(code);
        } else if (strlen(code) > 0) {  // Handle calculator expressions
            int result = evaluate_expression(code);
            printf("%d\n", result);
        }
    }

    return 0;
}

// Functions for handling printy, variables, and expressions
// ... (Implementation details omitted for brevity, but they would involve
// parsing and executing the corresponding code)
