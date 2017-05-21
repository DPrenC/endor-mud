/**************************************************************************
Fichero: loinus.c
Autor: Riberales
Creación: 27-09-05
Descripción: El tendero de alimentación.
***************************************************************************/

#include <properties.h>
inherit NPC;
public void create()
{
    ::create();
    SetStandard("loinus","enano",10,GENDER_MALE);
    AddId(({"loinus","tendero"}));
    SetShort("Loinus");
    SetLong(W("Loinus es un enano de edad avanzada. Llegó a estas tierras "
              "cuando el rey Belthain pidió a los ciudadanos de Kha-annu que "
              "ayudasen en el funcionamiento de Annufam. Su larga barba le da "
              "un toque de admiración por parte de los que tratan con él.\n"));
}
