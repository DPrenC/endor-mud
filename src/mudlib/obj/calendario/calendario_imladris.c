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
  SetNomMeses(([1:"tuil�",2:"lair�",3:"y�vi�",4:"quell�",5:"hr�v�",6:"coir�"]));
  SetNumDiasPorSemana(6);
  SetNomDias(([1:"orghilion",2:"oranor",3:"orithil",4:"orgaladhad",5:"ormenel",6:"orbelain"]));
  SetAnyoBase(6500);
}


