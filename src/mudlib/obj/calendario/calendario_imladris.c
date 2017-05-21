/*
DESCRIPCION  : calendario de Imladris, para los elfos del Oeste
FICHERO      : /obj/calendario/calendario_imladris.c
*/

inherit "/obj/calendario/calendario";

public void create()
{
  ::create();
  SetTipoCalendario("imladris");
  SetNumMesesPorAnyo(6);
  SetNomMeses(([1:"tuilë",2:"lairë",3:"yávië",4:"quellë",5:"hrívë",6:"coirë"]));
  SetNumDiasPorSemana(6);
  SetNomDias(([1:"orghilion",2:"oranor",3:"orithil",4:"orgaladhad",5:"ormenel",6:"orbelain"]));
  SetAnyoBase(6500);
}


