// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <iostream>
#include <string>
#include <vector>

const auto PUNCTUATION = "~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\""s;

Word::Word(const string& word): word_{word}
{
    std::size_t pos; 
	pos = word_.find(" ");
	if (pos!=std::string::npos) throw WordContainsSpace();

	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()|| (RemovePunct(word_).empty())) throw WordContainsNoLetters{};
	// Note, we will cover exceptions in more detail later on in the course.
    
    //RemovePunct(word_);
    auto containsSpaces = false;
    auto testSpaces = ""s;
    char spaceChar;
    
    
    //check if the word contains spaces
    for (auto i = 0; i < word_.length(); i++)
    {
        spaceChar = word_[i];
        testSpaces += spaceChar;
    }
    
    for (auto i = 0; i < testSpaces.length(); i++)
    {
        if (testSpaces[i] == ' ')
            containsSpaces = true;
    }
    
    //check if the word contains letters
    auto checkAlpha = ""s;
    char ch;
    
    for (auto i = 0; i < word_.length(); i++)
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
    
    if (RemovePunct(UpCase(word_)) == RemovePunct(UpCase(rhs.word_)))
		return true;
	else
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

}


//Helper Method: Converts string to uppercase
string Word::UpCase(const string wrd) const
{
    string temp = wrd;
    
    for (int i = 0; i < temp.length(); i++)
    {
        temp.at(i) = toupper(temp.at(i));
    }
    return temp;
}

//Helper Method: Removes punctuation
string Word::RemovePunct(const string wrd) const
{
    string temp = "";
    
    for (int i = 0; i < wrd.length(); i++)
    {
        if (!ispunct(wrd[i])) 
        {
            temp  += wrd[i];
        }
    }
    return temp;
}