#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * prInt - prints an integer
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
	if (num < 0)
	{
		num /= -1;
		mnsFlg = 1;
	}
	charFlg = checkForChar(num);
	lenght = getSize(num);
	i = (lenght - 1);

	p = malloc(i * sizeof(long int));
	if (!p)
		return (-1);

	if (num == 0)
		p[0] = 48;
	while (num > 0 && charFlg == 0)
	{
		mod = num % 10;
		p[i] = (mod + 48);
		i--;
		num /= 10;
	}

	if (mnsFlg)
	{
		_putchart('-');
		lenght++;
	}
	if (charFlg)
		prCharacter(num);
	else
		prInteger(p, lenght);
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
 */
void prInteger(int *num, int lenght)
{
	int i = 0;

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
