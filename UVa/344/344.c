#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char array[103][10] = {"i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix",
		"x", "xi", "xii", "xiii", "xiv", "xv", "xvi", "xvii", "xviii", "xix",
		"xx", "xxi", "xxii", "xxiii", "xxiv", "xxv", "xxvi", "xxvii", "xxviii",
		"xxix", "xxx", "xxxi", "xxxii", "xxxiii", "xxxiv", "xxxv", "xxxvi", 
		"xxxvii", "xxxviii", "xxxix", "xl", "xli", "xlii", "xliii", "xliv", 
		"xlv", "xlvi", "xlvii", "xlviii", "xlix", "l", "li", "lii", "liii", 
		"liv", "lv", "lvi", "lvii", "lviii", "lix", "lx", "lxi", "lxii", 
		"lxiii", "lxiv", "lxv", "lxvi", "lxvii", "lxviii", "lxix", "lxx", 
		"lxxi", "lxxii", "lxxiii", "lxxiv", "lxxv", "lxxvi", "lxxvii",
		"lxxviii", "lxxix", "lxxx", "lxxxi", "lxxxii", "lxxxiii", "lxxxiv",
		"lxxxv", "lxxxvi", "lxxxvii", "lxxxviii", "lxxxix", "xc", "xci", "xcii"
		,"xciii", "xciv", "xcv", "xcvi", "xcvii", "xcviii", "xcix", "c"};

int main(){
	int cases, i, j;
	scanf("%d", &cases);
	while(cases != 0){
		int cont_i = 0, cont_v = 0, cont_x = 0, cont_l = 0, cont_c = 0;
		for(i = 0; i < cases; i++){
			for(j = 0; j < strlen(array[i]); j++){
				cont_i = (array[i][j] == 'i') ? cont_i += 1 : cont_i;
				cont_v = (array[i][j] == 'v') ? cont_v += 1 : cont_v;
				cont_x = (array[i][j] == 'x') ? cont_x += 1 : cont_x;
				cont_l = (array[i][j] == 'l') ? cont_l += 1 : cont_l;
				cont_c = (array[i][j] == 'c') ? cont_c += 1 : cont_c;
			}
		}

		printf("%d: %d i, %d v, %d x, %d l, %d c\n", cases, cont_i, cont_v, cont_x,
				cont_l, cont_c);

		scanf("%d", &cases);
	}


	return 0;
}