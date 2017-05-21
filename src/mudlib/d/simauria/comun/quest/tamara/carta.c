/***
Fichero: carta.c
Autor: (modificación) [kastwey@simauria], 13/01/2005.
Descripción: Carta de tamara para Altur.
25/02/2005: [kastwey]: Pongo una propiedad Owner para evitar que alguien la coja
ese alguien muere, y la coja otro cualquiera.
***/

#include "path.h"
#include <moving.h>
#include <colours.h>
#include <properties.h>
#define AO TP->QueryGenderEndString()

inherit THING;
string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }



string leer()
{
    if (query_verb() != "leer") return "";
    if (TP->QueryRealName() != QueryOwner())
    // la carta no es de este player
    {
        say(W(CAP(TNAME) + " desdobla la carta y comienza a leer. Mientras lo "
              "hace, observas como su cara se tiñe de un rojo intenso. "
              "Rápidamente, arruga la carta y la tira lejos.\n"));
        call_out("remove",1);
        return W("Al desdoblar la carta, puedes leer en letras "
                "grandes: " + TC_RED + "NO SEAS TRAMPOS" +
                CAP(AO) + "! ESTA CARTA NO TE PERTENECE!\n" +
                TC_NORMAL + "Avergonzad" + AO + ", arrugas la "
                "carta y la tiras lejos.\n");
    }
    // Sí es el propietario:
    say(TP->QueryName()+" lee la carta de Tamara.\n",TP);
    return W("Querido Altur:\n" +
             (TP->QueryGender() == GENDER_MALE ? "El portador " :
              "La portadora ") + "de esta carta ha facilitado enormemente "
             "nuestro ahora próximo encuentro. Nunca podremos agradecérsel" +
             AO + " como se merece. Ya sabes que no soy demasiado buena "
             "escribiendo, pero en cualquier caso debes saber que yo siempre "
             "te he amado, y que mis sentimientos perdurarán siempre. "
             "Ahora puedo ocultarme, amor mío, y ya no tengo miedo.\n\n "
             "Te espero en la posada esta noche.\n\n\nFielmente tuya:\n   "
             "Tamara.\n");
}


create() {
  ::create();
  AddId("carta");
  AddId("quest_carta_tamara");
  SetShort("una carta");
  SetLong(W("Es una carta escrita en papel perfumado, está simplemente plegada, sin llevar  "
  "ningún sello de identificación aparente.\n"));
  SetWeight(30);
  Set(P_CANT_STEAL,1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetReadMsg(SF(leer));
}

public varargs int move(mixed dest, int method, mixed extra)
{
	if (method == M_GIVE && !dest->QueryHerreroTamaraQuest()) return ME_NO_GIVE;
	return ::move(dest, method, extra);
}
