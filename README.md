

🧩 Features
🎮 Entity Component System (ECS)
The core of the engine uses an ECS architecture, allowing highly modular and scalable game logic.

Entity: A game object identified by a unique ID (e.g., player, enemy, projectile).

Component: Defines the data or behavior attached to entities (e.g., PositionComponent, VelocityComponent, RenderComponent).

System: Executes logic on entities that have a matching set of components (e.g., MovementSystem, RenderSystem).

This design makes it easy to add or remove behaviors without tightly coupling systems or duplicating logic.

💾 Smart Pointers
Used std::shared_ptr and std::unique_ptr to manage memory throughout the ECS, ensuring:

Automatic cleanup of unused components

No manual delete calls

Safer and more modern memory management

🖥️ SDL2 Integration
SDL2 powers the rendering pipeline and input system:

Window creation and management

Real-time keyboard input

Sprite rendering and texture loading

🧠 What I Learned
🧱 ECS Architecture
I learned how to build and structure an engine where game entities are composed of components and operated on by systems. This pattern:

Decouples logic from data

Encourages clean and reusable code

Makes it easier to prototype and expand features

⚙️ Smart Pointers in C++
Working with shared_ptr and unique_ptr taught me modern memory management:

Avoid memory leaks and dangling pointers

Focus more on logic than manual cleanup

Build safer, more maintainable code

🎮 Game Development Fundamentals
Using SDL2 gave me experience with:

Implementing a frame-limited game loop

Handling real-time input events

Managing textures and 2D rendering

