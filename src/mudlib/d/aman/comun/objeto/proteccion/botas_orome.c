/* Fichero: botas_orome.c
Autor: Aulë
Fecha: 03/08/2014
Descripción: botas de Oromë.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BOTAS, 5, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("las botas del gran Cazador Silente");
SetLong(
"Estas magníficas botas son una pieza de inestimable valor para Oromë, puesto que "
"mediante el poder de su hermana Vána han sido imbuidas de una energía que le confiere "
"al vala la capacidad de avanzar a gran velocidad cuando va a pie, sin dejar huella "
"alguna y en un silencio total, de forma que cuando así lo desea y recurre a sus "
"vestiduras mortales, ni el más avisado de los Elfos podría oír su aproximación.\n"
"Las botas de caña alta y flexible parecen estar hechas de cuero blando pero resistente\n"
"un color que las hace camuflarse entre la espesura de la floresta.\n");
SetIds(({"botas","ropa", "calzado", "botas_orome"}));
SetAds(({"de", "orome", "altas", "del", "cazador", "silente", "floresta", "cuero"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este .\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "éstas botas.\n");
}