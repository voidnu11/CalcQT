GCC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
LGFLAGS=-lgtest_main  -lgtest -lpthread --coverage
CLIBS = -lstdc++
BD=build/
UNAME_S := $(shell uname -s)
APP=calcqt

all: run

run: install
ifeq ($(UNAME_S),Darwin)
	open $(HOME)/Applications/CalcQT/$(APP)
else
	cd $(HOME)/Applications/CalcQT && ./$(APP)
endif

build: full_clean
	@mkdir $(BD)
	cp -R assets model controller view *.cpp *.pro build
	cd build && qmake calcqt.pro
	make -C $(BD)

install: build
	@mkdir -p $(HOME)/Applications/CalcQT/
	cp -rf $(BD)$(APP) $(HOME)/Applications/CalcQT/
	make clean

uninstall:
	rm -rf $(HOME)/Applications/CalcQT/

dvi:
ifeq ($(UNAME_S),Darwin)
	open documentation.html
else
	xdg-open documentation.html
endif

dist:
	tar -cvf $(HOME)/Applications/CalcQT/../CalcQT.tar $(HOME)/Applications/CalcQT/
	gzip $(HOME)/Applications/CalcQT/../CalcQT.tar

tests: clean_report
	$(GCC) $(CFLAG) tests.cpp model/Calc/calculator.cpp model/Calc/validator.cpp model/Calc/rpn.cpp model/Calc/displaytext.cpp -o tests -lgtest -lpthread
	./tests

gcov_report: clean_report
	@$(GCC) model/Calc/calculator.cpp model/Calc/validator.cpp model/Calc/rpn.cpp model/Calc/displaytext.cpp --coverage tests.cpp $(FLAGS) -o tests -lgtest -lpthread
	@./tests
	lcov -t "tests" --no-external -o tests.info -c -d ./
	genhtml -o report tests.info
ifeq ($(UNAME_S),Darwin)
	open report/index.html
else
	xdg-open report/index.html
endif

check:
	clang-format -n main.cpp tests.cpp model/Calc/calculator.cpp model/Calc/rpn.cpp model/Calc/validator.cpp model/Calc/displaytext.cpp controller/maincontroller.cpp view/mainwindow.cpp view/plotwindow.cpp view/mainwindow.cpp view/calculatordisplay.cpp view/basetitlebar.cpp
	cppcheck --language=c++ --enable=all --suppressions-list=suppression.cfg .main.cpp tests.cpp model/Calc/calculator.cpp model/Calc/rpn.cpp model/Calc/validator.cpp model/Calc/displaytext.cpp controller/maincontroller.cpp view/mainwindow.cpp view/plotwindow.cpp view/mainwindow.cpp view/calculatordisplay.cpp view/basetitlebar.cpp


full_clean: clean
	rm -rf $(BD)

clean: clean_report
	rm -f $(BD)*.o $(BD)*.cpp $(BD)*.h $(BD)*.pro
	rm -rf $(BD)assets $(BD)model $(BD)controller $(BD)view

clean_report:
	rm -f *.gcda *.gcno *.info tests
	rm -rf report

