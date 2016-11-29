#include "sprite.h"
#include "display.h"
#include <string>
#include <iostream>

using namespace std;
//���A�����A�w�i�F�i�w�i��h��Ԃ��L���j��ݒ肵������
void Display::setup(int width, int height, char background){
	_width = width + 1;
	_height = height;
	_background = background;
	_data = "";
	_maskMode = false;
	_maskData = "";
	//init
	for(int i = 0; i < _width * _height; i ++){
		_data += '@';
		_maskData += ' ';
	}
	clear();
}
//��ʃN���A
void Display::clear(){
	_masked = false;
	for(int y = 0; y < _height; y++){
		for(int x = 0; x < _width; x++){

			_data[_width * y + x] = _background;

			_maskData[_width * y + x] = ' ';
		}
	}
}
//�`��
void Display::render(){
	//if(_masked) _mask();
	for(int y = 0; y < _height; y++){
		_data[_width * y + _width - 1] = '\n';
	}

	system("cls"); //unix�p�̃X�N���[���N���A�R�}���h��windows�̃R�}���h�v�����v�g�̃X�N���[���N���A�֕ύX
	cout << _data;
	//printf("%s",_data);
}
//���s�[�g�摜
void Display::repeatBackground(Sprite* s){
	for(int x = 0; x < _width; x += s->getWidth()){
		for(int y = 0; y < _height; y += s->getHeight()){
			s->setX(x);
			s->setY(y);
			draw(s);
		}
	}
}
//�X�v���C�g����ʂɒǉ�
void Display::draw(Sprite *s){
	_draw(s, 0, 0);
}
void Display::mask(Sprite *s){
	_masked = true;
	_maskMode = true;
	_draw(s, 0, 0);
	_mask();
	_maskMode = false;
}
void Display::_draw(Sprite* s, double px, double py){
	//��ʂɃh�b�g�R���Z�b�g
	setDots(s->getX() + px, s->getY() + py, s->getData(), s->getWidth(), s->getHeight(), s->getTransparent(), s->getScale());
	int childSize = s->getChild().size();
	for(int i = 0; i < childSize; i ++){
		Sprite* cs = s->getChild()[i];
		//�e�ł���s�̍��W����_�Ƃ��A�q�̍��W������
		_draw(cs, s->getX(), s->getY());
	}
}
//�h�b�g��ł�
void Display::setDot(int x, int y, char c){
	//c = c==' '?'0':'1';
	if(x >= _width || y >= _height || x < 0 || y < 0){
		return;
	}
	if(_maskMode && c != ' '){
		_maskData[_width * y + x] = '@';
		return;
	}
	_data[_width * y + x] = c;
}
//�h�b�g�Q��ł�
void Display::setDots(double x, double y, string data, int w, int h, bool transparent, double scale){
	int _x = (int)(x + 0.5);
	int _y = (int)(y + 0.5);
	//�X�P�[���̓K�p
	for(int ty = 0; ty < h; ty++){
		for(int tx = 0; tx < w; tx++){
			char c = data[w * ty + tx];
			//�w�i�������[�h�Ȃ�󔒂𖳎�����
			if(transparent && c == ' '){
				continue;
			}
			//�h�b�g��ł�
			setDot(_x + scale * (double)tx, _y + scale * (double)ty, c);
		}
	}
}
//mask
void Display::_mask(){
	int size = _maskData.size();
	for(int i = 0; i < size; i ++){
		if(_maskData[i] != '@'){
			_data[i] = ' ';
		}
	}
}
//���̃Q�b�^�[
int Display::getWidth(){
	return _width - 1;
}
//�����̃Q�b�^�[
int Display::getHeight(){
	return _height;
}
