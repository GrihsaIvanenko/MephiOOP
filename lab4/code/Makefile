test: capitanInfoTest weaponHolderTest weaponTest

##################################################

capitanInfoTest: capitanInfo
	g++ -std=c++17 ./ships/TCapitanInfoTest.cpp ./build/ships/*  -lgtest -lgtest_main -lpthread -o ./build/ships/test
	./build/ships/test
	rm ./build/ships/test

capitanInfo:
	g++ -std=c++17 -c ./ships/TCapitanInfo.cpp -o ./build/ships/TCapitanInfo.o



#####################################################

weaponHolderTest: weaponHolder
	g++ -std=c++17 ./weapons/TWeaponHolderTest.cpp ./build/weapons/*  -lgtest -lgtest_main -lpthread -o ./build/weapons/test
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
