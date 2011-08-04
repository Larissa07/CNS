#define ler_conf read_eeprom(255)// le o espaco 255 onde esta definido configuracao do processo
#define iniciado 128// valor que indica que o processo ja foi iniciado alguma vez
#define bloqueado 172// valor que indica que o processo esta bloqueado
char SENHA[4]={'0','0','0','0'}
char digito=0;

void verifica()
{
   if(ler_conf==iniciado)
   {
      
      if(ler_conf==bloqueado)
   }
   else
   {
      lcd_inst(0x80);
      printf(lcd_Dado," USUARIO ID: 0  ");
      lcd_inst(0xc0);
      printf(lcd_Dado," SENHA :        ");
      delay_ms(2000);
      limpa_lcd();
      usuario.id=0;
   }
}
for(i=0;i<4;i++)
{
   while(direita!=2)
   {
   lcd_inst(0x80);
   lcd_inst(0x0d);
   if(input(cima) && digito<9)digito++;
   if(input(baixo) && digito>0)digito--;
   lcd_inst(0xc0);
   printf(Lcd_Dado,"%c",digito);
   }
   SENHA[i]=digito;
   
}
void limpa_lcd();
{
   lcd_inst(0x80);
   printf(lcd_Dado,"                ");
   lcd_inst(0xc0);
   printf(lcd_Dado,"                ");
}
