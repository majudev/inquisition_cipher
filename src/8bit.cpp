/** 
* The MIT License (MIT)
* Copyright (c) 2016 Krystyna Gasiñska, Micha? Maj
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
#endif

size_t InquisitionCipher::InquisitionCipher::encode8(char * text, size_t * length, char * encoded){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::encode8();" << std::endl;
#endif
	unsigned int now = 0;
	int zn1, zn2, res1, res2;
	int x1, x2, y1, y2;
	while (now < *length) {
		zn1 = (int) text[now];
		++now;
		if (now < *length) zn2 = (int) text[now];  
		else zn2 = (int)'\0';
		++now;
             
		this->findxy((char) zn1, &x1, &y1);
		this->findxy((char) zn2, &x2, &y2);

		if (x1 == x2) {
			if (y1 == y2) {
				res1 = zn1;
				res2 = zn2;
			} else {
				res1 = (int)this->key[x1][(y1+1)%this->DIM];
				res2 = (int)this->key[x2][(y2+1)%this->DIM];
			}
		} else {
			if (y1 == y2) {
				res1 = (int)this->key[(x1 + 1)%this->DIM][y1];
				res2 = (int)this->key[(x2 + 1)%this->DIM][y2];
			} else {
				res1 = (int)this->key[x2][y1];
				res2 = (int)this->key[x1][y2];
			}
		}
		encoded[now-2] = (char) res1;
		encoded[now-1] = (char) res2;
	}
	*length = now ;
	return 0;
}


size_t InquisitionCipher::InquisitionCipher::decode8(char * text, size_t * length, char * decoded){
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::decode8();" << std::endl;
#endif
	unsigned int now = 0;
	int zn1, zn2, res1, res2;
	int x1, x2, y1, y2;
	while (now < *length) {
		zn1 = (int) text[now];
		++now;
		if (now < *length) zn2 = (int) text[now];  
		else zn2 = (int)'\0';
		++now;
             
		this->findxy((char) zn1, &x1, &y1);
		this->findxy((char) zn2, &x2, &y2);

		if (x1 == x2) {
			if (y1 == y2) { res1 = zn1; res2 = zn2; }
			else { res1 = (int)this->key[x1][(y1-1+this->DIM)%this->DIM]; res2 = (int)this->key[x2][(y2-1+this->DIM)%this->DIM]; }
		} else {
			if (y1 == y2)  { res1 = (int)this->key[(x1 -1+this->DIM)%this->DIM][y1]; res2 = (int)this->key[(x2 -1+this->DIM)%this->DIM][y2]; }
			else {res1 = (int)this->key[x2][y1]; res2 = (int)this->key[x1][y2]; }
		}
             
		decoded[now-2] = (char) res1;
		decoded[now-1] = (char) res2;
	}
	*length = now ;
	return 0;
}