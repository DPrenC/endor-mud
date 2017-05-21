/*
DESCRIPCION : fichero base de un cementerio
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/cementerio.c
MODIFICACION: 24-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

#define MAX_PNJ         2   //No mas de 2 por habitacion

#define PROB_CUERVO     20  //probabilidades de aparicion de pnj
#define PROB_MURCIELAGO 40
#define PROB_FANTASMA   25
#define PROB_ESPECTRO   15

public string lugar;      //donde esta el cementerio
public int abierta;       //esta la tumba abierta = se puede bajar a ella? 0=no, 1=si
public int amedida;       //pnj no automatico? 0=no, 1=si

static int crow;
static int bat;
static int ghost;
static int spectre;

create() {
 string str;
 int i;

 ::create();
 if (!lugar) lugar="?";
 SetIntShort("el cementerio de "+lugar);

 // dotacion de pnj's
 if (amedida==0) {
    i=0;
    crow=(random(100)<PROB_CUERVO?1:0);
    i+=crow;
    if (i<MAX_PNJ) {bat=(random(100)<PROB_MURCIELAGO?1:0); i+=bat;}
    if (i<MAX_PNJ) {ghost=(random(100)<PROB_FANTASMA?1:0); i+=ghost;}
    if (i<MAX_PNJ) {spectre=(random(100)<PROB_ESPECTRO?1:0); i+=spectre;}
    }


//descripcion y detalles
str="";
switch(random(3)){
   case 0: str+="Te encuentras en el cementerio de "+lugar+", un lugar solitario e inquietante. A "
                "tu alrededor observas multitud de tumbas, la mayor parte bastante abandonadas.\n";break;
   case 1: str+="Ante ti se extiende el solitario cementerio de "+lugar+". Aqui las viejas lapidas "
                "son los unicos testigo del inexorable paso del tiempo. Es un lugar inquietante.\n";break;
   case 2: str+="Estas en medio del cementerio de "+lugar+", rodeado de silenciosas tumbas. Sopla "
                "un viento gelido que parece provenir del interior de las fosas de este lugar.\n";break;
   }

switch(random(3)){
   case 0: str+="La inscripcion de la lapida de la tumba que tienes ante ti ha sido borrada por "
                "el paso del tiempo. A nadie parece importar que se olvide a su propietario.\n";
                AddDetail(({"inscripcion"}),
                   "La inscripcion de la lapida ha sido borrada por el paso del tiempo.\n");
                break;
   case 1: str+="Una especie de escualida enredadera ha crecido junto a la lapida de esta tumba. "
                "La planta se aferra a la vida, pero la tierra parece no ser muy buena aqui...\n";
                AddDetail(({"enredadera"}),
                   "Es una pequenya y escualida planta espinosa sin valor alguno. Se empenya en "
                   "crecer junto a lapida que la protege del frio viento, pero parace que la tierra "
                   "del lugar no aporta mucho alimento.\n");
                break;
   case 2: str+="Sobre la lapida de la tumba que tienes frente a ti se encuentra la escultura de "
                "una gargola de piedra. Las cuencas vacias de sus ojos parecen mirarte fijamente.\n";
                AddDetail(({"gargola"}),
                   "La gargola esta posada en cuclillas sobre lapida vertical de la tumba con las "
                   "alas plegadas. Ves como todos sus musculos estan en tension, como si estuviese "
                   "preparada para saltar sobre ti. Las cuencas de sus ojos estan vacias.\n");
                break;
   }

if (abierta){
   switch(random(3)){
      case 0: str+="La losa que cierra esta tumba esta rota.\n";break;
      case 1: str+="La losa que cerraba esta tumba ha desaparecido.\n";break;
      case 2: str+="Alguien ha movido la losa que cierra esta tumba.\n";break;
      }
   }

  SetIntLong(str);

  AddDetail(({"tumba","cementerio"}),QueryIntLong());

  SetIntNoise("Un frio gelido se hace sentir.\n");
  SetIntSmell("Hmm.. el aire es humedo y frio.\n");
  SetLocate("cementerio de Zarkam");
  SetIndoors(0);

  if (crow!=0) AddItem(PNJ("animal/cuervo"), REFRESH_DESTRUCT, crow);
  if (bat!=0) AddItem(PNJ("animal/murcielago"), REFRESH_DESTRUCT, bat);
  if (ghost!=0) AddItem(PNJ("monstruo/fantasma"), REFRESH_DESTRUCT, ghost);
  if (spectre!=0) AddItem(PNJ("monstruo/espectro"), REFRESH_DESTRUCT, spectre);
}
