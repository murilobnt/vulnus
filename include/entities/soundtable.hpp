#ifndef _SOUNDTABLE_HPP_
#define _SOUNDTABLE_HPP_

#include <SFML/Audio.hpp>

class SoundTable {
private:
	sf::Music bgm; // 1
	sf::Music playerStep; // 2
	sf::Music playerGetHit; // 3

public:
	SoundTable();
	void playSound(int id);
};

#endif