// Comando salidas

int main() {
  if (TP->SetObvious(!TP->QueryObvious()))
    write("Mostrando salidas obvias.\n");
  else
    write("Ocultando salidas obvias.\n");
  return 1;
}
