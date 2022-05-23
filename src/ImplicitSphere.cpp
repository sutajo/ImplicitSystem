#include "ImplicitSphere.hpp"

using namespace Implicit;
using namespace autodiff;

Sphere::Sphere()
{
	SetEquation();
	compute_bounds();
}

Sphere::Sphere(double iso)
{
	SetEquation();
	compute_bounds();
}

Sphere::Sphere(double iso, double radius)
{
	SetEquation();
	compute_bounds();
}

double Sphere::Evaluate(const glm::dvec3& p)
{
	return Differentiated::FieldValue(p);
}

double Sphere::FieldValue(const glm::dvec3& p)
{
	return Differentiated::FieldValue(p) - m_iso;
}

glm::dvec3 Sphere::GetStartVertex()
{
	return project(m_bounds.max());
}

glm::dvec3 Sphere::GetCenterVertex()
{
	return glm::vec3(0, 0, 0);
}

void Sphere::compute_bounds()
{
	std::list<glm::dvec3> points;
	points.push_back(glm::vec3(m_radius, 0, 0) );
	points.push_back(glm::vec3(-m_radius, 0, 0));
	points.push_back(glm::vec3(0, m_radius, 0) );
	points.push_back(glm::vec3(0, -m_radius, 0));
	points.push_back(glm::vec3(0, 0, m_radius) );
	points.push_back(glm::vec3(0, 0, -m_radius));
	m_bounds.compute(points);
}

void Implicit::Sphere::SetEquation()
{
	Equation = [&](const autodiff::dual& x, const autodiff::dual& y, const autodiff::dual& z) -> autodiff::dual
	{
		return x * x + y * y + z * z - m_radius*m_radius;
	};
}

double Sphere::getDistance(const glm::dvec3& p)
{
	return glm::length(p);
}
