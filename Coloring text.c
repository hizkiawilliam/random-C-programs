#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reset();
void green();
void red();
void yellow();
void blue();
void magenta();
void cyan();
void scrable();
void printd(char* x, int y);
void printc(char text[100], char color[10]);
int r = 0;

int main()
{
	system("COLOR");
	printd("Text is here right now \n",2);
	printc("Hello World\n","red");
	printc("Hello World\n","yellow");
	printc("Hello World\n","green");
	printc("Hello World\n","cyan");
	printc("Hello World\n","blue");
	printc("Hello World\n","magenta");
	return (0);
}

void printc(char text[100], char color[10]){
	if ((strcmp("RED",color)==0)||(strcmp("red",color)==0))
	{
		red();
		printf("%s",text);
		reset();	
	}
	else if ((strcmp("GREEN",color)==0)||(strcmp("green",color)==0))
	{
		green();
		printf("%s",text);
		reset();	
	}
	else if ((strcmp("BLUE",color)==0)||(strcmp("blue",color)==0))
	{
		blue();
		printf("%s",text);
		reset();	
	}
	else if ((strcmp("YELLOW",color)==0)||(strcmp("yellow",color)==0))
	{
		yellow();
		printf("%s",text);
		reset();	
	}
	else if ((strcmp("MAGENTA",color)==0)||(strcmp("magenta",color)==0))
	{
		magenta();
		printf("%s",text);
		reset();	
	}
	else if ((strcmp("CYAN",color)==0)||(strcmp("cyan",color)==0))
	{
		cyan();
		printf("%s",text);
		reset();	
	}
	else
	{
		reset();	
		printf("%s",text);
	}
	
}
void green(){
	printf("\033[0;32m");
}
void red(){
	printf("\033[0;31m");
}
void yellow(){
	printf("\033[0;33m");
}
void blue(){
	printf("\033[0;34m");
}
void magenta(){
	printf("\033[0;35m");
}
void cyan(){
	printf("\033[0;36m");
}
void reset(){
	printf("\033[0m");
}

void printd(char* x, int y)
{
	int i;
	for(i=0;i<strlen(x);i++)
	{
		if (i<strlen(x)-1){
			scrable();
		}
		printf("%c",x[i]);
		Sleep(y);
	}
}

void scrable()
{
	srand(getpid());
	int i, counter = 3;
	char scrab[56] = "^%$#@!sidufygt384756_+-)(*&hrznxbcv102jekwlqm{<}>|:?";
	char scrab2[56] = "402jekw>756_+-^%$#lqm{<}@!sidufybcvgt38)(*&hrznx1|:?";
	for(i=0;i<counter;i++)
	{
		printf("%c",scrab2[r]);
		r += 1;
		if (r>56){
			r=0;
		}
		Sleep(50);
		printf("\b");
	}
}
