/* Fichero: lanza_orome.c
Autor: Aulë
Fecha: 19&10/2014
Descripción: la poderosa lanza del vala cazador Oromë, azote de monstruos malignos
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_LANZA, 20, P_SIZE_LARGE, M_ESPECIAL);
   SetShort("la lanza de la Gran Cacería forestal");
   SetLong(
   "Esta lanza, propiedad del famoso vala cazador Oromë, fue creada por él en "
   "colaboración con Aulë, el vala Herrero. Mide algo más de los dos metros y su "
   "punta, elegantemente ovalada y reluciente como si fuera de la más pura plata, late "
   "con fuego de poder interior. El largo mango, de la más fina madera de las hayas "
   "sagradas que crecen en los bosques de Oromë, está habilmente trabajada con motivos "
   "ecuestres. A lomos del gran caballo Nahar, su propietario ha derribado con ella a "
   "multitud de bestias inmundas, pero también magníficas piezas de caza.\n");
   SetIds(({"lanza", "arma","lanza_orome"}));
   SetAds(({"larga", "de", "madera", "forestal", "caza", "orome"}));
    SetWeight(1500);
    SetNumberHands(1);
  SetValue(3000000);

  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar la lanza  con la que Oromë abatió a tantos oponentes.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "esta poderosa lanza.\n");
}