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
#endif

bool InquisitionCipher::InquisitionCipher::findxy(char whattofind, int*x, int*y) {
#ifdef _DBG
	std::cout << "[D] Running InquisitionCipher::InquisitionCipher::findxy(" << (int) whattofind << ");" << std::endl;
#endif
	int i, j;
	for (i=0; i<this->DIM; ++i) {
		for (j=0; j<this->DIM; ++j) {
			if (whattofind == this->key[i][j]) {
				*x = i;
				*y = j;
#ifdef _DBG
				std::cout << "[D] x=" << (int) *x << "\ty=" << (int) *y << std::endl;
#endif
				return true;
			}
		}
	}
	return false;
}