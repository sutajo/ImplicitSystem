#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>

class Token;
class Lexeme;

class Lexer
{
public:
	/**
	 * \brief Create a new lexer Which will generate the lexemes for the
	 * file
	 *
	 * \param fname File to be lexed
	 */
	Lexer(std::vector<Token> tokens);

	/**
	 * \brief Get lexemes from lexer
	 */
	std::vector<std::string> Lex(std::string fname);

protected:
	virtual void lex()=0;
	std::string m_fname;
	bool m_lexed;
	std::vector<std::Token> m_tokens;
	std::vector<std::string> m_lexemes;
};

class Token
{
public:
protected:
private:
	std::string m_pattern;
	std::string m_lexeme;
	std::regex m_regex;
};

class Lexeme
{
public:

private:
	std::string m_type;
	std::string m_contents;
};

#endif
