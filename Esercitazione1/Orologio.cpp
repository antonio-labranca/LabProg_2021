#include <iostream>

int dist(char a, char b) {
    return std::min('Z'-'A'-std::abs(a-b)+1, std::abs(a-b));
}

long getTime(std::string s) {
    /*SOLUZIONE 1
    long passi = dist('A', s.at(0));
    for(int i= 0; i < s.length()-1; i++){
        passi += dist(s.at(i), s.at(i+i));
    }*/

    char lancetta = 'A';
    long passi = 0;
    for(char c : s) {
        passi += dist(lancetta, c);
        lancetta = c;
    }
    return passi;

}