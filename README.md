# _printf

### Prototype:

`int _printf(const char * const format, ...);`


### Return:
Integer containing lenght of printed string.

### Description:

This function attempts to replicate the functionality of the [standard library](https://man7.org/linux/man-pages/man3/stdio.3.html "man stdio")'s [printf function](https://man7.org/linux/man-pages/man3/printf.3.html "man printf").
_At it's current rendition, the program is *incapable* of reproducing every single functionality of the standard printf._

**Following is a list of valid parameters for this version:**

1. - %d - Prints an integer to stdout. If it receives a character, then it will print said character's ascii value.
2. - %i - Behaves exactly like %d in this instance.
3. - %c - Prints a character to stdout.
4. - %s - Prints a string of characters to stdout.

Besides said parameters, the function is capable of printing plain text, chars, strings and integers.

---

### Technical description and diagrams:
-
    ### _printf()
    The root function, it's purpose is to receive all of the variadic arguments as well as the string characters to be printed in order to call
    for the most suitable functions to handle the given types and arguments.

    As a first step, this function scans the given string for parameters whilst printing each and all characters contained within.
    If a modulo is found, the following character will be recognized by the program as an argument, said character will be sent to the
    identifier function in order to determine if the argument is valid, and, in case it is, which function to call.

    The structure will return a pointer to the function in charge of handling the given argument, said pointer will be used to invoke
    the function having the va_list item 'args' passed to it.

    _printf diagram:
    ![Screenshot from 2022-11-07 17-49-16](https://user-images.githubusercontent.com/110310135/200412506-6888776c-48ad-4e0d-bb0f-8a28ed2f1203.png)

---

   ### main.h
   Contains the typedef for the structure used by the identifier function, prototypes for each and all functions in charge of handling
   different types, as well as some required libraries.

---

   ### format_functions.c
   Contains the functions in charge of printing the following:

   1. - Strings
       `int s_string(va_list aValue)` Declares a char * to the current value held by aValue, as well as a counter.
       	     		      	       Whilst the pointer points to anything but NULL, a single character is printed
				       to stdout and the loop repeats until the string reaches NULL.				     
				       The counter is used to cycle through the values of the pointer, in an array-like fashion.
				       If the value held by aValue is NULL s_string printf "(null)" and returns 0.
   2. - Chars
       `int c_char(va_list aValue)`   Simply prints a char making use of va_arg(aValue, int) and returns 1 for lenght control purposes.   					

   In order to print any and all values in this section, format_functions.c also defines the _putchar function.
   The _putchar function simply makes use of the `write()` function to print 1 byte of data to stdout.

---

   ### prInt.c
   Contains all the functions required to print integers as well as the ascii value of characters passed to it.
   This function as well as all of its sub-functions make use of the _putchar defined in main.h to print to stdout.

   prInt contains the following functions:

   0. - `int prInt(long int);`
				The main function in charge of calling the other functions, as well as splitting
				the given integer (long int) into small chunks for printing. Detailed explaination at end of file.
   1. - `int checkForChar(int);`
				Checks if the given number is a character, also checks whether the number passed to it is actually a char
				or just a number of value greater than 99.
				It accomplishes this by comparing the value passed to it to every character from A to z after checking that
				num < 99.
				Returns 1 if num is a character, 0 if false.
   2. - `int getSize(long int);`
				Returns the lenght of the given number, I.E.: the number '100' returns a value of '3' because '100' contains
				3 integers. The value 1000 returns '4', 10000 returns 5, etc.
				This function accomplishes this by dividing the given number by 10 until the value is 0 and increasing a counter
				at each step of the divisions.
				If the given number is 0, the function returns a lenght of 1.
   3. - `void prInteger(int *, int);`
				Receives a pointer to an array of integers as well as the size of said array.
				This function defines a counter and a loop, the loop will keep going until the counter is greater than the lenght
				of the given array, to ensure all of the values are printed. It is done this way because the first value of the
				array of integers (*[0]) is always NULL, except for arrays containing a single '0'.
				The function will check if the number contained within the array is greater than 0, if it is, the number is printed.
				Because of the way numbers are stored in this array, the value is never truly 0, except when a single 0 is passed
				to the function, for this, we know that if *[i] = 0, we are dealing with an array containing nothing but a single
				'0', for such, the function prints *[0].
   4. - `void prCharacter(char);`
				In order to print the ASCII value of characters of value lesser than 99, part of the main prInt is skipped and
				instead it is handled by this function.
				The value sent to this function is taken as a char, the function divides this char by 10 and adds 48 to it in order
				to get the number of the first integer that composses this character, then it prints it.
				The second value is printed in a similar manner, except instead of dividing, it modulos it to get the second character.
				These operations are condensed into a single _putchar() call each.


A detailed look on prInt:

      int prInt(va_list)
      This function takes as a parameter a va_list and turns it into a long int and returns its lenght on success, -1 on failure.
      This function defines a pointer in which all the values of the original number (num) will be stored as an array of integers.
      	   This pointer makes use of malloc to allocate enough memory for the value to be stored.
      This function defines the flag mnsFlg.
      	   When this flag is on, the minus symbol is printed before the number, indicating it is a negative value.
      This function defines the charFlg.
      	   when this flag is on, the value of num will be sent to prCharacter for printing, instead of prInteger.
      This function defines the lenght variable.
      	   This variable will hold the output of the getSize() function, that is, the lenght of the given integer.
	   This value will be used to determine the size of malloc required to store the desired value as an array of ints in the pointer.
	   This value will be used to determine in which possition each character of num will be stored in the pointer, as they will be stored
	   	in reverse order.
      This function defines the i counter.
      	   This counter will hold the value of lenght, this value will be known as the last index in our array of integers.

      prInt workflow:

      1. -  prInt will check whether the given number is a negative value, to simplify operations, if the value is a negative number
      	    it will be converted to a possitive before any further checks are made. This conversion will set the mnsFlg to true.

      2. - prInt will call for the checkForChar function, passing the (possitive) integer as a parameter. The return of this function will be
      	   stored in the charFlg variable. 0 for false, 1 for true.

      3. - prInt will call for the getSize function, passing the (possitive) integer as a parameter. The return of this function will be stored
      	   in the lenght variable, this is the total lenght of the number passed to prInt.

      4. - `i` will be assigned the value of lenght.

      5. - *p will be malloc'd by the value of lenght * sizeof(long int), this will assign the memory we need for our operations.
      	   If malloc fails, the program will return -1 to signal an error.

      6. - if the number passed to the prInt function is equal to 0, the index 0 of the pointer *p will be assigned the value of 48, the ascii for 0.

      7. - while number is greater than 0 and if charFlg is equal to 0
      	  -
      	  1. mod will be assigned the value of num % 10, this will give us the last value contained within num
	   2. The index i of p will be assigned the value of mod. Mod will be converted to ascii by adding +48 to it.
	      Since i = lenght, p[i] is effectively the last index in the array i.
	   3. We subtract 1 from i, to move to the previous value in the array.
	   4. We divide our number by 10, to get rid of this last character
	   5. The loop repeats until num is equal to 0.

      8. - prInt will check if mnsFlg is true, if it is, '-' will be printed by calling the _putchar function before continuing.

      9. - prInt will check if charFlg is true, if it is, step 7 was skipped and the number is sent to prCharacter for printing.

      10. - If prCharacter is false, prInt calls for prInteger to print our value. The pointer *p as well as it's lenght are passed to
      	    prInteger for printing.

      11. The pointer *p is freed since it is no longer needed and the program returns 0, finishing the process.
