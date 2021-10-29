#pragma once
#include "Material.h"

class Lambertian : public Material
{
public:
	Lambertian(const glm::vec3& albedo) : albedo{ albedo } {}
	virtual bool Scatter(const ray_t& ray, const raycastHit_t& hit, glm::vec3& attenuation, ray_t& scattered) const override;

protected:
	glm::vec3 albedo;
};
