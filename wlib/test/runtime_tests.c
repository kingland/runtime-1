/*
The MIT License (MIT)

Copyright (c) 2015 Terence Parr, Hanzhou Shi, Shuai Yuan, Yuanyuan Zhang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
The MIT License (MIT)

Copyright (c) 2015 Terence Parr, Hanzhou Shi, Shuai Yuan, Yuanyuan Zhang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <string.h>
#include <cunit.h>
#include <wich.h>

#define HEAP_SIZE           4096

static void setup() {
}

static void teardown() {
}


void test_strings() {
	String *s1 = String_new("hello"), *s2 = String_new("hellw");
	assert_equal(true, String_le(s1,s2));
	assert_equal(true, String_lt(s1,s2));
	assert_equal(false, String_ge(s1,s2));
	assert_equal(false, String_gt(s1,s2));
	assert_equal(true, String_neq(s1,s2));
	assert_equal(false, String_eq(s1,s2));

	String *s3 = String_new("hello"), *s4 = String_new("hellaz");
	assert_equal(false, String_le(s3, s4));
	assert_equal(false, String_lt(s3, s4));
	assert_equal(true, String_ge(s3, s4));
	assert_equal(true, String_gt(s3, s4));
	assert_equal(true, String_neq(s3,s4));
	assert_equal(false, String_eq(s3,s4));

	String *s5 = String_new("hello"), *s6 = String_new("helloa");
	assert_equal(true, String_le(s5, s6));
	assert_equal(true, String_lt(s5, s6));
	assert_equal(false, String_ge(s5, s6));
	assert_equal(false, String_gt(s5, s6));
	assert_equal(true, String_neq(s5,s6));
	assert_equal(false, String_eq(s5,s6));

	String *s7 = String_new("hello"), *s8 = String_new("hello");
	assert_equal(false, String_neq(s7,s8));
	assert_equal(true, String_eq(s7,s8));
}


int main(int argc, char *argv[]) {
	cunit_setup = setup;
	cunit_teardown = teardown;

	test(test_strings);

	return 0;
}