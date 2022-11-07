Printf

Description: 

void _printf(const char * const format, ...);

This functions emulates the standard printf, it's a variadic function. 
First recives a string argument specifyng format to print and then recives 
variadic arguments, if there is no variadic arguments only prints the string.
If there is no variadic or any string arguments the compiler is not gonna work.

How it works?:

The function prints the arguments chat by char, starting on the string format argument
then if there is a format specifyer '%' the programs jumps to a specyfic function to print it
then come back and keep going. The way was it does is comparing the format char with a struct
char variable with formats all inside of an a structure array called frmt (format), if it matchs 
a function pointer call the sub-function what we need. 

All the function only prints and returns nothing.

![Screenshot from 2022-11-07 17-49-16](https://user-images.githubusercontent.com/110310135/200412506-6888776c-48ad-4e0d-bb0f-8a28ed2f1203.png)
