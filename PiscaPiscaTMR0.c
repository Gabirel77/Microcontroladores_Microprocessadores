#include <PiscaPiscaTMR0.h>

int1  ja_li1 = 0;
int1  ja_li2 = 0;
int8  unidade = 0;
int8  filtro1 = 1;
int8  filtro2 = 1;
int1  sistema_rodando = 0;
int8  contador_pisca = 0;

int1  fim_25ms = 0;
int8  contador_25ms = 25;
int8  codigo[10] = {254,56,221,125,59,119,247,60,255,127};
int8  tempos_pisca[10] = {20, 16, 12, 10, 8, 6, 5, 4, 3, 2}; //trabalhar com meio periodo se for 1000, fazer o calculo pra 500 pois é 500 aceso e 500 apagado

void atualiza_display();

#INT_TIMER0
void  TIMER0_isr(void) 
{
   contador_25ms--;
   if(contador_25ms==0)
   {
      contador_25ms = 25;
      fim_25ms = 1;
   }
}

void main()
{
   setup_comparator(NC_NC_NC_NC);
   output_low(LAMPADA);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8|RTCC_8_bit);      //1,0 ms overflow
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      atualiza_display();
      if(fim_25ms)
      {
         fim_25ms=0;
         if(input(RA1)==0)
         {
            contador_pisca = 0;      // Zera o tempo
            output_high(LAMPADA);         
            sistema_rodando = 1;
         }

         if(input(RA2)==0)
         {
            output_low(LAMPADA);
            sistema_rodando = 0;
         }
         if(input(RA3)==0 && sistema_rodando == 0)
         {
            if(ja_li1==0)
            {
               filtro1--;
               if(filtro1==0)
               {
                  ja_li1=1;
                  if(unidade>=9)
                  unidade=0;
                  else
                  unidade++;
               }
            }
         }
         else
         {
         ja_li1=0;
         filtro1=1;
         }
         
         if(input(RA4)==0 && sistema_rodando == 0)
         {
            if(ja_li2==0)
            {
               filtro2--;
               if(filtro2==0)
               {
                  ja_li2=1;
                  if(unidade<=0)
                  unidade=9;
                  else
                  unidade--;
               }
            }
         }
         else
         {
         ja_li2=0;
         filtro2=1;
         }
         
         if(sistema_rodando == 1)
         {
            contador_pisca++;
            if(contador_pisca >= tempos_pisca[unidade])
            {
               contador_pisca=0;
               output_toggle(LAMPADA);
            }
         }
         
      }
   }
}


void atualiza_display()
{
   output_b(codigo[unidade]);
}

