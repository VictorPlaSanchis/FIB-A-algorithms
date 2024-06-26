make:
	g++ -c main.cc
	g++ -o program.exe main.o
	rm *.o
	@echo "**************************************************************************************"
	@echo "*                                                                                    *"
	@echo "*  To execute the program: ./program.exe param1 [param2] [param3] [param4] [param5]  *"
	@echo "*  param1: INPUT FILE, example: ./file.txt                                           *"
	@echo "*  param2: N (length of soup), example: 10                                           *"
	@echo "*  param3: MAX WORD LENGTH, example: 10                                              *"
	@echo "*  param4: SEED (for generating the soup), example: 0                                *"
	@echo "*  param5: ED (decide what ED to use), example: 0, 1, 2 or 3                         *"
	@echo "*                                                                                    *"
	@echo "**************************************************************************************"