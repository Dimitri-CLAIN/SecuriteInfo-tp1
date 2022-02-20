//
//  main.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-15.
//

#include "DictionaryAttack.hpp"
#include <iostream>

//int rec(char *key, int keyN, int arrN)
//{
////    char arr[43] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
////        '0','1','2','3','4','5','6','7','8','9',
////        '!','@','#','$','%','&','*'};
//    char arr[5] {'a','b','c','d', 'e'};
//
//    std::cout << key << std::endl;
//    if (std::string(key).compare("eeee") == 0)
//        return 1;
//    if (arrN >= 5) {
//        return rec(key, keyN + 1, 0);
//    }
//    key[keyN] = arr[arrN];
//    return rec(key, keyN, arrN + 1);
//
//}

//void line(char *key, int i) {
//    char arr[5] {'a','b','c','d', 'e'};
//
//    for (int arrI = 0; arrI != 5; arrI++) {
//        key[i] = arr[arrI];
//        std::cout << key << std::endl;
//        line(key, arrI);
//    }
//}
//
//void rec(char *key)
//{
//
//    std::cout << key << std::endl;
//    for (int keyI = 0; std::string(key).compare("eeee");) {
//        int it = 0;
//        line(key, keyI);
//        keyI++;
//        it++;
//    }
//}

int col(char *res, char *array, int i, int n) {
    std::cout << res << std::endl;
    if (n == 3) {
        return 0;
    }
    res[i] = array[n];
    return col(res, array, i, n + 1);
}

int prev(char *res, char *array) {
    while (std::string(res).compare("aaaa") != 0) {
        for (int m = 0; m != 4; m++) {
            col(res, array, m, 0);
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
//    DictionaryAttack dic("Hash.txt");
//    dic.startIntoThreads("Dictionary.txt", 1);
    char res[5] {'\0', '\0', '\0', '\0', '\0'};
    char arr[4] {'a','b','c','\0'};

    prev(res, arr);
//    rec(res);
    return 0;
}

// https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php


// res[8]; // mettre a null
//
// arr = [abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*]
// recursive
    // if i == 8
    //  return
    // if n == max arr
    //  recusive i--, 0
    // res[i] = arr[n]
    // recursive i, n++
