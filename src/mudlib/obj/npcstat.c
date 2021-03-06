// Statistic object for gathering the object numbers
// of all loaded NPCs.

mixed npcs;

void create()
{
  npcs = ({ });
}

mixed display(object ob)
{
  string str;
  str = sprintf("%-20s %3d %O",ob->QueryName(),ob->QueryGoChance(),ob->HeartDebug());
  return str;
}

mixed Query()
{
  npcs = npcs - ({ 0 });
  return map(npcs, "display", TO);
}

void Add(object ob)
{
  npcs += ({ ob });
}
