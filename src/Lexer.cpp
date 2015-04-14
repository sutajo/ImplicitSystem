#include "Lexer.hpp"

Lexer::Lexer(std::string fname) :
	m_fname(fname),
	m_lexed(false)
{ }

std::vector<std::string> Lexer::Lex()
{
	if (!m_lexed) lex();
	m_lexed = true;
	return m_lexemes;
}
