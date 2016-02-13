#include "tween.h"
#include "texture.h"
#include <math.h>
//--------------------------------------------------------//
//�X�v���C�g���C�[�W���O���ʂɂ���Ĉړ�����
//--------------------------------------------------------//
bool SpriteTween::moveTo(Sprite *s, int targetX, int targetY){
	moveTo(s, targetX, targetY, 1, 0.14);

}
bool SpriteTween::moveTo(Sprite *s, int targetX, int targetY, double targetScale, double speed){
	//�قڈړ�������������true��Ԃ�
	if(fabs(s->getX() - targetX) < 0.4 && fabs(s->getY() - targetY) < 0.4 && fabs(s->getScale() - targetScale) < 0.04){
		s->setX(targetX);
		s->setY(targetY);
		s->setScale(targetScale);
		return true;
	}
	s->setX(s->getX() + (targetX - s->getX()) * speed);
	s->setY(s->getY() + (targetY - s->getY()) * speed);
	s->setScale(s->getScale() + (targetScale - s->getScale()) * speed);
	return false;
}
