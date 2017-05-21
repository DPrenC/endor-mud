/****************************************************************************
Fichero: loca_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripción: una pueblerina un poco loca.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

public string f_mirar()
{
    return "Valzhana es una pueblerina de Nandor que no parece estar muy bien a juzgar "
        "por los movimientos sin sentido que hace y, más concretamente, por la cara "
        "desencajada que pone con sus muecas.\n Tiene los pelos revueltos y la ropa mal "
        "puesta, vieja y más sucia que el suelo que pisa.\n Poca gente sabe de ella, "
        "pues no se deja tratar mucho, aunque ciertamente todos la evitan  debido a su "
        "locura.\n\n Valzhana se acerca a tu cara y te susurra: ¡¿Qué miras "+
        CAP(TP->QueryName())+"?!, ¿Acaso tengo monos en la cara?\n";
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
    SetSmell("Huele de mal como nunca habías olido antes.\n");
    AddSubDetail(({"ropa","ropas"}), "Son ropas andrajosas y asquerosamente sucias "
        "que las tiene puestas muy desordenadamente y fuera de sitio, no es de "
        "extrañar que con algún movimiento se le vea algo que no debería de verse.\n");
    AddSubDetail("cara", "En su cara desencajada resaltan esos ojos, medio fuera de "
        "las órbitas, que muestran una terrible mirada de odio.\n");
    AddSubDetail(({"pelo","pelos","melena","pelo revuelto"}), "Tiene todos los pelos "
        "revueltos escandalosamente, algunos le tapan parte de la cara. Seguro que no "
        "tiene 2 pelos dirijidos hacia el mismo sitio.\n");
    InitAChats(15,({"La loca chilla escandalosamente.\n",
        "Valzhana grita: descendiente de satanaaaaaás.\n",
        "Valzhana intenta morderte la cara.\n", "Valzhana grita.\n",
        "Valzhana grita: vas a morir, vendrás conmigo al infierno.\n",
        "La loca grita: ¡socorro, que han llegado los demonios!\n", SF(f_chillar)}));
    // Le pongo 20 porque al estar loca se supone que está algo descontrolada.
    InitChats(20,({"Valzhana te mira y se ríe a carcajada: jajajajaaa!.\n",
        "Valzhana se balancea de un lado para otro sin mover los piés del sitio.\n",
        "valzhana acerca su cara a la tuya y hace muecas raras.\n",
        "Valzhana canturrea.\n",
        "Valzhana canturrea endemoniadamente.\n",
        "Valzhana dice: ¡locos, están todos locos!.\n",
        "Valzhana dice: no puede ser, no puede ser.\n",
        "Valzhana dice: vendrán de la ultratumba y os llevarán a todos, ¡a todos!\n",
        "Valzhana te dice: te conozco y sé lo que haces con esos niños.\n", SF(f_chillar)}));
    SetNoGet("Valzhana se tira a morderte la cara.\n");
    SetShrugMsg("Valzhana grita y se remueve con la mirada perdida.\n");
    AddQuestion("niños", "Valzhana dice: niños... que? ah...\n");
    SetCitizenship("nandor");
}

public void init()
{
    ::init();
    write("Valzhana te grita: ¡fuera de aquí, esta es mi casa!\n");
    say("Valzhana le grita a " + CAP(TP->QueryName()) + " que se vaya que esta es su casa.\n",TP);
}
