/* Archivo        tumba.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripci�n:   Tumba en el cementerio de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("ceroom");

void recuperar_()
{
    int uno=TP->QueryAttribute("tienelibro");
    object lib=present("quest_libro_daryl",TP);
    if ((uno) && (!lib))
    {
        tell_object(TP,("Al entrar en la tumba, ves el libro que hab�as "
            "perdido al salir, y naturalmente, lo coges.\n"));
        say(CAP(TP->QueryName())+" recoge algo del suelo.\n",TP);
        object obj=clone_object(QUEST+"/sherek/libro");
         obj->move(TP);
    }
}

create()
{
    ::create();
    SetIntShort("una tumba en el cementerio de la aldea de Sloch");
    SetIntLong("A pesar de lo que pudiera parecer, viendo como estaba la "
        "parte del cementerio donde est� esta tumba, aqu� abajo no impera el "
        "caos. Alguien ha adecentado este lugar, agrand�ndolo un poco, "
        "limpi�ndolo y haci�ndolo m�s c�modo ... M�s a�n: mir�ndolo bien te "
        "da la sensaci�n que hay alguien que vive aqu� por raro que pueda "
        "parecer.\n Puedes ver un jerg�n de paja en una esquina, y un "
        "peque�o cofre en la otra. La salida queda hacia arriba oculta por "
        "la maleza.\n");
    SetIntSmell("A pesar de todo el orden, todav�a huele a tierra y a "
        "cerrado, pero no es desagradable.\n");
    SetIntNoise("El silencio es total. Desde aqu� no se oye absolutamente "
        "nada m�s que tu respiraci�n.\n");
    SetIntBright(20);
    AddDetail(({"suelo"}), "Est� bastante limpio a excepci�n de alguna "
        "tierra justo debajo del agujero por el que has entrado. "
        "Probablemente es la que se cae cuando uno pasa por un hueco tan "
        "estrecho.\n");
    AddDetail(({"pared", "paredes"}), "Han sido trabajadas hace poco ya que "
        "ves recientes marcas de pico, posiblemente para agrandar m�s el "
        "espacio y hacer posible que una tumba sea habitada por alguien m�s "
        "que no fuese un muerto.\n");
    AddDetail(({"techo"}), "Est� formado por la gran l�pida que tapa la "
        "tumba. En uno de sus extremos hay un trozo roto que forma el "
        "agujero por el cual se entra a este lugar.\n");
    AddDetail(({"agujero", "hueco", "entrada", "arriba"}), "Es un peque�o "
        "hueco en la losa que tapa la tumba por el que apenas cabe el cuerpo "
        "de una persona.\n");
    AddDetail(({"maleza", "malezas"}), "desde aqu� abajo tapan la poca luz "
        "que debiera haber llegado por el agujero de entrada.\n");
    AddItem(QUEST+"sherek/cofre");
    AddExit("arriba", SHERALD("cementerio/cementerio02"));
}

init()
{
    ::init();
    call_out("recuperar_",1);
}

