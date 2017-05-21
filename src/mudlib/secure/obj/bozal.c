/**
 * /secure/bozal.c, complemento de /obj/tool/silence-o-matic.c
 *
 * [Nyh] Esto es estupido y te lo puedes saltar de mil maneras diferentes
 *
 */

#include <properties.h>
#include <moving.h>
#include <magia.h>
#include <commands.h>

inherit THING;

int contador;

create () {
   contador = 30;
   ::create();
   AddId(({"bozal_magico","bozal"}));
   AddAdjective(({"un","el"}));
   SetShort("el bozal magico ("+contador+" minutos)");
   SetLong(W("Este es el bozal magico que se te ha concedido por molestar y/o "
             "faltar al respeto a algún habitante de Simauria.\n")+
           W("La próxima vez cuida mejor tu comportamiento antes de hacer "
             "algo de lo que luego puedas arrepentirte.\n")+
             "Te quedan "+contador+" minutos para que el bozal desaparezca.\n");
   SetWeight(0);
   SetValue(0);
   SetSize(0);
   Set(P_MAGIC, 1);
   Set(P_NODROP, 1);
   Set(P_NOSELL, 1);
   Set(P_NOBUY, 1);
   Set(P_NOGIVE, 1);
   Set(P_NOGET, 1);
   Set(P_AUTOOBJECT, 1);
}

init () {
    ::init();
    if (environment() != TP) return;
    add_action("nada", "gritar");
    add_action("nada", "=", AA_SHORT);
    add_action("nada", "'", AA_SHORT);
    add_action("nada", "decir");
    add_action("nada", "beep");
    add_action("nada", "tell");
    add_action("nada", "tel");
    add_action("nada", "telepatia");
    add_action("nada", "telepatía");
    call_out("cuentatras", 60);
}

cuentatras() {
    if (--contador) {
       SetShort("el bozal magico ("+contador+" minutos)");
       SetLong(W("Este es el bozal magico que se te ha concedido por molestar y/o "
                 "faltar al respeto a algún habitante de Simauria.\n")+
               W("La próxima vez cuida mejor tu comportamiento antes de hacer "
                 "algo de lo que luego puedas arrepentirte.\n")+
                 "Te quedan "+contador+" minutos para que el bozal desaparezca.\n");
             call_out("cuentatras", 60);
        return 1;
     }
     if (contador == 1) call_out("destruir",1);
}

destruir() {
   log_file("BOZAL",ctime(time())+" ---> Bozal autodestruido en "+
   capitalize(getuid(TP))+".\n");
   write("El bozal desaparece de tu boca magicamente.\n"
         "La proxima vez cuida mejor tu comportamiento.\n");
   remove();
   if (TO) destruct(TO);
   return 1;
}

nada() {
    write("\tEl bozal te impide hablar.\n");
    return 1;
}
