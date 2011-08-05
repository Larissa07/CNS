//@@@@@@@@@@  biblioteca para manipulacao do usuario @@@@@@@@@@@@


#define novo_usuario (read_eeprom(254)*4)// le a memória para saber quantos usuário tem cadastrados, e assim saber o proximo endereco para novo usuario
#define senha_baixa ((read_eeprom(254)*4)+1)// le a memória para saber quantos usuário tem cadastrados + 1, e assim saber o proximo endereco para senha  do novo usuario
#define senha_alta ((read_eeprom(254)*4)+2)// le a memória para saber quantos usuário tem cadastrados + 2, e assim saber o proximo endereco para senha novo usuario
#define incrementa_usuario ((read_eeprom(254)+1)// le a memória para saber quantos usuário tem cadastrados, e soma mais um para incrementar a quantidade


union password
{
int16 completa;
int parte[2];
} senha;

void salvar_user(struct user)
{
   write_eeprom(novo_usuario,user.id);
   senha.completa = user.senha;
   write_eeprom(senha_baixa,senha.parte[0])
   write_eeprom(senha_alta,senha.parte[1])
   write_eeprom(254,)
   
}
