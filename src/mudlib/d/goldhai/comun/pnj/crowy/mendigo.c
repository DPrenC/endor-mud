/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 08-02-99                |
 |               Ultima Modificacion.. 07-03-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


#define ASESINOS DOM_STD "asesinos"

inherit NPC;

create()
{
  ::create();
 SetStandard("Fernis","duende",3,GENERO_MASCULINO);
 SetIds(({"mendigo","fernis","Fernis","fernis el mendigo"}));
 SetShort("Fernis, el mendigo");
 SetAlign(0);
 SetWhimpy(0); // O mata o muere

 InitChats(15,({
               "El mendigo dice: Frobbon est� aqui, noto su presencia.\n",
               "El mendigo dice: Si invocas al fantasma se aparecer�.\n",
               "El mendigo te pregunta: �Sabes quien es Frobbon?.\n"}));

  AddQuestion(({"frobbon","Frobbon","anillo","anillo de frobbon","anillo de Frobbon"}),
"Fue hace algunos a�os, Frobbon era un enano respetado y muy trabajador. "
"Ten�a un preciado anillo que su padre le hab�a regalado y una noche unos "
"salteadores quisieron robarselo, pero Frobbon se resisti� y muri� a manos "
"de aquellos sanguinarios. Desde entonces se rumorea que si le invocas en "
"este lugar se aparece su fantasma reclamando su anillo.\n");

  AddQuestion(({"salteador","salteadores","asaltantes"}),
"Pues hace mucho tiempo de aquello pero seguramente podr�s obtener alguna\n\
informaci�n en la taberna de contrabandistas.\n");
}

public int QueryCrowiano()
{
 return 1;
}

private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}

public varargs void Die(mixed silent) {
 object ASESINO;

 ASESINO=PO;
 if (!ASESINO->QueryIsPlayer()) {return ::Die(silent);}
 if(!existe_jugador(ASESINO->QueryRealName())) {return ::Die(silent);}
 ASESINOS->SetAsesino(ASESINO->QueryRealName(),2,1,0,0);
 ::Die(silent);
}
