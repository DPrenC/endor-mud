/****************************************************************************
Fichero: loca_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripci�n: una pueblerina un poco loca.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

public string f_mirar()
{
    return "Valzhana es una pueblerina de Nandor que no parece estar muy bien a juzgar "
        "por los movimientos sin sentido que hace y, m�s concretamente, por la cara "
        "desencajada que pone con sus muecas.\n Tiene los pelos revueltos y la ropa mal "
        "puesta, vieja y m�s sucia que el suelo que pisa.\n Poca gente sabe de ella, "
        "pues no se deja tratar mucho, aunque ciertamente todos la evitan  debido a su "
        "locura.\n\n Valzhana se acerca a tu cara y te susurra: ��Qu� miras "+
        CAP(TP->QueryName())+"?!, �Acaso tengo monos en la cara?\n";
}

public string f_chillar()
{
    if (TO->Fighting())
    {
        tell_room(MARH("nandor/calle11"), "Escuchas unos alarmantes gritos provenientes "
        "del porche del norte.\n");
    }else{
        tell_room(MARH("nandor/calle11"), "Te parece escuchar un leve canturreo "
        "proveniente del porche del norte.\n");
    }
    return "";
}

create()
{
    ::create();
    AddId(({"mujer", "humana", "loca", "pueblerina", "valzhana","Valzhana", "aldeana"}));
    SetStandard("Valzhana", "humano", ([GC_TORPE:18]), GENDER_FEMALE);
    SetShort("Valzhana la loca");
    SetLong(SF(f_mirar));
    SetAlign(-50);
    SetWeight(90000);
    SetSmell("Huele de mal como nunca hab�as olido antes.\n");
    AddSubDetail(({"ropa","ropas"}), "Son ropas andrajosas y asquerosamente sucias "
        "que las tiene puestas muy desordenadamente y fuera de sitio, no es de "
        "extra�ar que con alg�n movimiento se le vea algo que no deber�a de verse.\n");
    AddSubDetail("cara", "En su cara desencajada resaltan esos ojos, medio fuera de "
        "las �rbitas, que muestran una terrible mirada de odio.\n");
    AddSubDetail(({"pelo","pelos","melena","pelo revuelto"}), "Tiene todos los pelos "
        "revueltos escandalosamente, algunos le tapan parte de la cara. Seguro que no "
        "tiene 2 pelos dirijidos hacia el mismo sitio.\n");
    InitAChats(15,({"La loca chilla escandalosamente.\n",
        "Valzhana grita: descendiente de satanaaaaa�s.\n",
        "Valzhana intenta morderte la cara.\n", "Valzhana grita.\n",
        "Valzhana grita: vas a morir, vendr�s conmigo al infierno.\n",
        "La loca grita: �socorro, que han llegado los demonios!\n", SF(f_chillar)}));
    // Le pongo 20 porque al estar loca se supone que est� algo descontrolada.
    InitChats(20,({"Valzhana te mira y se r�e a carcajada: jajajajaaa!.\n",
        "Valzhana se balancea de un lado para otro sin mover los pi�s del sitio.\n",
        "valzhana acerca su cara a la tuya y hace muecas raras.\n",
        "Valzhana canturrea.\n",
        "Valzhana canturrea endemoniadamente.\n",
        "Valzhana dice: �locos, est�n todos locos!.\n",
        "Valzhana dice: no puede ser, no puede ser.\n",
        "Valzhana dice: vendr�n de la ultratumba y os llevar�n a todos, �a todos!\n",
        "Valzhana te dice: te conozco y s� lo que haces con esos ni�os.\n", SF(f_chillar)}));
    SetNoGet("Valzhana se tira a morderte la cara.\n");
    SetShrugMsg("Valzhana grita y se remueve con la mirada perdida.\n");
    AddQuestion("ni�os", "Valzhana dice: ni�os... que? ah...\n");
    SetCitizenship("nandor");
}

public void init()
{
    ::init();
    write("Valzhana te grita: �fuera de aqu�, esta es mi casa!\n");
    say("Valzhana le grita a " + CAP(TP->QueryName()) + " que se vaya que esta es su casa.\n",TP);
}
