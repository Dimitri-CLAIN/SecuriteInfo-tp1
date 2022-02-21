//
//  main.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-15.
//

#include "DictionaryAttack.hpp"
#include <iostream>
#include <thread>

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

void exo2() {
    char set[44] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*'};
//    char set[5] = {'a','b','c','d', '\0'};
    int k = int(std::strlen(set));
    std::vector<std::thread> threads;

    for (int i = 8; i >= 0;) {
        if (threads.size() <= 5) {
            threads.push_back(std::thread(&printAllKLengthRec, set, "", k, i));
            i--;
        }
    }
    for (auto &th : threads) {
        if (th.joinable())
            th.join();
    }
}

int main( int argc, char **argv) {
    

//    dic.startIntoThreads("Dictionary.txt", 1);
    
    exo2();
    return 0;
}
