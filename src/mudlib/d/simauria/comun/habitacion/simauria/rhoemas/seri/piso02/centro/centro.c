/***************************************************************************************
 ARCHIVO:   centro.c
 AUTOR:     [z] Zomax
 FECHA:     14-01-2002
 COMENTARIOS:   Centro del templo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit SIM_ROOM;

int llave,visto;
object llavem;

string fhueco()
{
    if (llave)
    {
        visto=1;
        return W("Parece que hay algo dentro de uno de los huecos, una "
        "especie de madera.\n");
    }
    else return W("Miras los huecos llenos de polvo y telara�as. No ves nada "
        "especial.\n");
}

reset(){
  ::reset();
  llave=1;
  visto=0;
}

create () {
  ::create();

  SetIndoors(1);
  Set(P_TPORT,0);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, segundo piso");
  SetIntShort("un alargado hueco");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Entras en un hueco del que sale una escalera de cuerda hacia abajo hasta "
    "no se sabe donde. Lo m�s sensato ser�a no bajar, pero si has llegado hasta aqu� "
    "es que no eres muy sensato que digamos. Esto est� lleno de polvo y telara�as "
    "que han invadido hasta los huecos de las paredes como si no hubiera pasado nadie "
    "en siglos. Los ladrillos grises y el poco espacio te aprisionan.\n"));

  AddDetail(({"pared","paredes"}),W("Son de roca gris, est�n muy sucias y demasiado pegadas "
    "a tu cuerpo para tu gusto. Adem�s est�n muy gastadas y llenas de huecos.\n"));
  AddDetail(({"hueco","huecos"}),SF(fhueco));
  AddDetail(({"ladrillo","ladrillos"}),W("Son bastante simples, uno en especial te llama la "
    "atenci�n: sobresale demasiado.\n"));
  AddDetail(({"telara�a","telaranya","telara�as","telaranyas","polvo"}),W("Hay "
    "telara�as y polvo por todas partes, se�al de que hace mucho que nadie "
    "pasaba por aqu�.\n"));
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("empujar","fempujar");
  AddExit("abajo",RHOEHAB("seri/piso01/centro/centro"));
  llave=1;
  visto=0;
}

int fcoger(string str)
{
    if (str=="polvo")
    {
        write(W("�Para qu� quieres coger polvo?, mejor lo dejas no sea que seas "
            "al�rgic"+AO+".\n"));
        return 1;
    }
    else if (str=="telaranya" || str=="telaranyas" || str=="telara�a" || str=="telara�as")
    {
        write(W("No necesitas coger eso, y puedes llevarte un disgusto si viene "
            "su due�a. Quiz�s sea venenosa, as� que decides no cogerlo.\n"));
        return 1;
    }
    else if (str=="escalera" || str=="escalera de cuerda")
    {
        write("Claro... y como sabes volar y todo... no digas tonter�as.\n");
        return 1;
    }
    else if ((str=="madera" || str=="madera de hueco") && llave && visto)
    {
   TP->SetAttribute("Cylin",1);
    if (TP->QueryHP()>50) TP->SetHP(50);
        if (TP->QuerySP()>50) TP->SetSP(50);
    TP->move(RHOEHAB("seri/piso02/centro/pasillo_01.c"),M_SPECIAL,
      ({"coge un trozo de madera de un "
        "hueco de la pared. Parece que ha cogido una pieza vital de la "
        "estructura, pues multitud de rocas se desmoronan del techo de la "
        "sala. Se abre una trampilla por la que cae",
      "cae desde una trampilla de la pared",
      "Coges un trozo de madera de uno de los huecos.\n\n"
            "����BROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMMMMMMMMMMMMMM!!!!\n\n"
              "Parece que acabas de quitar una pieza vital de "
              "la estructura. Montones de rocas caen sobre ti "
              "mientras se abre una trampilla en un lateral por "
              "la que caes.\n\nEso te ha dolido"}));
    foreach(object ob:all_inventory())
    {
        if (query_once_interactive(ob))
        {
            if (ob->QueryHP()>50) ob->SetHP(50);
            if (ob->QuerySP()>50) ob->SetSP(50);
            ob->move(RHOEHAB("seri/piso02/centro/pasillo_01.c"),M_SPECIAL,
              ({" cae por la trampilla",
              "cae desde una trampilla de la pared",
              "Sin poder evitarlo, caes tambi�n por la trampilla.\n\n"
              "Eso te ha dolido"
            }));
        }
    }
    tell_room(RHOEHAB("seri/piso02/centro/pasillo_01"),"La trampilla "
      "se cierra sin dejar rastro.\n");
        llavem=clone_object(RHOEVAR("seri/llave_madera.c"));
        llavem->move(this_player(),M_SILENT);
        llave=0;
        visto=0;
        return 1;
     }
}

public int fempujar(string str)
{
    if (str && str=="ladrillo")
    {
        write("Empujas inocentemente el ladrillo.\n");
        write(W("No deber�as haber hecho eso, �inconsciente!.\n"
            "����BROOOOOOOOOOOOOOMMMMMMMMMMMMMM!!!!\n"
            "Montones de rocas caen sobre ti mientras se "
            "abre una trampilla en un lateral por "
            "la que caes.\nEso te ha dolido.\n"));
        if (TP->QueryHP()>50) TP->SetHP(50);
        if (TP->QuerySP()>50) TP->SetSP(50);
        TP->move(RHOEHAB("seri/piso02/centro/pasillo_01"),M_SILENT);
        TP->LoofAfterMove();
        say(W(CATP+" empuja un ladrillo. �En qu� estar� pensando? De repente desaparece "
        "no sabes c�mo.\n"),TP);
        return 1;
    }
    return 0;
}