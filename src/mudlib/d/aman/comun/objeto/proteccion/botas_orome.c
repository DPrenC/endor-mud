/* Fichero: botas_orome.c
Autor: Aul�
Fecha: 03/08/2014
Descripci�n: botas de Orom�.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BOTAS, 5, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("las botas del gran Cazador Silente");
SetLong(
"Estas magn�ficas botas son una pieza de inestimable valor para Orom�, puesto que "
"mediante el poder de su hermana V�na han sido imbuidas de una energ�a que le confiere "
"al vala la capacidad de avanzar a gran velocidad cuando va a pie, sin dejar huella "
"alguna y en un silencio total, de forma que cuando as� lo desea y recurre a sus "
"vestiduras mortales, ni el m�s avisado de los Elfos podr�a o�r su aproximaci�n.\n"
"Las botas de ca�a alta y flexible parecen estar hechas de cuero blando pero resistente\n"
"un color que las hace camuflarse entre la espesura de la floresta.\n");
SetIds(({"botas","ropa", "calzado", "botas_orome"}));
SetAds(({"de", "orome", "altas", "del", "cazador", "silente", "floresta", "cuero"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este .\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "�stas botas.\n");
}