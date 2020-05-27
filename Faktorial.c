#include <stdio.h>
int main()
{
    faktorial(5);    
    return 0;
}

int faktorial(int input){
	int i;
    unsigned long long factorial = 1;

    // show error if the user enters a negative integer
    if (input < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=input; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
        printf("Factorial of %d = %llu", input, factorial);
    }

    return 0;
}
