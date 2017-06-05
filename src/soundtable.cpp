#include "soundtable.hpp"

SoundTable::SoundTable(){
	bgm.openFromFile("sounds/happy8bitloop.wav");
	bgm.setLoop(true);

	playerStep.openFromFile("sounds/footstep.ogg");
	playerStep.setVolume(30);

	playerGetHit.openFromFile("sounds/metallichit.wav");
}

void SoundTable::playSound(int id){
	switch(id){
		case 1:
			//bgm.play();
		break;
		case 2:
			//playerStep.play();
		break;
		case 3:
			//playerGetHit.play();
		break;
		default:
		break;
	}
}