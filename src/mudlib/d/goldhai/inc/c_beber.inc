int beber(string str)
{
 if (!str)
  return notify_fail("�Qu� es lo que quieres beber?\n"),0;
 if (str != "agua" && str != "agua del r�o" &&
     str != "agua del cashigan" && str != "agua r�o" &&
     str != "r�o" && str != "cashigan")
  return notify_fail("No creo que puedas beber eso.\n"),0;

 this_player()->SetDrink(this_player()->QueryDrink()-5);
 write("Te agachas en la orilla y bebes un poco de agua del r�o.\n");
 write("Arrrgghhhhh... el agua esta salada y te est� entrando m�s sed.\n");
 say(CAP(TNREAL)+" se agacha y bebe un poco de agua del r�o Cashigan.\n");
 return 1;
}
