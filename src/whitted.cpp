#include <nori/integrator.h>
#include <nori/scene.h>
#include <nori/sampler.h>
#include <nori/warp.h>
#include <nori/bsdf.h>
#include <nori/emitter.h>

NORI_NAMESPACE_BEGIN

class WhittedIntegrator : public Integrator {
public:
	WhittedIntegrator(const PropertyList &props) {}

	void preprocess(const Scene *scene) {
		for (auto mesh : scene->getMeshes()) {
			if (mesh->isEmitter()) {
				emitt_mesh_vec.push_back(mesh);
				emitt_dpdf.append(1.0f);
			}
		}
		emitt_dpdf.normalize();
	}

	Color3f Li(const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
	
		Intersection its;
		if (!scene->rayIntersect(ray, its)) return Color3f(0.0f);
		

		Point3f x = its.p;
		Point3f y;
		Normal3f nx = its.shFrame.n;
		Normal3f ny;
		Vector3f x_y;
		Vector3f y_x;
		float idxPDF, dirPDF, pointPDF;

		if (!its.mesh->getBSDF()->isDiffuse()) {
			float xi = sampler->next1D();
			if (xi < 0.95f) {

				BSDFQueryRecord new_bq{ its.toLocal(-ray.d) };
				Color3f new_bsdf = its.mesh->getBSDF()->sample(new_bq, sampler->next2D());
				Ray3f new_ray{ its.p, its.toWorld(new_bq.wo) };

				return  1.0526f * new_bsdf * Li(scene, sampler, new_ray);
			}
			else
				return Color3f(0.0f);
		}

		// Emitter sampling
		int emitt_idx = emitt_dpdf.sample(sampler->next1D(), idxPDF);
		Mesh *emitt_mesh = emitt_mesh_vec[emitt_idx];

		// sampling point on the emitter
		pointPDF = emitt_mesh->samplePosition(sampler->next2D(), y, ny);

		x_y = (y - x).normalized();
		y_x = -x_y;

		// Emitter radiance 
		const Color3f rad = emitt_mesh->getEmitter()->Sample_Le(scene, sampler, x, y, ny, dirPDF);

		if (its.mesh->isEmitter()) return rad;
		if (rad[0]==0,rad[1]==0,rad[2]==0)	return Color3f(0.0f);

		// f_r (bsdf)
		BSDFQueryRecord bq = { its.toLocal(-ray.d), its.toLocal(x_y), ESolidAngle };
		const Color3f bsdf = its.mesh->getBSDF()->eval(bq);

		//geo factor
		float g = fabs(nx.dot(x_y) * ny.dot(y_x)) / (y - x).dot(y - x);
		return rad * g * bsdf / (idxPDF * pointPDF);

	}

	std::string toString() const {
		return "WhittedIntegrator[]";
	}

public:
	std::vector<Mesh *> emitt_mesh_vec;
	DiscretePDF emitt_dpdf;
};

NORI_REGISTER_CLASS(WhittedIntegrator, "whitted");
NORI_NAMESPACE_END