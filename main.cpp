/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 *   Name: Reinier Garcia Ramos                                        *
 *                                                                     *
 *   Program Title/Name: 07-Vector Grading                             *
 *                                                                     *
 *   Purpose:                                                          *
 *   Receives an undetermined amount of grades provided by the user    *
 *   from the console, and stores them in a vector. The input stops    *
 *   when the user enters either 999 or -999. And then based on those  *
 *   grades, it calculates the equivalent grade letters, as well as    *
 *   the lowest, the highest and the average grade.                    *
 *                                                                     *
 *   More Details:                                                     *
 *   https://github.com/reymillenium/20240627_2306_07_vector_grading   *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <iomanip>
#include<random>
#include <vector>
#include <numeric>
#include <algorithm>
#include <regex>

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::setw;
using std::string;
using std::to_string;
using std::accumulate;
using std::vector;
using std::count;
using std::for_each;
using std::partial_sort_copy;
using std::regex;
using std::regex_match;


// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &);

// Receives and validates an integer number from the console
int getInteger(const string &, int, int, bool = false, const string & = "Invalid input. Please try again.", const vector<int> & = {});


// CUSTOM FUNCTIONS


// Gets the grades from the user, typing on the console
vector<int> getGrades(int, int, const vector<int> &);

// Gets a vector of letter grades based on a given vector of grades
vector<char> getLetterGrades(vector<int>);

// Gets a letter grade based on a given grade
char getLetterGrade(int);

// Sorts the grades in ascending order (from lowest to highest)
vector<int> sortGrades(const vector<int> &);

// Returns the highest grade from a previouslly ascending sorted vector of grades (the last one)
int getHighestGrade(const vector<int> &);

// Returns the lowest grade from a previouslly ascending sorted vector of grades (the first one)
int getLowestGrade(const vector<int> &);

// Calculates the average grade among a given vector of grades
double calcAverage(vector<int>);

// Displays the results including the grades, the letter grades, as well as the lowest, highests and the average grade
void displayGradeResults(const vector<int> &, const vector<char> &, int, int, double);

// Prints on the console a table with the grades and its equivalent letter grades
void printGradesTable(const vector<int> &, const vector<char> &);

// Main Function
int main() {
    constexpr int GRADE_MIN = 0; // The minimum possible grade
    constexpr int GRADE_MAX = 100; // The maximum possible grade
    const vector<int> sentinelValues {-999, 999}; // Values to cancel the input

    // Gets all the grades from the user, typing on the console
    const vector<int> vGrades = getGrades(GRADE_MIN, GRADE_MAX, sentinelValues);
    // Obtains the letter grades based on the given grades
    const vector<char> vLetterGrades = getLetterGrades(vGrades);
    const vector<int> vSortedGrades = sortGrades(vGrades); // Sorts the grades

    // Gets the highest, the lowest and the average grade
    const int highestGrade = getHighestGrade(vSortedGrades);
    const int lowestGrade = getLowestGrade(vSortedGrades);
    const double averageGrade = calcAverage(vGrades);

    // Displays the results on the console
    displayGradeResults(vGrades, vLetterGrades, highestGrade, lowestGrade, averageGrade);

    return 0;
}

// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input) {
    const regex pattern("^[+-]?[0-9]+$");
    return regex_match(input, pattern);
}

// Receives and validates an integer number from the console
int getInteger(const string &message, const int minValue, const int maxValue, const bool showRange, const string &errorMessage, const vector<int> &sentinelValues) {
    string numberAsString; // Value typed by the user, received as a string, that can be an integer or not
    int number = 0; // Integer convertion (if possible) of the value typed by the user
    bool keepAsking = true; // If we must keep asking for a value to the user, until receiving an integer

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        getline(cin, numberAsString);

        if (const bool isIntegerNumber = isInteger(numberAsString); !isIntegerNumber) {
            cout << "  That's not an integer number. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even an integer
        }

        number = stoi(numberAsString); // When we reach this point, that means we have a proper integer
        const bool invalidInput = number < minValue || maxValue < number; // If the input is valid, based only in minimum & maximum possible values
        // If the typed number is not among the given sentinel values (breaking values)
        const bool numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), number) == 0;
        keepAsking = invalidInput && numberIsNotSentinel;
        if (keepAsking) cout << errorMessage << endl;
    } while (keepAsking);

    return number;
}


// CUSTOM FUNCTIONS


// Gets the grades from the user, typing on the console
vector<int> getGrades(const int minValue, const int maxValue, const vector<int> &sentinelValues) {
    vector<int> grades; // The vector to include all the given grades, before returning it
    bool numberIsNotSentinel; // If the typed number is not among the given sentinel values (breaking values)

    do {
        int grade = getInteger("  Type the grade or cancel with wither -999 or 999", minValue, maxValue, true, "  Invalid input. Please try again.", sentinelValues);
        numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), grade) == 0;
        if (numberIsNotSentinel) grades.push_back(grade);
    } while (numberIsNotSentinel);

    return grades;
}

// Gets a vector of letter grades based on a given vector of grades
vector<char> getLetterGrades(vector<int> grades) {
    vector<char> letterGrades; // The letter grades

    for_each(grades.begin(), grades.end(), [&](const int grade) {
        letterGrades.push_back(getLetterGrade(grade));
    });

    return letterGrades;
}

// Gets a letter grade based on a given grade
char getLetterGrade(const int grade) {
    char charGradeLetter = 'F';
    if (90 <= grade && grade <= 100) charGradeLetter = 'A';
    if (80 <= grade && grade < 90) charGradeLetter = 'B';
    if (70 <= grade && grade < 80) charGradeLetter = 'C';
    if (60 <= grade && grade < 70) charGradeLetter = 'D';
    return charGradeLetter;
}

// Sorts the grades in ascending order (from lowest to highest)
vector<int> sortGrades(const vector<int> &grades) {
    vector<int> sortedGrades(grades.size()); // Stores the sorted grades. Initialized with the same length of the given grades
    // Sorts the elements in the range [first, last) of the given grades vector in ascending order, storing a copy of the result in the range of the sorted grades vector
    partial_sort_copy(grades.begin(), grades.end(), sortedGrades.begin(), sortedGrades.end());
    return sortedGrades;
}

// Returns the highest grade from a previouslly ascending sorted vector of grades (the last one)
int getHighestGrade(const vector<int> &sortedGrades) {
    return sortedGrades.back();
}

// Returns the lowest grade from a previouslly ascending sorted vector of grades (the first one)
int getLowestGrade(const vector<int> &sortedGrades) {
    return sortedGrades.front();
}

// Calculates the average grade among a given vector of grades
double calcAverage(vector<int> grades) {
    return accumulate(grades.begin(), grades.end(), 0) / static_cast<double>(grades.size());
}

// Displays the results including the grades, the letter grades, as well as the lowest, highests and the average grade
void displayGradeResults(const vector<int> &grades, const vector<char> &letterGrades, const int highestGrade, const int lowestGrade, const double averageGrade) {
    cout << endl;
    cout << "  These are your grades: " << endl;
    // Prints on the console the table with the grades & letter grades
    printGradesTable(grades, letterGrades);

    cout << endl;
    cout << "  The highest grade is " << highestGrade << " (" << getLetterGrade(highestGrade) << ")" << endl;
    cout << "  The lowest grade is " << lowestGrade << " (" << getLetterGrade(lowestGrade) << ")" << endl;
    cout << setprecision(2) << fixed << "  The average grade (final grade) is " << averageGrade << endl;
}

// Prints on the console a table with the grades and its equivalent letter grades
void printGradesTable(const vector<int> &grades, const vector<char> &letterGrades) {
    const size_t length = grades.size();

    cout << endl;
    cout << "  ------------------------" << endl;
    cout << "  | Grade | Letter Grade |" << endl;
    cout << "  ------------------------" << endl;
    for (int i = 0; i < length; i++) {
        cout << "  |  " << setw(3) << grades[i] << "  |       " << setw(1) << letterGrades[i] << "      |" << endl;
        cout << "  ------------------------" << endl;
    }
}
