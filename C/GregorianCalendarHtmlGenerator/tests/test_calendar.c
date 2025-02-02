#include "../include/calendar.h"
#include <CUnit/Basic.h>

// Define file paths as constants
#define TEST_OUTPUT_DIR "./tests/html/"
#define TEST_OUTPUT_FILE TEST_OUTPUT_DIR "test_output.html"
#define EXPECTED_EMPTY_FILE TEST_OUTPUT_DIR "expected_output_empty.html"
#define EXPECTED_NON_EMPTY_FILE TEST_OUTPUT_DIR "expected_output_non_empty.html"
#define EXPECTED_WEEK_NUMBER_FILE TEST_OUTPUT_DIR "expected_output_week_number.html"
#define EXPECTED_SATURDAY_FILE TEST_OUTPUT_DIR "expected_output_saturday.html"
#define EXPECTED_SUNDAY_FILE TEST_OUTPUT_DIR "expected_output_sunday.html"
#define EXPECTED_JAN_2020_FILE TEST_OUTPUT_DIR "expected_output_jan_2020.html"
#define EXPECTED_2020_FILE TEST_OUTPUT_DIR "expected_output_2020.html"

// Test function declarations
void test_printDayCell_empty();
void test_printDayCell_non_empty();
void test_printWeekNumberCell();
void test_printEmptyDayCell_saturday();
void test_printEmptyDayCell_sunday();
void test_isLeapYear_leap();
void test_isLeapYear_non_leap();
void test_getZellerCongruence();
void test_getDaysInMonth_leap_february();
void test_getDaysInMonth_non_leap_february();
void test_getWeekNumber();
void test_printMonthHTML();
void test_printYearHTML();

// Helper function for file comparison
int compare_files(const char *file1, const char *file2);

int main() {
    CU_initialize_registry();
    
    CU_pSuite suite = CU_add_suite("Calendar_Test_Suite", 0, 0);
    
    CU_add_test(suite, "test_printDayCell_empty", test_printDayCell_empty);
    CU_add_test(suite, "test_printDayCell_non_empty", test_printDayCell_non_empty);
    CU_add_test(suite, "test_printWeekNumberCell", test_printWeekNumberCell);
    CU_add_test(suite, "test_printEmptyDayCell_saturday", test_printEmptyDayCell_saturday);
    CU_add_test(suite, "test_printEmptyDayCell_sunday", test_printEmptyDayCell_sunday);
    CU_add_test(suite, "test_isLeapYear_leap", test_isLeapYear_leap);
    CU_add_test(suite, "test_isLeapYear_non_leap", test_isLeapYear_non_leap);
    CU_add_test(suite, "test_getZellerCongruence", test_getZellerCongruence);
    CU_add_test(suite, "test_getDaysInMonth_leap_february", test_getDaysInMonth_leap_february);
    CU_add_test(suite, "test_getDaysInMonth_non_leap_february", test_getDaysInMonth_non_leap_february);
    CU_add_test(suite, "test_getWeekNumber", test_getWeekNumber);
    //CU_add_test(suite, "test_printMonthHTML", test_printMonthHTML);
    //CU_add_test(suite, "test_printYearHTML", test_printYearHTML);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}

void test_printDayCell_empty() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printDayCell(file, 0, WEEKDAY_COLOR);
    fclose(file);
    
    FILE *expected = fopen(EXPECTED_EMPTY_FILE, "w");
    fprintf(expected, "<td style='background-color:white;'></td>");
    fclose(expected);
    
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_EMPTY_FILE));
}

void test_printDayCell_non_empty() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printDayCell(file, 15, WEEKDAY_COLOR);
    fclose(file);
    
    FILE *expected = fopen(EXPECTED_NON_EMPTY_FILE, "w");
    fprintf(expected, "<td style='background-color:white;'>15</td>");
    fclose(expected);
    
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_NON_EMPTY_FILE));
}

void test_printWeekNumberCell() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printWeekNumberCell(file, 42);
    fclose(file);
    
    FILE *expected = fopen(EXPECTED_WEEK_NUMBER_FILE, "w");
    fprintf(expected, "<td style='background-color:gray; color:white;'>42</td>");
    fclose(expected);
    
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_WEEK_NUMBER_FILE));
}

void test_printEmptyDayCell_saturday() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printEmptyDayCell(file, SATURDAY);
    fclose(file);
    
    FILE *expected = fopen(EXPECTED_SATURDAY_FILE, "w");
    fprintf(expected, "<td style='background-color:yellow;'></td>");
    fclose(expected);
    
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_SATURDAY_FILE));
}

void test_printEmptyDayCell_sunday() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printEmptyDayCell(file, SUNDAY);
    fclose(file);
    
    FILE *expected = fopen(EXPECTED_SUNDAY_FILE, "w");
    fprintf(expected, "<td style='background-color:orange;'></td>");
    fclose(expected);
    
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_SUNDAY_FILE));
}

void test_isLeapYear_leap() {
    CU_ASSERT(isLeapYear(2020) == 1);
}

void test_isLeapYear_non_leap() {
    CU_ASSERT(isLeapYear(2019) == 0);
}

void test_getZellerCongruence() {
    CU_ASSERT(getZellerCongruence(2020, 10) == 4); // 1st October 2020 was a Thursday (4)
}

void test_getDaysInMonth_leap_february() {
    CU_ASSERT(getDaysInMonth(FEBRUARY, 2020) == 29);
}

void test_getDaysInMonth_non_leap_february() {
    CU_ASSERT(getDaysInMonth(FEBRUARY, 2019) == 28);
}

void test_getWeekNumber() {
    CU_ASSERT(getWeekNumber(2020, 1, 1) == 1); // 1st January 2020 was in the 1st week
}

void test_printMonthHTML() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printMonthHTML(file, 2020, 1); // Print January 2020
    fclose(file);
    
    // Manually create expected_output_jan_2020.html for January 2020 and compare
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_JAN_2020_FILE));
}

void test_printYearHTML() {
    FILE *file = fopen(TEST_OUTPUT_FILE, "w");
    printYearHTML(file, 2020); // Print 2020
    fclose(file);
    
    // Manually create expected_output_2020.html for 2020 and compare
    CU_ASSERT(compare_files(TEST_OUTPUT_FILE, EXPECTED_2020_FILE));
}

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    if (f1 == NULL || f2 == NULL) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 0;
    }

    char ch1 = fgetc(f1);
    char ch2 = fgetc(f2);

    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) {
            fclose(f1);
            fclose(f2);
            return 0;
        }
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
    }

    int result = (ch1 == EOF && ch2 == EOF);
    fclose(f1);
    fclose(f2);
    return result;
}
