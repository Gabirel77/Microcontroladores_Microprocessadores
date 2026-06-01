#include <main.h>


void main()
{
   output_low(RB0);
   output_low(RB1);
   output_low(RB2);
   output_low(RB3);
   while(TRUE)
   {
      if(input(RA1)==0)
      {
         if(input(RB3)==0)
         output_high(RB0);
         else if(input(RB3)==1)
         output_low(RB0);        
      }
      if(input(RA2)==0)
      {
         if(input(RB0)==1)
         output_high(RB1);
         else if(input(RB0)==0)
         output_low(RB1);        
      }
      if(input(RA3)==0)
      {
         if(input(RB1)==1)
         output_high(RB2);
         else if(input(RB1)==0)
         output_low(RB2);        
      }
      if(input(RA4)==0)
      {
         if(input(RB2)==1)
         output_high(RB3);
         else if(input(RB2)==0)
         output_low(RB3);        
      }
      
   }

}
