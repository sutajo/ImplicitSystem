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
	std::vector<Object*> m_object_list;
	Object* m_tree;
};

#endif//IMPLICIT_FILE_LOADER_HPP

