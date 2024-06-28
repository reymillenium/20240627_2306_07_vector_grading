# COP 1334 Assignment - Introduction to C++

## Chapter 7

## Title: Vector Grading

### Exercise Description:

Create a program that gets grades for a student using  vector<int>vGrades

Input the grades in a function called getGrades which returns a vector

getGrades keeps getting grades until a sentinel of either 999 or -999 is input.

Pass the grades to a function called getLetterGrade(vector<int>) that uses an if else if statement to get the letter grades as follows

90 and above A  
80 and above B  
70 and above C  
60 and above D  
0 and above F  
else error message

getLetterGrade returns the letter grade of an individual grade

use a for loop to for each grade to get the letter grade  
Put the letter grade into a vector<char>vLetterGrades

sort the function using a vector sort. Remember to include <algorithm>

call a function called sortVector passing the unsorted vector into the function. Return the sorted vector

Function prototype vector<int> sortGrades(vector<int>);

Write the following functions  
getHighestGrade(vector<int>); returns an int  
getLowestGrade(vector<int>); returns an int  
calcAverage(vector<int>); returns a double

calculate the final grade for the student using the average

Make sure to comment on top, comment each variable, and comment the purpose of each function.

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

  Type the grade or cancel with wither -999 or 999 (0 - 100): 99
  Type the grade or cancel with wither -999 or 999 (0 - 100): 100
  Type the grade or cancel with wither -999 or 999 (0 - 100): 98
  Type the grade or cancel with wither -999 or 999 (0 - 100): 89
  Type the grade or cancel with wither -999 or 999 (0 - 100): 87
  Type the grade or cancel with wither -999 or 999 (0 - 100): 67
  Type the grade or cancel with wither -999 or 999 (0 - 100): 99
  Type the grade or cancel with wither -999 or 999 (0 - 100): 68
  Type the grade or cancel with wither -999 or 999 (0 - 100): 99
  Type the grade or cancel with wither -999 or 999 (0 - 100): 100
  Type the grade or cancel with wither -999 or 999 (0 - 100): 73
  Type the grade or cancel with wither -999 or 999 (0 - 100): 55
  Type the grade or cancel with wither -999 or 999 (0 - 100): 123
  Invalid input. Please try again.
  Type the grade or cancel with wither -999 or 999 (0 - 100): 100
  Type the grade or cancel with wither -999 or 999 (0 - 100): -999

  These are your grades: 

  ------------------------
  | Grade | Letter Grade |
  ------------------------
  |   99  |       A      |
  ------------------------
  |  100  |       A      |
  ------------------------
  |   98  |       A      |
  ------------------------
  |   89  |       B      |
  ------------------------
  |   87  |       B      |
  ------------------------
  |   67  |       D      |
  ------------------------
  |   99  |       A      |
  ------------------------
  |   68  |       D      |
  ------------------------
  |   99  |       A      |
  ------------------------
  |  100  |       A      |
  ------------------------
  |   73  |       C      |
  ------------------------
  |   55  |       F      |
  ------------------------
  |  100  |       A      |
  ------------------------

  The highest grade is 100 (A)
  The lowest grade is 55 (F)
  The average grade (final grade) is 87.23
  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


