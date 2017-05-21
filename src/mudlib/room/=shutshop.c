/* The final shop for armageddon */

#include <stdrooms.h>

inherit "/std/shop";

void create() {
  ::create();

  SetIntShort("La tienda de Armagedon");
  SetIntLong(
    "Te encuentras en la tienda de Armagedon cerca del fin del universo.\n"
    "Un pequenyo pasillo hacia el oeste conduce al Restaurante.\n");
  SetList(0);
  SetIdentify(0);
  SetAppraise(0);
  SetBuy(0);
  ForbidShopkeeper();
  SetLivingTrade(1);
  AddExit("oeste", RESTROOM);
  AddExit("este", CHURCH);
}
