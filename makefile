cs:
	@echo `pwd`
	@rsync -r -t -u -v --delete \
	--include "*.html"          \
	--exclude "*"               \
	. downing@$(CS):cs/projects/integer/

OS       := $(shell uname)
VALGRIND := $(shell which valgrind)

ifeq ($(OS), Darwin)
	BOOST :=
else
	BOOST := -I/public/linux/include/boost-1_38
endif

.PRECIOUS: %.c++.app
.PRECIOUS: %.class

RunInteger.c++.app: RunInteger.c++ Integer.h
	g++ -ansi -pedantic $(BOOST) -Wall $< -o RunInteger.c++.app

TestInteger.c++.app: TestInteger.c++ Integer.h
	g++ -ansi -pedantic $(BOOST) -lcppunit -ldl -Wall $< -o TestInteger.c++.app

RunInteger.class: RunInteger.java Integer.java
	javac -Xlint RunInteger.java

TestInteger.class: TestInteger.java Integer.java
	javac -Xlint TestInteger.java

RunInteger.c++x: RunInteger.c++.app
	$(VALGRIND) RunInteger.c++.app

TestInteger.c++x: TestInteger.c++.app
	$(VALGRIND) TestInteger.c++.app

RunInteger.javax: RunInteger.class
	java -ea RunInteger

TestInteger.javax: TestInteger.class
	java -ea TestInteger

RunInteger.pyx:
	RunInteger.py

TestInteger.pyx:
	TestInteger.py

clean:
	rm -f *.app
	rm -f *.class
	rm -f *.pyc

list:
	ls -al *.app
	ls -al *.class

run:
	make RunInteger.c++x

test:
	make TestInteger.c++x
