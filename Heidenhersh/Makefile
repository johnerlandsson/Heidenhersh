CC		= g++
CFLAGS	= -std=c++11 -g -I../libHeidenhersh/src -Wall
LDFLAGS	= -L../libHeidenhersh/ -l Heidenhersh
TARGET	= Heidenhersh

all: $(TARGET)

$(TARGET): Heidenhersh.cpp
	$(CC) Heidenhersh.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)
	
clean:
	rm -f $(TARGET)