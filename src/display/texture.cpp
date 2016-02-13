#include "texture.h"
#include "sprite.h"
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <time.h>
//#include "textfield.h"
using namespace std;
///--------------------------------------------------------//
//�e�N�X�`���f�[�^�N���X
//--------------------------------------------------------//
void TextureData::setup(string _data, int _width, int _height, bool _transparent = false){
	data = _data;
	width = _width;
	height = _height;
	transparent = _transparent;
}
//--------------------------------------------------------//
//�e�N�X�`���N���X(Sprite���p��)
//--------------------------------------------------------//
void Texture::setTextureData(TextureData _texture, bool _transparent){
	data = _texture.getData();
	texture = _texture;
	transparent = _transparent;
	width = texture.getWidth();
	height = texture.getHeight();
	/*TextField* t = new TextField;
	t->setText("test");
	t->x = 9;
	t->y = 7;
	addChild(t);*/
}
//--------------------------------------------------------//
//�e�N�X�`�����[�_�[
//--------------------------------------------------------//
bool TextureDataLoader::load(const char* fileName){
	if((fp = fopen(fileName, "r,ccs=UTF-8")) == NULL) {
		return false;
	}
	list.clear();
	parse();
	fclose(fp);
	return true;
}
TextureData TextureDataLoader::get(string label){
	return list.at(label);
}
void TextureDataLoader::convertToTexture(int width, int height, string name, vector<string> lines){
	printf("-------------------------\n");
	printf("name : %s\n", name.c_str());
	printf("width,height : %d,%d\n", width, height);
	int length = lines.size() - 1;
	string data = "";
	for(int i = 0; i < length; i ++){
		while(lines[i].size() < width){
			lines[i] += " ";
		}
		data += lines[i];
	}
	printf("data : ");
	for(int i = 0; i < width*height; i ++){
		printf("%c",data.c_str()[i]);
	}
	printf("\n");

	list[name].setup(data, width, height, false);
	double interval = 0.05 * CLOCKS_PER_SEC;
	clock_t cc = clock();
	while(clock() - cc < interval);
}
//�ǂݍ��񂾃f�[�^�̃p�[�X
void TextureDataLoader::parse() {
	char c;
	int id, twidth, width, height;
	string name="";
	vector<string> lines;
	string phase = "";
	while(1) {

		c = fgetwc(fp);
		//-------------------------------------------------------//
		//�@�V�K�e�N�X�`���̏���
		//-------------------------------------------------------//
		if(c == '@') {
			//���̃e�N�X�`���J�n�L�����𔭌�������e�N�X�`���o�^
			if(phase == "data"){
				convertToTexture(width, height, name, lines);
			}
			//���̃f�[�^�o�^�ɔ����ď�����
			id = 0;
			name = "";
			lines.clear();
			lines.push_back("");
			height = twidth = width = 0;
			//�t�F�[�Y���u�e�N�X�`�����̃p�[�X�v���[�h��
			phase = "name";
			continue;
		}
		//-------------------------------------------------------//
		//�@�t�F�[�Y�@�F�@�e�N�X�`�����̃p�[�X
		//-------------------------------------------------------//
		if(phase == "name"){
			if(c == '\n'){
				//���s�R�[�h�����o������p�[�X���I�����A
				//�t�F�[�Y���u�e�N�X�`���f�[�^�̃p�[�X�v���[�h��
				phase = "data";
				continue;
			}
			name += c;
			continue;
		}
		//-------------------------------------------------------//
		//�@�t�F�[�Y�@�F�@�e�N�X�`���f�[�^�̃p�[�X
		//-------------------------------------------------------//
		if(phase == "data"){
			if(c == '\n' || c < 0) {
				height++;
				if(width < twidth){
					width = twidth;
				}
				twidth = 0;
				lines.push_back("");
				id++;
				//c < 0�܂�EOF�H�Ȃ�Ō�̃f�[�^��o�^���A�I���B
				if(c < 0){
					//�e�N�X�`���o�^
					convertToTexture(width, height, name, lines);
					break;
				}
				continue;
			}
			twidth++;
			lines[id] += c;
			continue;
		}
	}
}
