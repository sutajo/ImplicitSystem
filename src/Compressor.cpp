#include "Compressor.hpp"

using namespace Implicit;

Compressor::Compressor(Object* scene)
{
	std::vector<Object*> object_addresses;
	object_addresses = scene->GetObjects();
	std::cout << "Object Nodes: " << object_addresses.size() << '\n';

	std::list<Primitive*> primitive_objects;
	size_t operators = 0;
	size_t primitives = 0;
	size_t transforms = 0;

	for (auto obj : object_addresses)
	{
		if (Implicit::Operator* o = dynamic_cast<Operator*>(obj))
		{
			printf("%p: Operator\n", o);
			printf("Children: %p | %p\n", o->LeftChild(),
					o->RightChild());
			operators++;
		}
		else if(Implicit::Primitive* p = dynamic_cast<Primitive*>(obj))
		{
			printf("%p: Primitive\n", p);
			primitives++;
			primitive_objects.push_back(p);
		}
		else if(Implicit::Transform* t = dynamic_cast<Transform*>(obj))
		{
			printf("%p: Transform\n", t);
			printf("Child: %p\n", t->GetChild());
			transforms++;
		}
		else printf("%p: What are you?\n", obj);
		printf("\n");
	}
	std::cout << "Primitives: " << primitives << '\t'
		<< "Transforms: " << transforms << '\t'
		<< "Operators: " << operators << '\n';

	std::cout << "Sizeof primitive container: " << primitive_objects.size() << '\n';
	//std::list<tree_node_t>
}

