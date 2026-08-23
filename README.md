# findfigures
This is short program on C++, related to task provided from LucidLink company.
Code in this program is based on populare approaches that can be found on sites like tutorialspoint.com and no AI tools are used.
Source code can be found also at GitHub: https://github.com/denimlm/findfigures/blob/main/README.md

### Task for resolution
## Here is the problem:
```
● Having a matrix of n by m elements. Each of them can be marked or not. In the
 example shown this is expressed by white (not marked) and red (marked) colors. The
 numbers inside are just for clearance, and will not be given as an input condition.
```

```
The goal is to find the number of all individual figures, by one figure we mean all
colored elements (squares in the matrix) that touch each other by one of their sides. If
two cells touch only a vertex (diagonally) and not a common side, they are not
considered one figure.

/*
 * +---+---+---+---+---+
 * | 1 |   |   |   |   |
 * +---+---+---+---+---+
 * | 1 |   | 2 | 2 |   |
 * +---+---+---+---+---+
 * |   | 2 |   | 2 |   |
 * +---+---+---+---+---+
 * |   | 2 | 2 | 2 |   |
 * +---+---+---+---+---+
 * |   |   |   |   | 3 |
 * +---+---+---+---+---+
 */

For example, for the matrix shown above, the program must give us a "3 figures" solution. The
figures themselves are marked with numbers in each square, but only for clarity. It is not
necessary for the program to mark the affiliation of the fields as in this case if this will slow down
the execution of the algorithm.
Requirements for the provided solution:
● Used programming language - C ++.
● It is important that the code is written professionally as a commercial software meeting
all quality requirements as such. It would be good to consider a scalable solution that
would work with large matrices of millions of elements.
● It is of no use to anyone if the algorithm is taken from the Internet, but on the other hand,
it is not forbidden to seek knowledge in the problem area if you think it is necessary.

The task does not aim to take too much of your time, the goal is to see how you write production
ready code. There is no need (still not forbidden) to further complicate the solution, such as the
use of external databases, multi-threaded execution, etc.
```
### Assumptions
Current implementation consider following assumptions:
 1. Matrix will be defined only with unsigned integer values
 2. Patterns represent integer numbers in uint32 range (e.g. pattern = 1 is valid pattern)
 3. Only one kind of pattern at a time, from witch figures are created, is provided matrix
```

```
# Program run
 Program can be run after compilation
 1. Go to build/ folder and run cmake ..
 2. Run make
 3. Run program ./bin/example
```
```
## Unit Tests
Unit tests are provided according recomendations for quality requirements expected from the company
Unt tests in this examle are based on Catch2 framework - https://github.com/catchorg/catch2
A basic tests are prepared and provided with this implementation according edge cases and considered assumptions
Unit tests are located at ut/ folder and can be run after compilation:
1. Go to ut/
2. Do cmake .
3. Run make
4. Run executable in ut_bin/ folder
    a) in console ./ut_bin/findfigures_tests
    b) or generate a report ./ut_bin/findfigures_tests -r console -s -o test_report.txt

```
```
