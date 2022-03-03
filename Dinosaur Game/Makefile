all				:	DinosaurFight

DinosaurFight	:   DinosaurFight.o
					g++ -o DinosaurFight.exe DinosaurFight.o
				
DinosaurFight.o	:	DinosaurFight.cpp
					g++ -I ./ -c DinosaurFight.cpp
				
clean			:	DinosaurFight.exe
					del *.o
					del DinosaurFight.exe