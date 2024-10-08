#!/bin/bash

echo "Quelle est le nom de votre porjet"
read name

mkdir $name 
cd ./$name

touch main.c
touch $name.h

echo "#include <stdlib.h>" >> main.c
echo "#include <stdio.h>" >> main.c
echo "#include <$name.h>" >> main.c
echo "" >> main.c
echo "int main(){}" >> main.c
echo "#ifndef NOM_DU_FICHIER_H" >> $name.h
echo "#define NOM_DU_FICHIER_H" >> $name.h
echo "#endif" >> $name.h

echo "Fini"
 


