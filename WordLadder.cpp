//Benjamin Gur CSCI 235 Project 5

#include "WordLadder.hpp"

WordLadder::WordLadder() {


}

void WordLadder::readLexicon(std::string input_file){
    std::ifstream file;
    file.open(input_file);
    if(!file.is_open()) {
        std::cerr << "Failed to open lexicon file" << std::endl;
        return;
    }
    std::string word_hold = "";
    while(!file.eof()){
        std::getline(file, word_hold);
        lexicon.push_back(word_hold);
    }
    lexicon.pop_back(); //Getting rid of the last element which is an empty string in the provided .dat file.
}

std::vector<std::string> WordLadder::findShortestLadder(std::string start_word, std::string end_word){
    if (findPossibleLadder(start_word, end_word))
        return dequeue.back();
    else {
        std::vector<std::string> empty_ladder;
        return empty_ladder; 
    }
}

bool WordLadder::wordCompare(std::string start_word, std::string compare_word, int diff_pos){
    if(compare_word[diff_pos] != start_word[diff_pos]){
        for(int i = 0; i < 4; i++){
            if(i != diff_pos){
                if(start_word[i] != compare_word[i])
                    return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
    
}

bool WordLadder::searchVector(std::vector<std::string> list, std::string check){
    for(int i = 0; i < list.size(); i++){
        if(list[i] == check)
            return true;
    }
    return false; 
}


bool WordLadder::findPossibleLadder(std::string start_word, std::string end_word){
    std::vector<std::string> start;
    start.push_back(start_word);
    ladder_queue.push(start);
    used.push_back(start_word);
    while(!ladder_queue.empty()){
        dequeue.push_back(ladder_queue.front());
        ladder_queue.pop();
        if(dequeue.back().back() == end_word){
            return true;
        }
        for(int i = 0; i < lexicon.size(); i++){
            for(int j = 0; j < 4; j++){
                if(wordCompare(dequeue.back().back(), lexicon[i], j) && !searchVector(used, lexicon[i])){
                    std::vector<std::string> new_ladder = dequeue.back();
                    new_ladder.push_back(lexicon[i]);
                    ladder_queue.push(new_ladder);
                    used.push_back(lexicon[i]);
                }
            }
        } 
    }
    return false;
}

void WordLadder::printOutput(){
    for(int i = 0; i < dequeue.back().size(); i++){
        std::cout << dequeue.back()[i] << std::endl;
    }
}