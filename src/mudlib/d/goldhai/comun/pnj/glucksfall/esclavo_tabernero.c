/****************************************************************************
Fichero: esclavo_tabernero.c
Autor: Buh
Fecha: 03/09/2006
Descripción: el esclavo del dueño de la taberna Espada negra.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
public string f_pregunta_amo();
inherit NPC;

create(){
    ::create();
    AddId(({"Goblin", "goblin", "sarnoso", "torpe", "sucio", "esclavo", "tabernero"}));
    SetStandard("Sarnoso", "orco", ([GC_TORPE:20]), GENDER_MALE);
    SetShort("sarnoso el tabernero");
    SetLong("Sarnoso es un Góblin, capturado por el Orco Okur cuando este era aún pirata."
        " Es un ser tan estúpido como sucio, su desgreñada forma de andar encorvado y su"
        " verdosa piel hacen que el apodo que los parroquianos de la taberna le pusieron"
        " en un principio, le quede idóneo.\n  Entre sus aficiones destacan hurgarse la"
        " nariz para seguidamente llevarse los dedos a la boca, y tropezar con cualquier"
        " cosa que se encuentre por la taberna arrojando jarras y platos por los aires.\n");
    SetAlign(-40);
    SetWeight(60000);
    SetSmell("Su olor no te sorprende, teniendo en cuenta que va asquerosamente sucio.\n");
    InitAChats(10, ({"Sarnoso se cae al suelo, al tropezar consigo mismo, pero se "
    "levanta enseguida.\n", "Sarnoso grita: ¡yo no he hecho nada!.\n"}));
    InitChats(2, ({"Sarnoso se hurga la nariz.\n",
        "A Sarnoso se le cae un vaso al suelo.\n",
        "Sarnoso parece que te mira, pero en realidad está mirando al suelo.\n"}));
    AddQuestion(({"amo", "orco", "tuerto", "okur"}), SF(f_pregunta_amo));

}

public string f_pregunta_amo(){
    object ob, env;
    env = environment();
    ob = present("tuerto",env);
    if (ob && living(ob))
    return "Sarnoso agacha la cabeza, posiblemente por la presencia de su amo.\n";
    return "Sarnoso dice temoroso: Okur es muy malo, me trata con maldad.\n";
}

