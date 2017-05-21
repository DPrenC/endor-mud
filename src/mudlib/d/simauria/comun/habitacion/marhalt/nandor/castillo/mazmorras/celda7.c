//7.c (c) Nemesis@Simauria
//Celda numero 7

/*
  01-12-99 [Angor@Simauria] cambio de Query("encontrado_papel_quest_granjero") por
           QueryAttr("encontrado_papel_quest_granjero") para que funcione la funcion
		   mover.

*/

#include "./path.h"
#include <colours.h>
#include <moving.h>
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>


#define MOVER ({"ladrillos","ladrillos de muro","ladrillos del muro","ladrillos \
de la pared oeste","ladrillos del muro oeste","ladrillos del oeste","ladrillos \
oeste"})

#define ENTRAR  ({"agujero","por agujero","por el agujero","en el agujero",\
"en agujero","hueco","en el hueco","por el hueco","por el hueco de la pared \
oeste","por hueco","por el hueco oeste","por hueco oeste"})

#define REMOVER ({"paja","paja de la cama","paja de cama","la paja de la \
cama","paja de camastro","paja del camastro","la paja del camastro",\
"paja de yacija","paja de la yacija","la paja de la yacija",\
"la paja de yacija"})

inherit SIM_ROOM;

int removido,abierto;

private string mirar_hueco();
private string mirar_cama();
private string mirar_ladrillos();
int mover(string str)
{
    if (!TP->QueryAttr("encontrado_papel_quest_granjero")) return 0;
    if (!str || member(MOVER,str) < 0)
    {
        return notify_fail("¿" + capitalize(query_verb()) + " qué?\n",
                           NOTIFY_NOT_VALID);
    }
    if (abierto)
    {
        write("Alguien ha movido los ladrillos por ti... Solo te queda "
                "entrar por el agujero.\n");
        return 1;
    }
    write("Quitas un par de ladrillos del agujero... Por detrás de ellos "
            "se ve la más negra oscuridad...\n");
    say(capitalize(TNAME) + " quita un par de ladrillos de la pared "
          "oeste dejando un pequeño hueco al descubierto.\n");
    abierto=1;
    AddDetail(({"hueco","agujero"}),SF(mirar_hueco));
    return 1;
}


int entrar(string str)
{
    if (!abierto || !TP) return 0;
    if (!str || member(ENTRAR,str) < 0)
    {
        return notify_fail("Entrar por dónde?\n",NOTIFY_NOT_VALID);
    }
    write("Entras en el agujero...\n"
            "Caes a un pozo muy negro.......\n"
            "...............\n"
            "...............\n"
            "........... Y aterrizas sobre un montón de paja....\n");
    say(capitalize(TNAME) + " se introduce por el agujero y desaparece.\n"
          "Al poco, escuchas un golpe sordo.\n");
    TP->move(CASTILLO("tunel/entrada"),M_SILENT,"por un agujero");
    return 1;
}


int remover(string str)
{
    object ob;
    if (!str)
    {
        return notify_fail("¿Qué quieres remover?\n",NOTIFY_NOT_VALID);
    }
    if (member(REMOVER,str) < 0)
    {
        return notify_fail("No ves " + str + " para remover.\n",
                           NOTIFY_NOT_VALID);
    }
    if (removido)
    {
        write("La paja ya ha sido removida.\n");
        return 1;
    }
    write("Entre la paja encuentras un pequeño papel.\n");
    say(capitalize(TNAME) + " remueve la paja y encuentra un papel.\n");
    ob=clone_object("/std/thing");
    ob->SetShort("un papel arrugado");
    ob->SetLong("Es un papel arrugado. Las letras parecen haber sido "
                  "escritas con sangre.\n"
                  "Puedes leer lo siguiente:\n\n"
                  TC_RED +
                  " ' Soy Niark de Pel. De todos los "
                  "prisioneros que moraron en esta mazmorra sólo yo "
                  "averigüé como escapar. Mi secreto es simple: en el muro "
                  "oeste hay una salida secreta que el señor del castillo "
                  "utiliza para huir cuando hay peligro. A través de ella "
                  "se puede salir de este horrible lugar. Usa esta "
                  "información sabiamente, hermano, y que la fortuna te "
                  "sea próspera.\n"
                  "                                               Niark "
                  "de Pel '\n" + TC_NORMAL);
    ob->Set(P_GENDER,GENDER_MALE);
    ob->SetValue(0);
    ob->Set(P_NOSELL,1);
    ob->SetWeight(10);
    ob->SetIds(({"papel","mensaje"}));
    if (ob->move(TP, M_SILENT) != ME_OK)
    {
        write("Intentas coger el papel pero se te cae al suelo.\n");
        say(capitalize(TNAME) + " intenta coger el papel pero se le cae "
              " al suelo.\n");
        ob->move(TO,M_SILENT);
    }
    else
    {
        write("Lo coges.\n");
        say(capitalize(TNAME) + " coge el papel.\n");
    }
    removido=1;
    TP->SetAttr("encontrado_papel_quest_granjero",1);
    return 1;
}


private string mirar_cama()
{
    string ms = "Es una yacija de cubierta de paja que no parece demasiado "
    "cómoda.\n";
    return (removido?ms:ms + "Entre la paja asoma algo. Quizás deberías "
                               "removerla para ver qué es.\n");
}

private string mirar_ladrillos()
{
    return (abierto?"Son un par de ladrillos, que antes tapaban el "
                      "hueco que puedes ver en la pared oeste.\n":
                    "En la pared oeste puedes ver un par de ladrillos que "
                      "parecen sueltos.\n");
}


private string mirar_hueco()
{
    if (!TP->QueryAttr("encontrado_papel_quest_granjero") && !abierto)
    {
        return "No ves nada de eso.\n";
    }
    return (abierto?"En la pared oeste puedes ver un pequeño hueco, aunque"
                      "crees que es lo suficientemente grande como para que "
                      "puedas pasar.\n":
                    "Es un pequeño hueco tapado con unos ladrillos.\n");
}

public void reset()
{
    removido=0;
    RemoveDetail("ladrillos");
    abierto=0;
    ::reset();
}

create (){
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("una húmeda celda");
    SetIntLong("Te encuentras en una confortable celda.\n"
                 "Hay un camastro en un rincón y una silla en el otro. También "
                 "puedes ver una inscripción en una de las paredes.\n");
    SetIntBright(10);
    SetIntSmell("Huele a humedad.\n");
    SetIntNoise("Extrañamente no se oye nada. El lugar está tan "
                  "silencioso como una tumba...\n");
    AddDetail(({"cama","camastro"}),SF(mirar_cama));
    AddDetail(({"inscripcion","inscripción"}),"Quizá puedas leerla.\n");
    AddDetail(({"vieja silla", "silla"}),"Es una silla como otra cualquiera, si bien está "
                            "cubierta de polvo.\n");
    AddDetail(({"pared oeste","pared del oeste","muro oeste","muro del oeste"}),
               "Es una pared no muy diferente de las otras...\n");
    AddDetail(({"muro","pared"}),"¿Qué muro quieres mirar?");
    AddDetail(({"hueco","agujero"}),SF(mirar_hueco));
    AddDetail("ladrillos",SF(mirar_ladrillos));
    AddReadMsg(({"inscripcion","pared"}),
                "Pone: 'El del número cuatro enterró a su gato.'\n");
    AddRoomCmd(({"pasar", "entrar"}), "entrar");
    AddRoomCmd(({"quitar","mover"}),"mover");
    AddRoomCmd("remover","remover");
    AddExit("este","./pasillo6");
    AddDoor("este", "una puerta metálica",
    "Una vieja puerta metálica para cerrar la celda.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta del este"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
