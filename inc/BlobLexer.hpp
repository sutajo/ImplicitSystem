#ifndef BLOBLEXER_HPP
#define BLOBLEXER_HPP

#include "Lexer.hpp"

#define R_NUM		"[0-9][0-9]*"
#define R_ANGLE		"[0-9]|[1-2][0-9][0-9]|3[0-5][0-9]|360"
#define R_COMMENT 	"#(.*)*"


class BlobLexer : public Lexer
{
public:
	/**
	 * \brief Construct a lexer for the blob tree language
	 *
	 * Blob tree language is regular, and therefore should be simple
	 * to process
	 */
	BlobLexer(std::string fname);

protected:
	/**
	 * \brief Generate lexemes for the lexer
	 */
	virtual void lex();

private:

};

#endif//BLOBLEXER_HPP
