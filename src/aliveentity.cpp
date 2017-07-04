#include "aliveentity.hpp"

void AliveEntity::increaseHealth(float modifier){
	this->health += modifier;
}

void AliveEntity::increaseSpeed(float modifier){
	this->speed += modifier;
}

void AliveEntity::decreaseHealth(float modifier){
	this->onCombo = true;
	this->entityComboDelimeter.resetLastUpdate();
	this->comboDamage += modifier;

	this->damageOutput.setString(IntToString::IntToString((int) - comboDamage));

	this->health -= modifier;
}

void AliveEntity::decreaseSpeed(float modifier){
	this->speed -= modifier;
}

AliveEntity::AliveEntity(int x, int y, float health, float speed, sf::Texture const& texture,
	                       int spriteX, int spriteY, int spriteW, int spriteH,
											   float entityGravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY) : 
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH),
AnimatedEntity::AnimatedEntity(spriteInitX, spriteEndX, spriteInitY, spriteEndY),
entityComboDelimeter(sf::seconds(2.5)) {
	this->movement = sf::Vector2f(0.f, 0.f);
	setSpritePosition(x, y);

	this->entityGravity = entityGravity;
	this->isJumping = true;
	this->animationLeftLoop = 0;
	this->animationRightLoop = 0;

	this->health = health;
	this->originalSpeed = speed;
	this->speed = speed;

	this->quad = 0;

	this->comboDamage = 0;

	this->onCombo = false;
}

void AliveEntity::moveEntity(const DynamicGrid& dynaGrid){
	moveSprite(movement);
	updateQuad(dynaGrid.getQuad(getSpritePosition()));
}

sf::Vector2f AliveEntity::getMovement() const{
	return this->movement;
}

void AliveEntity::setMovementX(float x){
	this->movement.x = x;
}

void AliveEntity::setMovementY(float y){
	this->movement.y = y;
}

void AliveEntity::applyGravity(){
	if (this->movement.y < 6)
		this->movement.y += entityGravity;
}

bool AliveEntity::getIsJumping() const{
	return this->isJumping;
}

void AliveEntity::setIsJumping(bool jumping){
	this->isJumping = jumping;
}

float AliveEntity::getGravity() const{
	return this->entityGravity;
}

float AliveEntity::getHealth() const{
	return this->health;
}

void AliveEntity::updateQuad(int newQuad){
	if(quad != newQuad){
		quad = newQuad;
	}
}

int AliveEntity::getQuad() const{
	return this->quad;
}

void AliveEntity::cccomboBreak(){
	this->onCombo = false;
	this->comboDamage = 0;
}

bool AliveEntity::getOnCombo() const{
	return this->onCombo;
}

GenericTimeHandler* AliveEntity::getEntityComboDelimeter(){
	return &this->entityComboDelimeter;
}

void AliveEntity::setComboDelimeter(int seconds){
	this->entityComboDelimeter = GenericTimeHandler(sf::seconds(seconds));
}

void AliveEntity::init(const sf::Font& font){
	this->damageOutput = sf::Text(std::string("-0"), font);

	this->damageOutput.setCharacterSize(20);
  	this->damageOutput.setColor(sf::Color::Red);
}

void AliveEntity::updateDamageText(){
	this->damageOutput.setPosition(getSpritePosition().x + getSpriteLocalBounds().width/2 - this->damageOutput.getLocalBounds().width/2, getSpritePosition().y - 32);
}

sf::Text AliveEntity::getDamageOutput() const{
	return this->damageOutput;
}

void AliveEntity::drawText(sf::RenderTarget& target){
  target.draw(this->damageOutput);
}

bool AliveEntity::isFacingRight() const{
	return this->facingRight;
}