#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Result/result.hpp"
#include "../../System/picojson.h"
#include "../../System/commons.hpp"
#include "../../Foods/FoodObject.hpp"
#include "../../Foods/selectedFood.hpp"
#include "../../Foods/Insect/Insect.hpp"
#include "../../Foods/Metal/Metal.hpp"
#include "../../Foods/Vegetables/Vegetables.hpp"
#include <fstream>
#include <cassert>
#define FOODTEXTURESIZE 100
#define FOODTOFOODLENGTH 200
#define TIMELIMITMAX 600

class GameMain : public Scene{
private:
  picojson::value settings;
  void LoadSettings();
  //std::vector<std::shared_ptr<FoodObject>> food;
  std::list<SelectedFood> selected;

  Random rand;
  FoodObject* food[3];
  int time_limit = TIMELIMITMAX;
  int pattern = rand(1, 6);

public:
  GameMain();
  void Update() override;
  void Draw() override;
  void Shuffle();
  void Move();
  void Reset();
  void SetFoodPos();
};