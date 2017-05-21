/****************************************************************************
Fichero: tuerto.c
Autor: Buh
Fecha: 03/09/2006
Descripción: Okur el tuerto dueño de la taberna espada negra
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
public string f_esta_esclavo();
public string f_pedir_ayuda();
inherit NPC;

create()
{
    ::create();
    AddId(({"Okur", "okur el tuerto", "Okur el tuerto", "okur", "tuerto", "amo"}));
    SetStandard("Okur", "orco", ([GC_LUCHADOR:60]), GENDER_MALE);
    SetShort("okur el tuerto");
    SetLong(
        "Okur es un orco de aspecto brutal. Su rostro de nariz porcina y sobresalientes"
        " colmillos, se adorna con una enorme cicatriz que le cubre la mitad derecha de"
        " la cara, en cuyo lado destaca la ausencia de la oreja y un mugriento parche que"
        " le cubre el ojo diestro.\n  Su cuerpo denota la ausencia de aventuras, puesto"
        " que una prominente barriga cuelga fláccida por encima de su cinturón enjoyado."
        " Gusta de adornar su peculiar cara y cuerpo con todo tipo de abalorios de poca"
        " monta: Pañuelos púrpuras en la cabeza, aros de oro en su única oreja, collares,"
        " medallones, etc.\n");
    SetAlign(-100);
    SetWeight(100000);
    SetSmell("Huele a orco que apesta.\n");
    AddSubDetail(({"cara", "nariz", "cicatriz", "oreja", "colmillos", "rostro"}),
        "Tiene la cara hecha un mapa con esa oreja que le falta, esos colmillos raros,"
        " el parche en el ojo, la curiosa cicatriz, y todo eso sumado a lo feo que "
        "ya de por sí es.\n");
    AddSubDetail("barriga", "Una inmensa barriga le da apariencia de barril.\n");
    AddSubDetail(({"adornos", "pendientes", "aros", "pañuelos", "pañuelo",
        "pañuelos purpuras", "colgantes", "medallones"}), "Distintos adornos lucen su"
        " estampa.\n");
    AddSubDetail(({"cinturón", "cinturon"}), "El cinturón es lo de mayor valor que lleva"
        " encima, distintas joyas incrustadas y una evilla de oro lo hacen un objeto"
        " interesante.\n");
    AddSubDetail(({"ojo", "ojo diestro", "parche"}), "El ojo derecho lo tiene tapado por"
        " un mugriento parche, el otro ojo parece estar bien.\n");
    InitAChats(15, ({"Okur grita: te voy a matar.\n", "Okur grita: ¡muere maldición!.\n",
        "Con el movimiento del combate, los adornos de Okur se mueven descontroladamente.\n",
        "Parece que a Okur le faltan reflejos con ese ojo tapado.\n", SF(f_pedir_ayuda)}));
    InitChats(3, SF(f_esta_esclavo));
    AddQuestion(({"esclavo", "sarnoso", "Sarnoso", "goblin"}),
        "Okur te dice: hace ya algunos años que lo tengo a mi servicio, ahora con la"
        " taberna parece que le hace más ilusión que las tareas que llevaba antes, pero"
        " sigue igual de torpe, es terriblemente inútil.\n Cualquier día de estos lo"
        " degüello y me busco otro esclavo.\n");
    AddQuestion(({"oreja", "ojo", "parche", "cicatriz"}), "Okur te dice molesto: no hagas"
        " tantas preguntas y consume algo, que para eso estamos aquí.\n", 1);
    AddQuestion(({"adornos", "colgantes", "aros", "pañuelos", "colgantes"}),
        "Okur te dice poniendo mala cara: ¿Qué le pasa a mis adornos?, si no te gustan no"
        " los mires, no estoy aquí para entretener a los impertinentes.\n", 1);

    AddItem(WEAPON, REFRESH_REMOVE, 
            ([P_WEAPON_TYPE: WT_LATIGO, P_WC:3, P_SIZE:P_SIZE_MEDIUM, P_MATERIAL:M_CUERO,
            P_ADS:({"un", "elástico", "elastico"}), P_IDS:({"latigo", "látigo", "arma"}),
            P_SHORT:"un             látigo", P_LONG: "Un latigo de tres colas con unas bolitas de plomo en la punta.\n",
            P_RESET_QUALITY:90]), SF(wieldme));
}

public string f_esta_esclavo()
{
    string *con_esclavo =
    ({"Okur grita: ¡sarnoso sirveme una cerveza!.\n",
    "A Sarnoso se le cae una jarra al suelo y Okur le grita: ¡maldito esclavo torpe,"
    " no vales para nada!.\n",
    "Okur golpea fuertemente el mostrador con su garra y grita: ¡sucio goblin, recoje un"
    " poco que lo tienes todo hecho una pozilga!.\n",
    "Okur murmura: maldito esclavo inútil.\n"});
    string *sin_esclavo =
    ({"Okur dice: maldita sea, ahora me tengo que buscar otro esclavo.\n",
"Okur murmura: ahora a ver quien demonios me lleva la taberna.\n"});
//buscamos al esclavo
        object ob, env;
    env = environment();
    ob = present("esclavo",env);
    if (ob && living(ob))
    {
        return con_esclavo[random(sizeof(con_esclavo))];
    }
    else
    {
        return sin_esclavo[random(sizeof(sin_esclavo))];
    }
}

public string f_pedir_ayuda()
{
    object ob, env;
    env = environment();
    ob = present("esclavo",env);
    if (ob && living(ob))
        return "Okur grita: ¡maldito esclavo inútil, ataca!.\n";
    return "";
}
