#include "ECS.h"
#include "../Logger/Logger.h"



int IComponent::nextId = 0;

int Entity::GetId() const {

	return id;
}

void Entity::Kill() {
	registry->KillEntity(*this);
	Logger::Log("Entity " + std::to_string(this->GetId()) + " was killed");
}


void System::AddEntityToSystem(Entity entity) {
	entities.push_back(entity);

}


void System::RemoveEntityFromSystem(Entity entity) {
	entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
		return entity == other;
		}), entities.end());


	 

}

std::vector<Entity> System::GetSystemEntities() const {
	
	return entities;
}

const Signature& System::GetComponentSignature() const {

	return componentSignature;
}




Entity Registry::CreateEntity() {
	int entityId;

	if (freeIds.empty()) {
		// if rthere are no free ids waiting to be reused

		entityId = numEntities++;
		if (entityId >= entityComponentSignatures.size()) {
			entityComponentSignatures.resize(entityId + 1);
		}

	}
	else {
		//reuse an id from the list of previously removed entities

		entityId = freeIds.front();
		freeIds.pop_front();

	}

	entityId = numEntities++;
	Entity entity(entityId);

	entity.registry = this;
	entitiesToBeAdded.insert(entity);

	if (entityId >= entityComponentSignatures.size()) {
		entityComponentSignatures.resize(entityId + 1);

	}








	Logger::Log("Entity created with id = " + std::to_string(entityId));

	return entity;
}



void Registry::KillEntity(Entity entity) {

	entitiesToBeKilled.insert(entity);


}












void Registry::AddEntityToSystems(Entity entity)
{
	const auto entityId = entity.GetId();
	const auto& entityComponentSignature = entityComponentSignatures[entityId];

	//loop all the systems 

	for (auto system : systems) {
		const auto& systemComponentSignature = system.second->GetComponentSignature();

		bool isInterested = (entityComponentSignature & systemComponentSignature) == systemComponentSignature;

		if (isInterested) {
			system.second->AddEntityToSystem(entity);
		}


	}


}


void Registry::RemoveEntityFromSystems(Entity entity) {
	for (auto system : systems) {
		system.second->RemoveEntityFromSystem(entity);
	}
}


void Registry::Update() {

	// processing the entities that waiting to be created to the active systems 


	for (auto entity : entitiesToBeAdded) {
		AddEntityToSystems(entity);
	}

	entitiesToBeAdded.clear();

	for (auto entity : entitiesToBeKilled) {

		RemoveEntityFromSystems(entity);

		entityComponentSignatures[entity.GetId()].reset();

		//make the entity id available to be reused
		freeIds.push_back(entity.GetId());
	}

	entitiesToBeKilled.clear();

}



