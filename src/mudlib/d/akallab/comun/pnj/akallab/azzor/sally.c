/****************************************************************************
Fichero: sally.c
Autor: Kastwey
Fecha: 06/12/2005
Descripci�n: Sally la gorda, la due�a del a taberna del mismo nombre.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>

inherit NPC;

string mensaje_ayuda()
// mensaje que lanza si est� en su taberna y hay espectadores en ella
{
    object env = environment();
    int cli; // clientes de la taberna


    if (!env) return "";
    if (!env->QueryTabernaSally())
    {
        return "Sally mira hacia todos lados en busca de ayuda.\n";
    }
    if (cli = sizeof(filter(all_inventory(env),(:$1->id("orco_borracho"):))) > 1)
    {
        return "Sally grita: �eh! �maldita panda de orcos borrachos! "
               "Es que ninguno va a levantar una mano para ayudarme?\n";
    }
    else if (cli == 1)
    {
        return "Sally mira al �nico cliente de la taberna y le espeta "
               "enfadada: �eh t�! �Es que no piensas defenderme?!\n";
    }
    return "Sally grita: �pero c�mo osas ponerme una mano encima!\n";
}

public create()
{
    ::create();
    seteuid(getuid());
    SetStandard("Sally","orco",30,GENDER_FEMALE);
    SetShort("Sally la gorda");
    SetLong("Es una orca desvergonzada, que no tiene reparo ni en enga�ar a "
            "sus clientes, ni en distraerles actuando para ellos a cualquier "
            "hora con tal de sacarles hasta la �ltima moneda. Su orondo "
            "cuerpo cubierto de pelo negro no le impide bailar y contonearse "
            "delante de quienes la contemplan. Tiene los colmillos te�idos de "
            "a�il y sus ojos refulgen con descaro.\n");
    AddId(({"orca","gorda"}));
    AddItem(ARMOUR,REFRESH_REMOVE,
            ([P_SHORT:"un vestido corto",
              P_LONG:"ES un vestido corto y ce�ido, de cuero color rojo "
                     "chill�n, con adornos dorados.\n",
              P_IDS:({"vestido","vestido corto","vestido de cuero",
                      "vestido dorado"}),
              P_ARMOUR_TYPE:AT_TUNICA,
              P_AC:2,
              P_SIZE:P_SIZE_MEDIUM,
                P_MATERIAL:M_CUERO,
              P_GENDER:GENDER_MALE,
              P_NUMBER:NUMERO_SINGULAR,
              P_VALUE:890,
              P_WEIGHT:470]),SF(wearme));

    AddItem(ARMOUR,REFRESH_REMOVE,
            ([P_SHORT:"un collar",
            P_LONG:"Est� hecho de extra�as gemas color �mbar, quiz� "
                   "procedente de lejanas tierras. Podr�a tener alg�n "
                   "valor.\n",
            P_IDS:({"collar","collar de gemas","collar de piedras","collar "
                    "�mbar"}),
            P_ARMOUR_TYPE:AT_AMULET,
            P_SIZE:P_SIZE_GENERIC,
                P_AC:1,
            P_VALUE:12300,
            P_WEIGHT:170,
            P_GENDER:GENDER_MALE,
            P_NUMBER:NUMERO_SINGULAR]),
            SF(wearme));

    InitChats(4,({"Sally canta a voz en cuello: En un barco llegar� mi "
                  "orco m�s amado, y en el mismo puerto este cuerpo le ser� "
                  "entregado.\n",
                  "Sally canta con tono lascivo: �Para qu� esperar otro "
                  "momento, si al siguiente mi orco navegar� al viento!\n",
                  "Sally canturrea: �Y una, caballeros, no se queda con las "
                  "ganas, que luego el pelaje se hace canas!\n"}));

    InitAChats(7,({"�c�mo te atreves a mancillar mi cuerpo!\n",
                   SF(mensaje_ayuda)}));

}

