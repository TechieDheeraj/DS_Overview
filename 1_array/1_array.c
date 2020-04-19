#include<stdio.h>

/*
   NOTE:

   Q1. How Compiler calculates for e.g a[2] ?  Because compiler does not know address of array(a) at compile time Right ?

   A1. Compiler forms a formula ->

       a[i] -> a + (i * (sizeof(int)))

       Array Name(a) represents the base address of array and also indices starts from 0.  

       a[2] -> a + (2 * 4)   ---> for 64 bit arch
  
  NOTE:  Why Array index starts from 0 why not 1 ?

         If it starts from 1:
         
         e.g  a is at address 200, a[2] will be at 208
         For the evaluation: a[2]

           a[i] -> a + (i) * sizeof(int)  -> this gives us 3rd location not 2nd.

         Compiler have to do extra airthmatic operation for each location access which can be avoided if we starts array from 0:

         a[i] ->  a + (i-1) * sizeof(int) -> This gives the correct ith location but costs compiler (i-1) extra operation
*/
       
int main() {

   int a[] = {1,2,3,4,5};

   printf("a[2]: %d\n", a[2]);
   printf("2[a]: %d\n", 2[a]); // Can Also access like this

   return 0;
}
