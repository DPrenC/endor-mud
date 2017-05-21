/*****************************************************************************************
 ARCHIVO:       robledal37.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit BASE_ISLA;

private int hay_fresas = 1;

public int cmd_coger(string str);
public string f_msgs_fresas();

create()
{
    if(::create()) return 1;

    SetIntShort("una ladera de la Colina Iluminada");
    SetIntLong("Te encuentras a los pies de la loma de la Colina Ilumninada en la "
        "parte norte de la isla. Los zarzales de fresas salvajes trepan entre una "
        "maraña de musgo y helechos luchando por obtener la escasa luz del sol, "
        "y de los montones de madera podrida salen lombrices y escarabajos.\n");
    AddDetail(({"suelo", "niebla"}), "Una espesa niebla se alza desde el suelo, frío y "
        "húmedo, y congela el aire de tal modo que, cuando respiras, emites vaho.\n");
    AddDetail(({"colina", "colina iluminada"}), "Una imponente colina sobresale en el "
        "horizonte, desde la que, seguramente, se pueda disfrutar de una sorprendente "
        "vista de toda la isla.\n");
    AddDetail(({"zarzales", "fresas", "fresas salvajes"}), SF(f_msgs_fresas));
    AddDetail(({"musgo", "maraña", "helechos"}), "Cantidades de musgo gris y verdecino "
        "helecho tapizan el suelo.\n");
    AddDetail(({"montones", "madera", "madera podrida"}), "Es esponjosa y está manchada "
        "y decolorida.\n");
    AddDetail("suelo", "Está cubierto de musgo y helechos.\n");
    SetIntSmell("Huele a madera podrida.\n");

    SetIndoors(0);

    AddRoomCmd("coger", "cmd_coger");

    AddExit("sur", HAB_BOSQUE_ISLA("robledal35.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal40.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal38.c"));

    AddItem(OBJ_COMIDA_VALINOR("hongo.c"), REFRESH_REMOVE, random(4));
}

public int cmd_coger(string str)
{
    object fresas;

    if(!str || (str != "fresa" && str != "fresas" && str != "fresas silvestres"))
    {
        return 0;
    }
    if(hay_fresas)
    {
        if(present("fresas_faeria", TO))
        {
            hay_fresas = 0;
            return 0;
        }
        write("Coges algunas fresas del zarzal.\n");
        say(CAP(TNAME) + " coge algunas fresas del zarzal.\n");

        fresas = clone_object(OBJ_COMIDA_VALINOR("fresas.c"));
        if(fresas->move(TP) != ME_OK)
        {
            write("No puedes llevar más peso. Sin poder evitarlo, las fresas se te caen "
                "al suelo.\n");
            say("Sin poder evitarlo, a " + CAP(TNAME) + ", se le caen las fresas al "
                "suelo.\n");
            fresas->move(TO);
            hay_fresas = 0;
            return NOTIFY_NOT_VALID;
        }
        hay_fresas = 0;
        return 1;
    }
    else return notify_fail("No hay fresas, mala suerte.\n", NOTIFY_NOT_VALID);
}

public string f_msgs_fresas()
{
    if(hay_fresas)
        return "Los zarzales están repletos de fresas que se apretujan unas contra "
               "otras.\n";
    return "Parece que alguien recogió las últimas fresas que quedaban.\n";
}

public void reset()
{
    ::reset();
    hay_fresas = 1;
}
