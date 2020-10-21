#include <iostream>
#include <cstring>
#include "../include/my_string.h"

using std::ostream;

String::String(const char *str) : ptr(strdup(str)), len(strlen(str)) {}

String String::String operator+ (const String& other) {
	size_t new_size = len + other.len + 1;
	char *buff = new char[new_size];

	snprintf(buff, new_size, "%s%s", ptr, other.ptr);
	buff[new_size-1] = '\0';

	String to_ret(buff);
	delete[] buff;

	return to_ret;
}

size_t String::length() { return len; }

const char* String::c_str() {
	return strdup(ptr);
}

void String::custom_destroy() { delete[] ptr; }

ostream& operator<< (ostream& os, const String& str) {
	os << str.ptr;
	return os;
}

