/***
Fichero: celda5.c
Autor: kastwey@simauria
Descripción: Celda del sótano de celdas del puesto de guardias de Siempreunidos.
Creación: 06/12/2004
07/12/2004: Añado la posibilidad de trepar o subir...
23/12/2004
Me dedico a ponerle algunas pistillas más a la cárcel, que sorgina dice que le hacen falta.
24/02/2005: corrijo un par de bugs y pongo algunos comandos más
28/02/2005: simplifico un montón y añado más cosillas
***/

#include "path.h"
#include <skills.h>
#include <moving.h>


#define POS_COGER ({"musgo del techo","musgo de esquina",\
  "musgo de la esquina","musgo de techo","el musgo del techo","el musgo de techo",\
  "ganzua","ganzúa","ganzua del techo","ganzúa del techo","ganzua de techo",\
  "ganzúa de techo","musgo"})
#define POS_TREPAR ({"al armazón","armazon","armazón","por armazon",\
    "por armazón","por el armazon","por el armazón","a las latas",\
    "a los recipientes","lata","cama","camastro","recipiente"})

inherit HAB_PUESTO("puesto_guardias/celdas/celdas_base");

int cmd_amontonar(string str);
int cmd_coger(string str);
int cmd_trepar(string str);
int desarmar_armazon(object pl);
int cmd_bajar();
int pGanzua, pMusgo, fases_armazon;



create()
{
    ::create();
    SetIntLong(W("Te encuentras en una húmeda celda, de no más de 1 metro cuadrado.\n"
    "El techo está muy alto, a unos tres metros del suelo, lo que no elimina en ningún modo la sensación de claustrofobia que te produce esta pequeña estancia.\n"
    "Como único elemento decorativo puedes ver un camastro en un rincón.\n"
    "También puedes ver una inscripción en una de las paredes.\n"));
    pGanzua = 1;
    pMusgo = 1;
    AddDetail(({"pared", "suelo", "techo"}), W("Tanto las paredes como el techo, están recubiertos de una gruesa capa de musgo debido a la humedad del lugar.\n"
    "Al fijarte mejor, te das cuenta que en una esquina del techo hay más cantidad de musgo de lo normal...\n"));
    AddDetail(({"esquina","esquina del techo","esquina de techo"}),"En una de las esquinas del techo, observas que hay más musgo de la cuenta, como si hubiese sido puesto ahí para tapar algo...\n");
    AddDetail(({"instripción", "inscripcion", "pared", "muro"}), W("En una de las paredes puedes leer la siguiente inscripción:\n"
    "En lo más alto de esta celda encontrarás la clave hacia la libertad.\n"));
    AddReadMsg(({"inscripcion","inscripción","inscripción de pared","inscripcion de pared"}),"En lo más alto de esta celda, encontrarás la clave hacia la libertad.\n");
    AddExit("sur", HAB_PUESTO("puesto_guardias/celdas/pasillo5"));
    AddRoomCmd(({"apilar","amontonar", "encarrar", "encajar", "superponer", "unir"}), "cmd_amontonar");
    AddRoomCmd(({"trepar", "subir", "escalar"}), "cmd_trepar");
    AddRoomCmd(({"bajar", "abajo"}), "cmd_bajar");
    AddRoomCmd("coger", "cmd_coger");
}

public string QueryIntLong()
{
    if (TP->QueryAttribute("sobre_armazon")) return W("Miras hacia abajo para hacerte una idea del lugar en el que estás... Lo único que te da tiempo a apreciar antes de preferir mirar al techo para no comenzar a gritar, es una celda de pequeñas dimensiones, y el armazón sobre el que estás subid" + AO + ".\n");
    if (present("recipiente_puesto_celdas")) return ::QueryIntLong();
    return W("Te encuentras en una húmeda celda, de no más de 1 metro cuadrado.\n"
    "Como único elemento decorativo puedes ver un camastro en un rincón.\n"
    "También puedes ver una inscripción en una de las paredes.\n");
}

int cmd_amontonar(string str)
{
    int i;
    object armazon;
    if (!str || (str != "bidones" && str != "recipientes"
      && str != "cubos" && str != "cacharros" && str != "latas"))
      {
          return notify_fail(capitalize(query_verb()) + " qué?\n");
      }

    if (TP->QueryAttribute("sobre_armazon")) return 0;
    if (present("recipiente_puesto_celdas 6", TO))
    {
        write(W("Comienzas a colocar los recipientes uno encima del otro.\n"
            "Una vez están los seis recipientes amontonados, te retiras y "
            "compruebas el resultado. Ahora puedes ver un armazón de unos "
            "tres metros de alto en mitad de la habitación.\n"));
        say(W(capitalize(TP->QueryName()) + " comienza a coger recipientes y "
            "a amontonarlos uno encima del otro.\n"
            "Cuando termina, se aleja unos pasos y contempla el resultado. "
            "En una de las esquinas de la estancia, se levanta ahora un armazón de tres metros de alto.\n"), TP);
        for (i=6;i--;)
            present("recipiente_puesto_celdas", TO)->remove();
        armazon = clone_object(OBJETO + "otro/faeria/armazon");
        armazon->move(TO,M_SILENT);
        return 1;
    }
    else if (!present("recipiente_puesto_celdas", TO)) return notify_fail("No ves " + str + " para amontonar.\n");
    else return notify_fail("Con los recipientes que tienes, no podrás llegar hasta el techo.\n");
}

int cmd_coger(string str)
{
    object musgo;
    if (!str) return 0;
    if (member (POS_COGER,str) < 0) return 0;
    if (str == "musgo")
    {
      return notify_fail ("Coger musgo de donde?\n",NOTIFY_NOT_VALID);
    }
    if (!(str == "ganzua" || str == "ganzúa" || str == "ganzua del techo" || str == "ganzúa del techo" || str == "ganzúa de techo" || str == "ganzua de techo"))
    {
        if (present("armazon_puesto_celdas", TO))
        {
            if (present("armazon_puesto_celdas", TO)->QueryUsandose()
                && present("armazon_puesto_celdas", TO)->QueryUsandose() != TP)
            {
                return notify_fail(W("Cuando bas a subir al armazón para coger "
                    "el musgo del techo, te das cuenta de que " +
                    capitalize(present("armazon_puesto_celdas", TO)->
                    QueryUsandose()->QueryName()) + " ya está encima... "
                    "Sería imposible de que ese armatoste soportara los dos pesos.\n"),NOTIFY_NOT_VALID);
            }
        }
        else
        {
            return notify_fail(W("El techo está demasiado alto como para que "
                "puedas coger musgo de ahí.\n"),NOTIFY_NOT_VALID);
        }
        if (!TP->QueryAttribute("sobre_armazon"))
        {
            return notify_fail(W("Antes de coger el musgo deberías trepar al "
                "armazón...\n"),NOTIFY_NOT_VALID);;
        }
        if (!pMusgo)
        {
            return notify_fail(W("Miras la esquina en busca de algo más de "
                "musgo para arrancar, pero tras varios intentos, lo único "
                "que consigues es mancharte de verde.\n"),NOTIFY_NOT_VALID);
        }
        write("Coges algo de musgo del techo.\n");
        say(W(capitalize(TP->QueryName()) + " coge algo de musgo del techo.\n"), TP);
        musgo = clone_object("/obj/herb");
        musgo->SetShort("un poco de musgo");
        musgo->SetLong("Es un poco de verde musgo.\n");
        musgo->AddId("musgo");
        musgo->AddId("musgo_puesto_celdas");
        musgo->SetClass("saciante");
        pMusgo = 0;
        if (musgo->move(TP) != ME_OK)
        {
            write ("El musgo se te resbala de entre los dedos y cae al suelo.\n");
            say("Sin poder evitarlo, el musgo se le resbala de entre los dedos y cae al suelo.\n", TP);
            musgo->move(TO);
        }
        RemoveDetail("techo");
        AddDetail(({"techo"}), "Al mirar al techo, ves como en la parte en la que el musgo ha sido quitado, se ve algo brillante... Parece una especie de ganzúa.\n");
        return 1;
    }
    else
    {
        if (TP->QueryAttribute("sobre_armazon"))
        {
            object ganzua;
            if (!pGanzua) return 0;
            if (pMusgo) return 0;
            write("Tiras de la ganzúa incrustada en el techo y consigues sacarla.\n");
            say(W(capitalize(TP->QueryName()) + " tira de la ganzúa incrustada en el techo, hasta que consigue sacarla.\n"), TP);
            ganzua = clone_object("/obj/ganzua");
            ganzua->AddId("ganzua_puesto_celdas");
            pGanzua = 0;
            RemoveDetail("techo");
            AddDetail("techo", "Cuando miras al techo, ves que en una de las esquinas hay un hueco sin musgo.\n");
            if (ganzua->move(TP) != ME_OK)
            {
                write("Sin poder evitarlo, la ganzúa se te resbala y cae al suelo.\n");
                say(W("Sin poder evitarlo, a " + capitalize(TP->QueryName()) + " se le resbala la ganzúa que cae al suelo.\n"), TP);
                ganzua->move(TO);
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


public int prevent_leave(mixed dest, int method, mixed extra)
{
    if (!PO || !PO->QueryIsPlayer()) return ::prevent_leave(dest, method, extra);
    if (  PO->QueryAttribute("sobre_armazon") && present("armazon",TO))
    {
        write("¿No crees que antes de salir de aquí deberías bajar del armazón?\n");
        return ME_NO_LEAVE;
    }
    else
    {
        if (TP->QueryAttribute("sobre_armazon")) TP->RemoveAttribute("sobre_armazon");
        return ::prevent_leave(dest, method, extra);
    }
}

int cmd_bajar()
{
    if (TP->QueryAttribute("sobre_armazon"))
    {
        object recipiente;
        int i;
        write("Con cuidado, comienzas a bajar del armazón. Sin embargo, cuando estás a punto de tocar el suelo, el armazón termina de desarmarse y los recipientes te caen encima.\n");
        say(W(capitalize(TP->QueryName()) + " comienza a bajar del armazón.\n"
        "Cuando está a punto de tocar el suelo, los recipientes terminan de desarmarse cayéndoles encima.\n"), TP);
        TP->RemoveAttribute("sobre_armazon");
        TP->Defend(10);
        RemoveRoomCmd("bajar");
        present("armazon_puesto_celdas", TO)->remove();
        for (i=6;i--;)
        {
            recipiente = clone_object(OBJETO + "otro/faeria/recipiente");
            recipiente->SetShort("un recipiente aplastado");
            recipiente->SetLong("Es un recipiente metálico que está medio aplastado.\n");
            recipiente->RemoveId("recipiente_puesto_celdas");
            recipiente->move(TO);
        }
        while (find_call_out("desarmar_armazon") != -1)
        {
            remove_call_out("desarmar_armazon");
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int desarmar_armazon(object pl)
{
    if (!pl)
    {
        fases_armazon = 0;
        while (find_call_out("desarmar_armazon") != -1)
        {
            remove_call_out("desarmar_armazon");
        }
        return 1;
    }
    fases_armazon++;
    switch(fases_armazon)
    {
        case 1:
            tell_object(pl, "El armazón comienza a crujir... Yo de ti intentaría hacer lo que sea que haces en lo alto de 6 latas apiladas y me bajaría cuanto antes.\n");
            say(W("El armazón comienza a crujir.\n" + capitalize(pl->QueryName()) + " mira hacia abajo con cara de susto.\n"), pl);
            call_out("desarmar_armazon", 5+random(6), pl);
            break;
        case 2:
            tell_object(pl, "El armazón continúa crujiendo. Sientes como se tambalea bajo tus pies.\n");
            say(W("El armazón sigue crujiendo. Cuando lo miras, ves como una de los recipientes de abajo, comienza a combarse bajo el peso de " + capitalize(pl->QueryName()) + ".\n"), pl);
            call_out("desarmar_armazon", 5+random(6), pl);
            break;
        case 3:
            tell_object(pl, W("Escuchas un crrluuunch! y miras hacia abajo a tiempo de ver como uno de los recipientes termina de aplastarse bajo tu peso.\n"
            "El armazón comienza a inclinarse peligrosamente, perdiendo la poca estabilidad que le quedaba.\n"));
            say(W("Escuchas un crluuunch! y miras el armazón, a tiempo de ver como el recipiente de abajo termina de doblarse bajo el peso de " + capitalize(pl->QueryName()) + ". El armazón se inclina cada vez más, a punto de perder la poca estabilidad que aún le queda.\n"), pl);
            call_out("desarmar_armazon", 5+random(6), pl);
            break;
        case 4:
            object recipiente;
            int i;
            tell_object(pl, "Finalmente, escuchas un estrépito bajo tus pies, mientras el armazón termina de desarmarse. Sin que puedas hacer nada, caes al suelo entre un montón de recipientes aplastados.\n");
            say(W("De pronto, escuchas un estrépito. Miras al armazón y ves como se desmorona bajo los pies de " + capitalize(pl->QueryName()) + ", que cae al suelo entre recipientes destrozados.\n"), TP);
            pl->Defend(10+random(11));
            pl->RemoveAttribute("sobre_armazon");
            present("armazon_puesto_celdas", TO)->remove();
            for (i=6;i--;)
            {
                recipiente = clone_object(OBJETO + "otro/faeria/recipiente");
                recipiente->SetShort("Un recipiente aplastado");
                recipiente->SetLong("Es un recipiente metálico. Está totalmente alastado.\n");
                recipiente->move(TO);
            }
            break;
    }
    return 1;
}

int cmd_trepar(string str)
{
    if (member(POS_TREPAR,str) < 0) return 0;
    if (str == "lata" || str == "recipiente")
    {
    	  if (present("recipiente",TO)) return write("Te subes a un recipiente y luego miras al techo, del que aún te separa una distancia más que considerable. Te bajas del recipiente.\n"),1;
        else return write("No ves " + str + " por donde subir.\n"),1;
    }
    else if (str == "cama" || str == "camastro")
    {
    	  return write("Te subes a la cama. Comienzas a dar saltitos a ver si así eres capaz de alcanzar el techo. Tras un rato, decides dejar de hacer el idiota y bajas al suelo.\n"),1;
    }
   if (!present("armazon_puesto_celdas", TO)) return write(W("No ves " + str + " por donde trepar.\n")), 1;
    if (TP->QueryAttribute("sobre_armazon")) return write("Ya estás arriba... No puedes trepar más.\n"), 1;
    if (present("armazon_puesto_celdas", TO)->QueryUsandose()) return write(W("Cuando vas a trepar al armazón, te das cuenta de que " + present("armazon_puesto_celdas", TO)->QueryUsandose()->QueryName() + " ya está en lo alto... Seguramente si intentas trepar tú también lo que consigas es que se desmonte la estructura.\n")), 1;
    if (TP->UseSkill(HAB_TREPAR) < 30)
    {
        object recipiente;
        int i;
        write("Comienzas a escalar por el armazón. Sin poder evitarlo, pierdes pie y caes al suelo, mientras el armazón se desmonta por completo.\n");
        say(W(capitalize(TP->QueryName()) + " comienza a trepar por el armazón pero pierde pie y cae al suelo, junto con los recipientes que formaban el armazón, que terminan desarmándose.\n"), TP);
        TP->Defend(5+random(6));
        present("armazon_puesto_celdas", TO)->remove();
        for (i=6;i--;)
        {
            recipiente = clone_object(OBJETO + "otro/faeria/recipiente");
            recipiente->move(TO);
        }
        return 1;
    }
    else
    {
        write("Comienzas a trepar por los salientes de los recipientes, hasta que por fin llegas arriba.\n");
        say(W(capitalize(TP->QueryName()) + " comienza a trepar por el armazón agarrándose a los salientes que encuentra... Por fin consigue llegar arriba.\n"), TP);
        present("armazon_puesto_celdas", TO)->SetUsandose(TP);
        TP->SetAttribute("sobre_armazon", 1);
        present("armazon_puesto_celdas", TO)->SetUsandose(TP);
        call_out("desarmar_armazon", 10+random(11), TP);
        return 1;
    }
}
reset()
{
	pGanzua = 1;
    pMusgo = 1;
    ::reset();
}
init()
{
	  ::init();
	  if (interactive(TP) && present("armazon_puesto_celdas",TO) && TP->QueryAttribute("sobre_armazon")) call_out("desarmar_armazon",10+random(6),TP);
}
