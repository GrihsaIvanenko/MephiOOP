all: TLevelReader TCapitanInfo TWeapon TWeaponHolder TObjectOnMap TShip TCargoShip TCargoWarShip TBase \
							TSpawnDescriptor TPirateBase TMission TLevelReader TShop TLevelSelector TPlaying \
							TGameCenter TimeHolder
	g++ -std=c++17 \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TObjectOnMap.o \
					./build/code/TShip.o \
					./build/code/TCargoShip.o \
					./build/code/TWarShip.o \
					./build/code/TCargoWarShip.o \
					./build/code/TBase.o \
					./build/code/TSpawnDescriptor.o \
					./build/code/TPirateBase.o \
					./build/code/TMission.o \
					./build/code/TLevelReader.o \
					./build/code/TLevelSelector.o \
					./build/code/TShop.o \
					./build/code/TPlaying.o \
					./build/code/TimeHolder.o \
					./build/code/TGameCenter.o \
					./game/code/main.cpp \
					-o ./build/code/game
	./build/code/game



Test: TestWeapons TestShips TestBases TestMyList TestTLevelReader

#####################################################

TestGameLogic: TestTLevelReader TestTShop

TGameCenter:
	g++ -std=c++17 -c \
					./game/code/TGameCenter.cpp \
					-o ./build/code/TGameCenter.o

TPlaying: TimeHolder
	g++ -std=c++17 -c \
					./game/code/TPlaying.cpp \
					-o ./build/code/TPlaying.o

TimeHolder:
	g++ -std=c++17 -c \
					./game/code/TimeHolder.cpp \
					-o ./build/code/TimeHolder.o

TestTShop: TLevelReader TCapitanInfo TWeapon TWeaponHolder TObjectOnMap TShip \
           					 TCargoShip TCargoWarShip TBase TSpawnDescriptor TPirateBase TMission TLevelReader TShop
		g++ -std=c++17 \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TObjectOnMap.o \
					./build/code/TShip.o \
					./build/code/TCargoShip.o \
					./build/code/TWarShip.o \
					./build/code/TCargoWarShip.o \
					./build/code/TBase.o \
					./build/code/TSpawnDescriptor.o \
					./build/code/TPirateBase.o \
					./build/code/TMission.o \
					./build/code/TLevelReader.o \
					./build/code/TShop.o \
					./game/tests/TShop/code/TestTShop.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestTShop
		valgrind ./build/tests/TestTShop
		rm ./build/tests/TestTShop

TShop:
	g++ -std=c++17 -c \
					./game/code/TShop.cpp \
					-o ./build/code/TShop.o

TLevelSelector:
	g++ -std=c++17 -c \
					./game/code/TLevelSelector.cpp \
					-o ./build/code/TLevelSelector.o

TestTLevelReader : TLevelReader TCapitanInfo TWeapon TWeaponHolder \
 					TCapitanInfo TObjectOnMap TShip TCargoShip TCargoWarShip TBase TSpawnDescriptor TPirateBase TMission
	g++ -std=c++17 \
					./build/code/TWeapon.o \
					./build/code/TWeaponHolder.o \
					./build/code/TCapitanInfo.o \
					./build/code/TObjectOnMap.o \
					./build/code/TShip.o \
					./build/code/TCargoShip.o \
					./build/code/TWarShip.o \
					./build/code/TCargoWarShip.o \
					./build/code/TBase.o \
					./build/code/TSpawnDescriptor.o \
					./build/code/TPirateBase.o \
					./build/code/TMission.o \
					./build/code/TLevelReader.o \
					./game/tests/TLevelReader/code/TestTLevelReader.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestTLevelReader
	valgrind ./build/tests/TestTLevelReader
	rm ./build/tests/TestTLevelReader

TLevelReader:
	g++ -std=c++17 -c \
					./game/code/TLevelReader.cpp \
					-o ./build/code/TLevelReader.o

TMission:
	g++ -std=c++17 -c \
					./game/code/TMission.cpp \
					-o ./build/code/TMission.o

#####################################################

TestMyList:
	g++ -std=c++17 \
					./container/tests/TestMyList.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestMyList
	valgrind ./build/tests/TestMyList
	rm ./build/tests/TestMyList


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
					./build/code/TSpawnDescriptor.o \
					./build/code/TBase.o \
					./build/code/TPirateBase.o \
					./base/tests/TestTPirateBase.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestPirateBase
	valgrind ./build/tests/TestPirateBase
	rm ./build/tests/TestPirateBase

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
					./build/code/TSpawnDescriptor.o \
					./base/tests/TestTSpawnDescriptor.cpp \
					-lgtest -lgtest_main -lpthread \
					-o ./build/tests/TestTSpawnDescriptor
	valgrind ./build/tests/TestTSpawnDescriptor
	rm ./build/tests/TestTSpawnDescriptor

TSpawnDescriptor: TWarShip
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
