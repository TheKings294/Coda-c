#!/bin/bash

function Hello {
	echo "Quel est votre nom"
	read name
	echo "Bonjour $name"
	
	echo "Quel est votre age"
	read age

	if [$age -ge 65];
	then 
	echo "Vous avez $age ans, vous etes senior"
	elif [$ age -ge 18]; 
	then 
	echo "Vous avez $age ans, vous etes adulte"
	else 
	echo "Vous etes un tous petit enfant"
	fi

}

Hello

echo "entrer deux nombres "
read nb1
read nb2

for (( i=5; i<0; i-- ))
do 
echo "$i"
done
