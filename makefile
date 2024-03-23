TARGET = program

PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_FILE = ./files/
DELF = .\obj\

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
	gcc $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	gcc -c $< -o $@


.PHONY : clean
clean :
	del $(DELF) $(TARGET).exe -rf

draw:
	dot $(PREF_FILE)Tree_Graph.dot -T png > $(PREF_FILE)Tree_graph.png
	dot $(PREF_FILE)Tree_Graph.dot -T svg > $(PREF_FILE)Tree_graph.svg
