#include "FileReader.h"
#include <iostream>

using namespace std;
/*  
 * Currently our code records all the lines that the word occurs in throughout the paragraph. 
 *  If the word occured multiple times in the same line we would need to record how many times 
 *  it occured. Our code would have to change to accomplish this. We recommend changing the 
 *  functionality of the integer vector passed to the paragraph "contains" function. Instead of 
 *  listing the lines that the word occurs on, the vector will allocate an element to each line
 *  number and record the integer number of word occurances per line.
 */ 
int main() 
{
	string file_name = "";
	string search_word_name = "";
	vector<int> line_numbers;
	
	cout << "Please enter file name: ";
	cin >> file_name;
	
	FileReader file_reader(file_name);
	Paragraph paragraph;
	file_reader.readFileInto(paragraph);
	
	cout << "Please enter a word to search for or ""."" to quit: ";
	cin >> search_word_name;
		
	while (search_word_name != ".")
	{
		
		Word search_word(search_word_name);
        auto[found, line_numbers] = paragraph.contains(Word{search_word_name});
		if (found)
		{
			cout << "\nWord found:\tline " << line_numbers[0] << endl;
			
			for (int i=1; i < line_numbers.size(); i++)
			{
				cout << "\t\tline " << line_numbers[i] << endl; 
			}
		} else {
			cout << "\nWord not found. \n";
		}
		
		cout << "\nPlease enter a word to search for or ""."" to quit: ";
		cin >> search_word_name;
	} 
	
	return 0;
}