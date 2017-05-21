/****************************************************************************
Fichero: romli.c
Autor: Riberales
Creaci�n: 24/01/06
Descripci�n: El  capit�n guardia que vigila en la entrada.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <guild.h>
#include <moving.h>


inherit PNJ_MINAS("guardia_base");


public int QueryCapitanMinas() { return 1; }

create()
{
    ::create();

    SetCapitanMinas(1);
    SetStandard("romli","enano",([GC_LUCHADOR:125]),GENDER_MALE);
    SetShort("Romli, el capit�n de la guardia");
    SetLong("Se trata de Romli, capit�n de la guardia enana de las minas. Es "
               "un enano muy fornido, con una cicatriz en la cara, la larga y "
               "t�pica barba b�fida que le llega al cinto de su armadura, y "
               "con la mirada de todo un veterano de las escaramuzas. Por su "
               "pinta, dir�as que es el m�ximo responsable de la seguridad en "
               "estas minas.\n");

    Set(P_CANT_LURE,1);
    SetGoChance(0);
    AddId(({"capitan","capit�n",",Romli","romli","enano"}));

    AddItem(ARMA_MINAS("hacha_romli"),REFRESH_REMOVE,SF(wieldme));

    AddItem("/std/armour",REFRESH_REMOVE,([
            P_SHORT: "una armadura enana",
            P_LONG: "Es una armadura de acero con la insignia del reino de "
                    "Kha-annu en el pecho. El cinto est� hecho del mithril "
                    "m�s puro que has visto nunca, y tiene diferentes "
                    "enganches para diversas armas.\n",
            P_IDS: ({"armadura","armadura enana"}),
            P_ARMOUR_TYPE: AT_ARMOUR,
            P_AC: 15,
            P_WEIGHT: 22000,
            P_MATERIAL: M_ACERO,
            P_SUB_DETAILS: ([({"cinto","cinturon","cintur�n"}):
                               "Es un cintur�n de mithril donde colgar las "
                               "armas.\n",
                             ({"insignia","escudo"}):
                             "Es la insignia del pueblo de Kha-annu. En su "
                             "parte superior hay una corona con cinco "
                             "diamantes, en representaci�n de sus cinco "
                             "ciudades principales, y en la parte inferior un "
                             "escudo con el borde plateado y el fondo verde, "
                             "donde aparece un le�n rampante ense�ando sus "
                             "fauces y flanqueado por un par de hachas.\n"])]),
            SF(wearme));

    InitChats(4,({
              "Romli te mira inquisidoramente.\n",
              "Romli escupe al suelo.\n",
              "El capit�n te mira, y mientras te sonr�e levanta su hacha.\n",
              "Romli dice: Eh, t�, a ver lo que haces por aqu�.\n"}));
}

