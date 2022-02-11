//
// Project 1
// CS 341 Spring 2021
// << Nick Magaru >>
//
// Populate this file with the function definitions for the acronymIterator class

#include "acronymIterator.h"

using namespace std;

characterParser::acronymIterator::acronymIterator(char* arr)
{
    curr = arr;
}

char& characterParser::acronymIterator::operator*()
{
    *curr = toupper(*curr);
    return *curr;
}

characterParser::acronymIterator& characterParser::acronymIterator::operator++()
{

    while (*curr != '\0')
    {
        if (*curr == ' ' || *curr == '\"' || *curr == '(')
        {
            ++curr;

            while (*curr == ' ' || *curr == '\"' || *curr == '(')
                ++curr;

            if (isalpha(*curr))
                break;
            else
                continue;
        }
        else 
        {
            ++curr;
        } 
    }
       
    return *this;
}

bool characterParser::acronymIterator::operator!=(const characterParser::acronymIterator& other)
{
    return curr != other.curr;
}

bool characterParser::acronymIterator::operator==(const characterParser::acronymIterator& other)
{
    return curr == other.curr;
}

