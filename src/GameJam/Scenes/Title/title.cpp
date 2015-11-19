#include "title.hpp"

Title::Title(){
  FailCheck(ResMed.Insert("res/sound/select.wav", AudioKey::Select));
}

void Title::Update(){

}

void Title::Draw(){
  App::Get().bgColor(Color::navy);
  Box test_box{ Vec2f(-200, -300), Vec2f(400, 100) };
  if (Collision::MouseToBox(App::Get().mousePosition(), test_box)){
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::red);
    if (App::Get().isPushButton(Mouse::LEFT)){
      ResMed.Get(AudioKey::Select).play();
      scene_manager->ChangeScene(std::make_shared<GameMain>());
    }
  }
  else{
  drawFillBox(test_box.pos.x(), test_box.pos.y(),
    test_box.size.x(), test_box.size.y(), Color::white);
  }

  Box explanation_box{ Vec2f(-200, -400), Vec2f(400, 100) };
  if (Collision::MouseToBox(App::Get().mousePosition(), explanation_box)){
	  /* 後ほど画像と交換予定（？） */
	  drawFillBox(explanation_box.pos.x(), explanation_box.pos.y(),
		  explanation_box.size.x(), explanation_box.size.y(), Color::blue);
	  if (App::Get().isPushButton(Mouse::LEFT)){
      ResMed.Get(AudioKey::Select).play();
		  scene_manager->ChangeScene(std::make_shared<Explanation>());
	  }
  }
  else{
	  drawFillBox(explanation_box.pos.x(), explanation_box.pos.y(),
		  explanation_box.size.x(), explanation_box.size.y(), Color::white);
  }
}