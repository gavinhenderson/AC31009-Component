### Contents

* [Video](#video)
* [Aims of the Design Pattern](#aim-of-the-design-pattern)
* [The Problem](#the-problem)
* [The Solution](#the-solution)
* [Code Along](#code-along)
  * [Rigid Class](#rigid-class)

## Video

<div style="text-align:center"><iframe width="560" height="315" src="https://www.youtube.com/embed/zlAqizx7Lf0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe></div>

## Aim of the Design Pattern

The aim of the 'Component' design pattern is to allows for the decoupling of domains from their entities allowing them to span multiple domains. Decoupling allows for code reusability and allows developers to work on different sections of the code at the same time.

## The Problem

Say we developed a 'character' who moves on player input, is animated on screen and interacts with the environment. Naturally we want to put everything that involves our character into one class so its all contained. This sounds like a good idea but this will end up in us having to duplicate lots of code between characters. It also means if we want to change one part of a character we have to alter the same function, exposing lots more possible errors and makes them harder to track. For example, if we want to update the physics of a character, we would be making changes in the same function as the graphics.

## The Solution

The solution to this problem is to separate out functionality into multiple components. A character is transformed into a GameObject, with multiple components that inherit from abstract interfaces. These abstract interfaces may cover functionality such as graphics and rendering, physics, and input.

<div style="text-align:center">
  <img src="diagrams/general.png">
</div>

## Code along

In the following demo, we provide an implementation of the Component design pattern by starting off with a sub-optimal solution. The following solution implements the protagonist of our game who we will call Fred The Frog. In our game we want to be able to move Fred the Frog around our screen and not be able to bump into other objects on the map. We also want him to be able to be animated so it is clear what he is doing. This is a somewhat realistic scenario of what we expect most objects in our game to be able to do in some capacity.

#### The Rigid Class

We start with a rigid class that is inflexible as seen below.

```cpp
class FredTheFrog {
public:
  // Constructor
  // Doesn't need any parameters as we know how we want Fred to Be and Act
  FredTheFrog() {
      velocityX     = 0;
      velocityY     = 0;
      x             = 0;
      y             = 0;
      acceleration  = 1;
      still         = new Sprite("frog.png");
      leftWalking   = new Sprite("frogleft.png");
      rightWalking  = new Sprite("frogright.png");
    }
  ~FredTheFrog() {}

  // Update function that we will add to the Game Loop to get called every loop iteration.
  void update(Map* map) {
    // Make changes based on keyboard inputs
    if (INPUT::getKeyDown() == "w") {
      velocityY -= acceleration;
    } else if (INPUT::getKeyDown() == "a") {
      velocityX -= acceleration;
    } else if (INPUT::getKeyDown() == "s") {
      velocityY += acceleration;
    } else if (INPUT::getKeyDown() == "d") {
      velocityX += acceleration;
    }

    // Alter the location of Fred and resolve collisions.
    x += velocityX;
    y += velocityY;
    map->sortCollisions(this*);

    // Display the correct sprite of Fred on the screen
    if (velocityX==0) { still.draw(x,y); }
    else if (velocityX>0) { rightWalking.draw(x,y); }
    else if (velocityX<0) { leftWalking.draw(x,y); }
  }

private:
  // We say (0,0) is the top left
  int velocityX, velocityY, x, y, acceleration;

  // We say that the sprite class is already implemented for this tutorial
  Sprite* still;
  Sprite* leftWalking;
  Sprite* rightWalking;
}
```
This code will run and work as expected. However, the problem occurs.

<div style="text-align:center">
  <img src="diagrams/example.png">
</div>
