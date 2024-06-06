#include "util.h"

unsigned long div(unsigned long dividend, unsigned long divisor) {
	unsigned long quotient = 0;
	
	while(dividend >= divisor) {
		dividend = dividend - divisor;
		quotient++;
	}

	return quotient;
}

unsigned char is_alpha(unsigned char aChar) {
	if((aChar >= 'A' && aChar <= 'Z') || (aChar >= 'a' && aChar <= 'z')) {
		return 1;
	}
	
	return 0;
}

unsigned char is_upper(unsigned char aChar) {
	if(aChar >= 'A' && aChar <= 'Z') {
		return 1;
	}
	
	return 0;
}

unsigned char is_lower(unsigned char aChar) {
	if(aChar >= 'a' && aChar <= 'z') {
		return 1;
	}
	
	return 0;
}

unsigned int is_num(unsigned char aChar) {
	if(aChar >= '0' && aChar <= '9')
		return 1;
	
	return 0;
}