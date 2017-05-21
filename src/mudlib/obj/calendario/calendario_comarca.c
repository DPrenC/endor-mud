/*
DESCRIPCION  : calendario de la Comarca, también válido para Bree
FICHERO      : /obj/calendario/calendario_comarca.c
*/

inherit "/obj/calendario/calendario";

public void create()
{
  ::create();
  SetTipoCalendario("comarca");
  SetNumMesesPorAnyo(12);
  SetNomMeses(([1:"postyule",2:"solmath",3:"rete",4:"astron",5:"thrimidge",6:"antelithe",7:"postlithe",8:"wedmath",9:"halimath",10:"crudo invierno",11:"blotmath",12:"anteyule"]));
  SetNumDiasPorSemana(7);
  SetNomDias(([1:"dister",2:"disol",3:"dilún",4:"dimar",5:"dimer",6:"dijov",7:"dialt"]));
  SetAnyoBase(1400);
}


