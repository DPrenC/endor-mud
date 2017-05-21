/**************************************************************************
Fichero: loinus.c
Autor: Riberales
Creaci�n: 27-09-05
Descripci�n: El tendero de alimentaci�n.
***************************************************************************/

#include <properties.h>
inherit NPC;
public void create()
{
    ::create();
    SetStandard("loinus","enano",10,GENDER_MALE);
    AddId(({"loinus","tendero"}));
    SetShort("Loinus");
    SetLong(W("Loinus es un enano de edad avanzada. Lleg� a estas tierras "
              "cuando el rey Belthain pidi� a los ciudadanos de Kha-annu que "
              "ayudasen en el funcionamiento de Annufam. Su larga barba le da "
              "un toque de admiraci�n por parte de los que tratan con �l.\n"));
}
