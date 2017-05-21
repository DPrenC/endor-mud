/* Hacha especial para Thualin
   Baldur, 07-08-02
*/	

inherit "/std/weapon";
#include <combat.h>
#include <properties.h>
#include <materials.h>

create(){
 ::create();
SetStandard(WT_HACHA,10,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(10000); // Aumentado el peso
 SetShort("un hacha enana");
 SetIds(({"hacha","hacha enana","hacha enana a 2 manos"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("Es una gran hacha enana de doble filo, forjada por un maestro armero\n"
	 "con el mejor acero. Por su tamaño sólo puede ser empuñada a 2 manos\n"
	 "si posees una gran fuerza.\n");
}
