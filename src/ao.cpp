#include <nori/integrator.h>
#include <nori/scene.h>
#include <nori/warp.h>

NORI_NAMESPACE_BEGIN

class AmbientOcclusionIntegrator : public Integrator {
public:
	AmbientOcclusionIntegrator(const PropertyList &props) {}

	Color3f Li(const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
		
		Intersection its;
 		if (!scene->rayIntersect(ray, its)) return Color3f(0.0f);

		float sum = 0.0f;
		Point3f x = its.p;
		int n = 1;
		for (int i = 0;i < n;i++) {
			Vector3f w = Warp::squareToCosineHemisphere(sampler->next2D());
			Ray3f shadow = Ray3f(x, its.shFrame.toWorld(w));
			if (scene->rayIntersect(shadow)) continue;
			sum += 1 ;
		}
		return Color3f(sum / n);
	}


	std::string toString() const {
		return "AmbientOcclusionIntegrator[]";
	}

};

NORI_REGISTER_CLASS(AmbientOcclusionIntegrator, "ao");
NORI_NAMESPACE_END