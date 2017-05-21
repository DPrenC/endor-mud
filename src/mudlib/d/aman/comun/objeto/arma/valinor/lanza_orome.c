/* Fichero: lanza_orome.c
Autor: Aul�
Fecha: 19&10/2014
Descripci�n: la poderosa lanza del vala cazador Orom�, azote de monstruos malignos
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_LANZA, 20, P_SIZE_LARGE, M_ESPECIAL);
   SetShort("la lanza de la Gran Cacer�a forestal");
   SetLong(
   "Esta lanza, propiedad del famoso vala cazador Orom�, fue creada por �l en "
   "colaboraci�n con Aul�, el vala Herrero. Mide algo m�s de los dos metros y su "
   "punta, elegantemente ovalada y reluciente como si fuera de la m�s pura plata, late "
   "con fuego de poder interior. El largo mango, de la m�s fina madera de las hayas "
   "sagradas que crecen en los bosques de Orom�, est� habilmente trabajada con motivos "
   "ecuestres. A lomos del gran caballo Nahar, su propietario ha derribado con ella a "
   "multitud de bestias inmundas, pero tambi�n magn�ficas piezas de caza.\n");
   SetIds(({"lanza", "arma","lanza_orome"}));
   SetAds(({"larga", "de", "madera", "forestal", "caza", "orome"}));
    SetWeight(1500);
    SetNumberHands(1);
  SetValue(3000000);

  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar la lanza  con la que Orom� abati� a tantos oponentes.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "esta poderosa lanza.\n");
}