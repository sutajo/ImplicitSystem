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
	 * this doesn't break when nested. Otherwise just separate it out and
	 * only allow it to work on an object.
	 */
	class Compressor : public Object
	{
	public:
		Compressor(Object* scene, float iso);
		virtual float Evaluate(const glm::vec3& point);
		virtual float FieldValue(const glm::vec3& point);
		virtual glm::vec3 Normal(const glm::vec3& point);
		virtual glm::vec3 GetStartVertex();
		virtual glm::vec3 GetCenterVertex();
	private:
		std::vector<Object> m_objects;
	};
};


#endif//IMPLICIT_COMPRESSOR_HPP
