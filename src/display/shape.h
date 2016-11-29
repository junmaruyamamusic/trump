#ifndef JP_TACM_SPRITE_PLUS
#define JP_TACM_SPRITE_PLUS

#include "sprite.h"
#include <string>

using namespace std;

//--------------------------------------------------------//
//�`���@�\�����ł̃X�v���C�g(Sprite���p��)
//--------------------------------------------------------//
class Shape : public Sprite {
public:
	Shape();
	void fill(char c){fillc = c;}//�h���̕������Z�b�g
	void noFill(){fillc = ' ';}//�h���̕������Ȃ��ɃZ�b�g
	void clear();
	void rect(int x, int y, int w, int h);
	void line(int x1, int y1, int x2, int y2);
private:
	char fillc;
};

#endif
