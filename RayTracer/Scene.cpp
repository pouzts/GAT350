#include "Scene.h"
#include "Material.h"

glm::vec3 Scene::Trace(const ray_t& r, float tMin, float tMax, raycastHit_t& hit)
{
    float tClosest = tMax;
    bool rayHit = false;
    for (auto& object : objects)
    {
        if (object->Hit(r, tMin, tClosest, hit))
        {
            rayHit = true;
            tClosest = hit.t;
        }
    }

	if (rayHit)
	{
		ray_t scattered;
		glm::vec3 attenuation;

		if (hit.material->Scatter(r, hit, attenuation, scattered))
		{
			return attenuation * Trace(scattered, tMin, tMax, hit);
		}
		else
		{
			return { 0, 0, 0 };
		}
	}


    return glm::vec3({0, 0, 0});
}

void Scene::Add(std::unique_ptr<Geometry> geometry)
{
	objects.push_back(std::move(geometry));
}
