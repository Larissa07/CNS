#include <16f876a.h>
#use delay(clock=16000000)
#include <teclado.c>
#include <lcd_modificado.c>
#include <funcoes.c>

char i;
int1 bloqueio=0;//indica se a maquina ja tem um bloqueio pendente (0>sim   1>nao)

void main()
{
   inicializa_lcd();
   port_b_pullups(true);
   while(1)
   {
   if(!bloqueio)func_normal();  //se bloqueio for==1 
   if(bloqueio)func_bloqueado();//se bloqueio for==0
   }
}
