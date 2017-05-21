/***************************************************************************************
 ARCHIVO:	carretilla_vacia.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripción: Una carretilla en las minas.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>


inherit "/std/container";



public void create ()
{
    ::create();

    SetShort("una carretilla");
    SetLong("Es una caja de madera, con una rueda enganchada a ella a través"
              " de un eje, y unos mangos en el otro extremo para levantarla "
              "y transportar el mineral con mayor facilidad.\n");

    SetIntShort("una carretilla");
    SetIntLong("En una carretilla.\n");
    SetIds(({"carretilla"}));

    SetMaxIntWeight(30000);
    SetWeight(10000);
    SetNoGet(1);

}


public int cmd_empujar(string str)
{
    string donde, que;
    object ob;

    if (!str) return notify_fail("¿"+CAP(query_verb())+ " qué?\n",
                     NOTIFY_NOT_VALID);

    if (sscanf(str,"%s al %s",que, donde) == 2 || sscanf(str,"%s "
        "hacia el %s",que, donde) == 2 || sscanf(str,"%s hacia %s",que, donde)
        == 2)
    {
        if (!ob = present(que, environment()))
        // no hay nada con el nombre que.
        {
            return notify_fail("No ves a " + que + " para " + query_verb() + ".\n",
                               NOTIFY_NOT_VALID);
        }
        if (ob != TO)
        // esta no es la carretilla que se quiere empujar
        {
            return notify_fail("¿" + CAP(query_verb()) + " qué?\n");
        }
        switch(donde)
        {
            case "n": donde = "norte"; break;
            case "s": donde = "sur"; break;
            case "e": donde = "este"; break;
            case "o": donde = "oeste"; break;
            case "ar": donde = "arriba"; break;
            case "ab": donde = "abajo"; break;
            case "se": donde = "sudeste"; break;
            case "so": donde = "suroeste"; break;
            case "ne": donde = "nordeste"; break;
            case "no": donde = "noroeste"; break;
        }

        string *salidas = m_indices(filter(environment()->QueryExits(),
                                           (:stringp($2[0]):)));
        if (member(salidas,donde) < 0)
        {
            return notify_fail("No puedes ir por ahí.\n",NOTIFY_NOT_VALID);
        }

        if (TP->fighting())
        {
            return notify_fail("No puedes dejar este lugar.\n",
                   NOTIFY_NOT_VALID);
        }
        if (sizeof(filter(all_inventory(environment()),(:$1->id("pnj_minas")
                   && living($1):))))
        {
            return notify_fail("Mejor no toques la carretilla en presencia de "
                               "sus dueños.\n",NOTIFY_NOT_VALID);
        }

if (TP->QueryTP() < 2)
        {
            return notify_fail("Estás muy cansad"+SEXO+" para poder "+
                               CAP(query_verb())+ "la carretilla.\n",
                               NOTIFY_NOT_VALID);
        }

        if (donde == "arriba")
        {
            return notify_fail("No puedes subir la carrettilla por la "
                               "escalera.\n",NOTIFY_NOT_VALID);
        }


        if (donde == "abajo")
        {
            object car_rota;
            move(environment()->QueryExits()[donde],M_SILENT);
            tell_object(TP,"Empujas la carretilla hacia el hueco, e "
                           "irremediablemente te cae al piso inferior.\n");
            tell_room(environment(TP),CAP(TNAME)+ " empuja la carretilla hacia"
                                      " el hueco, y de repente observas como "
                                      "cae estrepitosamente a la planta "
                                      "inferior.\n",({TP}));
            tell_room(environment(),"Una carretilla cae por el hueco de "
                                    "acceso al piso superior y se estrella "
                                    "contra la fría piedra.\n");
            car_rota = clone_object(OTRO_MINAS("carretilla_rota"));
            car_rota->move(environment());
            TP->AddTP(-2);

            return remove();
        }


        if (environment()->QueryExits()[donde] == CAM_KHA_KEN("entra_mina"))
        {
            object guardia;
            if (sizeof(filter(all_inventory(environment()),
                      (:$1->id("guardian_minas") && living($1):))))
            {
                tell_object(TP,"Eh, "+CAP(TNAME)+", ¿dónde crees que vas con "
                               "esa carretilla?\n");
                tell_room(environment(),"Un guardia detiene a "+CAP(TNAME)+
                                        "cuando intentaba salir de las minas "
                                        "con una carretilla.\n",({TP}));
                guardia->kill(TP);
                return 1;
            }

            return notify_fail("La cuesta está demasiado inclinada para que "
                               "puedas subir la carretilla.\n",NOTIFY_NOT_VALID);
        }

        TP->move(environment()->QueryExits()[donde],M_SPECIAL,
               ({"se va en dirección "+donde+" empujando una carretilla",
                  "llega empujando una carretilla",
                "te vas en dirección "+donde+" empujando la carretilla"}));
        move(environment()->QueryExits()[donde],M_SILENT);

        return 1;
    }
    return notify_fail("¿Empujar qué hacia dónde?\n",NOTIFY_NOT_VALID);
}

public void init()
{
    ::init();
    add_action("cmd_empujar","empujar");
    add_action("cmd_empujar","mover");
    add_action("cmd_empujar","arrastrar");
}
