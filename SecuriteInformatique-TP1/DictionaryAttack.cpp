//
//  DictionaryAttack.cpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-16.
//

#include "DictionaryAttack.hpp"

#include <fstream>
#include <iostream>
#include <cstdio>
#include <thread>
#include <iterator>
#include <CommonCrypto/CommonDigest.h>


DictionaryAttack::DictionaryAttack(const std::string hashFile) :
    _hash(readFile(hashFile))
{}

std::vector<std::string> DictionaryAttack::readFile(const std::string filename) {
    std::ifstream file(filename);

    if (file.fail())
        std::cerr << "Filename incorrect " << filename << ", please retry";
    std::vector<std::string> lines(std::istream_iterator<std::string>(file), {});
    file.close();
    return lines;
}

std::string DictionaryAttack::wordToHash(const std::string word) {
    unsigned char digest[16];
    const char* string = word.c_str();
    char res[33];

    CC_MD5(string, (CC_LONG)strlen(string), digest);
    for (size_t i=0; i<CC_MD5_DIGEST_LENGTH; ++i)
        std::sprintf(res, "%s%.2x", res, digest[i]);
    return res;
}

bool DictionaryAttack::isInMyHash(const std::string hashWord) {
    bool res = false;

    std::for_each(_hash.begin(), _hash.end(), [hashWord, &res](std::string code) {
        if (code.compare(hashWord) == 0) {
            res = true;
        }
    });
    return res;
}

void DictionaryAttack::attack(std::vector<std::string> dictionary) {
    std::for_each(dictionary.begin(), dictionary.end(), [this](std::string word) {
        std::string code = wordToHash(word);
        if (isInMyHash(code))
            std::cout << word << " = " << code << std::endl;
    });
}

void DictionaryAttack::startIntoThreads(const std::string dictionaryFile, int nbThreads) {
    std::vector<std::thread> threads;

    std::ifstream file(dictionaryFile);
    unsigned long fileLen = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
    unsigned long size = (fileLen - 1) / nbThreads + 1;

    std::string tmpLine;
    std::vector<std::string> tmpVect;
    file.clear();
    file.seekg(0);

    for (int n = 0; std::getline(file, tmpLine); n++) {
        tmpVect.push_back(tmpLine);
        if (n == size) {
            n = 0;
            threads.push_back(std::thread([this, tmpVect] { attack(tmpVect); }));
            tmpVect.clear();
        }
    }
    file.close();

    for (auto &th : threads) {
        if (th.joinable())
            th.join();
    }
}
