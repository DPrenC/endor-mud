int beber(string str)
{
 if (!str)
  return notify_fail("¿Qué es lo que quieres beber?\n"),0;
 if (str != "agua" && str != "agua del río" &&
     str != "agua del cashigan" && str != "agua río" &&
     str != "río" && str != "cashigan")
  return notify_fail("No creo que puedas beber eso.\n"),0;

 this_player()->SetDrink(this_player()->QueryDrink()-5);
 write("Te agachas en la orilla y bebes un poco de agua del río.\n");
 write("Arrrgghhhhh... el agua esta salada y te está entrando más sed.\n");
 say(CAP(TNREAL)+" se agacha y bebe un poco de agua del río Cashigan.\n");
 return 1;
}
