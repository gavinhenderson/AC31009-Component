class PhysicsComponent {
  public:
    PhysicsComponent();
    ~PhysicsComponent();

    void update(FredTheFrog& fred, Map& map){
      fred.x += fred.velocityX;
      fred.y += fred.velocityY;
      map.sortCollisions(fred);
    }
  private:
}

class GraphicsComponent {
  public:
    GraphicsComponent(Sprite& frog, Sprite& frogLeft, Sprite& frogRight) :
      still(frog), leftWalking(frogLeft), rightWalking(frogRight) {}
    ~GraphicsComponent();

    void update(FredTheFrog& fred){
      if(fred.velocityX==0){ still.draw(x,y); }
      else if(fred.velocityX>0){ rightWalking.draw(x,y); }
      else if(fred.velocityX<0){ leftWalking.draw(x,y); }
    }

  private:
    Sprite& still;
    Sprite& frogLeft;
    Sprite& frogRight;
}

class FredTheFrog {
public:
  FredTheFrog(PhysicsComponent& physics, GraphicsComponent& graphics) :
    velocityX(0), velocityY(0), x(0), y(0), acceleration(1),
    physicsComponent(physics), graphicsComponent(graphics) {}
  ~FredTheFrog(){}

  void update(Map& map){
    // Deal with keyinputs
    if(INPUT::getKeyDown() == "w"){
      velocityY -= acceleration;
    }else if(INPUT::getKeyDown() == "a"){
      velocityX -= acceleration;
    }else if(INPUT::getKeyDown() == "s"){
      velocityY += acceleration;
    }else if(INPUT::getKeyDown() == "d"){
      velocityX += acceleration;
    }

    // Update components
    physicsComponent.update(this*, map)
    graphicsComponent.update(this*)
  }

private:
  // We say (0,0) is the top left
  int velocityX, velocityY, x, y, acceleration;

  // Here we store our components
  PhysicsComponent& physicsComponent;
  GraphicsComponent& graphicsComponent

  // Sprite class exists for this sake
  Sprite* still;
  Sprite* leftWalking;
  Sprite* rightWalking;
}
