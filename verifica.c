#define ler_conf read_eeprom(255)// le o espaco 255 onde esta definido configuracao do processo
#define iniciado 128// valor que indica que o processo ja foi iniciado alguma vez
#define bloqueado 172// valor que indica que o processo esta bloqueado

//@@@@@@@@@@  biblioteca para manipulacao do usuario @@@@@@@@@@@@

#define novo_usuario (read_eeprom(254)*6)// le a mem�ria para saber quantos usu�rio tem cadastrados, e assim saber o proximo endereco para novo usuario
#define dig_0 ((read_eeprom(254)*6)+1)// le a memoria para saber o proximo endereco para senha 
#define dig_1 ((read_eeprom(254)*6)+2)// le a memoria para saber o proximo endereco para senha 
#define dig_2 ((read_eeprom(254)*6)+3)// le a memoria para saber o proximo endereco para senha 
#define dig_3 ((read_eeprom(254)*6)+4)// le a memoria para saber o proximo endereco para senha 
#define incrementa_usuario (read_eeprom(254)+1)// le a mem�ria para saber quantos usu�rio tem cadastrados, e soma mais um para incrementar a quantidade
#define admin 1 // le a mem�ria para saber quantos usu�rio tem cadastrados, e soma mais um para incrementar a quantidade
#define admin_block 2 // le a mem�ria para saber quantos usu�rio tem cadastrados, e soma mais um para incrementar a quantid
#define block 3 // le a mem�ria para saber quantos usu�rio tem cadastrados, e soma mais um para incrementar a quantid


char SENHA[4]={'0','0','0','0'};
char digito=0, i=0, lcd=0;

struct users
{
   char id;
   char senha[4];
   char status;   // variavel que diz a situa��o se for 1= adim; se for 2=> adim bloqueando; se for 3 => s� bloqueando
} usuario;


//******************************************************************************************************************

void novo_user()
{
   write_eeprom(novo_usuario,usuario.id);
   write_eeprom(dig_0,usuario.senha[0]);
   write_eeprom(dig_1,usuario.senha[1]);
   write_eeprom(dig_2,usuario.senha[2]);
   write_eeprom(dig_3,usuario.senha[3]);
   write_eeprom(254,incrementa_usuario);   
}


void limpa_lcd();
void verifica()
{
   if(ler_conf==iniciado)
   {
      
      if(ler_conf==bloqueado)bloqueio=1;
   }
   else
   {
      lcd_inst(0x80);
      printf(lcd_Dado," USUARIO ID: 0  ");
      lcd_inst(0xc0);
      printf(lcd_Dado," SENHA :        ");
      //delay_ms(2000);
      //limpa_lcd();
      usuario.id=0;    //carregando id do primeiro usuario
      for(i=0;i<4;i++)
      {
      while(1)
      {
         
         lcd_inst(200+i);
         printf(Lcd_Dado,"%u",digito);
         lcd_inst(200+i);
         lcd_inst(0x0d);
         while(!teclado());
         if(teclado()==3)break;
         if(!input(cima) && digito<9)digito++;
         if(!input(baixo) && digito>0)digito--;
         printf(Lcd_Dado,"%u",digito);
         while(teclado());
      }
      while(teclado());
      usuario.senha[i]=digito; // salva os digitos da senha do usuario
      digito=0;
      }
      usuario.status = admin;
      novo_user(); /// salva usuario na eeprom
   }
}

void limpa_lcd()
{
   lcd_inst(0x80);
   printf(lcd_Dado,"                ");
   lcd_inst(0xc0);
   printf(lcd_Dado,"                ");
}



