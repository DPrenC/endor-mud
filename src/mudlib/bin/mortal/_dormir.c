// Comando dormir

#include <sounds.h>

public int main(string arg) {
  if (!TP) return 0;

  if (TP->QueryStatusSleeping()) {
    write("Te despiertas y te pones en pie.\n");
    say(capitalize(TP->QueryName())+" se despierta y se pone en pie.\n");
    TP->SetStatusNormal();
    play_sound(environment(TP), SND_SUCESOS("despertar"));
    return 1;
  }
  else {
    if (TP->Fighting()) return notify_fail("¡No puedes dormirte en pleno combate!\n");
    write("Te tumbas en el suelo y caes en un profundo sueño.\n");
    say(capitalize(TP->QueryName())+" se tumba en el suelo y se duerme placidamente.\n");
    TP->SetStatusSleeping();
    play_sound(environment(TP), SND_SUCESOS("dormir"));
    return 1;
  }
  
  return 0;
}