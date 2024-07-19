#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdio.h>
#include <stdlib.h>


// Constants for days of the week
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7


// Months of the Year
#define JANUARY    1
#define FEBRUARY   2
#define MARCH      3
#define APRIL      4
#define MAY        5
#define JUNE       6
#define JULY       7
#define AUGUST     8
#define SEPTEMBER  9
#define OCTOBER   10
#define NOVEMBER  11
#define DECEMBER  12


// Constants for cell background colors
#define WEEKDAY_COLOR    "style='background-color:white;'"
#define SATURDAY_COLOR   "style='background-color:yellow;'"
#define SUNDAY_COLOR     "style='background-color:orange;'"
#define WEEK_COLOR       "style='background-color:gray; color:white;'"
#define MONTH_COLOR      "style='background-color:white;'"


// Function declarations
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getZellerCongruence(int year, int month);
void printMonthHTML(FILE *file, int year, int month);
void printYearHTML(FILE *file, int year);
void printEmptyDayCell(FILE *file, int dayOfWeek);
void printWeekNumberCell(FILE *file, int weekNumber);
void printDayCell(FILE *file, int day, const char *color);
int getWeekNumber(int year, int month, int day);


#endif // CALENDAR_H
