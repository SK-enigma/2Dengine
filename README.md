 FEATURES
Entity Component System (ECS)
– Highly modular game logic where:
• Entity = game object (player, enemy, projectile) identified by a unique ID
• Component = data/behavior attached to entities (e.g., PositionComponent, VelocityComponent, RenderComponent)
• System = logic runner on entities with matching components (e.g., MovementSystem, RenderSystem)

Smart Pointers
– Modern C++ memory management with std::shared_ptr and std::unique_ptr
• Automatic cleanup of unused components
• No manual delete calls
• Reduces memory leaks and dangling pointers

SDL2 Integration
– Core rendering and input via SDL2:
• Window creation & management
• Real-time keyboard handling
• Sprite rendering & texture loading

 WHAT I LEARNED
ECS Architecture
– Decoupling of data & logic for clean, reusable code
– Rapid prototyping and feature expansion without tight coupling

Smart Pointers in C++
– Focus on game logic, not manual memory cleanup
– Safer code with automatic resource management

Game Development Fundamentals
– Implemented a frame-limited game loop
– Handled input events in real time
– Managed textures and 2D rendering pipelines
