#pragma once
#include "../FoodObject.hpp"
#include "../../System/commons.hpp"

class Metal :public FoodObject{
private:

public:
	Metal();
	~Metal();

	virtual void Update();
	virtual void Draw();
  virtual void SetBox(Box box);

};