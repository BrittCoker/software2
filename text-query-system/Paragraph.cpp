// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
    paragraph_.push_back(line);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
    bool temp = false;
    vector<int> line_numbers;
	for (int i = 0; i < paragraph_.size(); i++)
	{
		if (paragraph_.at(i).contains(search_word)) {
			line_numbers.push_back(i+1);
			temp = true;
		}
	}
	return tuple<bool,vector<int>>(temp, line_numbers);

}