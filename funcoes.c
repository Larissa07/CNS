#define rele1    PIN_C4 
#define rele2    PIN_C5 
#define rele3    PIN_C6
#define led_vermelho PIN_B6  //fincionamento bloqueado
#define led_verde    PIN_B7  //fincionando normal
//*******************************************************************************************************************
void func_normal()
{
 output_high(rele1);
 output_high(rele2);
 output_high(rele3);
 output_high(led_verde);
 lcd_inst(0x80);
 printf(Lcd_Dado,"  FUNC_NORMAL   ");
 lcd_inst(0xc0);
 printf(Lcd_Dado,"PR. TECLA P/ BLO");
 while(!teclado());

}
//******************************************************************************************************************
void func_bloqueado()
{
 output_low(rele1);
 output_low(rele2);
 output_low(rele3);
 output_high(led_vermelho);
 lcd_inst(0x80);
 printf(Lcd_Dado," FUNC_BLOQUEADO ");
 lcd_inst(0xc0);
 printf(Lcd_Dado,"PR. TECLA P/ DES");
 while(!teclado());
}
//******************************************************************************************************************
