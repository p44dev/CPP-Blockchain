#include <iostream>
#include <ctime>
#include <vector>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

int main()
{
    // Start Blockchain
    Blockchain awesomeCoin;
    
    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    awesomeCoin.addBlock(data1);
    
    time_t data2Time;
    TransactionData data2(0.2233, "Martha", "Fred", time(&data2Time));
    awesomeCoin.addBlock(data2);
    
    // Let's see what's in the awesomeCoin blockchain!
    awesomeCoin.printChain();
    
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    // Someone's getting sneaky
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000; 
    hackBlock->data.receiverKey = "Mark";

    // Look at data
    awesomeCoin.printChain();

    // Why is it not valid?
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    return 0;
}
