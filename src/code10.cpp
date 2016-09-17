/** 
*The MIT License (MIT)
*Copyright (c) 2016 Krystyna Gasiñska
*Permission is hereby granted, free of charge, 
*to any person obtaining a copy of this software 
*and associated documentation files (the "Software"), 
*to deal in the Software without restriction, 
*including without limitation the rights to use, 
*copy, modify, merge, publish, distribute, sublicense, 
*and/or sell copies of the Software, and to permit 
*persons to whom the Software is furnished to do so, 
*subject to the following conditions:
*The above copyright notice and this permission notice shall be 
*included in all copies or substantial portions of the Software.
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
*EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
*IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
*DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
*ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*Submitting bug reports of unofficial builds is leading cause of male impotence.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

    const int DIM = 16;
    
void fill_key (unsigned char Key[][DIM]) {
     int i, j, k=0;
     for (i=0; i<DIM; ++i) {
         for (j=0; j<DIM; ++j) {
             Key[i][j] = (unsigned char) k;
             ++k;
         }
     }
}

bool findxy (unsigned char whattofind, unsigned char Key[][DIM], int*x, int*y) {
     int i, j;
     for (i=0; i<DIM; ++i) {
          for (j=0; j<DIM; ++j) {
             if (whattofind == Key[i][j]) {
                            *x = i;
                            *y = j;
                            return true;
             }
          }
     }
     return false;
}

void data_gen (size_t length, unsigned char* text) {
     int i;
     srand( time( NULL ) );
     for (i=0; i<length; ++i) {
         text [i] = (unsigned char) ( std::rand() % (DIM * DIM) ) + 0;
     }
}

size_t encode(unsigned char Key[][DIM], unsigned char * text, size_t * length, unsigned char * encoded){
       int now = 0;
       int zn1, zn2, res1, res2;
       int x1, x2, y1, y2;
       while (now < *length) {
             zn1 = (int) text[now];
             ++now;
             if (now < *length) zn2 = (int) text[now];  
             else zn2 = (int)'\0';
             ++now;
             
             findxy ((unsigned char) zn1, Key, &x1, &y1);
             findxy ((unsigned char) zn2, Key, &x2, &y2);

             if (x1 == x2) {
                    if (y1 == y2) { res1 = zn1; res2 = zn2; }
                    else { res1 = (int)Key[x1][(y1+1)%DIM]; res2 = (int)Key[x2][(y2+1)%DIM]; }
             }
             else {
                  if (y1 == y2)  { res1 = (int)Key[(x1 + 1)%DIM][y1]; res2 = (int)Key[(x2 + 1)%DIM][y2]; }
                  else {res1 = (int)Key[x2][y1]; res2 = (int)Key[x1][y2]; }
             }
             
             encoded[now-2] = (unsigned char) res1;
             encoded[now-1] = (unsigned char) res2;
       }
       *length = now ;
return 0;
}


size_t decode(unsigned char Key[][DIM], unsigned char * text, size_t * length, unsigned char * decoded){
       int now = 0;
       int zn1, zn2, res1, res2;
       int x1, x2, y1, y2;
       while (now < *length) {
             zn1 = (int) text[now];
             ++now;
             if (now < *length) zn2 = (int) text[now];  
             else zn2 = (int)'\0';
             ++now;
             
             findxy ((unsigned char) zn1, Key, &x1, &y1);
             findxy ((unsigned char) zn2, Key, &x2, &y2);

             if (x1 == x2) {
                    if (y1 == y2) { res1 = zn1; res2 = zn2; }
                    else { res1 = (int)Key[x1][(y1-1+DIM)%DIM]; res2 = (int)Key[x2][(y2-1+DIM)%DIM]; }
             }
             else {
                  if (y1 == y2)  { res1 = (int)Key[(x1 -1+DIM)%DIM][y1]; res2 = (int)Key[(x2 -1+DIM)%DIM][y2]; }
                  else {res1 = (int)Key[x2][y1]; res2 = (int)Key[x1][y2]; }
             }
             
             decoded[now-2] = (unsigned char) res1;
             decoded[now-1] = (unsigned char) res2;
       }
       *length = now ;
return 0;
}




int main () {
    int i, j, k, x, y;
    unsigned char Key [DIM][DIM];
    size_t length=21;
    unsigned char text [length];
    unsigned char encoded[length+1],decoded[length+1];
    
    fill_key (Key);
    for (i=0; i<DIM; ++i) {
          for (j=0; j<DIM; ++j) {
             cout << (int) Key[i][j] << " ";
             
          }
          cout << endl;
     }
     cout << endl;
     cout << "wygenerowany tekst do zakodowania:" << endl;
     data_gen (length, text);
     for (i=0; i<length; ++i) {
         cout << (int)text[i] << " ";     
     }
     cout << endl << "tekst zakodowany:" << endl;
     encode(Key, text, &length, encoded);
     for (i=0; i<length; ++i) {
         cout << (int)encoded[i] << " ";     
     }
     cout << endl << "tekst po odkodowaniu:" << endl;
     decode(Key, encoded, &length, decoded);
     for (i=0; i<length; ++i) {
         cout << (int)decoded[i] << " ";     
     }

//    cin >> i;
return 0;
}



