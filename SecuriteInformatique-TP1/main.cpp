//
//  main.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-15.
//

#include "DictionaryAttack.hpp"
#include <iostream>
#include <thread>
#include <fstream>

DictionaryAttack dic("Hash.txt");
std::vector<std::thread> threads;
int state = 0;

void printAllKLengthRec(char set[], std::string prefix, int n, int k)
{
    if (k == 0)
    {
        std::string hash = dic.wordToHash(prefix);
//        std::cout << (prefix) << std::endl;
        if (dic.isInMyHash(hash)) {
            std::ofstream myfile;
            myfile.open ("result.txt");
            myfile << prefix << " = " << hash << std::endl;
            myfile.close();
            std::cout << prefix << " = " << hash << std::endl;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        std::string newPrefix;
        newPrefix = prefix + set[i];
        if (threads.size() <= 50) {
            threads.push_back(std::thread(&printAllKLengthRec, set, newPrefix, n, k - 1));
        } else {
            printAllKLengthRec(set, newPrefix, n, k - 1);
            state += 1;
        }
    }
}

void exo2() {
    char set[44] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*'};
    int k = int(std::strlen(set));

    for (int i = 1; i <= 8; i++) {
        printAllKLengthRec(set, "", k, i);
        for (int x = 0; x < threads.size(); x++) {
            if (threads[x].joinable()) {
                threads[x].join();
                threads.erase(threads.begin() + x);
            }
        }
//        if (threads.size() <= 5) {
//            threads.push_back(std::thread(&printAllKLengthRec, set, "", k, i));
//            i--;
//        }
    }
}

int main( int argc, char **argv) {
    

//    dic.startIntoThreads("Dictionary.txt", 1);

    exo2();
//    std::cout << dic.wordToHash("aceahdhj") << std::endl;
    return 0;
}
