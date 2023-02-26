#pragma once

#include "Types.hpp"
#include <set>

namespace eecsge
{
	class System
	{
	public:
		std::set<Entity> mEntities;
	};
}

// example system
// for (auto const& entity : mEntities)
// {
// 	auto& rigidBody = GetComponent<RigidBody>(entity);
// 	auto& transform = GetComponent<Transform>(entity);
// 	auto const& gravity = GetComponent<Gravity>(entity);

// 	transform.position += rigidBody.velocity * dt;

// 	rigidBody.velocity += gravity.force * dt;
// }