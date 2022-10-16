#ifndef DICC_SORTED_VECTOR
#define DICC_SORTED_VECTOR

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include "ED.cc"
#include <algorithm>


using namespace std;

class diccSortedVector : EstructuraDades {

private:

    vector<string> Dictionary;

    SearchResult FindDicctionary(int inf, int sup, string n){
        if(inf > sup)
        return SearchResult::WORD_NOT_FOUND;
        else {
            int central;
            central = (inf + sup)/2;
            int cpm = n.compare(Dictionary[central]);
            if(cpm == 0){
                return SearchResult::WORD_FOUND;
            }
            else{
                if(cpm > 0)
                    return FindDicctionary(central+1,sup,n);
                else
                    return FindDicctionary(inf,central-1,n);
            }
        }
    }

public:

    void addWord(string word) {
        if(word=="") return;
        Dictionary.push_back(word);
    }

    void sorterDictionary(){
        sort(Dictionary.begin(), Dictionary.end());
    }

    SearchResult findWord(string n){
        return FindDicctionary(0,Dictionary.size()-1,n);
    }

    vector<string> data() {
        return Dictionary;
    }

};

#endif