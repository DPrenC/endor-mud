/****************************************************************************
Fichero: perro_guardian.c
Autor: Ratwor
Fecha: 19/04/2008
Descripci�n: unos perros para las perreras del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;
create()
{
    ::create();
	SetStandard("un perro guardi�n", "animal", 11+d3(), GENDER_MALE);
    SetShort("Un perro guardi�n");
    SetLong("Es un enorme perro negro de enmara�ado pelaje, cuerpo ancho y cola "
    "frondosa. Estos animales  criados durante generaciones por los Dhes-Bl�in como "
    "perros guardianes, provienen de los lobos negros que a�n hoy pueden encontrarse en "
    "los bosques del norte de Marhalt.\n");
    AddId(({"un perro guardi�n", "perro", "guardi�n", "guardian", "perro guardian"}));
    InitChats(3, ({"El perro te gru�e amenazadoramente.\n",
    	  "El perro te mira con ojos feroces.\n",
    	  "El perro ense�a los  dientes.\n"}));
    InitAChats(20, ({"El perro lanza feroces dentelladas.\n",
    	  "El perro ladra furiosamente.\n",
    	  "El perro se lanza hacia adelante y cierra sus fuertes mand�bulas.\n",
    	  "El perro asesta una veloz dentellada.\n"}));
    SetSmell("Huele a perro sucio.\n");
    SetWeight(67000);
    SetAggressive(1);
    SetHands(({({"la dentadura", TD_CORTE,0})}));
    SetCitizenship("nandor");
}
