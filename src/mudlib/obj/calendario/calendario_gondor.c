/*
DESCRIPCION  : calendario de los Dúnedain para Gondor y antaño para Arnor.
FICHERO      : /obj/calendario/calendario_gondor.c
*/

inherit "/obj/calendario/calendario";

public void create()
{
  ::create();
  SetTipoCalendario("gondor");
  SetNumMesesPorAnyo(12);
  SetNomMeses(([1:"narwain",2:"nínui",3:"gwaeron",4:"gwirith",5:"lothron",6:"nórui",7:"cerveth",8:"urui",9:"ivanneth",10:"narbeleth",11:"hithui",12:"girithron"]));
  SetNumDiasPorSemana(7);
  SetNomDias(([1:"orghilion",2:"oranor",3:"orithil",4:"orgaladh",5:"ormenel",6:"orbelain",7:"oraearon"]));
  SetAnyoBase(3000);
}


