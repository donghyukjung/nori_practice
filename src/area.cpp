#include <nori/common.h>
#include <nori/emitter.h>
#include <nori/integrator.h>
NORI_NAMESPACE_BEGIN

class AreaLight : public Emitter {
public:
	AreaLight(const PropertyList &prop) {
		m_rad = prop.getColor("radiance");
	}
	Color3f m_rad;
	std::string toString() const {
		return "AreaLight[]";
	}
};

NORI_REGISTER_CLASS(AreaLight, "area");	
NORI_NAMESPACE_END