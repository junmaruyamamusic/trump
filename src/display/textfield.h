#ifndef JP_TACM_TEXTFIELD
#define JP_TACM_TEXTFIELD
#include <string>
#include "sprite.h"

//--------------------------------------------------------//
//�e�L�X�g�\���N���X(Sprite���p��)
//--------------------------------------------------------//
class TextField : public Sprite {
public:
	TextField();
	void setText(string _text);
private:
	string text;
};

#endif
