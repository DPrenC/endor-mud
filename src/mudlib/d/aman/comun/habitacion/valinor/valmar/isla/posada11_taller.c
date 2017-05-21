/*****************************************************************************************
 ARCHIVO:       posada11_taller.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Taller.
 COMENTARIOS:   Punto de exploración, si el player se come un engendro, muere, poesito.
*****************************************************************************************/

#include "./path.h"
#include <input_to.h>

inherit BASE_ISLA;

public int cmd_comer(string str);
public void f_pobre_player(object pl);
public int f_comer_engendro(string str);
public void f_confirmar_comer();

create()
{
    if(::create()) return 1;

    SetIntShort("el taller");
    SetIntLong("Te hallas en un sótano bastante caótico. En las paredes, expuestos en "
        "vitrinas, colgados en ristras del techo y esparcidos por todas partes "
        "distingues variados productos. En un rincón humea un caldero colocado sobre una "
        "especie de  trípode al calor de la lumbre.\n");
    AddDetail(({"pared", "paredes"}), "Son de piedra, dispuestos en multitud de "
        "anaqueles, se observan todo tipo de frascos, recipientes, alambiques y "
        "utensilios de diversas formas y tamaños.\n");
    AddDetail("productos", "Hay potingues y mejunjes metidos en frascos. También hay "
        "animalillos conservados en líquido, hierbas y plantas.\n");
    AddDetail(({"anaqueles", "vitrinas"}), "Son de madera y no tienen puerta.\n");
    AddDetail(({"techo", "ristras"}), "Puedes ver ajos, pieles de animales y una especie "
        "de plasta sólida metida en una red.\n");
    AddDetail(({"plasta", "plasta sólida", "plasta solida"}), "Son como tripas de bichos "
        "apelmazadas.\n");
    AddDetail("ajos", "Son tan grandes como cabezas de ardilla.\n");
    AddDetail(({"pieles", "pieles de animales"}), "Están secas.\n");
    AddDetail(({"caldero", "caldero humeante"}), "Humea y borbotea sin cesar.\n");
    AddDetail(({"tripode", "trípode"}), "Es un armazón de tres patas.\n");
    AddDetail("lumbre", "Es un fueguito de lo más corriente.\n");
    AddDetail(({"recipientes", "frascos"}), "Al menos están etiquetados: lenguas y ojos "
        "de sapo, uñas de cocodrilo, dientes de conejo, alas de murciélago, hojas de "
        "marihuana, agua del arroyo negro, cascabel de serpiente...\n");
    AddDetail("animalillos", "Puedes ver desde pequeños ratones de campo hasta engendros "
        "similares a conejos.\n");
    AddDetail(({"liquido", "líquido"}), "Es verde, en él flotan sustancias más espesas "
        "y oscuras.\n");
    AddDetail("engendros", "Son unos bichos deformes, ¿serán comestibles?\n");
    AddDetail("sustancias", "Son, ... pues eso, espesas y oscuras.\n");
    AddDetail(({"hierbas", "plantas"}), "También están metidas en frascos etiquetados: "
        "mandrágora, estramonio, belladona y beleño negro.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Una mezcla de olores fétidos y ajo.\n");
    SetIntNoise("Escuchas el borboteo del caldero.\n");

    AddRoomCmd("comer", "cmd_comer");

    AddExit("arriba", HAB_BOSQUE_ISLA("posada08_salon.c"));
}

public int cmd_comer(string str)
{
	  object pl;

    if(!str) return 0;
    if(str == "engendro")
    {
        f_confirmar_comer();
        return 1;
    }
    else return 0;
}

public void f_confirmar_comer()
{
    input_to("f_comer_engendro", INPUT_PROMPT, "\n  ¿De veras quieres hacer eso?(si/no): ");
}

public int f_comer_engendro(string str)
{
    str = LOWER(str);

    if(str == "si" || str == "sí" || str == "s")
    {
        write("\nEn fin, como quieras. Coges un bote de la estantería, lo abres y sacas lo "
            "que hay dentro.\nTe comes un bichito.\n");
        say(CAP(TNAME) + " coge algo de la estantería y se lo come.\n");
//        TP->SetExplored();
        call_out("f_pobre_player", 2, TP);
    }
    else if(str == "no" || str == "n")
    {
        write("\nRecapacitas y dejas el bote donde estaba.\n");
    }
    else f_confirmar_comer();
    return 1;
}

public void f_pobre_player(object pl)
{
    pl->SetDieMsg("#jug# ha muerto a causa de una terrible indigestión.");
    pl->Die();
    return;
}
