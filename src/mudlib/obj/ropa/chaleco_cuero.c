/* un chaleco de cuero, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TABARDO, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("un chaleco de cuero");
SetLong(
"Es una resistente prenda exterior de cuero curtido pero sin teñir que se ajusta al "
"tronco, está exento de mangas y llega a la cintura.\n"
"En la parte delantera se cierra mediante unos botones de estaño que ajustan en "
"ojales hechos con flexibles tiras, también de cuero.\n"
"Es una prenda exterior resistente, que protege el tronco del frío y el calor, aunque "
"dicha protección se ve mermada por el hecho de que no cuenta con mangas, aunque los "
"movimientos que permite son más desahogados.\n");
SetIds(({"chaleco","ropa"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}