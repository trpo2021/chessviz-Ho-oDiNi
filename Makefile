CXXFLAGS = -Wall -Werror -Wextra -I scr
CXX = g++

CH_SCR = scr/chessviz/
LIB_SCR = scr/libchessviz/

CH_OBJ = obj/scr/chessviz/
LIB_OBJ = obj/scr/libchessviz/
CH_BIN = bin/

.PHONY: chessviz

$(CH_BIN)chessviz.exe: $(CH_OBJ)main.o $(LIB_OBJ)libchessviz.a
	$(CXX) $(CXXFLAGS) -o $@ $^
$(LIB_OBJ)libchessviz.a: $(LIB_OBJ)func.o
	ar rcs $@ $^
$(CH_OBJ)main.o: $(CH_SCR)main.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(LIB_OBJ)func.o: $(LIB_SCR)func.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
-include main.d func.d

clean:
	rm $(CH_OBJ)*.o
	rm $(LIB_OBJ)*.o
	rm $(LIB_OBJ)*.a
	rm $(CH_BIN)*.exe
