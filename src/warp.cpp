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

#include <nori/warp.h>
#include <nori/vector.h>
#include <nori/frame.h>

NORI_NAMESPACE_BEGIN

Point2f Warp::squareToUniformSquare(const Point2f &sample) {
    return sample;
}

float Warp::squareToUniformSquarePdf(const Point2f &sample) {
    return ((sample.array() >= 0).all() && (sample.array() <= 1).all()) ? 1.0f : 0.0f;
}

Point2f Warp::squareToTent(const Point2f &sample) {
	auto inv_cdf = [](float x) {return (x < 0.5f) ? (sqrt(2.0f * x) - 1.0f) : (1.0f - sqrt(2.0f*(1.0f - x)));};
	return Point2f(inv_cdf(sample[0]), inv_cdf(sample[1]));
}

float Warp::squareToTentPdf(const Point2f &p) {
	auto pdf = [](float x) {return abs(x) <= 1 ? (1 - abs(x)) : 0;};
	return pdf(p[0])*pdf(p[1]);
}


Point2f Warp::squareToUniformDisk(const Point2f &sample) {
	float r = sqrt(sample[0]);
	float th = 2 * M_PI * sample[1];
	return Point2f(r*cos(th), r*sin(th));

}

float Warp::squareToUniformDiskPdf(const Point2f &p) {
	return (pow(p[0], 2) + pow(p[1], 2) <= 1) ? INV_PI : 0;
}

Vector3f Warp::squareToUniformSphere(const Point2f &sample) {
	float th = acos(1 - 2 * sample[0]);
	return Vector3f(sin(th)*sin(2*M_PI*sample[1]), sin(th)*cos(2*M_PI*sample[1]), cos(th));
}

float Warp::squareToUniformSpherePdf(const Vector3f &v) {
	return INV_FOURPI;
}

Vector3f Warp::squareToUniformHemisphere(const Point2f &sample) {
	float th = acos(1 - sample[0]);
	return Vector3f(sin(th)*sin(2 * M_PI*sample[1]), sin(th)*cos(2 * M_PI*sample[1]), cos(th));
}

float Warp::squareToUniformHemispherePdf(const Vector3f &v) {
	return (v[2] > 0) ? INV_TWOPI : 0;
}

Vector3f Warp::squareToCosineHemisphere(const Point2f &sample) {
	return Vector3f(sample[0]*sin(2 * M_PI*sample[1]), sample[0]*cos(2 * M_PI*sample[1]), cos(asin(sample[0])));
}

float Warp::squareToCosineHemispherePdf(const Vector3f &v) {
	return (v[2] > 0) ? INV_TWOPI : 0;
}

Vector3f Warp::squareToBeckmann(const Point2f &sample, float alpha) {
    throw NoriException("Warp::squareToBeckmann() is not yet implemented!");
}

float Warp::squareToBeckmannPdf(const Vector3f &m, float alpha) {
    throw NoriException("Warp::squareToBeckmannPdf() is not yet implemented!");
}

NORI_NAMESPACE_END
