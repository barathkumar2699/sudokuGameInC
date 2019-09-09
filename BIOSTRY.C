#include <BIOS.H>
#include <stdio.h>
#include <stdlib.h>

void main()
{
 int key, shift;
 int lastshift;
 clrscr();
 do
 {

     while(bioskey(1)==0);
     key=bioskey(0);
     printf("%d\n",key);
 }while(key!=283);
}

