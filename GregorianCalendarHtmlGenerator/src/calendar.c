#include "../include/calendar.h"

// Constants for cell background colors
const char *weekdayColor = "style='background-color:white;'";
const char *saturdayColor = "style='background-color:yellow;'";
const char *sundayColor = "style='background-color:orange;'";
const char *weekColor = "style='background-color:gray; color:white;'";
const char *monthColor ="style='background-color:white;'";


void printDayCell(FILE *file, int day, const char *color) {
    if (day == 0) {
        fprintf(file, "<td %s></td>", color);
    } else {
        fprintf(file, "<td %s>%d</td>", color, day);
    }
}

void printWeekNumberCell(FILE *file, int weekNumber) {
    fprintf(file, "<td %s>%d</td>", weekColor, weekNumber);
}

void printEmptyDayCell(FILE *file, int dayOfWeek) {
    if (dayOfWeek == SATURDAY) {
        printDayCell(file, 0, saturdayColor);
    } else if (dayOfWeek == SUNDAY) {
        printDayCell(file, 0, sundayColor);
    } else {
        printDayCell(file, 0, weekdayColor);
    }
}

int isLeapYear(int year) {
    
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }

    return 0;                
}

//Zeller's congruence
int getZellerCongruence(int year, int month) {

    if (month < MARCH) {
        month += 12;
        year--;
    }
    const int q = 1;    
    int k = year % 100;
    int j = year / 100;
    int h = (q + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return ((h + 5) % 7) + 1;
}

int getDaysInMonth(int month, int year) {

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == FEBRUARY && isLeapYear(year)) {
        return 29;
    }else{
        return (month < JANUARY || month > DECEMBER) ? 0 : daysInMonth[month];
    }

}

int getWeekNumber(int year, int month, int day) {

    int dayOfYear = 0;
    for (int m = 1; m < month; m++) {
        dayOfYear += getDaysInMonth(m, year);
    }
    dayOfYear += day;

    // Week number
    int jan1DayOfWeek = getZellerCongruence(year, JANUARY);
    int weekNumber = (dayOfYear - 1 + (jan1DayOfWeek - 1)) / 7 + 1;

    // Adjust if the calculated week number is for the next year
    if (weekNumber == 53) {
        int daysInYear = 365 + isLeapYear(year);
        if (dayOfYear > daysInYear - 7) {
            weekNumber = 1;
        }
    }

    return weekNumber;
}

void printMonthHTML(FILE *file, int year, int month) {

    const char *monthNames[] = {"January", 
                                "February", 
                                "March", 
                                "April", 
                                "May", 
                                "June", 
                                "July", 
                                "August", 
                                "September", 
                                "October", 
                                "November", 
                                "December"};

    int firstDay = getZellerCongruence(year, month);
    int daysInMonth = getDaysInMonth(month, year);

     // HTML Table Start for the month
    fprintf(file, "<table border='1'>\n");
    fprintf(file, 
        "<tr>\
            <th colspan='8'>%s %d</th>\
        </tr>", monthNames[month - 1], year);
    fprintf(file, 
        "<tr>\
            <th %s>Wk</th>\
            <th %s>Mo</th>\
            <th %s>Tu</th>\
            <th %s>We</th>\
            <th %s>Th</th>\
            <th %s>Fr</th>\
            <th %s>Sa</th>\
            <th %s>Su</th>\
        </tr>\n",
        weekColor, weekColor, weekColor, weekColor, weekColor, weekColor, weekColor, weekColor);

    int currentDay = MONDAY;
    int weekNumber = getWeekNumber(year, month, currentDay);

    while (currentDay <= daysInMonth) {
        fprintf(file, "<tr>");
        printWeekNumberCell(file, weekNumber);

        for (int dayOfWeek = MONDAY; dayOfWeek <= SUNDAY; dayOfWeek++) {
            if (currentDay > daysInMonth || (currentDay == MONDAY && dayOfWeek < firstDay)) {
                printEmptyDayCell(file, dayOfWeek);
            } else {
                if (dayOfWeek == SATURDAY) {
                    printDayCell(file, currentDay, saturdayColor);
                } else if (dayOfWeek == SUNDAY) {
                    printDayCell(file, currentDay, sundayColor);
                } else {
                    printDayCell(file, currentDay, weekdayColor);
                }
                currentDay++;
            }
        }

        fprintf(file, "</tr>\n");
        weekNumber++;
    }

    fprintf(file, "</table> <p>\n");
    // HTML Table End for the month
}

void printYearHTML(FILE *file, int year) {
    fprintf(file, "<h1>Year %d</h1>\n", year);
    for (int month = JANUARY; month <= DECEMBER; month++) {
        printMonthHTML(file, year, month);
    }
}


