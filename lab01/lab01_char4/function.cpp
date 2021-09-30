//
// Created by David on 09/29/2021.
//

#include "function.h"

string capitalizeWords(string text) {
    if (text[0] >= 'a' && text[0] <= 'z') {
        text[0] -= 32;
    }
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == ' ' && (text[i+1] >= 'a' && text[i+1] <= 'z')) {
            text[i+1] -= 32;

        }
    }
    return text;
}