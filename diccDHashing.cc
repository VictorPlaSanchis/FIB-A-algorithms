#ifndef DICC_DOUBLE_HASHING
#define DICC_DOUBLE_HASHING

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <bitset>
#include "ED.cc"
using namespace std;

#define MAX_SIZE 5000000
#define MIN_SIZE 2
#define NULL_ELEMENT "_NULL_ELEMENT_"
#define DELETED_ELEMENT "_DELETED_ELEMENT_"

class diccDHashing {

private:

    unsigned int size;
    unsigned int keysAdded;
    unsigned int biggestPrime;

    vector<string> hashTable;
    bitset<MAX_SIZE> primeNumbers;

    void setPrimeNumbers(){
        primeNumbers = bitset<MAX_SIZE>();
        primeNumbers.set(0);
        primeNumbers.set(1);
        for(int i = 2; i*i <= MAX_SIZE; i++) {
            if(primeNumbers.test(i)) {
                for(int j = i*i; j <= MAX_SIZE; j += i) {
		    if(primeNumbers.test(j))
                    	primeNumbers.flip(j);
                }
            }
        }
    }

     int getValue(string word) {
        return hash<string>{}(word);
    }

    int hash1(string word){
        return getValue(word)%size;
    }

    int hash2(string word){
        return this->biggestPrime - (getValue(word)%biggestPrime);
    }

public:

    diccDHashing(int size = MAX_SIZE){
        if(size > MAX_SIZE) throw invalid_argument("La tabla no puede ser mas grande que 10000000000...");
        if(size < MIN_SIZE) throw invalid_argument("La tabla tiene que ser minimamente de 2 posiciones...");

        setPrimeNumbers();

        this->size = size;
        this->keysAdded = 0;

        this->biggestPrime = size - 1;
        while(!primeNumbers.test(biggestPrime)) {
            this->biggestPrime--;
        }

        for(int i = 0; i < size; i++) {
            hashTable.push_back(NULL_ELEMENT);
        }
    }

    void addWord(string word){
        if(word=="") return;
        //cout << "Adding word:{" << word << "}" << endl;
        
        if(findWord(word) == SearchResult::WORD_FOUND) {
            cout<<("ERROR : Palabra ya en la tabla!\n");
            return;
        }

        if(this->size <= this->keysAdded) {
            cout<<("ERROR : Tabla llena!\n");
            return;
        }

        int probe = hash1(word);
        int offset = hash2(word);

        while(hashTable[probe] != NULL_ELEMENT){
            if(DELETED_ELEMENT == hashTable[probe])
                break;
            probe = (probe+offset) % size;
        }

        hashTable[probe] = word;
        keysAdded++;
    }

    void printTable() {
        int i=0;
        for(string word : hashTable) {
            cout << i++ << ": " << word << endl;
        }
    }

    SearchResult findWord(string word){
        int probe = hash1(word);
        int offset = hash2(word);
        int initialPos = probe;
        bool firstItr = true;

	int its = 0;
        while(true){
	    if(its>MAX_SIZE) break;
            if(hashTable[probe] == NULL_ELEMENT)
                break;
            else if(hashTable[probe] == word)
                return SearchResult::WORD_FOUND;
            else if(probe == initialPos && !firstItr)
                return SearchResult::WORD_NOT_FOUND;
            else
                probe = ((probe + offset) % this->size);
            firstItr = SearchResult::WORD_NOT_FOUND;
	    its++;
        }
        return SearchResult::WORD_NOT_FOUND;
    }

};

#endif