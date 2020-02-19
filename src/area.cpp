#include <nori/common.h>
#include <nori/emitter.h>
#include <nori/scene.h>
#include <nori/warp.h>
#include <nori/integrator.h>
NORI_NAMESPACE_BEGIN

class AreaLight : public Emitter {
public:

	AreaLight(const PropertyList &props) {
		this->m_radiance = props.getColor("radiance");
	}

	Color3f Sample_Le(const Scene *scene, Sampler *sampler, Point3f &x, Point3f &y, Normal3f &n_y, float &pdf) const {
		
		// emitter to mesh
		Vector3f y_x = x - y;
		Intersection its;
		if (!scene->rayIntersect(Ray3f(x, -y_x), its))
			return Color3f(0.0f);


		if (n_y.dot(y_x) < 0)
			return Color3f(0.0f);

		if (!its.mesh->isEmitter())
			return Color3f(0.0f);

		pdf = Warp::squareToCosineHemispherePdf(its.toLocal(y_x));
		return m_radiance;
	}

	std::string toString() const {
		return "AreaLight[]";
	}

	EClassType getClassType() const {
		return EEmitter; 
	}

private:
	Color3f m_radiance;
};

NORI_REGISTER_CLASS(AreaLight, "area");
NORI_NAMESPACE_END