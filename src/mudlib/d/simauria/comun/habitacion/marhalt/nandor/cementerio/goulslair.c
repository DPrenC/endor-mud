/**          goulslair.c : Cementerio de Nandor
            Creado por : Nemesis
            Fecha : 23-Nov-98
            Ultima modificacion :
	    ***/

#include "path.h"


inherit SIM_ROOM;

create()
{
  ::create();
  SetLocate("Cementerio de Nandor");
  SetIntShort("una tumba");
  SetIntLong(W(
    "Estás dentro de lo que parece ser una tumba. O al menos lo era, pues ahora"
    "parece más bien la guarida de algo. Algo maligno. Por todas partes hay trozos"
    "de cadáveres, restos de algun festín inhumano. Es un lugar muy estrecho donde"
    "apenas hay sitio para moverse y el techo está muy bajo. Te produce una gran"
    "sensación de claustrofobia."
    "Una escalera desvencijada conduce al exterior.\n"));
  SetIndoors(1);
  SetIntBright(10);
  SetIntSmell("El hedor a carne putrefacta y a humedad es insoportable.\n");
  AddDetail("tumba",
    "Sin duda ahora sirve de cobijo a algún ser maligno.\n");
  AddDetail(({"escalera","escalera desvencijada"}),
    "Es de madera y está bastante podrida. Parece que se vaya a caer en pedazos "
    "con sólo mirarla mal...\n");
  AddDetail(({"restos","trozos","restos de cadaveres","festin","restos de cadáveres","festín"}),
    "El suelo está cubierto de ellos. Hay montones de piernas y brazos medio roídos.\n");
  AddDetail("paredes",
    "Son de tierra húmeda. Los gusanos pululan por ellas.\n");
  AddDetail("techo",
    "Es de madera, parece la tapa de un ataúd...\n");
  AddExit("arriba","./cemen3e");
  AddItem(QUEST + "ghoul/qghoul",REFRESH_DESTRUCT,1);
}

