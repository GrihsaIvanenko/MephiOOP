Test: TestWeapons TestShips TestBases

#####################################################

MyList:
	g++ -std=c++17 -c \
					./container/code/MyList.cpp \
					-o ./build/code/MyList.o

#####################################################

TestBases: TestTObjectOnMap TestTBase TestTSpawnDescriptor TestTPirateBase

TestTPirateBase: TPirateBase
	g++ -std=c++17 \
					./build/code/TObjectOnMap.o \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TShip.o \
					./build/code/TWarShip.o \
					./build/code/MyList.o \
					./build/code/TSpawnDescriptor.o \
					./build/code/TBase.o \
					./build/code/TPirateBase.o \
					./base/tests/TestTPirateBase.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TPirateBase
	valgrind ./build/tests/TPirateBase
	rm ./build/tests/TPirateBase

TPirateBase: TBase TSpawnDescriptor
	g++ -std=c++17 -c \
					./base/code/TPirateBase.cpp \
					-o ./build/code/TPirateBase.o

TestTSpawnDescriptor: TSpawnDescriptor
	g++ -std=c++17 \
					./build/code/TObjectOnMap.o \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TShip.o \
					./build/code/TWarShip.o \
					./build/code/MyList.o \
					./build/code/TSpawnDescriptor.o \
					./base/tests/TestTSpawnDescriptor.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestTSpawnDescriptor
	valgrind ./build/tests/TestTSpawnDescriptor
	rm ./build/tests/TestTSpawnDescriptor

TSpawnDescriptor: MyList TWarShip
	g++ -std=c++17 -c \
					./base/code/TSpawnDescriptor.cpp \
					-o ./build/code/TSpawnDescriptor.o

TestTBase: TBase
	g++ -std=c++17 \
        			./build/code/TBase.o \
        			./build/code/TObjectOnMap.o \
        			./base/tests/TestTBase.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTBase
	valgrind ./build/tests/TestTBase
	rm ./build/tests/TestTBase

TBase:
	g++ -std=c++17 -c \
    					./base/code/TBase.cpp \
    					-o ./build/code/TBase.o

TestTObjectOnMap: TObjectOnMap
	g++ -std=c++17 \
        			./build/code/TObjectOnMap.o \
        			./base/tests/TestTObjectOnMap.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTObjectOnMap
	valgrind ./build/tests/TestTObjectOnMap
	rm ./build/tests/TestTObjectOnMap

TObjectOnMap:
	g++ -std=c++17 -c \
    					./base/code/TObjectOnMap.cpp \
    					-o ./build/code/TObjectOnMap.o

#####################################################

TestShips: TestTCapitanInfo TestTShip TestTCargoShip TestTWarShip TestTCargoWarShip

TestTCargoWarShip: TCargoWarShip
	g++ -std=c++17 \
					./build/code/TObjectOnMap.o \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TShip.o \
					./build/code/TWarShip.o \
					./build/code/TCargoShip.o \
					./build/code/TCargoWarShip.o \
					./ships/tests/TestTCargoWarShip.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestTWarShip
	valgrind ./build/tests/TestTWarShip
	rm ./build/tests/TestTWarShip

TCargoWarShip: TWarShip TCargoShip
	g++ -std=c++17 -c \
					./ships/code/TCargoWarShip.cpp \
					-o ./build/code/TCargoWarShip.o

TestTWarShip: TWarShip
	g++ -std=c++17 \
					./build/code/TObjectOnMap.o \
	        		./build/code/TWeapon.o \
                    ./build/code/TWeaponHolder.o \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./build/code/TWarShip.o \
        			./ships/tests/TestTWarShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTWarShip
	valgrind ./build/tests/TestTWarShip
	rm ./build/tests/TestTWarShip

TWarShip: TShip TWeaponHolder
	g++ -std=c++17 -c \
        			./ships/code/TWarShip.cpp \
        			-o ./build/code/TWarShip.o

TestTCargoShip: TCargoShip
	g++ -std=c++17 \
	        		./build/code/TObjectOnMap.o \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./build/code/TCargoShip.o \
        			./ships/tests/TestTCargoShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTCargoShip
	valgrind ./build/tests/TestTCargoShip
	rm ./build/tests/TestTCargoShip

TCargoShip: TShip
	g++ -std=c++17 -c \
        			./ships/code/TCargoShip.cpp \
        			-o ./build/code/TCargoShip.o

TestTShip: TShip
	g++ -std=c++17 \
        			./build/code/TCapitanInfo.o \
        			./build/code/TShip.o \
        			./build/code/TObjectOnMap.o \
        			./ships/tests/TestTShip.cpp \
        			-lgtest -lgtest_main -lpthread \
        			-o ./build/tests/TestTShip
	valgrind ./build/tests/TestTShip
	rm ./build/tests/TestTShip

TShip: TCapitanInfo TObjectOnMap
	g++ -std=c++17 -c \
        			./ships/code/TShip.cpp \
        			-o ./build/code/TShip.o

TestTCapitanInfo: TCapitanInfo
	g++ -std=c++17 \
    			./build/code/TCapitanInfo.o \
    			./ships/tests/TestTCapitanInfo.cpp \
    			-lgtest -lgtest_main -lpthread \
    			-o ./build/tests/TestTCapitanInfo
	valgrind ./build/tests/TestTCapitanInfo
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
	valgrind ./build/tests/TestTWeaponHolder
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
	valgrind ./build/tests/TestTWeapon
	rm ./build/tests/TestTWeapon


TWeapon:
	g++ -std=c++17 -c \
			./weapons/code/TWeapon.cpp \
			-o ./build/code/TWeapon.o

#####################################################

clean:
	rm -r ./build/code/*
