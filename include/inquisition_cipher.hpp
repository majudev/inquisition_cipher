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
*
* Always beware of eggplants.
*/

#ifndef _INQUISITION_CIPHER_H_
#define _INQUISITION_CIPHER_H_
#include <cstddef>

namespace InquisitionCipher{
	enum KeyType { BIT8, BIT4 };
	
	class Key{
		public:
			Key(KeyType k);
			Key(char * key, KeyType k);
			size_t to_string(char ** string, size_t * size);
			~Key();
		protected:
			char * key;
			KeyType k;
			friend class InquisitionCipher;
	};

	class InquisitionCipher{
		public:
			InquisitionCipher(Key & k);
			~InquisitionCipher();
			size_t encode(char * text, size_t * length, char * encoded);
			size_t decode(char * text, size_t * length, char * encoded);
		private:
			int DIM;
			char ** key;
			bool findxy (char whattofind, int*x, int*y) ;
			size_t encode4(char * text, size_t * length, char * encoded);
			size_t decode4(char * text, size_t * length, char * encoded);
			size_t encode8(char * text, size_t * length, char * encoded);
			size_t decode8(char * text, size_t * length, char * encoded);
	};
}
#endif