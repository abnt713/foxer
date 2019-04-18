#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/exit_area.hpp>
#include <gs2d/other/geared_up/sample_level.hpp>

class LevelOne;

class LevelTwo : public gs::SampleLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::ExitArea exit;
  gs::ThreadedLevelLoader level_one_loader;

  void on_fade_out();
  void on_fade_in();
  void handle_level_events(const float &delta_time);
  void level_init();

public:
  LevelTwo();
  LevelTwo(gs::MainObject *character, gs::LevelProxy *level_proxy,
           const std::string &start_position_id, bool fade_in = true);
};

#endif
