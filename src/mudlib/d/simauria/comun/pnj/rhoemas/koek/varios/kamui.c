/***************************************************************************************
 ARCHIVO:   kamui.c
 AUTOR:     [z] Zomax
 FECHA:     27-04-2003
 COMENTARIOS:   Kamui, el alquimista.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

public string foro()
{
    mapping quest=TP->QueryAttribute("DraegoQuest");

    if (quest && member(quest,"tunica") && (quest["tunica",0]==9 || quest["tunica",0]==10))
    {
        quest+=(["tunica":10]);
        return W("Kamui te dice: Pues aunque estoy acostumbrado a convertir el "
        "plomo m�s que la paja si, podr�a hacerlo, de hecho tengo por aqu� un "
        "'m�todo cient�fico' que me ense�aron hace tiempo... pero no puedo, lo "
        "siento, arruinar�a la econom�a del lugar, si la gente se enterara de "
        "que voy haciendo esa clase de favores todos vendr�an a por monta�as "
        "de oro y nadie trabajar�a. No puedo, al menos no sin un 'incentivo', "
        "ya me entiendes...\n");
    }
    else return "Kamui se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Kamui","humano",15,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Kamui");
  SetIds(({"humano","alquimista","Kamui","kamui"}));
  SetShort("Kamui el alquimista");
  SetLong(W("Kamui es el alquimista de la zona, un humano con ansias de ciencia que "
    "pasa el rato entre m�quinas de lo m�s extra�as y poco �tiles. Tiene unas cejas "
    "espesas y las manos bastante sucias por culpa de los experimentos que hace.\n"));
  InitChats(5,({"Kamui recoge varias piezas de metal y las pone en un cacharro.\n",
        "Kamui dice: �La ciencia lo es todo!.\n",
        "Kamui dice: Este experimento era as�... no... espera... era...\n",
        "Kamui se rasca la barbilla pensativo.\n"}));
  AddQuestion(({"oro","paja"}),SF(foro),1);
  AddQuestion(({"alquimia","alquimista"}),W("Kamui te dice: La alquimia es una ciencia, pura "
    "ciencia...\n"),1);
}

init(){
  ::init();

  add_action("fmatar","matar");
}

public int fmatar(string str)
{
    mapping quest=TP->QueryAttribute("DraegoQuest");

    if (!str) return 0;
    else (lower_case(str));
    if (quest && member(quest,"tunica") && living(TO) && TO->id(str) && present("hilos de paja",TP) && quest["tunica",0]==10)
    {
        quest+=(["tunica":11]);
        present("hilos de paja",TP)->remove();
        write (W("Kamui te dice: �Est� bien, est� bien!, se nota que sabes 'convencer sutilmente'... "
        "la verdad es que es imposible para un cient�fico como yo negarse ante tal 'incentivo'... "
        "veamos... quer�as que convirtiera la paja en oro, �no?, bueno, eso es sencillo, espera...\n\n"
        "Le das a Kamui los hilos de paja, que los pone en una bolsa y los mete en una especie de "
        "caja de acero cubierta de cables y empieza a girar una manivela... De repente se para y "
        "abre la caja.\nKamui te dice: Toma, pero que no se entere nadie, �me oiste? NADIE.\n"));
        clone_object(RHOEVAR("koek/varios/hilo_oro"))->move(TP,M_NOCHECK);
        return 1;
    }
}