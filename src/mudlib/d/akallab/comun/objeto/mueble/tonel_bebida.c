/*
DESCRIPCION  : tonel de bebida
FICHERO      : /d/akallab/comun/objeto/mueble/tonel_bebida
MODIFICACION : 16-09-01 [Angor@Simauria] Creacion
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <messages.h>

//contenido
#define TONEL_VINO_TINTO_JOVEN 0
#define TONEL_VINO_TINTO_VIEJO 1
#define TONEL_VINO_TINTO_PICADO 2
#define TONEL_VINO_TINTO_BUENO 3

#define TONEL_CERVEZA_WEISS 4
#define TONEL_CERVEZA_SCHWARTZ 5
#define TONEL_CERVEZA_PILS 6
#define TONEL_CERVEZA_BRUNE 7

//volumen (cc)
#define VOLUMEN_PASO 25 //tamaño botellin
#define VOLUMEN_MAX  5000 //50 l

int tipo;
int volumen;
string contenido;
string variedad;
string adjetivo;
int alcohol;
int sed;
int vida;

string VerTonel()
{
 string s;
 s="Es un gran tonel de madera que, por el olor que desprende, dirias que "
   "de "+contenido+". Abres un momento su espita y observas que ";
 if (volumen==0) s+="esta vacio";
 else s+="contiene "+contenido+" "+variedad;
 return (s+".\n");
}

SetVolumen(int i)
{
  volumen=(i>VOLUMEN_MAX? VOLUMEN_MAX: i);
  return;
}


SetTonelTipo(int i)
{
  switch(i)
  {
  case TONEL_VINO_TINTO_JOVEN:
       {
	   tipo=i;
	   contenido="vino";
	   variedad="tinto";
	   adjetivo="joven";
	   alcohol=2;
	   sed=1;
	   vida=2;
	   break;
	   }
  case TONEL_VINO_TINTO_VIEJO:
       {
	   tipo=i;
	   contenido="vino";
	   variedad="tinto";
	   adjetivo="viejo";
	   alcohol=3;
	   sed=1;
   	   vida=3;
	   break;
	   }
  case TONEL_VINO_TINTO_PICADO:
       {
	   tipo=i;
	   contenido="vino";
	   variedad="tinto";
	   adjetivo="picado";
	   alcohol=3;
	   sed=1;
	   vida=1;
	   break;
	   }
  case TONEL_VINO_TINTO_BUENO:
       {
	   tipo=2;
	   contenido="vino";
	   variedad="tinto";
	   adjetivo="bueno";
	   alcohol=2;
	   sed=2;
	   vida=3;
	   break;
	   }
  case TONEL_CERVEZA_WEISS:
       {
	   tipo=i;
	   contenido="cerveza";
	   variedad="blanca";
	   adjetivo="suave";
       alcohol=1;
	   sed=3;
	   vida=2;
	   break;
	   }
  case TONEL_CERVEZA_SCHWARTZ:
       {
  	   tipo=i;
  	   contenido="cerveza";
	   variedad="negra";
	   adjetivo="fuerte";
	   alcohol=1;
	   sed=2;
	   vida=2;
  	   break;
	   }
  case TONEL_CERVEZA_PILS:
       {
  	   tipo=i;
  	   contenido="cerveza";
	   variedad="rubia";
	   adjetivo="amarga";
	   alcohol=1;
	   sed=2;
	   vida=1;
  	   break;
	   }
  case TONEL_CERVEZA_BRUNE:
       {
   	   tipo=i;
   	   contenido="cerveza";
	   variedad="morena";
	   adjetivo="con cuerpo";
	   alcohol=1;
	   sed=2;
	   vida=2;
   	   break;
  	   }
  }


}

create() {
 ::create();
 SetVolumen(100+random(1000));
 SetTonelTipo(TONEL_VINO_TINTO_JOVEN);
 AddId("tonel");
 SetShort("un tonel");
 SetLong(VerTonel());
 SetWeight(20000);
 SetValue(100);
}

init() {
  ::init();
  add_action("beber_cmd","beber");
}

int beber_cmd(string str)
{
int ok;
string que,donde,suf;
int incSed, incVida, incAlc;

  ok=0;
  if (!TP) return 0;
  if (!str)
  {
  write("¿Beber que? ('beber de tonel' o 'beber <bebida> de tonel' "
    "para beber de alli)\n");
  return 0;
  }
  if (sscanf(str,"de %s",donde)==1)
  {
     //write("donde["+donde+"]\n");
     if (donde=="tonel") ok=1;
	 else
	 {
	 write("No puedes beber de "+donde+".\n");
	 return 0;
	 }
  }
  else
  {
     if (sscanf(str,"%s de %s",que,donde)==2)
	 {
	 write("que["+que+"] donde["+donde+"]\n");
	     if ((donde=="tonel")&&(que==contenido)) ok=1;
	     else
	     {
	         if (donde!="tonel") write("No puedes beber de "+donde+".\n");
		     else write("Este tonel contiene "+contenido+", no "+que+".\n");
             return 0;
	     }
	 }
	 else
	 {
         write("¿Beber que? ('beber de tonel' o 'beber <bebida> de tonel' "
		 "para beber de alli)\n");
	     return 0;
	 }

  }


  if (ok==1)
  {
     if (volumen>=0)
	 {
	   //write("volumen["+volumen+"]");
       volumen=(volumen-VOLUMEN_PASO<0?0:volumen-VOLUMEN_PASO);
       //write("volumen nuevo["+volumen+"]");

	   incSed=VOLUMEN_PASO/5*sed;
	   incVida=VOLUMEN_PASO/5*vida;
	   incAlc=VOLUMEN_PASO/5*alcohol;

	   //write("sed ["+incSed+"] vida["+incVida+"] alcohol["+incAlc+"].\n");

	    TP->AddDrink(incSed);
	    TP->AddAlcohol(incAlc);
	    TP->Heal(incVida);

       write("Abres la espita del tonel y bebes un trago de "+contenido+". Por su sabor, "
	     "se trata de un"+(tipo>=TONEL_CERVEZA_WEISS?"a ":" ")+contenido +" "+variedad+" "+
	     adjetivo+". Te sientes refrescad"+AO+" y apagas parte de tu sed.\n");
       tell_room(TO, ({ MSG_SEE, capitalize(TP->QueryName())+" bebe un poco de "+contenido+" de un tonel.\n" }), ({ TP }));
  }
  else
  {
       write("Abres la espita del tonel e intentas beber un trago de "+contenido+", pero "
	     "das cuenta de que el tonel esta vacio.\n");
       tell_room(TO, ({ MSG_SEE, capitalize(TP->QueryName())+" intenta beber un poco de "+contenido+
	     " de un tonel, pero se da cuenta de que esta vacio.\n" }), ({ TP }));
  }
  return 1;
  }
return 0;
}
