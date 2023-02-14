#pragma once

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "Types.hpp"
#include <memory>
#include <vector>


class Coordinator
{
public:
	void Init();


	// Entity methods
	Entity CreateEntity();

	void DestroyEntity(Entity entity);


	// Component methods
	void RegisterComponent();

	template<typename T>
	void AddComponent(Entity entity, T component);

	void RemoveComponent(Entity entity);

	template<typename T>
	T& GetComponent(Entity entity);

	ComponentType GetComponentType();

	// System methods
	template<typename T>
	std::shared_ptr<T> RegisterSystem();

	void SetSystemSignature(Signature signature);
private:
	std::unique_ptr<ComponentManager> mComponentManager;
	std::unique_ptr<EntityManager> mEntityManager;
	std::unique_ptr<SystemManager> mSystemManager;
};
