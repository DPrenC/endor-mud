#include "path.h"
inherit ATB_CI("std_ciudad");
private int estado_fragua;
create()
{
  ::create();
  SetIntLong(W(
  "Est�s en la fragua del prestigioso enano solpador Kheron, es una"
  " estancia oscura y c�lida debido al calor que se necesita para solpar"
  " el vidrio, es una sala peque�a donde puedes ver multitud de objetos"
  " de vidrio tremendamente hermosos, lo que demuestra el arte de Kheron"
  ".\n"));
AddItem(PNJ("atbalnin/ciudad/Kheron"), REFRESH_DESTRUCT, 1);
    AddExit("nordeste", ATB_CI("ciudad06"));
}
int SetFragua(int valor){
estado_fragua=valor;
return 1;
}
int QueryFragua()
{
return estado_fragua;
}


init(){
SetFragua(0);
::init();}