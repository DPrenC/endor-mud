/***
Fichero: celdas_base.c
Autor: kastwey@simauria
Descripción: Habitación pase para la zona de las celdas.
12/12/2004 Añado que se pueda intentar coger musgo.
14/12/2004
Cambio algunas cosillas para heredar las celdas de este fichero, y los pasillos de otro.
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_siempreunidos");

int cmd_coger(string str);

create()
{
    ::create();
    SetIntShort("una celda");
    SetIntLong(W("Te encuentras en una húmeda celda, de no más de 1 metro cuadrado.\n"
    "El techo está muy alto, a unos tres metros del suelo, lo que no elimina en ningún modo la sensación de claustrofobia que te produce esta pequeña estancia.\n"
        "Como único elemento decorativo puedes ver un camastro en un rincón.\n"));
    SetIndoors(1);
    SetIntBright(20);
    SetIntNoise("Escuchas como algunas gotas de agua se deslizan por las paredes hasta caer al suelo.\n");
    SetIntSmell("Huele a humedad.\n");
    AddDetail(({"cama", "camastro"}), "Más que una cama esto no es más que un delgado colchón de paja tirado en el suelo.\n");
    AddDetail(({"pared", "suelo", "techo"}), "Tanto las paredes como el techo, están recubiertos de una gruesa capa de musgo debido a la humedad del lugar.\n");
AddItem(OBJETO "otro/faeria/recipiente",REFRESH_REMOVE,1);
    // añadimos un bichito para cada celda.
    switch(random(100))
    {
        case 0..19: // araña:
            AddItem(PNJ_PUESTO("aranya"), REFRESH_REMOVE, 1);
            break;
        case 20..39: // rata
            AddItem(PNJ_PUESTO("rata"), REFRESH_REMOVE, 1);
            break;
        case 40..59: // serpiente
            AddItem(PNJ_PUESTO("serpiente"), REFRESH_REMOVE, 1);
            break;
        case 60..79: // murciélago
            AddItem(PNJ_PUESTO("murcielago"), REFRESH_REMOVE, 1);
            break;
        case 80..99:
        // no hay ningún bicho.
            break;
    }
    AddDetail("musgo", "Es una gruesa capa de musgo que cubre casi toda la pared y el techo.\n");
}


public int prevent_leave(mixed dest, int method, mixed extra)
{
    // debug    tell_object(find_object("kastwey"), to_string(method) + "\n" + to_string(extra) + ".\n" + PO->QueryName() + ".\n");
    if (!query_wiz_level(PO) && (method == M_TELEPORT || (method == M_SILENT && !extra)))
    {
        write("Una fuerza mágica impide que realices el teletransporte.\n");
        return ME_NO_LEAVE;
    }
    else
    {
        return ::prevent_leave(dest, method, extra);
    }
}

init()
{
    ::init();
    add_action("cmd_coger", "coger");
}


int cmd_coger(string str)
{
    string *palabras;
    if (!str || (str != "musgo de techo" && str != "musgo del techo" && str != "musgo de pared" && str != "musgo" && str != "musgo de la pared")) return 0;
    palabras = explode(str, " ");
    switch(palabras[sizeof(palabras)-1])
    {
        case "techo":
            write("El techo está demasiado alto para que puedas coger musgo de él.\n");
            break;
        case "pared":
            write("Intentas arrancar un trozo de musgo de la pared, pero está tan firmemente sujeto que te es imposible coger nada.\n");
            break;
        default:
            write("Intentas arrancar un trozo de musgo de la pared, pero está tan firmemente sujeto que te es imposible coger nada.\n");
            break;
    }
    return 1;
}

public string QueryIntLong()
{
    return ::QueryIntLong()[..<3]
        + to_string(present("recipiente_puesto_celdas")?
            " y un recipiente de lata junto a la cama.\n":
            ".\n");
}
