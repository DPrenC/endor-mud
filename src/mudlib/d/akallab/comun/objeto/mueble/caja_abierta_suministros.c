/*
DESCRIPCION  : una caja abierta con suministros
FICHERO      : /d/akallab/comun/objeto/mueble/caja_abierta_suministros.c
MODIFICACION : 16-09-01 [Angor@Simauria] Creacion
*/


#include "./path.h"

#include <properties.h>

inherit CONTAINER;


#define PEQUENYO 0
#define MEDIO 1
#define GRANDE 2

#define MANZANAS 0
#define NARANJAS 1
#define PATATAS 2
#define CEBOLLA 3
#define PESCADO 4

int contMax;

void hacerDesc(int tipo)
{

 switch (tipo)
 {
 case PEQUENYO:
    {
	SetShort("una caja pequeña");
    SetLong("Es una pequeña caja de madera sin tapadera.\n");
    SetIntShort("dentro de una pequeña caja");
    SetIntLong("Estas en el interior de una pequeña caja de madera.\n");
	AddId(({"caja","cajon"}));
	contMax=3;
    SetWeight(1000);
    break;
    }
 case MEDIO:
    {
	SetShort("una caja mediana");
    SetLong("Es una caja de mediano tamaño de madera sin tapadera.\n");
    SetIntShort("dentro de una caja de mediano tamaño");
    SetIntLong("Estas en el interior de una caja de mediano tamaño de madera.\n");
	AddId(({"barril"}));
	contMax=8;
    SetWeight(5000);
    break;
    }
 case GRANDE:
    {
	SetShort("un gran cajon");
    SetLong("Es un cajon de gran tamaño de madera sin tapadera.\n");
    SetPreIntShort("dentro de");
    SetIntShort("un cajón de gran tamaño");
    SetIntLong("Estas en el interior de un cajon de gran tamaño de madera.\n");
	AddId(({"barril"}));
	contMax=15;
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
	case CEBOLLA:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/cebolla");
		break;
		}
	case PESCADO:
	    {
		ob=clone_object("/d/akallab/comun/objeto/comida/bacalao");
		break;
		}
   }

   ob->move(TO);
  }
}

create () {
  object ob;
  int tipo;
  int i, j;

  ::create();

  contMax=1;
  tipo=random(GRANDE+1);
  hacerDesc(tipo);

  SetPreContent("Contiene:\n");
  SetValue(100);
  //SetWeight(1000);
  SetMaxIntWeight(75000);
  Set(P_NOGET,1);

  //objetos que contiene:
  tipo=random(PESCADO+1);
  hacerContenido(contMax, tipo);
  AddId(({"caja","cajon"}));
}