#include "entities/soundtable.hpp"

SoundTable::SoundTable(){
	bgm.openFromFile("sounds/happy8bitloop.wav");
	bgm.setLoop(true);

	psb.loadFromFile("sounds/footstep.ogg");
	playerStep.setBuffer(psb);
	playerStep.setVolume(30);

	pghb.loadFromFile("sounds/metallichit.wav");
	playerGetHit.setBuffer(psb);
}

void SoundTable::playSound(int id){
	switch(id){
		case 1:
			bgm.play();
		break;
		case 2:
			playerStep.play();
		break;
		case 3:
			playerGetHit.play();
		break;
		default:
		break;
	}
}

void SoundTable::stopSound(){
	bgm.stop();
}

void SoundTable::pauseSound(){
	bgm.pause();
}