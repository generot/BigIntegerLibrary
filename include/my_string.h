#ifndef __MY_STRING__
#define __MY_STRING__

class String {
private:
	const char *ptr;
	size_t len;
public:
	String(const char *str);
	
	String operator+ (const String& other);

	size_t length();
	const char *c_str();
	void custom_destroy();

	friend ostream& operator<< (ostream& os, const String& str);
};

#endif
