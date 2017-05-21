// Comando descansar

public int main(string arg) {
  if (!TP) return 0;

  if (TP->QueryStatusResting()) {
    write("Te pones en pie.\n");
    say(capitalize(TP->QueryName())+" se pone en pie.\n");
    TP->SetStatusNormal();
    return 1;
  }
  else {
    if (TP->Fighting()) return notify_fail("No te puedes poner a descansar en pleno combate.\n");
    
    if (TP->QueryStatusSleeping()) {
      write("Te despiertas y te reincorporas, quedando sentado.\n");
      say(capitalize(TP->QueryName())+" se despierta, se incorpora y queda sentado.\n");
    }
    else {
      write("Te sientas a descansar.\n");
      say(capitalize(TP->QueryName())+" se sienta a descansar.\n");
    }
    TP->SetStatusResting();
    return 1;
  }
  
  return 0;
}