inherit THING;

#include <properties.h>
#include "./path.h"


int romper_cmd(string str)
{
    if (!str) return notify_fail("romper qué??\n",NOTIFY_NOT_VALID);
	   object ob = present(str,TP);
	   if (!ob) return notify_fail("No tienes " + str + " que romper.\n",NOTIFY_NOT_VALID);
	   if (TO == ob)
		  {
		      tell_object(TP,"Rompes el cráneo orco y liberas al espíritu atrapado en su interior.\n"
    		      "Sientes como tu cuerpo se recupera ligeramente.\n");
    		  tell_room(environment(TP),CAP(TNAME) + " rompe un cráneo orco y sientes una presencia "
    		      "sobrenatural en el ambiente que se desvanece.\n",({TP}));
  		    TP->AddHP(11);
  		    if (TP->QueryHP() > TP->QueryMaxHP()) TP->SetHP(TP->QueryMaxHP());
  		    return TO->remove(),1;
  		}
    return 0;
}

create()
{
::create();

SetShort("un cráneo orco");
SetLong(W("Son los restos de lo que antaño fue un guerrero orco,"
" tiene marcas de haber sido utilizado en magia negra. Está en muy mal "
"estado, podrías romperlo con facilidad.\n"));
    SetIds(({"cráneo","craneo","cráneo orco","craneo orco"}));
    SetWeight(1500);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    Set(P_NOSELL);
}

init()
{
    ::init();
    add_action("romper_cmd","romper");
}