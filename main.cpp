/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 *   Name: 07-Arrays-intro                                             *
 *                                                                     *
 *   Purpose:                                                          *
 *   Receives 10 integers provided by the user from the console,       *
 *   and stores them in an array. And then based on them, it           *
 *   calculates the sum, the average and the largest element.          *
 *                                                                     *
 *   More Details:                                                     *
 *   https://github.com/reymillenium/20240621_0127_arrays_intro        *
 *                                                                     *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <limits> // For SHRT_MAX, SHRT_MIN, etc
#include <iomanip> // for setprecision, setw, fixed
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream (used in humanizeInteger, humanizeDouble, etc)
#include <vector> // to use vectors
#include <fstream> // For ifstream, ofstrea, fstream
#include <numeric> // For accumulate, transform_reduce, (in the vectors)
#include <algorithm> // For max_element, min_element, find, count, transform (to use in vectors), or for max()

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::setw;
using std::string;
using std::to_string;
using std::stringstream;
using std::accumulate;
using std::vector;
using std::find;
using std::count;
using std::for_each;
using std::partial_sort_copy;

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &);

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &, int);

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &);

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &, int);

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &) -> T;

// Receives and validates an integer number from the console
int getInteger(const string &, int, int, bool = false, const string & = "Invalid input. Please try again.", const vector<int> & = {});

// Receives and validates a double number from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.");

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &);

// Gets a string with or without spaces, from the terminal
string getString();

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(long long int);

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(long double, int = 2);

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(unsigned long int, bool = true, const string & = "$");

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(long double, int = 2, bool = true, const string & = "$");

// Rounds up a given double number, with a given amount of decimal places
double roundUp(double, int);

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(unsigned long long int);

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

// Determines is a given int number is prime or not
bool isPrime(unsigned long long int);

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegersInArray(const int [], int);

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegersInArray(const int [], int);

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&)[N]);

// Calculates the sum of all the elements inside an array of doubles
double simpleSumOfDoublesInArray(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
double neatSumOfDoublesInArray(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&)[N]);

template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&)[N][M]);

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegersInArray(const int [], int);

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegersInArray(const int [], int);

// Calculates the average among all the numbers inside an array of integers
template<int N>
int templateAverageAmongIntegersInArray(int (&)[N]);

// Calculates the average among all the numbers inside an array of doubles
double simpleAverageAmongDoublesInArray(const double [], int);

// Calculates the average among all the numbers inside an array of doubles
double neatAverageAmongDoublesInArray(const double [], int);

template<int N>
double templateAverageAmongDoublesInArray(double (&)[N]);

template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&)[N][M]);

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int [], int);

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int [], int);

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double [], int);

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double [], int);

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&)[N][M]);

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&)[N][M]);

// Determines if the given value is lower than the also given minimum value
bool isInvalid(long double value, double);

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(long double, double);

// CUSTOM FUNCTIONS

template<int N>
void loadRainfalls(const vector<string> &, double (&)[N]);

template<int N>
void loadRainfallsPlus(const vector<string> &, double (&)[N]);

// template<size_t a, size_t b>
template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &, double (&)[N][M]);

template<int N, int M>
void loadMonkeysFoodArraySlim(const vector<string> &, double (&)[N][M]);

string getLeastRainfallMonth(const vector<string> &, double [], int);

string getMostRainfallMonth(const vector<string> &, double [], int);

void displayResults(double, double, double);

// class MonthlyRainLog {
// public:
//     string monthName;
//     double rainAmount;
//
//     // dummy constructor
//     MonthlyRainLog() {
//     }
//
//     // Parameterized constructor
//     MonthlyRainLog(const string &aMonthName, const double &aRainAmount) {
//         monthName = aMonthName;
//         rainAmount = aRainAmount;
//     }
// };

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

// Main Function
int main() {
    constexpr int GRADE_MIN = 0; // THe minimum possible grade
    constexpr int GRADE_MAX = 100; // THe maximum possible grade
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

// Gets the grades from the user, typing on the console
vector<int> getGrades(const int minValue, const int maxValue, const vector<int> &sentinelValues) {
    vector<int> grades; // The vector to include all the given grades, before returning it
    bool numberIsNotSentinel; // If the typed number is not among the given sentinel values (breaking values)

    do {
        int grade = getInteger("Type the grade", minValue, maxValue, true, "Invalid input. Please try again.", sentinelValues);
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
    vector<int> sortedGrades(grades.size());
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
    const size_t length = grades.size();

    cout << endl;
    cout << "These are your grades: " << endl;
    cout << endl;
    cout << "------------------------" << endl;
    cout << "| Grade | Letter Grade |" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < length; i++) {
        cout << "|  " << setw(3) << grades[i] << "  |       " << setw(1) << letterGrades[i] << "      |" << endl;
        cout << "------------------------" << endl;
    }

    cout << endl;
    cout << "The highest grade is " << highestGrade << " (" << getLetterGrade(highestGrade) << ")" << endl;
    cout << "The lowest grade is " << lowestGrade << " (" << getLetterGrade(lowestGrade) << ")" << endl;
    cout << "The average grade is " << averageGrade << endl;
}

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &item) {
    cout << item;
}

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        print(item);
    }
}

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &item) {
    cout << item << endl;
}

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        printl(item);
    }
}

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &message) -> T {
    cout << message;
    T value;
    cin >> value;
    cin.ignore();
    return value;
}

// Receives and validates an integer number from the console
int getInteger(const string &message, const int minValue, const int maxValue, const bool showRange, const string &errorMessage, const vector<int> &sentinelValues) {
    int number = 0; // Number typed by the user
    bool keepAsking; // If we must keep asking for a value to the user

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        cin >> number;
        cin.ignore();

        const bool invalidInput = number < minValue || maxValue < number; // If the input is valid, based only in minimum & maximum possible values
        // If the typed number is not among the given sentinel values (breaking values)
        const bool numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), number) == 0;
        keepAsking = invalidInput && numberIsNotSentinel;

        if (keepAsking) cout << errorMessage << endl;
    } while (keepAsking);

    return number;
}

// Receives and validates a double number from the console
double getDouble(const string &message, const double minValue, const double maxValue, const bool showRange, const string &errorMessage) {
    double number = 0; // Number typed by the user
    bool invalidInput; // If the input is valid

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        cin >> number;
        cin.ignore();

        invalidInput = number < minValue || maxValue < number;
        if (invalidInput) cout << errorMessage << endl;
    } while (invalidInput);

    return number;
}

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &message) {
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

// Gets a string with or without spaces, from the terminal
string getString() {
    string value;
    getline(cin, value);
    return value;
}

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(const long long int integerValue) {
    const bool isNegative = integerValue < 0;
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > (isNegative ? 1 : 0); j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    const bool hasNegativeDecimals = decimals < 0;

    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34, -0.34 (the zero, and possibly also a negative sign, must be removed next)
    return humanizeInteger(integerValue) + decimalsAsString.substr(hasNegativeDecimals ? 2 : 1, precision + 1);
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(const unsigned long int integerValue, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedInteger(integerValue) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(const long double doubleValue, const int precision, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedDouble(doubleValue, precision) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Rounds up a given double number, with a given amount of decimal places
double roundUp(const double value, const int decimalPlaces) {
    const double multiplier = pow(10.0, decimalPlaces);
    return ceil(value * multiplier) / multiplier;
}

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(const unsigned long long int number) {
    if (number != 0)
        return number + recursiveSum(number - 1);
    return 0;
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return to_string(number) + additive;
}

// Determines is a given int number is prime or not
bool isPrime(const unsigned long long int value) {
    if (value <= 1)
        return false;
    for (unsigned long long int i = 2; i <= value / 2; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegersInArray(const int integersArray[], const int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += integersArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegersInArray(const int integersArray[], const int length) {
    return accumulate(integersArray, integersArray + length, 0);
}

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&integersArray)[N]) {
    int sum = 0;
    for (auto number: integersArray) {
        sum += number;
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of doubles
double simpleSumOfDoublesInArray(const double doublesArray[], const int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += doublesArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of doubles
double neatSumOfDoublesInArray(const double doublesArray[], const int length) {
    return accumulate(doublesArray, doublesArray + length, 0.0);
}

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&doublesArray)[N]) {
    double sum = 0.0;
    for (auto number: doublesArray) {
        sum += number;
    }
    return sum;
}

// Calculates the sum of all the elements inside a two-dimensional array of doubles
template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    double sum = 0.0;

    for (auto &row: twoDimensionsDoublesArray) {
        for (auto &number: row) {
            sum += number;
        }
    }

    return sum;
}

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegersInArray(const int array[], const int length) {
    return simpleSumOfIntegersInArray(array, length) / static_cast<double>(length);
}

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegersInArray(const int array[], const int length) {
    return neatSumOfIntegersInArray(array, length) / static_cast<double>(length);
}

// Calculates the average among all the numbers inside an array of integers
template<int N>
int templateAverageAmongIntegersInArray(int (&integersArray)[N]) {
    const int length = sizeof(integersArray) / sizeof(integersArray[0]);
    return sumOfIntegersWithRangeOverReference(integersArray) / length;
}

// Calculates the average among all the numbers inside an array of doubles
double simpleAverageAmongDoublesInArray(const double array[], const int length) {
    return simpleSumOfDoublesInArray(array, length) / length;
}

// Calculates the average among all the numbers inside an array of doubles
double neatAverageAmongDoublesInArray(const double array[], const int length) {
    return neatSumOfDoublesInArray(array, length) / length;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N>
double templateAverageAmongDoublesInArray(double (&doublesArray)[N]) {
    const int length = sizeof(doublesArray) / sizeof(doublesArray[0]);
    return sumOfDoublesWithRangeOverReference(doublesArray) / length;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&doublesTwoDimensionalArray)[N][M]) {
    const int rows = sizeof(doublesTwoDimensionalArray) / sizeof(doublesTwoDimensionalArray[0]);
    const int columns = sizeof(doublesTwoDimensionalArray[0]) / sizeof(doublesTwoDimensionalArray[0][0]);

    return templateSumOfDoublesInTwoDimensionsArray(doublesTwoDimensionalArray) / (rows * columns);
}

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int integersArray[], const int length) {
    int highestInteger = integersArray[0];
    if (length == 1) return highestInteger;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] > highestInteger)
            highestInteger = integersArray[i];
    }

    return highestInteger;
}

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int integersArray[], const int length) {
    int lower = integersArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] < lower)
            lower = integersArray[i];
    }

    return lower;
}

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double doublesArray[], const int length) {
    double lower = doublesArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] < lower)
            lower = doublesArray[i];
    }

    return lower;
}

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double doublesArray[], const int length) {
    double higher = doublesArray[0];
    if (length == 1) return higher;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] > higher)
            higher = doublesArray[i];
    }

    return higher;
}

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double lower = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number < lower)
                lower = number;
        }
    }

    return lower;
}

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double higher = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number > higher)
                higher = number;
        }
    }

    return higher;
}

// Determines if the given value is lower than the also given minimum value
bool isInvalid(const long double value, const double minValue) {
    return value < minValue;
}

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(const long double value, const double minValue) {
    if (isInvalid(value, minValue))
        cout << "You must type a number greater or equal than " << minValue << ". Try again!" << endl;
}


// CUSTOM FUNCTIONS


template<int N>
void loadRainfalls(const vector<string> &months, double (&rainfalls)[N]) {
    const int arraySize = sizeof(rainfalls) / sizeof(rainfalls[0]);
    for (int i = 0; i < arraySize; i++) {
        rainfalls[i] = getDouble("Enter rainfall for " + months[i], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
    }
}

template<int N>
void loadRainfallsPlus(const vector<string> &months, double (&rainfalls)[N]) {
    int counter {0};
    for (double &rainfall: rainfalls) {
        rainfall = getDouble("Enter rainfall for " + months[counter], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
        counter++;
    }
}

// template<size_t a, size_t b>
template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &weekDays, double (&monkeysFood)[N][M]) {
    const int rows = sizeof(monkeysFood) / sizeof(monkeysFood[0]);
    const int columns = sizeof(monkeysFood[0]) / sizeof(monkeysFood[0][0]);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            monkeysFood[row][col] = getDouble("Please type how many pounds of food the " + ordinalFromNumber(row + 1) + " monkey will eat on " + weekDays[col], 0, INT_MAX);
        }
    }
}

template<int N, int M>
void loadMonkeysFoodArraySlim(const vector<string> &weekDays, double (&monkeysFood)[N][M]) {
    int rowIndex = 0;

    for (auto &row: monkeysFood) {
        int cellIndex = 0;

        for (auto &cell: row) {
            cell = getDouble("Please type how many pounds of food the " + ordinalFromNumber(rowIndex + 1) + " monkey will eat on " + weekDays[cellIndex], 0, INT_MAX);
            cellIndex++;
        }
        rowIndex++;
    }
}

string getLeastRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleLowerDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string leastRainfallMonth = months[targetIndex];
    return leastRainfallMonth;
}

string getMostRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleHigherDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string mostRainfallMonth = months[targetIndex];
    return mostRainfallMonth;
}

void displayResults(const double average, const double lowerAmount, const double higherAmount) {
    cout << endl;
    cout << "The average amount of food eaten per day by the whole family of monkeys is " << humanizeDouble(average) << " lbs." << endl;
    cout << "The least amount of food eaten during the week by any one monkey is " << humanizeDouble(lowerAmount) << " lbs." << endl;
    cout << "The greatest amount of food eaten during the week by any one monkey is " << humanizeDouble(higherAmount) << " lbs." << endl;
}
