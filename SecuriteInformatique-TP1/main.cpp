//
//  main.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-15.
//

#include "DictionaryAttack.hpp"
#include <iostream>

DictionaryAttack dic("Hash.txt");

void printAllKLengthRec(char set[], std::string prefix, int n, int k)
{
    if (k == 0)
    {
//        std::cout << (prefix) << std::endl;
        dic.isInMyHash(dic.wordToHash(prefix));
        return;
    }
    for (int i = 0; i < n; i++)
    {
        std::string newPrefix;
        newPrefix = prefix + set[i];
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
}

int main( int argc, char **argv) {
    char set[44] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*'};
    int k = int(std::strlen(set));

//    dic.startIntoThreads("Dictionary.txt", 1);
    
    for (int i = 1; i <= 8; i++)
        printAllKLengthRec(set, "", k, i);
    return 0;
}
