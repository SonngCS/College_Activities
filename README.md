Here I will post some of my solutions for activities and exams I take.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# First practical exam -algorithms- #

This piece of code is written in "Portugol" and takes an integer "n" (total population of a city) and another integer "m" (total of months with covid vaccination)
The objective of the program is to gather the data of the first and second doses of covid vaccine taken (m lines for first doses, each line representing one month, and m more lines for second doses). Then, as an answer we must receive two percentages based on the total population: one representing the people who took the first dose and another for the people who received the second. Afterward, the program must say which months had the most vaccinated people (one line for first dose and another for second).
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



# Group Activity -Algorithms and Computer programming- #

This program has the objective to read a cvs file which has data from brazil's measles vaccination on recent years. From this file, the piece of code has to give some informations and generate some outputs, depending on the user's choice.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



# Second Practical exam -Algorithm projects- #

This problem involves a imaginary telephone company which is trying to spend less when printing the clients' numbers. The logic applied to do that is by omitting repeating numbers (from the first digits of the second number of the list). Each telephone number may have c digits, with  0 < c <= 200; each list of numbers can have up to 100000 numbers (one in each row). A telephone number can start with a 0 but if the imput for the list's size is 0, the program should end.

Example:
The numbers 535456, 535488, 536566 e 835456 will be placed:


First number: 5 3 5 4 5 6

Second number:_ _ _ _ 8 8    

Third number: _ _ 6 5 6 6 

Last number:  8 3 5 4 5 6

Total digits omitted: 6

The program, as output, must give us the number of digits that can be omitted.

PS: This was one of my first attempts and the best solution for this problem differs from mine by using sorting algorithms (such as quick sort) to organize the numbers in the list, taking much less execution time as the result.
