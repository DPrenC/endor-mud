// Comando titulo

public int main(string str) {
  if (!TP) return 0;

  if (!str) {
    write("Tu t�tulo es " + TP->QueryTitle() + ".\n");
    return 1;
  }
  TP->SetTitle(str);
  return 1;
}