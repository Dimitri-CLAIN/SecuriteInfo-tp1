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
    std::vector<std::string> _hash; // Faire un 'tuple', string et bool liée. Quand on trouve le hash il passe en true. TODO

    static std::vector<std::string> readFile(const std::string filename);
    void attack(std::vector<std::string> dictionary);

    void splitVector(std::vector<std::string> values, int nb);

public:
    DictionaryAttack(const std::string hashFile);
    void startIntoThreads(const std::string dictionaryFile, int nbThreads);
    bool isInMyHash(const std::string hashWord);
    static std::string wordToHash(const std::string word);
};
#endif /* DictionaryAttack_hpp */


/**
    TODO
   * Creation de thread
   * Pour chaque hash faire un thread, Attention les threads ne doivent pas être trop nombreux
 */
