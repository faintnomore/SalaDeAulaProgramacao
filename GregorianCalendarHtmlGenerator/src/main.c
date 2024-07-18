#include "../include/calendar.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // Validate input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <year> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int year = atoi(argv[1]);
    if (year < 1583) {
        fprintf(stderr, "Year must be 1583 or later.\n");
        return EXIT_FAILURE;
    }

    char *filename = argv[2];

    // Open file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // HTML Start
    fprintf(file, 
        "<!DOCTYPE html>\n\
        <html lang='en'>\n\
        <head>\n\
            <meta charset='UTF-8'>\n\
            <meta content='width=device-width, initial-scale=1.0'>\n\
            <link rel='stylesheet' href='./style.css' />\n\
            <title>Calendar %d-%d-%d</title><p>\n\
            <style>\n\
                table { width: 20%%; height: 20%%; border-collapse: collapse; }\n\
                th, td { border: 1px solid black; padding: 5px; text-align: center; }\n\
            </style>\n\
        </head>\n\
        <body>\n", year-1, year, year+1);

    // Generate calendar for the specified year and surrounding years
    for (int i = year - 1; i <= year + 1; i++) {
        printYearHTML(file, i);
    }

    
    fprintf(file, "</body>\n</html>\n");
    // HTML End
    
    fclose(file);

    printf("Calendar generated successfully in %s\n", filename);

    return EXIT_SUCCESS;
}
