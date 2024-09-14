#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H
#include "../ECS/ECS.h"

#include "../Components/RigidBodyComponent.h"
#include "../Components/TransformComponent.h"



class MovementSystem : public System {

public:

	MovementSystem() {
		RequireComponent<TransformComponent>();
		RequireComponent<RigidBodyComponent>();


	}

	void Update(double deltaTime) {
		for (auto entity : GetSystemEntities()) {
			auto& transform = entity.GetComponent<TransformComponent>();
			auto& rigidbody = entity.GetComponent<RigidBodyComponent>();

			transform.position.x += rigidbody.velocity.x * deltaTime;
			transform.position.y += rigidbody.velocity.y * deltaTime;

		}

	}


};











#endif
