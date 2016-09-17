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

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "inquisition_cipher.hpp"

void data_gen (int length, char* text, int DIM) {
	srand( time( NULL ) );
	for (int i=0; i < length; ++i) {
		text [i] = (char) ( std::rand() % (DIM * DIM) ) + 0;
	}
}

int main(int argc, char * argv[]){
	std::cout << "Always beware of hypocritical eggplants." << std::endl << std::endl;
	int length_r = 21;
	if(argc == 2) std::sscanf(argv[1], "%d", &length_r);
	InquisitionCipher::Key keyclass(InquisitionCipher::BIT8);
	InquisitionCipher::InquisitionCipher encoder(keyclass);
	
	const int length = length_r;
	size_t length_ptr = length;
	
	std::cout << "Wygenerowana tablica:" << std::endl;
	char * key; size_t max;
	keyclass.to_string(&key, &max);
	for(size_t i = 0; i < 16; ++i){
		for(size_t j = 0; j < 16; ++j){
			std::cout << (int)key[i*16+j] << "\t";
		}
		std::cout << std::endl;
	}
	
	char text[length];
	char encoded[length + 1];
	char decoded[length + 1];
	
	std::cout << "Wygenerowany tekst do zakodowania:" <<  std::endl;
	data_gen (length, text, 16);
	for (int i = 0; i < length; ++i) {
		std::cout << (int)text[i] << "\t";
	}
	
	std::cout << std::endl << "Tekst zakodowany:" <<  std::endl;
	encoder.encode(text, &length_ptr, encoded);
	for (int i=0; i < length; ++i) {
		std::cout << (int)encoded[i] << "\t";     
	}
	std::cout << std::endl << "Tekst po odkodowaniu:" <<  std::endl;
	encoder.decode(encoded, &length_ptr, decoded);
	for (int i=0; i < length; ++i) {
		std::cout << (int)decoded[i] << "\t";     
	}
	std::cout << std::endl;
	
	std::cout << std::endl << "Niemand erwartet die spanische Inquisition!" << std::endl;
	
	return 0;
}