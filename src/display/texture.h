#ifndef _JP_TACM_TEXTURE_LIST
#define _JP_TACM_TEXTURE_LIST

#include "sprite.h"
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
using namespace std;
//--------------------------------------------------------//
//�e�N�X�`���f�[�^�N���X
//--------------------------------------------------------//
class TextureData {
public:
	string getData(){return data;}
	int getWidth(){return width;}
	int getHeight(){return height;}
	bool getTransparent(){return transparent;}
	void setup(string _data, int _width, int _height, bool _transparent);
protected:
	string data;
	int width, height;
	bool transparent;
};
//--------------------------------------------------------//
//�e�N�X�`���N���X(Sprite���p��)
//--------------------------------------------------------//
class Texture : public Sprite{
public:
	TextureData getTextureData(){return texture;}
	void setTextureData(TextureData _texture, bool transparent = false);
protected:
	TextureData texture;
};
//--------------------------------------------------------//
//�e�N�X�`�����[�_�[
//--------------------------------------------------------//
class TextureDataLoader {
private:
	FILE *fp;
	map<string, TextureData> list;
	void convertToTexture(int width, int height, string name, vector<string> lines);
	void parse();
public:
	bool load(const char* filename);
	TextureData get(string label);
};
#endif
