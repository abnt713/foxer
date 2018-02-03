#include "gamesimple/components/animatedentity.hpp"

AnimatedEntity::AnimatedEntity(int spriteInitX, int spriteEndX, int spriteInitY,
                               int spriteEndY) {
  this->spriteInitX = spriteInitX;
  this->spriteEndX = spriteEndX;
  this->spriteInitY = spriteInitY;
  this->spriteEndY = spriteEndY;
  this->animationLoopState = 0;
}

AnimatedEntity::AnimatedEntity(){}

int AnimatedEntity::getSpriteInitX() const { return this->spriteInitX; }

int AnimatedEntity::getSpriteEndX() const { return this->spriteEndX; }

int AnimatedEntity::getSpriteInitY() const { return this->spriteInitY; }

int AnimatedEntity::getSpriteEndY() const { return this->spriteEndY; }
