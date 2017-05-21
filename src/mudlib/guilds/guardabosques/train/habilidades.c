/***
fichero: /guilds/guardabosques/train/habilidades.c
30/08/2004. Kastwey@simauria. Añadido el SetIntShort.
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

  SetIntShort("la habitación de aprendizaje");
  SetIntLong(W("Estás en una habitación del gremio donde puedes aprender "
  	"nuevas habilidades y aumentar "
  	"el nivel máximo de tus habilidades físicas. Es una habitación "
  	"grande, con varios ventanales y el suelo recubierto con esteras. Al "
  	"sur parece estar la habitación de entrenamiento mágico. Ves un "
  	"cartel que podrías leer.\n"));

    SetIndoors(1);
    SetIntBright(50);

    AddDetail(({"esteras", "estera"}), W("En el suelo ves varias esteras, "
  	"seguramente para no hacerte daño al entrenar.\n"));
  AddDetail(({"ventanal", "ventanales"}), W("Son unos grandes ventanales que "
  	"dan a la zona de entrenamiento.\n"));
  AddExit("norte", TRAIN+"entrenamiento");
  AddExit("sur", TRAIN+"magia");
  AddItem(BASE+"/pnj/ledtha");

  AddDetail("cartel", "Es un cartel. Podrías leerlo.\n");
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
	, STR->radjust(to_string(NIV_MASDANYO_GUARDABOSQUES  ),3," ")+" ........ Daño mejorado (daño)\n"
	, STR->radjust(to_string(NIV_ARCO_GUARDABOSQUES      ),3," ")+" ........ Tiro con arco (arco)\n"
	, STR->radjust(to_string(NIV_BALSAMO_GUARDABOSQUES      ),3," ")+" ........ Aplicar bálsamo (bálsamo)\n"
 , STR->radjust(to_string(NIV_DO_BALSAMO_GUARDABOSQUES      ),3," ")+" ........ Preparar bálsamo (preparar bálsamo)\n"
    , STR->radjust(to_string(NIV_REFLEXES_GUARDABOSQUES  ),3," ")+" ........ Reflejos de combate (reflejos)\n"
	});
//"Apósito de curación (aposito)\n"
//añado: experto,parada,daño y reflejos
  str = sort_array(str, SF(<));
  msg = "Lees el cartel:\n"
	"Ledtha puede enseñarte diversas habilidades, así como ayudarte a mejorar las "
	"que ya conoces, cuando has llegado a su límite usándola por tu cuenta. Las "
	"habilidades que puedes aprender, y sus niveles se detallan a continuacion:\n\n"
	"Nivel        Habilidad\n"
	"-----        ---------\n";
  for (i=sizeof(str);i--;) msg+=str[i];
  msg += "El nombre entre paréntesis denota el comando de aprendizaje. Por ejemplo, "
	"para aprender la lucha con espada, se deberá poner 'aprender espada'.\n";

  AddReadMsg("cartel", msg);

}
