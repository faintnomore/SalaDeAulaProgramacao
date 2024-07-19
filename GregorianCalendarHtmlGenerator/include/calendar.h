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

//Calendar information
#define WEEKDAYS 7
#define WEEKS_YEAR 53
#define YEAR_DAYS 365
#define LEAP_YEAR_INTERVAL 4


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

/**
 * @brief Prints a table cell with a specified day and background color.
 * 
 * @param file Pointer to the output file.
 * @param day The day number to print. If day is 0, an empty cell is printed.
 * @param color The background color style for the cell.
 */
void printDayCell(FILE *file, int day, const char *color);

/**
 * @brief Prints a table cell with the week number.
 * 
 * @param file Pointer to the output file.
 * @param weekNumber The week number to print.
 */
void printWeekNumberCell(FILE *file, int weekNumber);

/**
 * @brief Prints an empty day cell with the appropriate background color based on the day of the week.
 * 
 * @param file Pointer to the output file.
 * @param dayOfWeek The day of the week (1 = Monday, ..., 7 = Sunday).
 */
void printEmptyDayCell(FILE *file, int dayOfWeek);

/**
 * @brief Checks if a given year is a leap year.
 * 
 * @param year The year to check.
 * @return int Returns 1 if the year is a leap year, 0 otherwise.
 */
int isLeapYear(int year);

/**
 * @brief Uses Zeller's congruence to determine the first day of the month.
 * 
 * @param year The year.
 * @param month The month (1 = January, ..., 12 = December).
 * @return int The day of the week (1 = Monday, ..., 7 = Sunday).
 */
int getZellerCongruence(int year, int month);

/**
 * @brief Returns the number of days in a given month and year.
 * 
 * @param month The month (1 = January, ..., 12 = December).
 * @param year The year.
 * @return int The number of days in the month.
 */
int getDaysInMonth(int month, int year);

/**
 * @brief Calculates the ISO week number for a given date.
 * 
 * @param year The year.
 * @param month The month (1 = January, ..., 12 = December).
 * @param day The day of the month.
 * @return int The ISO week number.
 */
int getWeekNumber(int year, int month, int day);

/**
 * @brief Prints an HTML table for a given month and year.
 * 
 * @param file Pointer to the output file.
 * @param year The year.
 * @param month The month (1 = January, ..., 12 = December).
 */
void printMonthHTML(FILE *file, int year, int month);

/**
 * @brief Prints an HTML table for the entire year.
 * 
 * @param file Pointer to the output file.
 * @param year The year to print.
 */
void printYearHTML(FILE *file, int year);


#endif // CALENDAR_H
