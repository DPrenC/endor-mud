/* Banco de Cored
 * [m] Maler
 * 16/07/00 [m] Creacion
*/

#include "./path.h"
#include <moving.h>

inherit BANK;


create() {
  ::create();
  SetLocate("Cored");
  SetBankName("cored");
  SetIntShort("el banco de Cored");
  SetIntLong(
"Te encuentras en el banco de Cored. Aquí puedes\n\
abrir o cancelar cuentas, sacar y meter dinero, etc...\n\
");
SetIntBright(50);

  SetIndoors(1);
  SetKeeper(PNJ("banquero"),REFRESH_DESTRUCT,1);
  AddExit("oeste",ROOMFF("patio16"));
}
