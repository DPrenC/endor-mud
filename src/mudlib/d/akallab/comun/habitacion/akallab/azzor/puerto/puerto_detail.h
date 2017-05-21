 /*
DESCRIPCION : definiciones comunes del puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/puerto_detail.h
MODIFICACION: 07-02-2000 [Angor@Simauria] Creacion
*/

AddDetail(({"darsena", "dársena"}),
    "Es la parte interior que queda resguardada en el puerto.\n");

AddDetail(({"malecon","malecones","malecón"}),
  "Un malecón es un grueso muro que sale desde la costa adentrándose en "
    "el mar. Su función es la de bloquear el oleaje para así proteger a "
	"los barcos que se hallen fondeados en la dársena del puerto.\n");

AddDetail(({"fortaleza"}),
  "La fortaleza de Azzor protege este importante puerto orco. Es una "
    "impresionante construcción maciza capaz de resistir los más duros "
	"asedios que se encuentra sobre un alto promontorio al Norte de la "
	"bahía natural en la que se encuentra construido el puerto.\n");

AddDetail(({"promontorio"}),
  "El promontorio es una altura de tierra que se adentra en el mar. "
    "Sobre ese alto macizo de roca se asienta la fortaleza de Azzor.\n");

AddDetail(({"bahia","bahía","barcos"}),
  "En la bahía que forma el puerto se pueden observar multitud de barcos "
    "fondeados. Algunos de ellos están anclados en medio mientras que "
	"otros se hallan atracados junto al muelle.\n");

AddDetail(({"portico","pórtico","pórticos","porticos"}),
  "Puedes observar que casi todos los edificios de por aquí tienen un "
    "pórtico en su fachada. El pórtico consiste en una galería con "
	"columnas y arcadas. Permite circular por aquí cuando llueve o hace "
	"mal tiempo. Los mercaderes ambulantes suelen colocar sus tenderetes "
	"bajo ellos.\n");

AddDetail(({"muelle"}), "En el muelle del puerto de Azzor sólo puedes "
    "encontrar tres cosas: barcos, tabernas y pelea. Tu sabrás lo que buscas.\n");

SetIntNoise("Las olas del mar chocan mansamente con el muelle del puerto.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("ciudad de Azzor");
SetIndoors(0);
//SetIntBright(0);
