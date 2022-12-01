Test: TestWeapons TestShips

#####################################################

TestShips: TestTCapitanInfo TestTShip TestTCargoShip TestTWarShip

TestTWarShip: TWarShip
	g++ -std=c++17 \
	        		./build/code/TWeapon.o \
                    ./build/code/TWeaponHolder.o \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./build/code/TWarShip.o \
        			./ships/tests/TestTWarShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTWarShip
	./build/tests/TestTWarShip
	rm ./build/tests/TestTWarShip

TWarShip: TShip TWeaponHolder
	g++ -std=c++17 -c \
        			./ships/code/TWarShip.cpp \
        			-o ./build/code/TWarShip.o

TestTCargoShip: TCargoShip
	g++ -std=c++17 \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./build/code/TCargoShip.o \
        			./ships/tests/TestTCargoShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTCargoShip
	./build/tests/TestTCargoShip
	rm ./build/tests/TestTCargoShip

TCargoShip: TShip
	g++ -std=c++17 -c \
        			./ships/code/TCargoShip.cpp \
        			-o ./build/code/TCargoShip.o

TestTShip: TShip
	g++ -std=c++17 \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./ships/tests/TestTShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTShip
	./build/tests/TestTShip
	rm ./build/tests/TestTShip

TShip: TCapitanInfo
	g++ -std=c++17 -c \
        			./ships/code/TShip.cpp \
        			-o ./build/code/TShip.o

TestTCapitanInfo: TCapitanInfo
	g++ -std=c++17 \
    			./build/code/TCapitanInfo.o \
    			./ships/tests/TestTCapitanInfo.cpp \
    			-lgtest -lgtest_main -lpthread \
    			-o ./build/tests/TestTCapitanInfo
	./build/tests/TestTCapitanInfo
	rm ./build/tests/TestTCapitanInfo

TCapitanInfo:
	g++ -std=c++17 -c \
    			./ships/code/TCapitanInfo.cpp \
    			-o ./build/code/TCapitanInfo.o

#####################################################

TestWeapons: TestTWeaponHolder TestTWeapon

TestTWeaponHolder: TWeaponHolder
	g++ -std=c++17 \
			./build/code/TWeapon.o \
			./build/code/TWeaponHolder.o \
			./weapons/tests/TestTWeaponHolder.cpp \
			-lgtest -lgtest_main -lpthread \
			-o ./build/tests/TestTWeaponHolder
	./build/tests/TestTWeaponHolder
	rm ./build/tests/TestTWeaponHolder


TWeaponHolder: TWeapon
	g++ -std=c++17 -c \
			./weapons/code/TWeaponHolder.cpp \
			-o ./build/code/TWeaponHolder.o

TestTWeapon: TWeapon
	g++ -std=c++17 \
			./build/code/TWeapon.o \
			./weapons/tests/TestTWeapon.cpp \
			-lgtest -lgtest_main -lpthread \
			-o ./build/tests/TestTWeapon
	./build/tests/TestTWeapon
	rm ./build/tests/TestTWeapon


TWeapon:
	g++ -std=c++17 -c \
			./weapons/code/TWeapon.cpp \
			-o ./build/code/TWeapon.o

#####################################################

clean:
	rm -r ./build/code/*
