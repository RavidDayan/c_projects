#ifndef PRINT_H
#define PRINT_H

#define MAX_DECIMAL_PRINT 2       /*const for how many digits to print right to  the . of a float number*/
void startMessage();              /*prints a start message for the user*/
void enterPrompt();               /*prints a message for the user to indicate to insert a prompt*/
void printMatrix(mat matrix);     /*iterate over all numbers in matrix and print with space to account for biggest number in matrix,
                                    deciamls and extra signs*/
int maxNumHeadLength(mat matrix); /*iterates over matrix  and finds the length of the lonest non decimal digits of the lopngest number*/
void legalStop();                 /*prints that the program stopped correctly with a stop command*/
void ilegalStop();                /*prints that the program stopped incorrectly without a stop command*/

#endif