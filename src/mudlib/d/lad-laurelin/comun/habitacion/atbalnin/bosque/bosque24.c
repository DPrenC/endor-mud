/***
Fichero_ bosque24.c
Autor: (sin comentarios en el archivo)
Modificaci�n: 21/12/2004 [kastwey@simauria]. A�ado aqu� la entrada a la zona de Faeria.
***/

#include "path.h"
#include <moving.h>
#include <skills.h>
#include <damage.h>


inherit ATB_B("bosque_este");
object arbol, cuerda;

#define ME capitalize(TI->QueryName())

int cmd_escalar(string str)
{
  int perc;

  if (str != "�rbol" && str != "arbol")
    return notify_fail("�Escalar qu�?\n"),0;
    if (!TP->CanSee())
  {
    return notify_fail("No ves nada... Decides no arriesgarte a escalar a ciegas "
                       "y tener un accidente.\n", NOTIFY_NOT_VALID);
  }
  if (!cuerda)
    return notify_fail("No podr�s escalar este �rbol sin antes engancharle una cuerda.\n"),0;

    write("Empiezas a escalar por la cuerda.\n");
  say(ME+" empieza a escalar por la cuerda.\n");

  perc=TI->UseSkill(HAB_TREPAR);
  if (perc<-50)
  {
    write("�La cuerda se te escapa por entre los dedos y caes haciendote da�o!\n");
    say(W("A "+ME+" se le escapa la cuerda por entre los dedos y cae dolorosamente.\n"));
    TI->Defend(50-(100+perc), DT_BLUDGEON);
    return 1;
  }
  if (perc<1)
  {
    write("�La cuerda se te escapa por entre los dedos y caes!\n");
    say(W("A "+ME+" se le escapa la cuerda por entre los dedos y cae.\n"));
    return 1;
  }

  if (TI->move(ATB_B("copa-del-arbol"),M_SPECIAL,({ME + " sube trepando por la cuerda","llega trepando por la cuerda","Consigues llegar hasta la copa del �rbol"})) != ME_OK) return write("Por alguna raz�n no puedes subir al �rbol.\nConsulta con un wizard.\n"),1;
  return 1;
}


int cmd_lanzar(string str)
{
  object *inv;
  int i, encontrado, perc, j;

  if (str!="cuerda a rama" && str!="cuerda a la rama"
    && str!="cuerda a las ramas" && str!="cuerda a �rbol"
    && str!="cuerda a arbol" && str!="cuerda contra arbol"
    && str!="cuerda contra �rbol")
      return write("�Lanzar qu� a d�nde?\n"),1;

  arbol=present("arbol");
  if (!arbol) return write("No hay ning�n �rbol al que atar la cuerda.\n"),1;
  inv=all_inventory(TI);
  i=0;
  encontrado=0;

  while(i<sizeof(inv) && !encontrado)
  {
    if (member(inherit_list(inv[i]), "/obj/cuerda.c")!=-1)
    {
      cuerda=inv[i];
      if (cuerda->QueryTied()[0]==0 && cuerda->QueryTied()[1]==0)
        encontrado=1;
    }
    i++;
  }
  if (!encontrado) return write("No tienes ninguna cuerda para lanzar.\n"),1;
  SetDieMsg(ME + " muere descalabrado en una ca�da.\n");

  if (!TP->CanSee())
  {
    return notify_fail("No ves nada... Te va a ser imposible lanzar la cuerda y "
                       "acertar.\n", NOTIFY_NOT_VALID);
  }
    perc=TI->UseSkill(HAB_LANZAR, 10);
  if (perc<-80)
  {
    say(ME + " lanza la cuerda con tan mala punter�a que la pierde.\n");
    cuerda->remove();
    return write("Lanzas la cuerda con tan mala punter�a que la pierdes.\n"),1;
  }
  if (perc<-60)
  {
    say(W(ME + " lanza la cuerda y se le escapa de entre los dedos, cayendo al suelo.\n"));
    cuerda->move(TO, M_SILENT);
    return write("Lanzas la cuerda y se te escapa de entre los dedos. La cuerda cae al suelo.\n"),1;
  }
  if (perc<1)
  {
    cuerda=0;
    return write("No consigues enganchar la cuerda en ning�n sitio.\n"),1;
  }
  cuerda->move(TO, M_SILENT);
  write(W("Lanzando la cuerda con punter�a consigues atar la cuerda a "
  	"una rama. Ahora puedes escalar el �rbol.\n"));
  say(W(ME + " consigue enganchar la cuerda a una rama con un lanzamiento "
  	"magistral.\n"));

  return 1;
}


int cmd_coger(string str)
{

  if (str=="cuerda" && cuerda)
  {
    if (!TP->CanSee()) return 0;
    write("Le das un tir�n a la cuerda y la recuperas.\n");
    say(ME + " le da un tir�n a la cuerda y la recupera.\n",TP);
    if (cuerda->move(TI, M_SILENT) != ME_OK)
    {
    	write("Sin poder evitarlo, la cuerda se te cae al suelo.\n");
    	say("a " + ME + " se le cae la cuerda al suelo.\n",TP);
    }
    cuerda->SetNoTake(cuerda->Query("P0"));
    cuerda->SetNoGive(cuerda->Query("P1"));
    cuerda->SetTied(({0, 0}));
    cuerda=0;
    return 1;
  }
  return 0;
}



create()
{
  ::create();

  SetIntLong(QueryIntLong()+
  	W("Est�s frente a un enorme �rbol. A juzgar por su tama�o, "
  	"seguramente estar� aqu� desde el principio de los tiempos.\n"
  	"Tambi�n puedes ver un borroso sendero que se aleja del bosque en direcci�n norte.\n"));
  SetIntShort("la zona este frente a un enorme �rbol");
  AddDetail(({"sendero","camino"}),"Es un sendero apenas visible entre la maleza del bosque.\n");
  AddItem(OTRO("arbol_legendario"), REFRESH_DESTRUCT);
  AddItem(QUEST+"/ent", REFRESH_REMOVE, 3+random(4));

  SetDieMsg("�#jug# cae de un �rbol y se rompe el cuello!");

  AddExit("oeste", ATB_B("bosque23"));
  AddExit("norte",HAB_PUESTO("calles/sendero1"));
  AddRoomCmd("lanzar",SF(cmd_lanzar));
  AddRoomCmd("escalar", SF(cmd_escalar));
  AddRoomCmd("coger", SF(cmd_coger));
}