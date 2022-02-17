//
//  main.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-15.
//

#include "DictionaryAttack.hpp"

int main(int argc, const char * argv[]) {
    DictionaryAttack dic("Hash.txt");
    dic.startIntoThreads("Dictionary.txt", 1);
    return 0;
}

// https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php
