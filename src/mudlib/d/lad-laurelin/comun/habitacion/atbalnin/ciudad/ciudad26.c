#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Desde este �ngulo la biblioteca parece incluso esplendorosa. "
  	"Todas las �pocas que ha pasado, las guerras y los maltratos no parecen "
  	"haberle pasado factura. Sabes que si te acercas m�s empezar�s a ver "
  	"grietas, remiendos y chapuzas sin fin, pero decides no romper el "
  	"hechizo, al menos por ahora.\n"));

  AddDetail("biblioteca", W("Es una gran biblioteca donde se guardan libros de "
  	"todo tipo. La entrada est� hacia el sur.\n"));
  SetIntShort("la zona central de la ciudad de Atbalnin");
  	
  AddExit("oeste", ATB_CI("ciudad24"));
  AddExit("norte", ATB_CI("ciudad27"));
  AddExit("sur", ATB_CI("ciudad28"));
  AddExit("este", ATB_CI("ciudad29"));
}
