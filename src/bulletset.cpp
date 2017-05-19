#include "bulletset.hpp"

BulletSet::BulletSet(){ }

void BulletSet::addBullet(Bullet bullet){
  this->bulletSet.push_back(bullet);
}

bool BulletSet::hasAtLeastOneBullet(){
  if(this->bulletSet.empty()){
    return false;
  }
  return true;
}

std::vector<Bullet> BulletSet::getBulletSet(){
  return this->bulletSet;
}
