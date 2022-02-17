//
//  DictionaryAttack.hpp
//  SecuriteInformatique-TP1
//
//  Created by Clain Dimitri on 2022-02-16.
//

#ifndef DictionaryAttack_hpp
#define DictionaryAttack_hpp

#include <stdio.h>
#include <string>
#include <vector>

class DictionaryAttack {

private:
    std::vector<std::string> _hash;

    static std::vector<std::string> readFile(const std::string filename);
    static std::string wordToHash(const std::string word);
    bool isInMyHash(const std::string hashWord);
    void attack(std::vector<std::string> dictionary);

    void splitVector(std::vector<std::string> values, int nb);

public:
    DictionaryAttack(const std::string hashFile);
    void startIntoThreads(const std::string dictionaryFile, int nbThreads);
};
#endif /* DictionaryAttack_hpp */


/**
    TODO
   * Creation de thread
   * Pour chaque hash faire un thread, Attention les threads ne doivent pas être trop nombreux
 */
