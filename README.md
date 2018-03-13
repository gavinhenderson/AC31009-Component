### Contents

* [Aims of the Design Pattern](#aim-of-the-design-pattern)
* [The Problem](#the-problem)
* [The Solution](#the-solution)
* [Code Along](#code-along)

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

In the following demo, we provide an implementation of the Component design pattern by starting off with a sub-optimal solution.

```cpp
class FredTheFrog {
public:
  FredTheFrog() :
    velocityX(0), velocityY(0), x(0), y(0), acceleration(1),
    still(new Sprite("frog.png")), leftWalking(new Sprite("frogleft.png")), rightWalking(new Sprite("frogright.png")) {}
  ~FredTheFrog() {}

  void update(Map* map) {
    //Deal with keyinputs
    if (INPUT::getKeyDown() == "w") {
      velocityY -= acceleration;
    } else if (INPUT::getKeyDown() == "a") {
      velocityX -= acceleration;
    } else if (INPUT::getKeyDown() == "s") {
      velocityY += acceleration;
    } else if (INPUT::getKeyDown() == "d") {
      velocityX += acceleration;
    } else if (INPUT::getKeyDown() == "space") {
    }

    //Deal with physics
    x += velocityX;
    y += velocityY;
    map->sortCollisions(this*);

    //Deal with graphics
    if (velocityX==0) { still.draw(x,y); }
    else if (velocityX>0) { rightWalking.draw(x,y); }
    else if (velocityX<0) { leftWalking.draw(x,y); }
  }

private:
  //We say (0,0) is the top left
  int velocityX, velocityY, x, y, acceleration;

  //Sprite class exists for this sake
  Sprite* still;
  Sprite* leftWalking;
  Sprite* rightWalking;
}

```

<div style="text-align:center">
  <img src="diagrams/example.png">
</div>
