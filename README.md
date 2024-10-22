2D Game Engine
Overview
This is a custom 2D Game Engine built in C++ using the SDL2 library. The engine implements an Entity Component System (ECS) architecture, which allows for flexible and modular design of game objects. By breaking down game objects into independent components, it enables better code reusability and easier maintainability. This project also helped me get hands-on experience with smart pointers (std::shared_ptr, std::unique_ptr), which I used extensively for managing resources and memory within the engine.

Features
Entity Component System (ECS): The core of the engine is the ECS architecture, where each game entity is composed of one or more components, making the system highly modular and extendable.

Entity: Represents a game object.
Component: Represents the behaviors or properties of entities (e.g., position, velocity, rendering).
System: Handles the logic and interactions between components.
Smart Pointers: Managed memory using std::shared_ptr and std::unique_ptr to handle component creation and destruction, ensuring safe memory management without manual deletion.

SDL2 Integration: Used SDL2 for rendering, input handling, and window management, providing the essential tools for 2D game development.

What I Learned
Entity Component System (ECS): I learned how to decouple game logic and structure entities in a way that is highly flexible and reusable. By using components, I can easily add or remove functionality from an entity without affecting other parts of the engine.

Entities are simple objects that only hold a unique ID.
Components define the data that represents different parts of an entity, like its position, velocity, or rendering attributes.
Systems operate on entities with specific components, handling the game logic for those components.
Smart Pointers in C++: I applied std::shared_ptr and std::unique_ptr for memory management within the ECS. Smart pointers simplified resource management, ensuring that memory was cleaned up automatically when no longer in use.

Game Development Fundamentals: Working with SDL2 helped me understand how to manage game loops, render sprites, and handle real-time input events.

