// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <iostream>
#include <string>
#include <vector>

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};
	// Note, we will cover exceptions in more detail later on in the course.
    
    auto containsSpaces = false;
    auto testSpaces = ""s;
    char spaceChar;
    
    for (int i = 0; i < word_.length(); i++)
    {
        spaceChar = word_[i];
        testSpaces += spaceChar;
    }
    
    for (int i = 0; i < testSpaces.length(); i++)
    {
        if (testSpaces[i] == ' ')
            containsSpaces = true;
    }
    
    auto checkAlpha = ""s;
    char ch;
    
    for (int i = 0; i < word_.length(); i++)
    {
        if(isalpha(word_[i]))
        {
            ch = word_[i];
            checkAlpha += ch;
        }
    }
    
    if (containsSpaces) throw WordContainsSpace();
    if (checkAlpha.length() == 0 ) throw WordContainsNoLetters();
	if (word_.empty()) throw WordContainsNoLetters();

}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    bool isSame = true;
    
	if (word_ == rhs.word_)
		return true;
	else if (word_.length() == rhs.word_.length())
    {
        for (int i = 0; i < word_.length(); i++)
        {
            if ( tolower(word_[i]) == tolower(rhs.word_[i]))
            {
                isSame = true;
            }
            else 
            {
                return false;
            }
        }
    }
        else
        {
            auto word1 = ""s;
            char ch1;
            
            auto word2 =""s;
            
            for (int i = 0; i < word_.length(); i++)
            {
                if(isalpha(word_[i]))
                {
                    ch1 = word_[1];
                    word1 += tolower(ch1);
                }
            }
            
            char ch2;
            for (int i =0; i < rhs.word_.length(); i++)
            {
                if(isalpha(rhs.word_[i]))
                {
                    ch2 = rhs.word_[1];
                    word2 += tolower(ch2);
                }
            }
            
            if (word1 == word2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
    if (isSame)
       {
            return true;
       }
        
    return false;
}

bool Word::isQueryable() const
{
    if (word_.length() >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
	return false;
}
