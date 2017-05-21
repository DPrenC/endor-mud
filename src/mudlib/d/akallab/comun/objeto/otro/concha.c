// DESCRIPCION  : conchas varias
// MODIFICACION : 28-05-2008 [Angor] Creacion

#include "path.h"
//#include AK_MACRO
#include <properties.h>
inherit THING;

#define SHELL_SIZE_TXT ({"pequeña","mediana","grande"})
#define SHELL_SIZE_VALUE ({1,2,4})
#define SHELL_STATE_TXT ({"rota","algo dañada","sucia", "en buen estado", "perfecta"})
#define SHELL_STATE_VALUE ({5,40,50,75,100}) // en %
#define SHELL_TYPE_TXT ({"paua","mejillon","conus-aegrutus"})
#define SHELL_TYPE_VALUE ({15,5,10})

#define SHELL_TYPE_DESC ({\
"Es una concha de Paua, ovalada, de unos 15x10 centimetros con brillos "+\
"nacarados y bandas enroscadas de colores brillantes en azul, verde y marron.\n",\
"Es una concha de Mejillón, larga, ovalada de textura aspera y color negro.\n",\
"Es una concha de Conus-Aegrutus, de unos 20 centimetros con forma de dos "+\
"conos invertidos pegados por la base. El superior es pequeño y tiene forma "+\
"de espiral con pequeños dientes y el inferior es grande, alargado y liso. Su "+\
"color es crema con bandas marrones claras horizontales.\n"})

private string *shell_size_txt, *shell_size_value, *shell_state_txt, *shell_state_value;
private string *shell_type_txt, *shell_type_value, *shell_type_desc;

create () {
  ::create();
  shell_size_txt=SHELL_SIZE_TXT;
  shell_size_value=SHELL_SIZE_VALUE;
  shell_state_txt=SHELL_STATE_TXT;
  shell_state_value=SHELL_STATE_VALUE;
  shell_type_txt=SHELL_TYPE_TXT;
  shell_type_value=SHELL_TYPE_VALUE;
  shell_type_desc=SHELL_TYPE_DESC;

  int si=random(sizeof(shell_size_txt));
  int st=random(sizeof(shell_state_txt));
  int ty=random(sizeof(shell_type_txt));
  
  SetShort("una concha de "+shell_type_txt[ty]);
  SetLong(shell_type_desc[ty]+"Es "+shell_size_txt[si]+" y está "+shell_state_txt[st]+".\n");
  SetIds(({"concha", shell_type_txt[ty] }));
  SetWeight(si*50);
  SetValue(shell_size_value[si]*shell_state_value[st]/100*shell_type_value[ty]);
 
  //replace_program();
}
