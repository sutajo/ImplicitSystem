#include "ImplicitFileLoader.hpp"

using namespace Implicit;

FileLoader::FileLoader(std::string fname) :
	m_fname(fname),
	m_tree(NULL)
{
	// If check is not zero, something when wrong
	if (check()) return; // This won't be easy to write

	// Otherwise compile it
	//compile(); // This will be tricky to write

	// Maybe some pruning too
	//prune(); // This will be even trickier
}

FileLoader::~FileLoader()
{
	// Free the tree entire tree
	for (std::vector<Object*>::iterator obj = m_object_list.begin();
			obj != m_object_list.end(); obj++)
		free(*obj);

	m_tree = NULL;
}

const Object* FileLoader::Get() const
{
	return m_tree;
}

Object* FileLoader::Get()
{
	return m_tree;
}

/*
 * Private methods
 */

// Does all syntax checking of the file
// Makes sure that all objects are defined
int FileLoader::check()
{

	std::ifstream in_file(m_fname);
	// TODO: Replace this with a better lookup table
	std::vector<std::string> object_names;
	unsigned int line_number = 1;
	std::string line;

	std::vector<std::string> matches;
	std::smatch match;

#define PRIMITIVE	"Primitive \\(" NAME "\\);"
#define TRANSLATE	"(" NAME ")\\.(translate)\\((" NUM "), (" NUM "), (" NUM ")\\);"
#define TRANSFORM	"(" NAME ") = " NAME " (.*);"



	std::regex language(TRANSFORM);


	// Compile regular expressions
	// They are for checking to see if a line is valid or not
	// If not, print an error and return 1
	//

	while (std::getline(in_file, line))
	{
		std::cout << "Line[" << line_number << "]: " << line << '\n';
		std::string s = line;

		while (std::regex_search(s, match, language))
		{
			for (auto x : match) matches.push_back(x);
			s = match.suffix().str();
		}

		line_number += 1;
	}

	in_file.close();

	std::cout << "Matches:\n";
	for (auto m : matches)
	{
		std::cout << m << '\n';
	}
}

