#include "../include/calendar.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Validates command-line arguments.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @param year Pointer to an integer where the year will be stored.
 * @param filename Pointer to a string where the filename will be stored.
 * 
 * @return 0 if arguments are valid; -1 if there is an error.
 */
int validateArguments(int argc, char *argv[], int *year, char **filename);

/**
 * @brief Generates the HTML content for the calendar.
 * 
 * @param file The file pointer where HTML content will be written.
 * @param year The year for which the calendar is generated.
 */
void generateCalendarHtml(FILE *file, int year);

/**
 * @brief Prints the execution time of the program.
 * 
 * @param start_time The clock time when the program started.
 */
void printExecutionTime(clock_t start_time);

int main(int argc, char *argv[]) {
    
    clock_t start_time = clock(); 

    int year;
    char *filename;
    
    // Validate input arguments
    if (validateArguments(argc, argv, &year, &filename) != 0) {
        return EXIT_FAILURE;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
    }

    generateCalendarHtml(file, year);

    fclose(file);

    printf("Calendar generated successfully in %s\n", filename);
    
    printExecutionTime(start_time);

    return EXIT_SUCCESS;
}

int validateArguments(int argc, char *argv[], int *year, char **filename) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <year> <filename>\n", argv[0]);
        return -1;
    }

    *year = atoi(argv[1]);
    if (*year < 1583) {
        fprintf(stderr, "Year must be 1583 or later.\n");
        return -1;
    }

    *filename = argv[2];
    return 0;
}

void generateCalendarHtml(FILE *file, int year) {
    fprintf(file, 
        "<!DOCTYPE html>\n\
        <html lang='en'>\n\
        <head>\n\
            <meta charset='UTF-8'>\n\
            <meta content='width=device-width, initial-scale=1.0'>\n\
            <link rel='stylesheet' href='./style.css' />\n\
            <title>Calendar %d-%d-%d</title><p>\n\
        </head>\n\
        <body>\n", year-1, year, year+1);

    // Generate calendar for the specified year and surrounding years
    for (int i = year - 1; i <= year + 1; i++) {
        printYearHTML(file, i);
    }
    
    fprintf(file, "</body>\n</html>\n");
}

void printExecutionTime(clock_t start_time) {
    clock_t end_time = clock() - start_time;
    double time_taken = ((double)end_time) / CLOCKS_PER_SEC; // seconds 
    printf("Code took %f seconds to execute \n", time_taken);
}
