#include "Blockchain.h"

int main() {
  Blockchain BlockChain;

  while (true) {
	  
cout << "\n\n╔╗ ┬  ┌─┐┌─┐┬┌─┌─┐┬ ┬┌─┐┬┌┐┌" << endl;
cout << "╠╩╗│  │ ││  ├┴┐│  ├─┤├─┤││││" << endl;
cout << "╚═╝┴─┘└─┘└─┘┴ ┴└─┘┴ ┴┴ ┴┴┘└┘\n\n" << endl;

	  cout << "🇨​​​​​🇷​​​​​🇮​​​​​🇵​​​​​🇹​​​​​🇴​​​​​🇬​​​​​🇷​​​​​🇦​​​​​🇫​​​​​🇮​​​​​🇦​​​​​\n\n" << endl;
	  
	cout << "Escolha uma Opção" << endl;
    cout << "Transferindo Dinheiro(💲):  1" << endl;
    cout << "Ver Dados de um Bloco:   2" << endl;
    cout << "Veja o Blockchain: 3" << endl;
    cout << "Feche o programa:  4" << endl;
    cout << "Escolha um número:" << endl;
    char Ans;
    cin >> Ans;
    if (Ans == '1') {
      string SenderKey, ReceiverKey;
      double Amount;
      int Diff;
      cout << "Digite sua SenderKey (Chave do Remetente):" << endl;
      cin >> SenderKey;
      cout << "Digite sua ReceiverKey (Chave do Receptor) :" << endl;
      cin >> ReceiverKey;
      cout << "Digite o valor:" << endl;
      cin >> Amount;
      cout << "Digite sua dificuldade ou zero para ignorar:" << endl;
      cin >> Diff;

      Transaction T1(SenderKey, ReceiverKey, Amount);

      if (Diff == 0) {
        Block block(
            T1,
            BlockChain.get_BlockChain()[BlockChain.get_BlockChain().size() - 1]
                .get_CurrentHash(),
            BlockChain.get_BlockChain().size());

        BlockChain.AddBlock(block);

        BlockChain.CheckHash(block.get_index() - 1, block.get_PrevHash());
      } else {
        Block block(
            T1,
            BlockChain.get_BlockChain()[BlockChain.get_BlockChain().size() - 1]
                .get_CurrentHash(),
            BlockChain.get_BlockChain().size(), Diff);

        BlockChain.AddBlock(block);

        BlockChain.CheckHash(block.get_index() - 1, block.get_PrevHash());
      }
    } else {
      switch (Ans) {
      case '2':
        cout << "Digite seu índice:" << endl;
        int index;
        cin >> index;
        if (index > BlockChain.get_BlockChain().size() || index < 1) {
          cout << "\n====== Não há nenhum bloco com este índice! ======\n"
               << endl;
        } else {
          BlockChain.ShowBlock(index - 1);
        }
        break;
      case '3':
        cout << "Sakhtan" << endl;
        break;
      case '4':
        BlockChain.ShowBlockchain();
        break;
      default:
        cout << "Escolha Errada!" << endl;
        break;
      }
    }
  }
}