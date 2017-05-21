/****************************************************************************
Fichero: ogro_shafil.c
Autor: Ratwor
Fecha: 31/08/2006
Descripción: El ogro que acompaña a la tabernera de la taberna Mi hacha me acompaña.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>

inherit NPC;

create()
{
    ::create();

    SetStandard("Goruck", "ogro", ([GC_LUCHADOR:90+d8()]), GENDER_MALE);
    AddId(({"ogro", "Goruck", "goruck"}));
    SetShort("Goruck el ogro");
    SetLong(
        "Goruck es un enorme ogro que hace algún tiempo consagró su vida a proteger y "
        "servir a la bella Safil. Su rostro de boca entreabierta de labio inferior caído "
        "y babeante, y sus ojillos de mirada vidriosa contrastan con su tremendo y "
        "brutal corpachón. Su cuello corto y grueso como el de un buey y su enorme tórax,"
        " están flanqueados por dos largos y musculosos brazos, del grosor de la pierna "
        "de un orco, mientras sus piernas, combadas hacia el exterior y rematadas en dos"
        " enormes pies descalzos, ayudan a mantener el peso de tan colosal masa muscular.\n");
    SetAlign(-100);
    SetWeight(185000);
    SetSmell("Huele horriblemente a ogro.\n");

    InitAChats(10, ({"El ogro grita ferozmente.\n",
        "Goruck grita: renacuajo te voy a destrozar.\n",
        "Goruck levanta los brazos rabioso.\n"}));
    InitChats(2, ({"Goruck mira inquisidoramente a su alrededor.\n",
        "Goruck se rasca la cabeza.\n",
        "Goruck te mira con mala cara.\n",
        "Goruck acaricia el filo de su hacha.\n"}));
    AddQuestion(({"shafil", "Shafil", "semi-elfa", "medio-elfa", "semi elfa", "medio elfa"}),
        "Goruck te dice: Shafil es como una flor de primavera, me gusta estar a su lado y"
        " protegerla de indeseables, aunque a veces es algo traviesa con los hombres."
        " Estaré junto a ella mientras viva.\n");

    AddItem(ARMA("hacha_ogro"),REFRESH_REMOVE, SF(wieldme));

    AddItem(ARMOUR,REFRESH_REMOVE,SF(wearme),
        ([P_SHORT: "unos enormes pantalones andrajosos",
        P_LONG:  "Son unos enormes pantalones viejos y rotos por los camales.\n",
        P_ARMOUR_TYPE:AT_TROUSERS,
        P_IDS: ({"pantalon", "pantalón", "pantalones", "pantalones andrajosos"}),
        P_AC: 2, P_MATERIAL:M_TELA,
        P_SIZE:P_SIZE_LARGE,
        P_RESET_QUALITY: 80,
        P_WEIGHT: 1050]) );
}
