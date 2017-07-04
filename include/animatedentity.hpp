#ifndef _ANIMATEDENTITY_HPP_
#define _ANIMATEDENTITY_HPP_

class AnimatedEntity {
private:
	int spriteInitX;
	int spriteEndX;
	int spriteInitY;
	int spriteEndY;

public:
	AnimatedEntity(int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);

	int getSpriteInitX() const;
	int getSpriteEndX() const;
	int getSpriteInitY() const;
	int getSpriteEndY() const;
};

#endif