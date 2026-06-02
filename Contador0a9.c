#include <Contador0a9.h>
         
int1  ja_li1 = 0;
int1  ja_li2 = 0;
int8  unidade = 0;
int8  filtro1 = 100;
int8  filtro2 = 100;
int8  codigo[10] = {254,56,221,125,59,119,247,60,255,127};

void atualiza_display();

void main()
{
   while(TRUE)
   {  
      atualiza_display();
      
      if(input(RA2)==0)
      {     
         if(ja_li1 == 0)
         {  
            filtro1--;
            if(filtro1 == 0)
            {
               ja_li1 = 1;
               if(unidade>=9)
               {
                  unidade=0;
               }
               else
                  unidade++;          
            }
         }
      }
      else
      {
         ja_li1=0;
         filtro1=100;
      }
      
      if(input(RA3)==0)
      {     
         if(ja_li2 == 0)
         {  
            filtro2--;
            if(filtro2 == 0)
            {
               ja_li2 = 1;
               if(unidade<=0)
               {
                  unidade=9;
               }
               else
                  unidade--;          
            }
         }
      }
      else
      {
         ja_li2=0;
         filtro2=100;
      }

       
       if(input(RA1)==0)
       {
         unidade=0;
       }
   }
}

void atualiza_display()
{
   output_b(codigo[unidade]);
}

