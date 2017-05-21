/****************************************************************************
Fichero: granjero_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripción: un granjero para los campos de cultivo de nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    AddId(({"granjero", "hombre", "labrador", "campesino", "aldeano", "pueblerino"}));
    SetStandard("un granjero", "humano", ([GC_NINGUNO:20]), GENDER_MALE);
    SetShort("un granjero");
    SetLong("Es un granjero de los que trabajan las tierras en los campos de cultivo de "
        "la villa de Nandor.\n Se pasa largas jornadas trabajando de sol a sol para "
        "el desarrollo del pueblo.\n");
    SetSmell("Huele bastante a sudor, cosa normal teniendo en cuenta las horas que "
        "trabaja.\n");
    InitAChats(6,({"El granjero dice: ¡maldita sea, que me paso la vida en las tierras "
        "para que vengas a atacarme de esta manera!\n",
        "El granjero grita fuertemente: ¡socooorro!\n",
         "El granjero grita: ¡déjame en paz!\n"}));

    InitChats(3,({"El granjero acaricia el mango de su azada.\n",
    "El granjero anda con la cabeza gacha.\n",
    "El granjero parece quejarse de la espalda.\n"}));

    AddQuestion(({"tierra","tierras","cultivo","cultivos","labrar","trabajo","trabajar"}),
        "El campesino te dice: ya ves, las tierras hay que cultivarlas y es muy duro,"
        " se requiere gente, pero es difícil encontrarla ya que es un trabajo forzoso,"
        " no a todo el mundo le gusta esto, pero hay que comer de alguna manera.\n",1);

    AddItem(WEAPON,REFRESH_REMOVE,
            ([P_WEAPON_TYPE:WT_HACHA, P_WC:5, P_SIZE:P_SIZE_MEDIUM,
            P_MATERIAL:M_HIERRO,P_SHORT:"una azada",
            P_LONG:"Una simple azada para trabajos en el campo.\n",
            P_IDS:({"azada"}), P_GENDER:GENDER_FEMALE,
            P_NUMBER_HANDS:2, P_WEIGHT:1400, P_VALUE: 530]), SF(wieldme));
    SetCitizenship("nandor");
    SetGoChance(50);
    AddWalkZones(MARH("nandor"));
}
