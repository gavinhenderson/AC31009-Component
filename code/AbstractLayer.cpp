class InputComponent{
  public:
    virtual InputComponent() {};
    virtual ~InputComponent() {};
    virtual void update(GameObject& obj);
  private:
}

class GraphicsComponent{
  public:
    virtual GraphicsComponent() {};
    virtual ~GraphicsComponent() {};
    virtual void update(GameObject& obj);
  private:
}

class PhysicsComponent{
  public:
    virtual PhysicsComponent() {};
    virtual ~PhysicsComponent() {};
    virtual void update(GameObject& obj);
  private:
}

class GameObject{
  public:
    int x,y,velocityX,velocityY;

    void update(){
      input->update(*this);
      graphics->update(*this);
      physics->update(*this);
    }
  private:
    InputComponent* input;
    GraphicsComponent* graphics;
    PhysicsComponent* phyics;
}
