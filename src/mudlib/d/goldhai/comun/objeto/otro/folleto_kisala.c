/*=============================================================*
 |           << GOLDHAI.Crowy [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 16-05-99                 |
 |              Ultima Modificacion...16-05-99                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit THING;

create() {
 ::create();

 SetShort("un folleto");
 SetLong("\
Observas con detenimiento el folleto y ves que se trata de un rudimentario\n\
papel con una breve explicación acerca de las amazonas y con un mapa de la\n\
ubicación del gremio.\n\
Seria interesante que leyeras el texto y el mapa del folleto.\n");
 SetIds(({"folleto","papel","folleto_kisala"}));
 SetValue(10);
 SetWeight(100);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);

 AddSubReadMsg(({"mapa","dibujo"}),
"Puedes ver un mapa...\n\
                         Lago Zinn                 ------------\n\
   p                      Amazonas                 |   ISLA   |\n\
   u                                               |  GOLDHAI |\n\
   e             Ciudad                            ------------\n\
   r               de\n\
   t             Crowy\n\
   o\n\
\n");
 AddSubDetail(({"mapa","dibujo"}),
"Puedes ver un mapa...\n\
                         Lago Zinn                 ------------\n\
   p                      Amazonas                 |   ISLA   |\n\
   u                                               |  GOLDHAI |\n\
   e             Ciudad                            ------------\n\
   r               de\n\
   t             Crowy\n\
   o\n\
\n");

 AddSubReadMsg(({"texto","historia"}),
"Puedes leer...\n\
    Las amazonas somos un pueblo constituido única y exclusivamente por\n\
mujeres y que ha sobrevivido durante el principio de la colonización de\n\
Goldhai de forma unida. Es por ello que a ti, como mujer, te invitamos\n\
a conocernos y a vivir junto a nosotras.\n");
 AddSubDetail(({"texto","historia"}),
"Puedes leer...\n\
    Las amazonas somos un pueblo constituido única y exclusivamente por\n\
mujeres y que ha sobrevivido durante el principio de la colonización de\n\
Goldhai de forma unida. Es por ello que a ti, como mujer, te invitamos\n\
a conocernos y a vivir junto a nosotras.\n");
}

