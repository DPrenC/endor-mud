
inherit THING;
mapping maps;

Cosa()
{
  write(maps+"\n");
  return(1);
}

create()
{
  ::create();
  SetShort("un poco de yesca");
  SetLong("Es yesca, un amasijo de ramitas secas y otras cosas.\n");
  SetWeight(100);
  SetValue(5);
  AddId("yesca");
}

