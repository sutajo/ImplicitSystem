/*
 * ImplicitOperator
 *
 * File: 	ImplicitOperator.cpp
 * Author:	Evan Wilde		<etcwilde@uvic.ca>
 * Date:	Mar 23 2015
 */

#include "ImplicitOperator.hpp"

using namespace Implicit;

Operator::Operator(Object* left, Object* right) :
	m_left_child(left),
	m_right_child(right)
{
	m_iso = (left->GetIso() + right->GetIso()) / 2.f;
}

Operator::Operator(Object* left, Object* right, float iso) :
	Object(iso),
	m_left_child(left),
	m_right_child(right)
{
}

glm::vec3 Operator::GetStartVertex()
{
	return project(GetCenterVertex());
}

glm::vec3 Operator::GetCenterVertex()
{
	return (m_left_child->GetCenterVertex()-m_right_child->GetCenterVertex())*0.5f;
}

std::vector<Object*> Operator::GetObjects() const
{
	std::vector<Object*> ret_vec;
	ret_vec.push_back((Object*)this);
	std::vector<Object*> left_children = m_left_child->GetObjects();
	std::vector<Object*> right_children = m_right_child->GetObjects();
	ret_vec.insert(ret_vec.end(), left_children.begin(), left_children.end());
	ret_vec.insert(ret_vec.end(), right_children.begin(), right_children.end());
	return ret_vec;
}
