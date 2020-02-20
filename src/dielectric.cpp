/*
    This file is part of Nori, a simple educational ray tracer

    Copyright (c) 2015 by Wenzel Jakob

    Nori is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    Nori is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <nori/bsdf.h>
#include <nori/frame.h>

NORI_NAMESPACE_BEGIN

/// Ideal dielectric BSDF
class Dielectric : public BSDF {
public:
    Dielectric(const PropertyList &propList) {
        /* Interior IOR (default: BK7 borosilicate optical glass) */
        m_intIOR = propList.getFloat("intIOR", 1.5046f);

        /* Exterior IOR (default: air) */
        m_extIOR = propList.getFloat("extIOR", 1.000277f);
    }

    Color3f eval(const BSDFQueryRecord &) const {
        /* Discrete BRDFs always evaluate to zero in Nori */
        return Color3f(0.0f);
    }

    float pdf(const BSDFQueryRecord &) const {
        /* Discrete BRDFs always evaluate to zero in Nori */
        return 0.0f;
    }

    Color3f sample(BSDFQueryRecord &bRec, const Point2f &sample) const {
		float etaI = m_extIOR, etaT = m_intIOR;
		Vector3f w_i = bRec.wi.normalized();
		Normal3f n = Normal3f(0, 0, 1);
		float cos_i = Frame::cosTheta(w_i);
		if (cos_i < 0) {
            n=-n;
			cos_i =-cos_i;
			std::swap(etaI, etaT);
		}
		
		float fre = fresnel(cos_i, etaI, etaT);
		if (sample[0] <= fre) {
			// reflection
			bRec.wo = -w_i + 2 * n.dot(w_i)*n;
			return Color3f(1.0f);
		}
		else {
			// refraction
			float sin_i = sqrt(1 - pow(cos_i,2));
			float sin_t = sin_i * etaI / etaT;
			float cos_t = sqrt(1 - pow(sin_t,2));
			bRec.wo = -etaI / etaT * bRec.wi + (etaI / etaT * bRec.wi.dot(n) - cos_t) * n;
			bRec.measure = EDiscrete;
		
			return Color3f(1.0f) / pow(etaI / etaT,2);
		}
    }

    std::string toString() const {
        return tfm::format(
            "Dielectric[\n"
            "  intIOR = %f,\n"
            "  extIOR = %f\n"
            "]",
            m_intIOR, m_extIOR);
    }
private:
    float m_intIOR, m_extIOR;
};

NORI_REGISTER_CLASS(Dielectric, "dielectric");
NORI_NAMESPACE_END
