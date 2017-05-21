/***
fichero: /guilds/guardabosques/train/habilidades.c
30/08/2004. Kastwey@simauria. A�adido el SetIntShort.
Modificado el allow_enter para que deje entrar a los wizards.
***/
#include "path.h"
#include <money.h>
#include <skills.h>

inherit TRAIN_BASE;

private int ordenar(string a, string b) { return a > b; }

create()
{
  string msg, *str;
  int i;
  ::create();

  SetIntShort("la habitaci�n de aprendizaje");
  SetIntLong(W("Est�s en una habitaci�n del gremio donde puedes aprender "
  	"nuevas habilidades y aumentar "
  	"el nivel m�ximo de tus habilidades f�sicas. Es una habitaci�n "
  	"grande, con varios ventanales y el suelo recubierto con esteras. Al "
  	"sur parece estar la habitaci�n de entrenamiento m�gico. Ves un "
  	"cartel que podr�as leer.\n"));

    SetIndoors(1);
    SetIntBright(50);

    AddDetail(({"esteras", "estera"}), W("En el suelo ves varias esteras, "
  	"seguramente para no hacerte da�o al entrenar.\n"));
  AddDetail(({"ventanal", "ventanales"}), W("Son unos grandes ventanales que "
  	"dan a la zona de entrenamiento.\n"));
  AddExit("norte", TRAIN+"entrenamiento");
  AddExit("sur", TRAIN+"magia");
  AddItem(BASE+"/pnj/ledtha");

  AddDetail("cartel", "Es un cartel. Podr�as leerlo.\n");
  str = ({ STR->radjust(to_string(NIV_VARA_GUARDABOSQUES      ),3," ")+" ........ Lucha con varas (vara)\n"
	, STR->radjust(to_string(NIV_CUCHILLO_GUARDABOSQUES  ),3," ")+" ........ Lucha con cuchillo (cuchillo)\n"
	, STR->radjust(to_string(NIV_LANZA_GUARDABOSQUES     ),3," ")+" ........ Lucha con lanza (lanza)\n"
	, STR->radjust(to_string(NIV_ESPADA_GUARDABOSQUES    ),3," ")+" ........ Lucha con espada (espada)\n"
	, STR->radjust(to_string(NIV_IDPLANTAS_GUARDABOSQUES ),3," ")+" ........ Identificar Plantas (identificar)\n"
	, STR->radjust(to_string(NIV_LANZAR_GUARDABOSQUES    ),3," ")+" ........ Lanzar objetos (lanzar)\n"
	, STR->radjust(to_string(NIV_RASTREAR_GUARDABOSQUES  ),3," ")+" ........ Rastrear (rastrear)\n"
	, STR->radjust(to_string(NIV_ESQUIVAR_GUARDABOSQUES  ),3," ")+" ........ Esquivar ataques (esquivar)\n"
	, STR->radjust(to_string(NIV_ESCONDERSE_GUARDABOSQUES),3," ")+" ........ Ocultarse entre la naturaleza (ocultarse)\n"
	, STR->radjust(to_string(NIV_EXPERTISE_GUARDABOSQUES ),3," ")+" ........ Esperto en combate (experto)\n"
	, STR->radjust(to_string(NIV_PARADA_GUARDABOSQUES    ),3," ")+" ........ Parada con armas (parada)\n"
	, STR->radjust(to_string(NIV_MASDANYO_GUARDABOSQUES  ),3," ")+" ........ Da�o mejorado (da�o)\n"
	, STR->radjust(to_string(NIV_ARCO_GUARDABOSQUES      ),3," ")+" ........ Tiro con arco (arco)\n"
	, STR->radjust(to_string(NIV_BALSAMO_GUARDABOSQUES      ),3," ")+" ........ Aplicar b�lsamo (b�lsamo)\n"
 , STR->radjust(to_string(NIV_DO_BALSAMO_GUARDABOSQUES      ),3," ")+" ........ Preparar b�lsamo (preparar b�lsamo)\n"
    , STR->radjust(to_string(NIV_REFLEXES_GUARDABOSQUES  ),3," ")+" ........ Reflejos de combate (reflejos)\n"
	});
//"Ap�sito de curaci�n (aposito)\n"
//a�ado: experto,parada,da�o y reflejos
  str = sort_array(str, SF(<));
  msg = "Lees el cartel:\n"
	"Ledtha puede ense�arte diversas habilidades, as� como ayudarte a mejorar las "
	"que ya conoces, cuando has llegado a su l�mite us�ndola por tu cuenta. Las "
	"habilidades que puedes aprender, y sus niveles se detallan a continuacion:\n\n"
	"Nivel        Habilidad\n"
	"-----        ---------\n";
  for (i=sizeof(str);i--;) msg+=str[i];
  msg += "El nombre entre par�ntesis denota el comando de aprendizaje. Por ejemplo, "
	"para aprender la lucha con espada, se deber� poner 'aprender espada'.\n";

  AddReadMsg("cartel", msg);

}
