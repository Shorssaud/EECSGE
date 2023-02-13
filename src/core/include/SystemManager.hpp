#pragma once

#include "System.hpp"
#include "Types.hpp"
#include <cassert>
#include <memory>
#include <unordered_map>


class SystemManager
{
public:
	template<typename T>
	// Register a system and return a shared pointer to it
	std::shared_ptr<T> RegisterSystem();

	template<typename T>
	// Set the signature for a system
	void SetSignature(Signature signature);

	// Notify each system that an entity has been destroyed
	void EntityDestroyed(Entity entity);

	// Notify each system that an entity's signature changed
	void EntitySignatureChanged(Entity entity, Signature entitySignature);

private:
	std::unordered_map<const char*, Signature> mSignatures{};
	std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
};
