// Benjamin Gur CSCI 235 Project 5

#ifndef Word_Ladder_
#define Word_Ladder_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>


class WordLadder{
public:
    //Default constructor
    WordLadder();



    /**
    @post reads lexicon words from the input file and stores them for
    later use
    **/
    void readLexicon(std::string input_file);

    /**
    @param start_word is the first word in the ladder
    @param end_word is the last word in the ladder
    @return a vector containing words s.t. the first word is start_word,
    the last word is end_word, and all words in between differ by
    only one character from the preceding and following words, in
    the shortest such transformation found in the current lexicon.
    If no transformation is found between start_word and end_word,
    returns an empty vector.
    **/
    std::vector<std::string> findShortestLadder(std::string start_word, std::string end_word);
    
    void printOutput(); //used for debuging.


private:
    std::vector<std::string> lexicon; //stores the lexicon of words. 

    std::vector<std::string> output; //used for debugging. 

    std::vector<std::string> used; //used words stored here

    std::queue<std::vector<std::string>>  ladder_queue; //queue for partial ladders

    std::vector<std::vector<std::string>> dequeue; //stores the dequed partial ladders

    //@return True if ladder possible else false.
    //@Param Parmas from FindShortest Ladder.
    bool findPossibleLadder(std::string start_word, std::string end_word); 
    
    //@return true if test passes false if fails.
    //@param Tests if all letters other than letter at diff_pos are the same, and that the letter at diff_pos is not the same.
    bool wordCompare(std::string start_word, std::string compare_word, int diff_pos);

    //@return true if check exists in list, else false.
    //@param any vector of strings and any string. 
    bool searchVector(std::vector<std::string> list, std::string check);

    

};



#endif