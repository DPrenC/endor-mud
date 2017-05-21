 /*
DESCRIPCION : definiciones comunes del puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/puerto_detail.h
MODIFICACION: 07-02-2000 [Angor@Simauria] Creacion
*/

AddDetail(({"darsena", "d�rsena"}),
    "Es la parte interior que queda resguardada en el puerto.\n");

AddDetail(({"malecon","malecones","malec�n"}),
  "Un malec�n es un grueso muro que sale desde la costa adentr�ndose en "
    "el mar. Su funci�n es la de bloquear el oleaje para as� proteger a "
	"los barcos que se hallen fondeados en la d�rsena del puerto.\n");

AddDetail(({"fortaleza"}),
  "La fortaleza de Azzor protege este importante puerto orco. Es una "
    "impresionante construcci�n maciza capaz de resistir los m�s duros "
	"asedios que se encuentra sobre un alto promontorio al Norte de la "
	"bah�a natural en la que se encuentra construido el puerto.\n");

AddDetail(({"promontorio"}),
  "El promontorio es una altura de tierra que se adentra en el mar. "
    "Sobre ese alto macizo de roca se asienta la fortaleza de Azzor.\n");

AddDetail(({"bahia","bah�a","barcos"}),
  "En la bah�a que forma el puerto se pueden observar multitud de barcos "
    "fondeados. Algunos de ellos est�n anclados en medio mientras que "
	"otros se hallan atracados junto al muelle.\n");

AddDetail(({"portico","p�rtico","p�rticos","porticos"}),
  "Puedes observar que casi todos los edificios de por aqu� tienen un "
    "p�rtico en su fachada. El p�rtico consiste en una galer�a con "
	"columnas y arcadas. Permite circular por aqu� cuando llueve o hace "
	"mal tiempo. Los mercaderes ambulantes suelen colocar sus tenderetes "
	"bajo ellos.\n");

AddDetail(({"muelle"}), "En el muelle del puerto de Azzor s�lo puedes "
    "encontrar tres cosas: barcos, tabernas y pelea. Tu sabr�s lo que buscas.\n");

SetIntNoise("Las olas del mar chocan mansamente con el muelle del puerto.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("ciudad de Azzor");
SetIndoors(0);
//SetIntBright(0);
