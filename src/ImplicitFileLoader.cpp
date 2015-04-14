#include "ImplicitFileLoader.hpp"

using namespace Implicit;

FileLoader::FileLoader(std::string fname) :
	m_tree(NULL)
{
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
