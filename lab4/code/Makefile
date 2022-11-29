test: capitanInfoTest weaponHolderTest weaponTest shipTest

##################################################

shipTest: ship
	g++ -std=c++17 ./ships/TShipTest.cpp ./build/ships/TShip.o ./build/ships/TCapitanInfo.o  -lgtest -lgtest_main -lpthread -o ./build/ships/test
	./build/ships/test
	rm ./build/ships/test

ship: capitanInfo
	g++ -std=c++17 -c ./ships/TShip.cpp -o ./build/ships/TShip.o

capitanInfoTest: capitanInfo
	g++ -std=c++17 ./ships/TCapitanInfoTest.cpp ./build/ships/TCapitanInfo.o  -lgtest -lgtest_main -lpthread -o ./build/ships/test
	./build/ships/test
	rm ./build/ships/test

capitanInfo:
	g++ -std=c++17 -c ./ships/TCapitanInfo.cpp -o ./build/ships/TCapitanInfo.o



#####################################################

weaponHolderTest: weaponHolder
	g++ -std=c++17 ./weapons/TWeaponHolderTest.cpp ./build/weapons/TWeaponHolder.o ./build/weapons/TWeapon.o  -lgtest -lgtest_main -lpthread -o ./build/weapons/test
	./build/weapons/test
	rm ./build/weapons/test

weaponHolder: weapon
	g++ -std=c++17 -c ./weapons/TWeaponHolder.cpp -o ./build/weapons/TWeaponHolder.o

weaponTest: weapon
	g++ -std=c++17 ./weapons/TWeaponTest.cpp ./build/weapons/TWeapon.o  -lgtest -lgtest_main -lpthread -o ./build/weapons/test
	./build/weapons/test
	rm ./build/weapons/test

weapon:
	g++ -std=c++17 -c ./weapons/TWeapon.cpp -o ./build/weapons/TWeapon.o

#####################################################

clean:
	rm -r ./build/ships/*
	rm -r ./build/weapons/*
