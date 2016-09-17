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
#ifdef _DBG
#include <iostream>
#include <cstdio>
#endif

InquisitionCipher::InquisitionCipher::InquisitionCipher(Key & k){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::InquisitionCipher();" << std::endl;
#endif
	if(k.k == BIT4) this->DIM = 4;
	else if(k.k == BIT8) this->DIM = 16;
	
	this->key = new char * [this->DIM];
	for(int i = 0; i != this->DIM; ++i){
		this->key[i] = new char [this->DIM];
		for(int j = 0; j != this->DIM; ++j) this->key[i][j] = k.key[this->DIM*i+j];
	}

#ifdef _DBG
	std::cout << "[D] TABLE =========================================" << std::endl;
	for (int i=0; i < this->DIM; ++i) {
		for (int j=0; j < this->DIM; ++j) {
			printf("%u ", this->key[i][j]);
		}
		std::cout << std::endl;
	}
	std::cout << "[D] TABLE =========================================" << std::endl;
#endif
}

InquisitionCipher::InquisitionCipher::~InquisitionCipher(){
	for(int i = 0; i != this->DIM; ++i){
		delete [] this->key[i];
	}
	delete [] this->key;
}

size_t InquisitionCipher::InquisitionCipher::encode(char * text, size_t * length, char * encoded){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::encode();" << std::endl;
#endif
	if(this->DIM == 4) return this->encode4(text, length, encoded);
	if(this->DIM == 16) return this->encode8(text, length, encoded);
	return 0;
}

size_t InquisitionCipher::InquisitionCipher::decode(char * text, size_t * length, char * encoded){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::decode();" << std::endl;
#endif
	if(this->DIM == 4) return this->decode4(text, length, encoded);
	if(this->DIM == 16) return this->decode8(text, length, encoded);
	return 0;
}