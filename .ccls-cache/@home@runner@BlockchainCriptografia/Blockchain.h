#ifndef Blockchain_H
#define Blockchain_H
#include "Block.h"
#include <vector>

class Blockchain {
private:
  vector<Block> BlockChain;

public:
  Blockchain();
  vector<Block> get_BlockChain();
  void ShowBlockchain();
  void ShowBlock(int);
  void AddBlock(Block &);
  bool CheckHash(int, size_t);
};
#endif

void Blockchain::ShowBlock(int index) {
  cout << "===========================" << endl;
  cout << "Carimbo de data e hora:" << endl;
  cout << BlockChain[index].get_Transaction().get_Timestamp() << endl;
  cout << "nonce:" << endl;
  cout << BlockChain[index].get_nonce() << endl;
  cout << "Hash atual:" << endl;
  cout << BlockChain[index].get_CurrentHash() << endl;
  cout << "Hash anterior:" << endl;
  cout << BlockChain[index].get_PrevHash() << endl;
  cout << "Dificuldade:" << endl;
  cout << BlockChain[index].get_Difficulty() << endl;
  cout << "===========================" << endl;
}

bool Blockchain::CheckHash(int index, size_t PrevHash) {
  if (BlockChain[index - 1].get_PrevHash() == PrevHash) {
    return true;
  }
  return false;
}

Blockchain::Blockchain() {
  Transaction GenesisTrans("", "", 0.00);
  Block Genesis(GenesisTrans, 0, 0);
  Genesis.set_nonce(0);
  BlockChain.push_back(Genesis);
}

vector<Block> Blockchain::get_BlockChain() { return BlockChain; }

void Blockchain::AddBlock(Block &block) {
  if (block.POW() == true) {
    BlockChain.push_back(block);
  } else {
    cout << "Block inválido!" << endl;
  }
}

void Blockchain::ShowBlockchain() {
  for (int i = 0; i < BlockChain.size(); i++) {
    cout << "============Block[" << i << "]===============" << endl;
    cout << "Carimbo de data e hora:" << endl;
    cout << BlockChain[i].get_Transaction().get_Timestamp() << endl;
    cout << "nonce:" << endl;
    cout << BlockChain[i].get_nonce() << endl;
    cout << "Hash atual:" << endl;
    cout << BlockChain[i].get_CurrentHash() << endl;
    cout << "Hash anterio:" << endl;
    cout << BlockChain[i].get_PrevHash() << endl;
    cout << "Dificuldade:" << endl;
    cout << BlockChain[i].get_Difficulty() << endl;
    cout << "===========================" << endl;
  }
}