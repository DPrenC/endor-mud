/********************
Fichero: theull.c
Descripci�n: artesano de cuero para la tienda de Crowy.
Autor: Lug y Yalin.
Fecha: 20/08/2007
********************/
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <money.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

public string informa()
{
    if (present("cinturon_gaena",TP)) return "Theull sonr�e satisfecho diciendo: �Precioso, "
        "verdad? No es por nada, pero hice un buen trabajo.\n";
    if (present("piel_gaena",TP)) return "Theull se�ala la piel de serpiente que llevas, y "
        "dice: S�, con esa piel podr�a hacerte un cintur�n como el que buscas. D�mela, y lo "
        "har� en un momento.\n";
        return "Theull mueve la cabeza y te dice: No s�, tal vez tenga alguno, podr�as consultar "
        "la lista.\n";
}

public string informa2()
{
    if (present("piel_gaena",TP)) return "Theull sonr�e y dice: S�, es muy buena para cinturones...\n";
    return "Theull suspira diciendo: Lo siento, ahora mismo, todas las pieles que tengo son "
    "para encargos.\n";
}

void recoger_(object piel, object pl)
{
    if (!pl) return;
    if (member(piel->QueryIds(),"piel_gaena") >= 0)
    {
        if (MONEY_LIB->QuerySomeonesValue(pl) < 2500)
        {
            write("Theull mueve negativamente la cabeza diciendo: Cobro 2500 monedas de cobre "
                "por hacer un cintur�n como �se, esta piel es dif�cil de trabajar. Vuelve "
                "cuando tengas el dinero.\nA continuaci�n te devuelve la piel y sigue con sus "
                "quehaceres.\n");
            say("Theull refunfu�a algo sobre el dinero, y le devuelve la piel a "+
                capitalize(pl->QueryName())+".\n",pl);
            piel->move(pl);
            return;
        }
        write("Theull te sonr�e, coge la piel de pit�n y se pone a trabajar en ella.\nEsperas "
            "un buen rato, mientras matas el tiempo contemplando los productos del artesano...\n"
            "Por fin, Theull se te acerca tendi�ndote un cintur�n, y te dice: Bueno, aqu� lo "
            "tienes. �Es bonito, verdad?\nY..., �realmente lo es!\n");
        say("Theull se pone a trabajar en ella, mientras "+capitalize(pl->QueryName())+" se "
            "distrae admirando los art�culos expuestos.\nAl cabo de un rato, Theull se le "
            "acerca, le entrega un cintur�n dici�ndole: Bueno, aqu� lo tienes. �Es bonito, "
            "verdad? Y a juzgar por la cara de "+capitalize(pl->QueryName())+" as� debe ser.\n",pl);
        string *precio;
        object cnt;
        precio = MONEY_LIB->PayValueString2(pl, 2500, 0, "por la elaboraci�n de un cintur�n");
        write(precio[0]);
        say(precio[1],pl);
        piel->remove();
        cnt = clone_object(OTRO("cinturon"));
        cnt->move(pl);
        return;
    }
    write("Theull mira lo que acabas de darle, y te lo devuelve diciendo: Hmmm, gracias, pero "
        "yo no necesito "+piel->QueryShort()+". Ya soy muy viejo y vivo bien con lo que "
        "tengo.\nY con una sonrisa, te lo devuelve.\n");
    say("Theull mira lo que acaba de recibir, y se lo devuelve a "+capitalize(pl->QueryName())+
        " diciendo: Gracias, pero no lo necesito. Ya soy muy viejo, y vivo bien con lo que "
        "tengo.\n",pl);
    piel->move(pl);
    return;
}

create()
{
    ::create();
    seteuid(getuid());
    SetStandard("theull","humano",10,GENERO_MASCULINO);
    SetName("Theull");
    AddId(({"theull","Theull","humano","viejo","artesano"}));
    SetShort("Theull el artesano");
    SetLong("Theull es un humano viejo y pac�fico.\nEn otros tiempos fu� cazador, y a�n "
        "conserva los r�pidos reflejos y mirada vigilante propios de su antigua afici�n.\n"
        "Ahora, quiz� por su vieja costumbre de hacerse las ropas con las pieles de sus presas, "
        "sigue trabajando el cuero, y, seg�n dicen sus clientes, con muy buen gusto y mano "
        "h�bil.\n");
    SetAlign(500);
    AddQuestion(({"cintur�n","cinturon"}),SF(informa),1);
    AddQuestion(({"piel","piel de serpiente"}),SF(informa2),1);
    SetShrugMsg("Theull mueve la cabeza murmurando: Pues ni idea.\n");
    InitChats(15,({
        "Theull raspa una piel con la cuchilla.\n",
        "Theull te sonr�e diciendo: Si buscas algo bueno de cuero, est�s en el sitio apropiado.\n",
        "Theull te pregunta: �Buscas algo en particular?\n",
        "Theull repasa cuidadosamente la costura de unas piezas de piel.\n"
    }));
}

void notify_enter(mixed from,int method,mixed extra)
{
  	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
