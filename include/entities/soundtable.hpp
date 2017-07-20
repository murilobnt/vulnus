#ifndef _SOUNDTABLE_HPP_
#define _SOUNDTABLE_HPP_

#include <SFML/Audio.hpp>

class SoundTable {
private:
	sf::Music bgm; // 1
	sf::SoundBuffer psb;
	sf::Sound playerStep; // 2
	sf::SoundBuffer pghb;
	sf::Sound playerGetHit; // 3

public:
	SoundTable();
	void playSound(int id);
	void stopSound();
	void pauseSound();
};

#endif