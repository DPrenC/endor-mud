/* **********************************************************
   *                                                        *
   *    Archivo: bardo.c                                    *
   *    Autor: [a] Articman                                 *
   *    Modificación: [a] Creación                          *
   *                                                        *
   ********************************************************** */

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create(){
    ::create();
    SetStandard("Guennir", "humano", ([GC_NINGUNO:19]),GENERO_MASCULINO);
    SetWhimpy(20);
    SetAlign(200);
    SetIds(({"humano","guennir","Guennir","bardo"}));
    SetShort("Guennir el bardo");
    SetLong("Guennir es un joven y apuesto bardo, mide casi dos metros y sus ojos y "
        "pelo son de color claro, aunque de semblante permanentemente triste. Viste "
        "ropa serias y tiene la mirada siempre perdida, como si estuviera en algún "
        "lugar lejano. Sus movimientos son lentos como si estuviera muy cansado. "
        "Parece necesitar que alguien le heche una mano.\n");
    InitChats(7,({"Guennir suspira.\n", "Guennir mira al cielo con ojos vidriosos.\n",
        "Guennir dice algun nombre entre dientes. No llegas a oirlo.\n",
        "Guennir dice: Oh, cruel destino, ¿Por qué no me permite ser feliz?.\n",
        "Guennir dice: Endeline, amor mío, ¿Dónde estás?.\n",
        "Guennir dice: ¿Por qué la gente no deja que el amor sea libre?\n"}));
    AddQuestion(({"destino"}),"Guennir dice: 'El destino, esa dura realidad que no nos "
        "permite a Endeline y a mi disfrutar de la felicidad.\n");
    AddQuestion(({"Endeline","endeline"}),"Endeline es la mujer más hermosa "
        "de todo el reino, su pelo, su rostro, su mirada... Toda ella me inspira "
        "para mis más bellos versos. Pero el ingrato de su padre no nos deja amarnos"
        " libremente.\n");
    AddQuestion(({"padre","padre de endeline","padre de Endeline"}),"Guennir "
        "dice: 'La familia de la bella Endeline es de clase alta, así que su padre es "
        "muy riguroso en la elección del prometido de su hija. Sólo podremos "
        "estar juntos si consigo llevarle un objeto pero no soy capaz.'\n");
    AddQuestion(({"objeto"}),"Guennir dice: 'El padre de Endeline entregara la "
        "mano de su hija sólo a aquel que demuestre ser merecedora de ella por su valor "
        "y fuerza. El primer hombre que le lleve un dedo de gárgola viva se "
       "convertirá en su marido.'\n");
    AddQuestion(({"dedo","dedo de gargola","dedo de gárgola","dedo de gargola viva",
        "dedo de gárgola viva"}),"Guennir dice: 'Las gárgolas son unos seres muy escasos "
        "y poderosos. Ya no sólo hay que encontrarlos, también hay que ser capaz de "
        "devolverle la vida para acabar con ella y así conseguir su dedo. ¡Oh triste "
        "ironía del destino!, Tengo entendido que para darles vida se necesita un "
        "amuleto.'\n");
    AddQuestion(({"amuleto","amuleto de gargola","amuleto de gárgola"}),"Guennir "
        "dice: 'Los amuletos para darle vida a las gárgolas son más escasos que las "
        "propias gárgolas.\n Tengo entendido que hay un libro que habla de ello.\n");
    AddQuestion(({"libro","libro del amuleto"}),
        "Guennir dice: he oído rumores de que en la biblioteca de Crowy hay un libro "
        "que habla sobre el extraño amuleto para devolverle vida a las gárgolas.\n");
    AddItem(GOBJETO("arma/gundistyr/lira"),REFRESH_REMOVE,SF(wieldme));
}

destroy_dedo(){
    object cab;

    if (cab=present("d_gargola"))
    cab->remove();

    call_out("destroy_dedo2",1);
    remove_call_out("destroy_dedo");
}

destroy_cabeza2(){
    object cab;

    if ( cab=present("d_gargola",TP) ) {
        cab->remove();
        call_out("destroy_dedo2",1);
    }

    while (remove_call_out("destroy_dedo2")!=-1);
}


notify_enter(mixed oldenv, int method, mixed extra) {

    object p;

    ::notify_enter(oldenv,method,extra);

    p=PO;

    if (p->id("d_gargola")) {
        if (QUESTMASTER->QueryQuestSolved("guennir_quest", TP)) {
            tell_object(TP,"Guennir te dice: 'Gracias, pero ya me ayudaste, ¿no te "
            "acuerdas?.\n  Alguien dijo que los rabitos de pasa son buenos para la "
            "memoria...\n");
            write_file (LOGS"GUENNIR",ctime(time())+TP->QueryRealName()+" ["+
            TP->QueryLevel()+"]   Ha resuelto de nuevo el quest de Guennir.\n");
            call_out("destroy_dedo",1);
            return 42;
        }
        QUESTMASTER->SetPlayerQuest("guennir_quest",TP);
        tell_object(TP,"Guennir te dice: '¡Muchas gracias! Ahora podré demostrar al "
        "padre de Endeline que realmente me merezco a su hija.\n");
        CHMASTER->SendMsg("info", "¡Guennir por fin va a ver cumplido su deseo! ¡¡Cons "+
        TP->QueryName()+"!!\n");
        call_out("destroy_dedo",1);
        write_file (LOGS"GUENNIR",ctime(time())+" "+TP->QueryRealName()+" ["+
        TP->QueryLevel()+"]   Ha resuelto el quest de Guennir.\n");
        return 42;
    }
}

