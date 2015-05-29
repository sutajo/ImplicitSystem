/*
 * Compressor
 *
 * File: 	Compressor.hpp
 * Author:	Evan Wilde		<etcwilde@uvic.ca>
 * Date:	May 22 2015
 */

#ifndef IMPLICIT_COMPRESSOR_HPP
#define IMPLICIT_COMPRESSOR_HPP

#include <vector>
#include <list>

#include <stdio.h>
#include <iostream>

#include "ImplicitSystem.hpp"
#include "ImplicitObject.hpp"

namespace Implicit
{
	/**
	 * \brief Takes the scene tree and converts it to a list structure
	 *
	 * The conversion to a list structure is slightly prohibitive to
	 * building the tree, but allows for faster evaluation times.
	 *
	 * TODO: Tests will need to be performed to ensure that
	 * this doesn't break when nested in a larger blob tree
	 */
	//class Compressor : public Object
	class Compressor
	{
	public:
		Compressor(Object* scene);
	private:
		Aabb m_bounds;
	private:
		enum NODE_TYPES
		{
			PRIMITVE,
			OPERATOR,
			TRANSFORM
		};

		typedef struct
		{
			// Offsets are only set if they are of type OPERATOR
			// Otherwise set to 1
			// Primitive address only set if of type PRIMITIVE
			NODE_TYPES type;
			Aabb bounding_box;
			unsigned long left_offset;
			unsigned long right_offset;
			Primitive* primitive;
		} tree_node_t;
	};
};

#endif//IMPLICIT_COMPRESSOR_HPP
