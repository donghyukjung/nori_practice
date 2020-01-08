#include <nori/integrator.h>
#include <nori/scene.h>

NORI_NAMESPACE_BEGIN

class SimpleIntegrator : public Integrator {
public:
	SimpleIntegrator(const PropertyList &props) {
		p = props.getPoint("position");
		psi = props.getColor("energy");
	}

	Color3f Li(const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
		/* Find the surface that is visible in the requested direction */
		Intersection its;
		Point3f x = its.p;
		const Ray3f shadow = Ray3f(x, -(x - p));
		if (!scene->rayIntersect(ray, its) || scene->rayIntersect(shadow))
			return Color3f(0.0f);
		
		return psi / (4 * pow(M_PI, 2))
			*(std::max(0.0f, its.shFrame.n.dot(p - x) / (its.shFrame.n.norm() * (p - x).norm()))
			/ (x - p).dot(x - p));
	}
	
	
	std::string toString() const {
		return "SimpleIntegrator[]";
	}
	Point3f p;
	Color3f psi;
};

NORI_REGISTER_CLASS(SimpleIntegrator, "simple");
NORI_NAMESPACE_END