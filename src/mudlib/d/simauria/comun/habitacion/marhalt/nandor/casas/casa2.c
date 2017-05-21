/**************************************************************************/
/*                                                                        */
/*  Casa de Leyma, la tendera creado por Cheto para la aldea de Nandor    */
/* [ch] Cheto                                                             */
/*  [k] Kintups                                                           */
/*                                                                        */
/* [ch] ??? 02 Jun 1997 --- Creación.                                     */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y añadidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create() {
  ::create();
  SetLocate("Aldea de Nandor");
  SetIntShort("la puerta de la casa de Leyma");
  SetIntLong(W(
    "Estás frente a la casa de Leyma, la tendera de la tienda que hay al otro "
    "lado de la calle, es una casa grande, aunque un poco austera, pues los "
    "beneficios de la tienda no dan para demasiados lujos, aunque es una casa "
    "muy acogedora. La puerta de la casa está cerrada con llave, por lo que "
    "no puedes entrar.\n"));
  SetIntBright(30);
  AddExit("norte","../calle2");
}