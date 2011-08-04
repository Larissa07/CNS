#include <16f876a.h>
#use delay(clock=16000000)
#include <lcd_modificado.c>
#include <funcoes.c>
#include <teclado.c>
#include <verifica.c>


struct user 
{
   char id;
   int16 senha;
   int1 block;
   int1 logado;
} usuario;


void main()
{
   inicializa_lcd();
   port_b_pullups(true);
   lcd_inst(0x80);
   printf(lcd_Dado,"   gbfrtd      ");
   verifica();
   while(1)
   {

   }
}
