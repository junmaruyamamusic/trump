#include "textfield.h"
#include <string>
//--------------------------------------------------------//
//�e�L�X�g�\���N���X
//--------------------------------------------------------//
TextField::TextField(){
	width = 0;
	height = 1;
}
//�e�L�X�g���Z�b�g
void TextField::setText(string _text){
	//�e�L�X�g��ۑ�
	text = _text;
	//�e�N�X�`���ɕϊ�
	data = _text;
	width = text.length();
	height = 1;
}
