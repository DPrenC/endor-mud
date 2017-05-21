/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <colours.h>
#include <moving.h>

inherit GBOSQUE;

 int sin_guardias;
int entrar();

public create()
{
    ::create();
    SetPreIntShort("frente a");
    SetIntShort("la mansión de Hardester Rankomme");
    SetIntLong("Te encuentras frente a la mansión del terrateniente "
        "Hardester Rankomme. Una casa de dos plantas con las paredes de color blanco. Puedes "
        "ver un anuncio colgado de la pared.\n");
    AddDetail(({"casa","mansion","mansión"}),"Ves una casa de dos plantas con las paredes "
        "blancas.\n");
    AddDetail(({"anuncio","hoja"}),"Será mejor que lo leas.\n");
    AddReadMsg(({"anuncio","hoja"}),
            (:(QUESTMASTER->QueryQuestSolved("daga_hardester",TP)?
               TC_RED + "ATENCIÓN\n" + TC_NORMAL
                 "--------\n\n" //
                 "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
                 "\n" //
                 "     " + TC_GREEN + "La daga del ilustrísimo Hardester\n" //
                 "     ya ha sido encontrada!\n" //
                 "     Estaremos eternamente agradecidos a " + capitalize(TNAME)+
                 "\n     por haberla recuperado.\n\n" + TC_NORMAL
                 "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
                 "\n":
                 "ATENCIÓN\n" //
                 "--------\n" //
                 "Se ofrece una recompensa de 20 monedas de mithril a quién "
                 "sea capaz de recuperar la daga del ilustrísimo Hardester "
                 "Rankomme. Se sabe que fue robada por unos piratas que "
                 "abandonaronn la isla en un barco.\n\n" ):));
    AddExit("norte",BOSCURO("bosque17"));
    AddExit("sur",BOSCURO("bosque16"));
    AddExit("este",BOSCURO("alrededor_crowy10"));
    AddExit("oeste",SF(entrar));
    AddItem(PNJ("crowy/kguardia_orco"),REFRESH_DESTRUCT,2);
    AddItem(PNJ("crowy/kguardia_elfo"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("crowy/kguardia_humano"),REFRESH_DESTRUCT,3);
    AddItem(PNJ("crowy/kguardia_enano"),REFRESH_DESTRUCT,3);
    SetLocate("bosque oscuro de Goldhai");
}


public int Guardia(object ob)
{
    if (ob->QueryIsNPC() && ob->id("guardian"))
    {
        sin_guardias=1;
        return 1;
    }
    return 0;
}

int entrar()
{
    sin_guardias=0;

    filter(all_inventory(),SF(Guardia));

    if (!query_once_interactive(TP) || !sin_guardias)
    {
        TP->move(MANSION("entrada"),M_GO);
        return 1;
    }
    if (!present("hrdaga",TP))
    {
        if (QUESTMASTER->QueryQuestSolved("daga_hardester",TP))
        {
            write("Un guardia te mira y hace un gesto de reconocimiento. "
                    "Ah, Hola " + capitalize(TNAME) + ". Pasa, Pasa...\n");
            TP->move(MANSION("entrada"),M_GO);
            return 1;
        }
        write("Un guardia te corta el paso y te dice: "
                "Lo siento, esto es una propiedad privada.\n");
        say("Cuando " + capitalize(TNAME) + " intenta pasar a la mansión, "
              "un guardia le corta el paso.\n");
        return 1;
    }
    write("Ven que llevas la daga y te dejan pasar.\n");
    TP->move(MANSION("entrada"),M_GO);
    return 1;
}