#ifndef CAMERAMOVEMENTSYSTEM_H
#define CAMERAMOVEMENTSYSTEM_H

#include "../ECS/ECS.h"
#include "../Components/CameraFollowComponent.h"
#include "../Components/TransformComponent.h"
#include <SDL.h>





struct CameraMovementSystem : public System {

    CameraMovementSystem() {

        RequireComponent<CameraFollowComponent>();
        RequireComponent<TransformComponent>();

    }


    void Update(SDL_Rect& camera) {
        for (auto entity : GetSystemEntities()) {
            auto transform = entity.GetComponent<TransformComponent>();

            // Only move the camera once the entity crosses the center of the screen
            if (transform.position.x > (Game::windowWidth / 2)) {
                camera.x = static_cast<int>(transform.position.x - (Game::windowWidth / 2));
            }

            if (transform.position.y > (Game::windowHeight / 2)) {
                camera.y = static_cast<int>(transform.position.y - (Game::windowHeight / 2));
            }

            camera.x = std::max(0, std::min(camera.x, Game::mapWidth - camera.w));
            camera.y = std::max(0, std::min(camera.y, Game::mapHeight - camera.h));



            camera.x = camera.x < 0 ? 0 : camera.x;
            camera.y = camera.y < 0 ? 0 : camera.y;
            camera.x = camera.x > camera.w ? camera.w : camera.x;
            camera.y = camera.y > camera.h ? camera.h : camera.y;
          
        }
    }






};

#endif
