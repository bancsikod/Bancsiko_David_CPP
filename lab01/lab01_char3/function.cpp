//
// Created by David on 09/29/2021.
//

#include "function.h"

string code(string text) {
    for (int i = 0; i < text.length(); ++i) {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            if (text[i] == 'z') {
                text[i] = 'a';
            } else if (text[i] == 'Z') {
                text[i] = 'A';
             } else {
                text[i] += 1;
            }
        }
    }
    return text;
}

string decode(string text) {
    for (int i = 0; i < text.length(); ++i) {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            if (text[i] == 'a') {
                text[i] = 'z';
            } else if (text[i] == 'A') {
                text[i] = 'Z';
            } else {
                text[i] -= 1;
            }
        }
    }
    return text;
}