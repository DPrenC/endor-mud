/*
DESCRIPCION : un espectro
FICHERO     : /d/akallab/comun/pnj/monstruo/espectro.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
              16-04-99 [Nemesis@Simauria] Modificado el Die. Tio, que lo habias
                       hecho inmortal! Los jugadores se volvían locos intentando
                       matarlo! Por cierto, deberías heredar el std/undead, que
                       pa eso está...
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <living.h>
#include <attributes.h>
#include <combat.h>

#include "path.h"
#include AK_MACRO

inherit NPC;

create () {
  ::create();
 SetName ("un espectro");
  SetShort("un espectro");
  SetLong (
    "Es una misteriosa aparicion que flota en el aire delante de ti. Esta masa de "
    "maligna energia tiene una forma levemente antropomorfa y esta rodeada por un "
    "halo incandescente. En sus ojos brilla una llama demoniaca.\n");

  SetLevel(40);
  AddId(({"espectro","aparicion","masa","energia"}));
  SetRace ("nomuerto");
  SetGender (GENDER_MALE);
  SetAC(11);
  Set(P_HANDS,({ ({"su incandescente garra derecha",0,15}),
                 ({"su incandescente garra izquierda",0,15}),
                 ({"una succion de energia",0,25})
                 }) );
  SetAlign(-3000);
  SetAggressive (0);
  Set(P_CORPSE,1);
  InitChats (10, ({
    "El espectro parpadea incandescente con una aura maligna.\n",
    "El espectro merodea por la zona sin un destino concreto.\n"
    "El espectro te mira al tiempo que un escalofrio te recorre el cuerpo.\n",
    "El espectro da un terrorifico alarido que te hiela la sangre.\n",
    }));

  InitAChats (80, ({
    "El espectro se carcajea con regocijo mientras absorbe tu energia vital.\n",
    "Oyes un maligno alarido en la lejania....\n",
    "El espectro te mira al tiempo que un escalofrio te recorre el cuerpo.\n",
    "Intentas huir, pero estas tan aterrorizad"+AO+" que no puedes hacerlo.\n"
    }));
}

public varargs void Die(mixed silent) {
  say("El espectro parpadea brevemente y se disuelve...\n");
  ::Die(silent);
}


