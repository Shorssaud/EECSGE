#include <EECSGE/Core.hpp>
#include <EECSGE/Physics.hpp>
#include <EECSGE/Graphics.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace eecsge;

Coordinator gCoordinator;
class PhysicsSystem : public System {
public:
	void Update(void) {
		std::cerr << "PENIS " << mEntities.size() << std::endl;
		for (auto const& entity : mEntities) {
			auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
			if (rigidBody.hasCollision == false) {
				rigidBody.position.x += rigidBody.velocity.x;
				rigidBody.position.y += rigidBody.velocity.y;
			}
		}
	}
};

TEST(Entities, MovementTest) {

    gCoordinator.Init();

	gCoordinator.RegisterComponent<RigidBody>();
	auto physics = gCoordinator.RegisterSystem<PhysicsSystem>();

	Signature Psignature;
	Psignature.set(gCoordinator.GetComponentType<RigidBody>());

	gCoordinator.SetSystemSignature<PhysicsSystem>(Psignature);


	// create entities
	auto e1 = gCoordinator.CreateEntity();

	gCoordinator.AddComponent<RigidBody>(e1,
		RigidBody{
			sf::Vector2i(0, 0),
			sf::Vector2f(1, 0),
			sf::Vector2f(0, 0),
			sf::Vector2f(0, 0),
			sf::Vector2f(0, 0),
			sf::Vector2f(0, 0),
			false
	});
	while (gCoordinator.GetComponent<RigidBody>(e1).position.x < 100) {
		physics->Update();
	}
	EXPECT_EQ(gCoordinator.GetComponent<RigidBody>(e1).position.x, 100);
	gCoordinator.DestroyEntity(e1);
}

TEST(Entities, RemovalTest) {
	Coordinator gCoordinator;
    gCoordinator.Init();
	std::vector<Entity> entities;
	// add 6 entities to coordinator
	for (int i = 0; i < 6; i++) {
		entities.push_back(gCoordinator.CreateEntity());
	}
	gCoordinator.DestroyEntity(entities[1]);
	// remove all entities from coordinator
	while(entities.size() > 0) {
		std::cerr << "Destroying entity " << entities[0] << std::endl;
		gCoordinator.DestroyEntity(entities[0]);
		// output on test logs to show that entities are being removed
		std::cerr << "Entity " << entities[0] << " removed" << std::endl;
		entities.erase(entities.begin());
	}
	EXPECT_EQ(entities.size(), 0);
}