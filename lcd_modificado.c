/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *                                                                     *
 *             Rotina Genérica de Manipulação de LCD 16x2              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


// Defina os pinos que estão ligados fisicamente

#define  RS    PIN_C0    // Pino de seleção de modo do display
#define  EN    PIN_A5    // Pino de habilitação do display
#define  D7    PIN_A0   // Pino de dados 7
#define  D6    PIN_A1    // Pino de dados 6
#define  D5    PIN_A2    // Pino de dados 5
#define  D4    PIN_A3    // Pino de dados 4

//prot�tipo das fun��es
void lcd_inst4(unsigned char dado);
void lcd_inst(unsigned char dado);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                      Rotina de Inicialização de LCD                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void inicializa_lcd(void)
{

   lcd_inst4(0b00000011);
   delay_ms(15);
   lcd_inst4(0b00000011);
   delay_ms(15);
   lcd_inst4(0b00000011);
   delay_ms(15);
   lcd_inst4(0b00000010);
   delay_ms(15);

   lcd_inst(0b00101000);
   delay_ms(15);
   lcd_inst(0b00001100);
   delay_ms(15);
   lcd_inst(0b00000110);
   delay_ms(15);
   lcd_inst(0b00000001);
   delay_ms(100);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                  Rotina de Envio de Comando para o LCD              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void lcd_inst4(unsigned char dado)
{

   output_low(RS);                          //Limpa o pino RS, modo comando
   delay_us(100);

   if (dado & 0b00001000) output_high(D7);         //Se o bit estiver em 1 liga a saída
   else                  output_low(D7);        //Caso contrário desliga a linha

   if (dado & 0b00000100) output_high(D6);         //Se o bit estiver em 1 liga a saída
   else                output_low(D6);         //Caso contrário desliga a linha

   if (dado & 0b00000010) output_high(D5);         //Se o bit estiver em 1 liga a saída
   else               output_low(D5);         //Caso contrário desliga a linha

   if (dado & 0b00000001) output_high(D4);        //Se o bit estiver em 1 liga a saída
   else                 output_low(D4);         //Caso contrário desliga a linha

   delay_us(100);

   output_high(EN);                                    //Gera pulso de enable
   delay_us(150);                                       //Aguarda 150 us
   output_low(EN);

   delay_ms(5);                                      //Faz a inicialização do display

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                  Rotina de Envio de Comando para o LCD              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void lcd_inst(unsigned char dado)
{
   output_low(RS);                                 //Limpa o pino RS, modo comando
   delay_us(100);

   if (dado & 0b10000000) output_high(D7);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D7);            //Caso contrário desliga a linha

   if (dado & 0b01000000) output_high(D6);         //Se o bit estiver em 1 liga a saída
   else                     output_low(D6);            //Caso contrário desliga a linha

   if (dado & 0b00100000) output_high(D5);         //Se o bit estiver em 1 liga a saída
   else                    output_low(D5);            //Caso contrário desliga a linha

   if (dado & 0b00010000) output_high(D4);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D4);            //Caso contrário desliga a linha

   delay_us(100);

   output_high(EN);                                    //Gera pulso de enable
   delay_us(1);                                       //Aguarda 150 us
   output_low(EN);

   if (dado & 0b00001000) output_high(D7);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D7);            //Caso contrário desliga a linha

   if (dado & 0b00000100) output_high(D6);         //Se o bit estiver em 1 liga a saída
   else                     output_low(D6);            //Caso contrário desliga a linha

   if (dado & 0b00000010) output_high(D5);         //Se o bit estiver em 1 liga a saída
   else                    output_low(D5);            //Caso contrário desliga a linha

   if (dado & 0b00000001) output_high(D4);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D4);            //Caso contrário desliga a linha


   delay_us(10);

   output_high(EN);                                    //Gera pulso de enable
   delay_us(150);                                       //Aguarda 150 us
   output_low(EN);

   delay_ms(5);                                     //Faz a inicialização do display

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                  Rotina de Envio de Dados para o LCD                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Lcd_Dado(char dado)
{

   output_high(RS);                                 //Limpa o pino RS, modo comando
   delay_us(100);

   if (dado & 0b10000000) output_high(D7);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D7);            //Caso contrário desliga a linha

   if (dado & 0b01000000) output_high(D6);         //Se o bit estiver em 1 liga a saída
   else                     output_low(D6);            //Caso contrário desliga a linha

   if (dado & 0b00100000) output_high(D5);         //Se o bit estiver em 1 liga a saída
   else                    output_low(D5);            //Caso contrário desliga a linha

   if (dado & 0b00010000) output_high(D4);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D4);            //Caso contrário desliga a linha

   delay_us(10);

   output_high(EN);                                    //Gera pulso de enable
   delay_us(1);                                       //Aguarda 150 us
   output_low(EN);

   if (dado & 0b00001000) output_high(D7);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D7);            //Caso contrário desliga a linha

   if (dado & 0b00000100) output_high(D6);         //Se o bit estiver em 1 liga a saída
   else                     output_low(D6);            //Caso contrário desliga a linha

   if (dado & 0b00000010) output_high(D5);         //Se o bit estiver em 1 liga a saída
   else                    output_low(D5);            //Caso contrário desliga a linha

   if (dado & 0b00000001) output_high(D4);         //Se o bit estiver em 1 liga a saída
   else                      output_low(D4);            //Caso contrário desliga a linha


   delay_us(10);

   output_high(EN);                                    //Gera pulso de enable
   delay_us(150);                                       //Aguarda 150 us
   output_low(EN);

   delay_ms(3);                                     //Faz a inicialização do display

}

