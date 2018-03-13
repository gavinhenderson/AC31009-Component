class PhysicsComponent {
  public:
    PhysicsComponent();
    ~PhysicsComponent();

    void update(FredTheFrom& fred, Map& map){
      fred.x += fred.velocityX;
      fred.y += fred.velocityY;
      map.sortCollisions(fred);
    }
  private:
}

class FredTheFrog {
public:
  FredTheFrog(PhysicsComponent& physics) :
    velocityX(0), velocityY(0), x(0), y(0), acceleration(1),
    physicsComponent(physics),
    still(new Sprite('frog.png')), leftWalking(new Sprite('frogleft.png')), rightWalking(new Sprite('frogright.png')) {}
  ~FredTheFrog(){}

  void update(Map& map){
    //Deal with keyinputs
    if(INPUT::getKeyDown() == "w"){
      velocityY -= acceleration;
    }else if(INPUT::getKeyDown() == "a"){
      velocityX -= acceleration;
    }else if(INPUT::getKeyDown() == "s"){
      velocityY += acceleration;
    }else if(INPUT::getKeyDown() == "d"){
      velocityX += acceleration;
    }

    //Update components
    physicsComponent.update(this*, map)

    //Deal with graphics
    if(velocityX==0){ still.draw(x,y); }
    else if(velocityX>0){ rightWalking.draw(x,y); }
    else if(velocityX<0){ leftWalking.draw(x,y); }
  }

private:
  //We say (0,0) is the top left
  int velocityX, velocityY, x, y, acceleration;

  //Here we store our components
  PhysicsComponent physicsComponent;

  //Sprite class exists for this sake
  Sprite* still;
  Sprite* leftWalking;
  Sprite* rightWalking;
}
