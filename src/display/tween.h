#ifndef _JP_TACM_TWEEN
#define _JP_TACM_TWEEN

#include <math.h>
#include "texture.h"
//--------------------------------------------------------//
//�X�v���C�g���C�[�W���O���ʂɂ���Ĉړ�����
//--------------------------------------------------------//
class SpriteTween {
public:
	//�X�v���C�g�����X�Ɏw�肵�����W�ֈړ�������
	static bool moveTo(Sprite *s, int targetX, int targetY, double targetScale, double speed);
	static bool moveTo(Sprite *s, int targetX, int targetY);
};

#endif
