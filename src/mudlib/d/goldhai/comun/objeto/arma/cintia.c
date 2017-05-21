/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 23-02-99                |
 |               Ultima Modificacion.. 26-10-00                |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <materials.h>
#include <properties.h>

inherit WEAPON;

create()
{
  if(!clonep(TO)) return;
 ::create();
 SetStandard(WT_ESPADA,7,P_SIZE_LARGE,M_ACERO);
 SetWeight(QueryWeight()+3000); // Un poco mas de peso
 SetShort("la espada 'cintia'");
 SetIds(({"espada","espada cintia","cintia","espada 'cintia'"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Se trata de la famosa espada 'cintia' creada por un herrero humano hace\n\
algunos años. En la hoja puedes ver una frase que dice:\n\
   'Esta espada representa la libertad del pueblo humano'\n");
}
