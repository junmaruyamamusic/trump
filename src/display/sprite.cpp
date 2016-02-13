#include "sprite.h"
#include <string>
using namespace std;
//--------------------------------------------------------//
//�`��I�u�W�F�N�g�̌��^
//Sprite�̖��O�̗R����ActionScript�̐^���ł��B
//--------------------------------------------------------//
Sprite::Sprite() {
	data = "";
	x = y = 0;
	width = height = 0;
	transparent = false;
	//�I�u�W�F�N�g�ŗL��id��ۑ�����B
	static int _id = 0;
	_id ++;
	id = _id;
	scale = 1;
}
void Sprite::addChild(Sprite* s) {
	//�q�I�u�W�F�N�g��ǉ�����B
	//�����ActionScript�̐^���ł���B
	child.push_back(s);
}
void Sprite::removeChild(Sprite* s) {
	//child�͎q�I�u�W�F�N�g�ł���B
	//�q�I�u�W�F�N�g�ɂ͏d�ˏ�������A�ǉ��������ԂɊǗ������K�v������B
	//����Đe��addChild�������ԂɂȂ�K�v������A
	//�\�[�g���Ă͂����Ȃ��B���̂��߁Aid����v������̂��폜������@��
	//���̕��@���������΂Ȃ������B
	//���������A���̊֐��͕p�ɂɌĂ΂�邱�Ƃ͂Ȃ��̂ŁA���܂�g��Ȃ��B
	//�P�ɃI�u�W�F�N�g�۔�\���ɂ���ꍇ�́Avisible��false�ɂ���Ηǂ��B
	int l = child.size();
	for(int i = 0; i < l; i ++){
		if(child[i]->id == s->id){
			child.erase(child.begin() + i);
			return;
		}
	}
}
void Sprite::setSize(int _width, int _height){
	width = _width;
	height = _height;
	data = "";
	for(int i = 0; i < width * height; i ++){
		data += ' ';
	}
}
//�h�b�g��ł�
void Sprite::dot(int x, int y, char c){
	//c = c==' '?'0':'1';
	if(x >= width || y >= height || x < 0 || y < 0){
		return;
	}
	data[width * y + x] = c;
}
