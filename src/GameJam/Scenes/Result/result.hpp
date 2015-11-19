#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Title/title.hpp"
#include "../../System/commons.hpp"
#include "../../Utility/Collision/collision.hpp"

class Result : public Scene{
private:

  // ���O��(��)
  enum class Animation
  {
    Toilet,
    Door,
    FadingOut, 
    Select,
  };

  Font font = Font("res/meiryo.ttc");
  Color image = Color::gray;    // �{����Texture
  Box title_f = Box{ Vec2f(-300, -400), Vec2f(250, 50) };
  Box retry_f = Box{ Vec2f(80, -400), Vec2f(200, 50) };
  Box background = Box{ Vec2f(-360, -480), Vec2f(720, 960) };
  Box keepout = Box{ Vec2f(-360, 960), Vec2f(720, 960) };
  int slide_count = 0;     // �g�C���ɋ삯���ރV�[���̐؂�ւ�����
  bool select_active = false;
  Animation animation = Animation::Toilet;
  float fedinf_a = 0;

public:
  Result();
  void Update() override;
  void Draw() override;
  void Select();
  void AnimationChange();
  void AnimationUpdate();
  void FedingOut();
  void FedingIn();
  void TimeReset();

};