#include <EECSGE/EECSGE.hpp>
#include <gtest/gtest.h>

Coordinator gCoordinator;

class PhysicsSystem : public System {
public:
	void Update(void) {
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
}