#include "Blockchain.hpp"
using namespace my_blockchain;
int main(int argc, char const *argv[])
{

  Blockchain my_blockchain(4, 100); // (Mining difficulty, Reward)
  // Generate new Private and Public keys.
  MyPrivateKey private_key = GeneratePrivateKey();
  std::string wallet_address = GetPublicKey(private_key);
  std::cout << "Wallet Address " << wallet_address << std::endl;
  // Create a new Transaction and sign it with the Private Key.
  Transaction tr(wallet_address, "another_Wallet", 10);
  tr.SignTransaction(private_key);
  // Add the transaction to the Blockchain.
  my_blockchain.AddTransaction(tr);
  // Mine a new Block and send the mining reward to wallet_address
  my_blockchain.AddBlock(wallet_address);
  // Print the BlockChain in JSON Format.
  my_blockchain.JSON();

  return 0;
}
