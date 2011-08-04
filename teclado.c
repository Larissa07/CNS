#define baixo    PIN_B4
#define direita  PIN_B5
#define esquerda PIN_B2
#define cima     PIN_B3

void teclado()
{
   char tecla=0;
   if(!input(cima))tecla=1;
   if(!input(esquerda))tecla=2;
   if(!input(direita))tecla=3;
   if(!input(baixo))tecla=4;
}
