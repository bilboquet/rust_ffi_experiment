# Nom de l'exécutable
TARGET = main

# Compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -Wall

# Bibliothèques à lier
LIBS = -ldl

# Règle par défaut
all: $(TARGET)

# Règle pour l'exécutable
$(TARGET): src/*.c
	$(CC) $(CFLAGS) -o $(TARGET) src/*.c $(LIBS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)