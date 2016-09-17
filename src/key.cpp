/** 
* The MIT License (MIT)
* Copyright (c) 2016 Krystyna Gasiñska, Michał Maj
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
* and associated documentation files (the "Software"), to deal in the Software without restriction, 
* including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
* and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
* subject to the following conditions: The above copyright notice and this permission notice shall be 
* included in all copies or substantial portions of the Software.
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* Submitting bug reports of unofficial builds is leading cause of male impotence.
*/

#include "inquisition_cipher.hpp"
#include <cstdlib>
#include <ctime>
#ifdef _DBG
#include <iostream>
#endif

InquisitionCipher::Key::Key(KeyType k) : k(k){
	int size;
	if(k == BIT4) size = 16;
	else if(k == BIT8) size = 256;
	else return;
	
	this->key = new char [size];
	char c = 0;
	for (int i = 0; i < size; ++i) {
		this->key[i] = c;
		++c;
	}
	
	srand(time(NULL));
	int max = rand() % 1000000;
	for (int i=0; i < max; ++i) {
		int x = rand() % size;
		int y = rand() % size;
		char InquisitionCipher = this->key[x];
		this->key[x] = this->key[y];
		this->key[y] = InquisitionCipher;
	}
}

InquisitionCipher::Key::Key(char * key, KeyType k) : k(k){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::Key::Key();" << std::endl;
#endif
	int size;
	if(k == BIT4) size = 16;
	else if(k == BIT8) size = 256;
	else return;
	this->key = new char [size];
	for(int i = 0; i != size; ++i){
		this->key[i] = key[i];
	}
}

size_t InquisitionCipher::Key::to_string(char ** string, size_t * size){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::Key::to_string();" << std::endl;
#endif
	if(k == BIT4) *size = 16;
	else if(k == BIT8) *size = 256;
	else return 0;
	*string = this->key;
	return *size;
}

InquisitionCipher::Key::~Key(){
	delete [] this->key;
}