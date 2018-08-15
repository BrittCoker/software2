// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include "Line.h"
#include "Word.h"
#include <iostream>
#include <vector>


using namespace std;
Line::Line(const string& line) : line_{line}
{
    stringToWordVector();
    
//    std::size_t pos;
//	string temp = line;
//	
//	while (temp != "")
//	{
//        stringToWordVector();
//		if (temp.find(" ") == std::string::npos) {
//			line_.push_back(temp.substr(0,temp.length()));
//			temp.erase(0,temp.length());
//		}
//		else {
//		pos = temp.find(" ");
//		line_.push_back(temp.substr(0,pos));
//		temp.erase(0,pos+1);
//		}
//    }

	// Hint: some of string's member functions might come in handy here
	// for extracting words.
}

bool Line::contains(const Word& search_word) const
{
    if (line_ == "")
		{
			return false;
		}
		
		if (!search_word.isQueryable())
		{
			return false;
		}
	
		for (auto i = 0; i < _wordVec.size(); i++)
		{
			if (_wordVec.at(i) == search_word)
			{
				return true;
			}
		}
		
		return false;

}

void Line::stringToWordVector()
{
	
	auto singleWord = ""s;
	char ch;
	auto isEndOfLine = false;
	
	if (line_ == "") return;			
			
	while (!isEndOfLine)
	{
		for (auto i = 0; i <= line_.length(); i++)
		{
			if (line_[i] == '\0' || line_[i] == ' ') 
			{
				isEndOfLine = true;
				Word temp(singleWord);
				_wordVec.push_back(temp);
				singleWord = "";
				
				if (line_[i] == '\0')
				{
					isEndOfLine = true;
				}
		
			}
			else
			{
				ch = line_[i];
				singleWord += ch;
			}		
				
		}
				
	}
}

