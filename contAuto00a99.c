#include <contAuto00a99.h>

int8  unidade = 0;
int8  dezena = 0;
int1  sistema_rodando = 0;//0 parado 1 rodando
int1  sobedesce = 0; //0 crescente e 1 decrescente
int1  qualdig = 0; // 0 unidade 1 dezena

int1  fim_100ms = 0;
int8  contador_100ms = 100;
int1  fim_1ms = 0;
int8  contador_1ms = 1;
int8  codigo[10] = {254,56,221,125,59,119,247,60,255,127};

void progressivo();
void regressivo();
void atualiza_display();

#INT_TIMER0
void  TIMER0_isr(void) 
{
   contador_100ms--;
   if(contador_100ms==0)
   {
      contador_100ms = 100;
      fim_100ms = 1;
   }
   
   contador_1ms--;
   if(contador_1ms==0)
   {
      contador_1ms = 1;
      fim_1ms = 1;
   }
}

void main()
{
   setup_comparator(NC_NC_NC_NC);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8|RTCC_8_BIT);      //1,0 ms overflow


   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      atualiza_display();
      if(fim_100ms)
      {
         fim_100ms=0;
         if(input(RA1)==0 && sistema_rodando == 0)
         {
            unidade=0;
            dezena=0;
         }

         if(input(RA2)==0 && sistema_rodando == 0)
         {
            sobedesce = 0;
            sistema_rodando = 1;
         }
         
         if(input(RA3)==0 && sistema_rodando == 0)
         {
            sobedesce = 1;
            sistema_rodando = 1;
         }
         
         if(input(RA4)==0)
         {
            sistema_rodando=0; 
         }
         
         if(sobedesce==0 && sistema_rodando==1)
         {
            progressivo();
         }
         if(sobedesce==1 && sistema_rodando==1)
         {
            regressivo();
         }     
      }
   }
}

void progressivo()//estar atento ao rb4 1 para unidade e 0 para dezena
{
   unidade++;
   if(unidade>=10)
   {
      unidade=0;
      dezena++;
      if(dezena>=10)
      {
         dezena=0;
      }
   } 
}

void regressivo()
{
   if(unidade == 0) 
   {
      unidade = 9;
      if(dezena == 0)
      {
         dezena = 9;
      }
      else
      {
         dezena--;
      }
   }
   else
   {
      unidade--;
   }
}

void atualiza_display()
{
   if(fim_1ms)
      {
         fim_1ms=0;
         if(qualdig==0)
         {
            qualdig=1;
            output_b(codigo[dezena] & 0b11101111);
         }       
         else
         {
            qualdig=0;
            output_b(codigo[unidade]);  
         }
         
      }
}
