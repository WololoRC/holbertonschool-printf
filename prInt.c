#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * prInt - prints an integer or a char's ascii value.
 *
 * @aValue: Number to print.
 *
 * Return: 0
 */
int prInt(va_list aValue)
{
	long int num = va_arg(aValue, int);
	int *p = NULL;
	int mod, i, charFlg, lenght, mnsFlg;

	mod = i = charFlg = lenght = mnsFlg = 0;

	if (num < 0) /** if num is negative, turn to possitive 4 stability*/
	{
		num /= -1;
		mnsFlg = 1;
	}
	charFlg = checkForChar(num); /** flag set if num = char*/
	lenght = getSize(num); /** lenght of num is used to assign last index*/
	i = (lenght - 1); /**set the last index of p minus void char */

	p = malloc(lenght * sizeof(int));
	if (!p)
		return (-1);
	if (num == 0) /** if num = 0 manually set the val of p to ASCII 0*/
		p[0] = 48;
	while (num > 0 && charFlg == 0)
	{
		mod = num % 10; /** get last int of n */
		p[i] = (mod + 48); /**set p last index to ASCII val of int num*/
		i--;
		num /= 10; /** Remove last int from num */
	}
	if (mnsFlg)
	{/** if flag, prints - and increases lenght, as lenght = chars printed*/
		_putchart('-');
		lenght++;
	}
	if (charFlg) /** if num is char, calls char print function */
		prCharacter(num);
	else /** print normal integer, if mnsflg, lenght to print substracts 1*/
		prInteger(p, lenght, mnsFlg);
	free(p);
	return (lenght);
}

/**
 * prCharacter - prints a character's ASCII value to stdout
 *
 * @num: the character to print
 */
void prCharacter(char num)
{
	_putchart((num / 10) + 48);
	_putchart((num % 10) + 48);
}

/**
 * prInteger - prints an array of numbers to stdout
 *
 * @num: array of numbers
 * @lenght: lenght of the array
 * @mnsFlg: Whether num is negative or possitive
 */
void prInteger(int *num, int lenght, int mnsFlg)
{
	int i = 0;

	if (mnsFlg)
		lenght -= 1;
	while (i < lenght)
	{
		_putchart(num[i]);
		i++;
	}
}

/**
 * getSize - Gets the lenght of a given integer
 *
 * @num: integer to find lenght of
 *
 * Return: Int
 */
int getSize(long int num)
{
	int i = 0;

	if (num == 0)
		i = 1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

/**
 * checkForChar - Checks if the given value is actually a char
 *
 * @num: integer to check for chars
 *
 * Return: 0 if false, 1 if true
 */
int checkForChar(int num)
{
	int tester = 'A';

	/**
	 * This is here to avoid bugs, characters of value 100 to 199 seem
	 * to bypass this number catcher function, so any value greater than
	 * 90 ends up returning false.
	 * Despite this, to ensure nothing slips pass this checker, we still do
	 * check to see if the passed argument is a char of greater than 90
	 * value.
	 */
	if (num > 90)
		return (0);

	while (tester <= 'Z')
	{
		if (num == tester)
			return (1);
		tester++;
	}
	tester = 'a';
	while (tester <= 'z')
	{
		if (num == tester)
			return (1);
		tester++;
	}
	return (0);
}
