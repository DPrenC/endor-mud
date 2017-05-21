#include "./path.h"
#include <colours.h>
#include <moving.h>
#include <properties.h>
#include <door.h>

inherit SHOP;

int go_north()
{
    if (present("llave1_s",TP) || present("llave2_n",TP) || present("llave3_l",TP) )
    {
        write("El posadero te para los pies.\n");
        say("El posadero detiene a "+TP->QueryName()+".\n");
        tell_room(TO,"El posadero dice: Eh, "+TP->QueryRace()+"! A donde vas con mi llave!? "
            "Tienes que\n\t"+TC_BOLD+"depositarla"+TC_NORMAL+" antes de salir!\n");
        return 1;
    }
    else return 0;
}

int go_south()
{
    if (present("llave1_s",TP) || present("llave2_n",TP) || present("llave3_l",TP) )
    {
        write("El posadero te para los pies.\n");
        say("El posadero detiene a "+TP->QueryName()+".\n");
        tell_room(TO,"El posadero dice: Eh, "+TP->QueryRace()+"! A donde vas con mi llave!? "
            "Tienes que\n\t"+TC_BOLD+"depositarla"+TC_NORMAL+" antes de salir.\n");
        return 1;
    }
    else
    {
        TP->move(CIUDAD+"baldur11",M_GO);
        return 1;
    }
}

int go_east()
{
    if (present("llave1_s",TP) || present("llave2_n",TP) || present("llave3_l",TP) )
    {
        write("El posadero te para los pies.\n");
        say("El posadero detiene a "+TP->QueryName()+".\n");
        tell_room(TO,"El posadero dice: Eh, "+TP->QueryRace()+"! A donde vas con mi llave!? "
            "Tienes que\n\t"+TC_BOLD+"depositarla"+TC_NORMAL+" antes de salir!\n");
        return 1;
    }
    else
    {
        TP->move(CIUDAD+"kilok1",M_GO);
        return 1;
    }
}

create()
{
    ::create();
    SetIntShort(TC_RED"Posada del Dragón Azul"TC_NORMAL);
    SetIntLong("El ambiente de la posada es bastante relajado. Una gran alfombra cubre todo el "
        "suelo desde la entrada hasta las escaleras que dan al segundo piso.\nDetrás del "
        "mostrador hay un cuadro bastante llamativo. Varias antorchas iluminan la habitación y "
        "un timbre decora el mostrador.\n");
    SetIntBright(70);
    SetIndoors(1);
    SetLocate("ciudad de Kha-annu");
    AddArticle(OTRO("llave1"),REFRESH_REMOVE,1);
    AddArticle(OTRO("llave2"),REFRESH_REMOVE,1);
    AddArticle(OTRO("llave3"),REFRESH_REMOVE,1);
    RemoveDustbin();
    SetSell(0);
    CanShow(0);
    SetAppraise(0);
    SetIdentify(0);
    AddDetail(({"alfombra","gran alfombra"}),"Cubre todo el suelo y está decorada con rombos y "
        "figuras geométricas.\n");
    AddDetail(({"escalera","escaleras"}),"Las escaleras llevan al segundo piso y están "
        "construidas en piedra.\n");
    AddDetail(({"mostrador"}),"Tallado en la misma roca de la montaña, se ve desgastado por "
        "el paso del tiempo.\n");
    AddDetail(({"cuadro"}),"Es un magnífico dibujo que representa un dragón azul descansando "
        "en un hermoso lago con un bosque espeso a su espalda.\n");
    AddDetail(({"timbre"}),"Es un pequeño timbre que puedes usar para llamar la atención del "
        "encargado.\n");
    AddDetail(({"antorcha","antorchas"}),"Decoran las paredes e iluminan la habitación.\n");
    AddDetail(({"pared","paredes"}),"De piedra, aprovechando ciertas cuevas de la Montaña de "
        "Kha-annu.\n");
    AddExit("norte",CIUDAD+"grimly11");
    AddExit("arriba","posada1");
    AddExit("sur",SF(go_south));
    AddExit("este",SF(go_east));
    AddDoor("norte","la puerta de la calle",
        "Es una puerta de madera, sencilla pero robusta.\n",
        ({"puerta","puerta de calle","puerta de la calle"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_DEFAULT_IN_RESET:1]));
    SetLocate("ciudad de Kha-annu");
    SetShopkeeper(PNJ("posadero"));
}

init() {
   ::init();
    add_action("go_north","n",1);
    add_action("Devuelta","depositar");
    add_action("Devuelta","devolver");
    add_action("Devuelta","entregar");
    add_action("Venta","vender");
    add_action("Timbre","usar");
    add_action("Timbre","tocar");
    add_action("Timbre","llamar");
    add_action("Timbre","pulsar");
    add_action("Timbre","apretar");
    add_action("Timbre","golpear");
    add_action("Matar","magia");
    add_action("Matar","matar");
}

Devuelta(string str)
{
    object ob;
    if (str != "llave" && (present("llave1_s",TP) || present("llave2_n",TP) || present("llave3_l",TP)) )
    {
        write("¿Depositar qué?\n");
        return 1;
    }
    if (!present("llave",TP)) return 0;
    if (ob=present("llave1_s",TP))
    {
        ob->remove();
        if(ob) destruct(ob);
        write("Entregas la llave al posadero, y este la guarda en su bolsillo.\n");
        say(TP->QueryName()+" entrega una llave al posadero.\n");
        tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve cuando quieras.\n");
        TO->AddArticle(OTRO("llave1"),REFRESH_REMOVE,1);
        return 1;
    }
    if (ob=present("llave2_n",TP))
    {
        ob->remove();
        if (ob) destruct(ob);
        write("Entregas la llave al posadero, y este la guarda en su bolsillo.\n");
        say(TP->QueryName()+" entrega una llave al posadero.\n");
        tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve cuando quieras.\n");
        TO->AddArticle(OTRO("llave2"),REFRESH_REMOVE,1);
        return 1;
    }
    if (ob=present("llave3_l",TP))
    {
           ob->remove();
        if (ob) destruct(ob);
        write("Entregas la llave al posadero, y este la guarda en su bolsillo.\n");
        say(TP->QueryName()+" entrega una llave al posadero.\n");
        tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve cuando quieras.\n");
        TO->AddArticle(OTRO("llave3"),REFRESH_REMOVE,1);
        return 1;
    }
}

Matar(string str)
{
    if (str == "posadero" || str == "ashurak" || str == "el posadero" ||
        str == "al posadero" || str == "Ashurak" || str == "Ashurak, el posadero")
    {
        write("No sería muy inteligente matar al posadero en SU posada, podría traerte "
            "complicaciones.\n");
        return 1;
    }
    else return 0;
}

Timbre(string str)
{
    if (str != "timbre") 
    {
    	   write("¿Qué quieres hacer con eso?.\n");
    	   return 1;
    }
    say(TP->QueryName()+" toca el timbre que hay sobre el mostrador.\n");
    if (QueryShopkeeper())
    {
        write("Aporreas el timbre que hay sobre el mostrador.\n");
        tell_room(TO,"El posadero dice: ¡Hey, "+capitalize(TP->QueryRace())+", Estoy aquí! "
            "¿Qué deseas?\n");
        return 1;
    }
    else
    {
        write("Aporreas el timbre que hay sobre el mostrador, pero nadie acude a atenderte.\n");
        return 1;
    }
}

int Venta(string str)
{
    if (!str)
    {
        write("¿Vender qué?\n");
        return 1;
    }
    if (QueryShopkeeper())
    {
        write("Intentas vender tu "+str+" al posadero.\n");
        say(TP->QueryName()+" intenta vender algo al posadero.\n");
        tell_room(TO,"El posadero dice: No, "+TP->QueryRace()+". No suelo comprar nada.\n");
        return 1;
    }
    else
    {
        write("No ves aquí a nadie para venderle nada.\n");
        return 1;
    }
}

