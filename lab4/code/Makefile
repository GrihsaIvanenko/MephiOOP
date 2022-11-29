weapons: weapon
	g++ ./build/weapons/*.o -o weapon
	rm ./build/weapons/*.o

weaponTest: weapon
	g++ ./weapons/TWeaponTest.cpp ./build/weapons/TWeapon.o  -lgtest -lgtest_main -lpthread -o ./build/weapons/test
	./build/weapons/test
	rm ./build/weapons/test

weapon:
	g++ -c ./weapons/TWeapon.cpp -o ./build/weapons/TWeapon.o


