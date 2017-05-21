/*****************************************************************************************
 ARCHIVO:       posada11_taller.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCI�N:   Posada del Unicornio Azul. Taller.
 COMENTARIOS:   Punto de exploraci�n, si el player se come un engendro, muere, poesito.
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
    SetIntLong("Te hallas en un s�tano bastante ca�tico. En las paredes, expuestos en "
        "vitrinas, colgados en ristras del techo y esparcidos por todas partes "
        "distingues variados productos. En un rinc�n humea un caldero colocado sobre una "
        "especie de  tr�pode al calor de la lumbre.\n");
    AddDetail(({"pared", "paredes"}), "Son de piedra, dispuestos en multitud de "
        "anaqueles, se observan todo tipo de frascos, recipientes, alambiques y "
        "utensilios de diversas formas y tama�os.\n");
    AddDetail("productos", "Hay potingues y mejunjes metidos en frascos. Tambi�n hay "
        "animalillos conservados en l�quido, hierbas y plantas.\n");
    AddDetail(({"anaqueles", "vitrinas"}), "Son de madera y no tienen puerta.\n");
    AddDetail(({"techo", "ristras"}), "Puedes ver ajos, pieles de animales y una especie "
        "de plasta s�lida metida en una red.\n");
    AddDetail(({"plasta", "plasta s�lida", "plasta solida"}), "Son como tripas de bichos "
        "apelmazadas.\n");
    AddDetail("ajos", "Son tan grandes como cabezas de ardilla.\n");
    AddDetail(({"pieles", "pieles de animales"}), "Est�n secas.\n");
    AddDetail(({"caldero", "caldero humeante"}), "Humea y borbotea sin cesar.\n");
    AddDetail(({"tripode", "tr�pode"}), "Es un armaz�n de tres patas.\n");
    AddDetail("lumbre", "Es un fueguito de lo m�s corriente.\n");
    AddDetail(({"recipientes", "frascos"}), "Al menos est�n etiquetados: lenguas y ojos "
        "de sapo, u�as de cocodrilo, dientes de conejo, alas de murci�lago, hojas de "
        "marihuana, agua del arroyo negro, cascabel de serpiente...\n");
    AddDetail("animalillos", "Puedes ver desde peque�os ratones de campo hasta engendros "
        "similares a conejos.\n");
    AddDetail(({"liquido", "l�quido"}), "Es verde, en �l flotan sustancias m�s espesas "
        "y oscuras.\n");
    AddDetail("engendros", "Son unos bichos deformes, �ser�n comestibles?\n");
    AddDetail("sustancias", "Son, ... pues eso, espesas y oscuras.\n");
    AddDetail(({"hierbas", "plantas"}), "Tambi�n est�n metidas en frascos etiquetados: "
        "mandr�gora, estramonio, belladona y bele�o negro.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Una mezcla de olores f�tidos y ajo.\n");
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
    input_to("f_comer_engendro", INPUT_PROMPT, "\n  �De veras quieres hacer eso?(si/no): ");
}

public int f_comer_engendro(string str)
{
    str = LOWER(str);

    if(str == "si" || str == "s�" || str == "s")
    {
        write("\nEn fin, como quieras. Coges un bote de la estanter�a, lo abres y sacas lo "
            "que hay dentro.\nTe comes un bichito.\n");
        say(CAP(TNAME) + " coge algo de la estanter�a y se lo come.\n");
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
    pl->SetDieMsg("#jug# ha muerto a causa de una terrible indigesti�n.");
    pl->Die();
    return;
}
