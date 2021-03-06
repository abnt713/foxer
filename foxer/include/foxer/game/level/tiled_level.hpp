// File: tiled_level.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2019 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_TILED_LEVEL_HPP_
#define FOX_TILED_LEVEL_HPP_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "foxer/external/json.hpp"
#include "foxer/game/level/level.hpp"
#include "foxer/game/level/tiled_json_container.hpp"

namespace fox {

class TiledLevel : public Level {
public:
  TiledLevel();
  explicit TiledLevel(const std::string &json_tiled_file);
  void load();
  virtual void init() = 0;
  virtual void handle_events(const float &delta_time) = 0;

protected:
  std::map<std::string, TiledJsonObj> events;
  TiledJsonObj get_event(const std::string &event_id) const;

private:
  std::string json_tiled_file;
  std::vector<std::string> get_tilesets(const std::string &sub_path,
                                        json j_tilesets);

  json level;
  bool has_been_loaded;

  void load_level_json();
};

} // namespace fox

#endif
