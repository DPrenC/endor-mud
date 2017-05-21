/****************************************************************************
Fichero: perro_guardian.c
Autor: Ratwor
Fecha: 19/04/2008
Descripción: unos perros para las perreras del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;
create()
{
    ::create();
	SetStandard("un perro guardián", "animal", 11+d3(), GENDER_MALE);
    SetShort("Un perro guardián");
    SetLong("Es un enorme perro negro de enmarañado pelaje, cuerpo ancho y cola "
    "frondosa. Estos animales  criados durante generaciones por los Dhes-Bláin como "
    "perros guardianes, provienen de los lobos negros que aún hoy pueden encontrarse en "
    "los bosques del norte de Marhalt.\n");
    AddId(({"un perro guardián", "perro", "guardián", "guardian", "perro guardian"}));
    InitChats(3, ({"El perro te gruñe amenazadoramente.\n",
    	  "El perro te mira con ojos feroces.\n",
    	  "El perro enseña los  dientes.\n"}));
    InitAChats(20, ({"El perro lanza feroces dentelladas.\n",
    	  "El perro ladra furiosamente.\n",
    	  "El perro se lanza hacia adelante y cierra sus fuertes mandíbulas.\n",
    	  "El perro asesta una veloz dentellada.\n"}));
    SetSmell("Huele a perro sucio.\n");
    SetWeight(67000);
    SetAggressive(1);
    SetHands(({({"la dentadura", TD_CORTE,0})}));
    SetCitizenship("nandor");
}
