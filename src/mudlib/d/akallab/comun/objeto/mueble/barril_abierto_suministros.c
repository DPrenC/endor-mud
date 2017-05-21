/*
DESCRIPCION  : un barril abierto con sumistros
FICHERO      : /d/akallab/comun/objeto/mueble/barril_abierto_suministros.c
MODIFICACION : 15-09-01 [Angor@Simauria] Creacion
*/

inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

#include <properties.h>
#define BARRIL_PEQUENYO 0
#define BARRIL_MEDIO 1
#define BARRIL_GRANDE 2

#define MANZANAS 0
#define NARANJAS 1
#define PATATAS 2
#define CARNE 3
#define PESCADO 4

int contMax;

void hacerDesc(int tipo)
{

 switch (tipo)
 {
 case BARRIL_PEQUENYO:
    {
	SetShort("un barril peque�o");
    SetLong("Es un peque�o barril de madera sin tapadera.\n");
    SetIntShort("dentro de un peque�o barril");
    SetIntLong("Estas en el interior de un peque�o barril de madera.\n");
	AddId(({"barril"}));
	contMax=3;
    SetWeight(1000);
    break;
    }
 case BARRIL_MEDIO:
    {
	SetShort("un barril mediano");
    SetLong("Es un barril de mediano tama�o de madera sin tapadera.\n");
    SetIntShort("dentro de un barril de mediano tama�o");
    SetIntLong("Estas en el interior de un barril de mediano tama�o de madera.\n");
	AddId(({"barril"}));
	contMax=6;
    SetWeight(5000);
    break;
    }
 case BARRIL_GRANDE:
    {
	SetShort("un barril grande");
    SetLong("Es un barril de gran tama�o de madera sin tapadera.\n");
    SetPreIntShort("dentro de");
    SetIntShort("un barril de gran tama�o");
    SetIntLong("Estas en el interior de un barril de gran tama�o de madera.\n");
	AddId(({"barril"}));
	contMax=9;
    SetWeight(10000);
    break;
    }
 }
}

hacerContenido(int max, int tipo)
{
  object ob;
  int i,j;
  i=random(max)+1;
  for(j=0;j<i;j++)
  {
   switch(tipo)
   {
     case MANZANAS:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/manzana");
		break;
		}
	case NARANJAS:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/naranja");
		break;
		}
	case PATATAS:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/patata");
		break;
		}
	case CARNE:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/cecina");
		break;
		}
	case PESCADO:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/salmon_ahumado");
		break;
		}
   }

   ob->move(TO);
  }
}

create ()
{
  int tipo;


  ::create();

  contMax=1;
  tipo=random(BARRIL_GRANDE+1);
  hacerDesc(tipo);

  Set(P_NOGET,1);

  SetPreContent("Contiene:\n");
  SetValue(100);
  //SetWeight(1000);
  SetMaxIntWeight(75000);

  //objetos que contiene:
  tipo=random(PESCADO+1);
  hacerContenido(contMax, tipo);
}