/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>

inherit KHA_ROOM;

create() {
  ::create();
   SetIntShort("los baños de Belthain, Rey de los Enanos");
  SetIntLong(
"Te encuentras en los impresionantes banyos de Belthain, Senyor de los "
"Enanos. Unas hermosas cascadas de agua caliente van llenando una inmensa "
"piscina de transparentes aguas azuladas. Toda clase de arboles rodean esta "
"estancia. Este lugar es simplemente lo mas bello que jamas puedas haber "
"contemplado.\n");

  SetIndoors(1);

  SetIntBright(100);

    AddExit("este",PISO2+"piso2_12");
    AddDoor("este","la puerta del pasillo",
        "Es una bonita puerta de madera bien trabajada, que cierra la salida "
        "hacia el pasillo.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo","puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail( ({"arbol","arboles"}),
    "Pinos, robles, sauces llorones, cerezos, almendros... Es increible como "
    "toda esta vegetacion puede prosperar en este lugar, el segundo piso de un "
    "castillo... Es algo magico.\n");
  AddDetail("suelo",
  "Las lamparas de diamantes se reflejan en el pulido suelo de marmol.\n");

  AddDetail( ({"paredes","pared"}),
  "Son paredes de pura roca, cubiertas con bellos tapices hilados en oro.\n");
  AddDetail( ({"cascada","cascadas"}),
"Las hermosas cascadas llenan constantemente la piscina de tibias aguas.\n"
"cristalinas y azuladas.\n");
  AddDetail( ({"piscina","agua"}),
"Aguas transparentes. La escena es maravillosa y hechizante.\n");

  AddItem(MONS+"sirviente",REFRESH_DESTRUCT,1);
  AddItem(MONS+"sirviente",REFRESH_DESTRUCT,1);
}