/*
 * ImplicitFileLoader
 *
 * File: 	ImplicitFileLoader.hpp
 * Author:	Evan Wilde		<etcwilde@uvic.ca>
 * Date:	Apr 12 2015
 */

#ifndef IMPLICIT_FILE_LOADER_HPP
#define IMPLICIT_FILE_LOADER_HPP

#include "ImplicitSystem.hpp"

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <regex>

#ifdef DEBUG
#include <iostream>
#endif

// Compiler Syntax
#define NUM 		"[0-9][0-9]*"

#define NAME 		"(?:/ )[a-zA-Z][a-zA-Z0-9]*|^[a-zA-Z][a-zA-Z0-9]*"
#define ANGLE 		"[0-9]|[1-9][0-9]|[1-2][0-9][0-9]|3[0-5][0-9]|360"
#define COMMENT		"#(?: )?[0-9a-zA-Z :\\*/+-]*"

// #define TRANSLATE	 NAME  " = " NAME ".translate\\(" NUM ", " NUM ", " NUM "\\);"

// #define TRANSLATE_S	NAME " + " "\\(" NUM ", " NUM ", " NUM "\\)"
// #define ROTATE_S	NAME " ^ " "\\(\\(" NUM ", " NUM ", " NUM "\\), " ANGLE "\\)"
// #define SCALE_S		NAME " \\* " NUM "|" NAME " \\* (" NUM ", " NUM ", " NUM ")"
// 
// #define TRANSLATE_L 	NAME ".translate\(" NUM ", " NUM ", " NUM "\)"
// #define ROTATE_L	NAME ".rotate((" NUM ", " NUM ", " NUM "), " ANGLE ")"
// #define SCALE_L		NAME ".scale(" NUM ", " NUM ", " NUM ")"
// 
// #define TRANSLATE	"(" TRANSLATE_S ")|(" TRANSLATE_L ")"
// #define ROTATE		"(" ROTATE_S ")|(" ROTATE_L ")"
// #define SCALE		"(" SCALE_S  ")|(" SCALE_L ")"
// 
// #define BLEND		NAME " \\* " NAME
// #define UNION		NAME " + " NAME
// #define DIFFERENCE	NAME " - " NAME
// #define INTERSECT	NAME " / " NAME
// 
// #define OPS		BLEND "|" INTERSECT "|" DIFFERENCE "|" UNION
// #define TRANSFORM	TRANSLATE "|" ROTATE "|" SCALE
// 
// #define CLAUSE		NAME " = (" OPS "|" TRANSFORM  ");(?: )?"
// #define LINE		"(" CLAUSE ")?(?:" COMMENT ")?"






using namespace Implicit;

/*
 * \class FileLoader
 *
 * \brief Loads blob files and creates a blob tree from that
 *
 * Language details:
 * 	# : Comment for rest of line -- Continue parsing
 * 	Primitive: Primitive object
 * 		For now a primitive consists of:
 * 			Geoff function
 * 			iso value
 * 			radius
 * 	Transforms:
 * 		translate (x, y, z);
 * 		rotate (axis, angle);
 * 		scale (x, y, z);
 *
 * 	Operations:
 * 		* : Blend
 *		/ : Intersect
 *		+ : Union
 *		- : Difference -- once it is implemented
 *	set : Defines the root node of the blob tree that is returned
 */

class FileLoader
{
public:
	FileLoader(std::string fname);
	~FileLoader();

	/**
	 * \brief Safe Get
	 * Returns the blob tree
	 *
	 * Returns NULL if the blob tree failed to compile
	 */
	const Object* Get() const;

	/**
	 * \brief Unsafe Get
	 * Only use this one if you know what you are doing
	 * * Returns NULL if the blob tree failed to compile
	 */
	Object* Get();
protected:
private:
	/**
	 * \brief checks the file to make sure that it is good
	 *
	 * \return 0 if the file is good and it is found
	 * 1 if the file is bad
	 * File not found: ENOENT
	 */
	int check();

	/**
	 * \brief Compiles the file into a blob tree
	 */
	void compile();

	/**
	 * \brief Removes un-used parts of the tree
	 */
	void prune();


	std::string m_fname;

	std::vector<Object*> m_object_list;

	Object* m_tree;
};

#endif//IMPLICIT_FILE_LOADER_HPP

