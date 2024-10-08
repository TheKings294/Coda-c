#!/bin/bash

echo "Donne un nombre de minutes :"
read minute
heure=$(( (minute/60) ))
minutes=$(( (minute%60) ))

echo "$minute corespond a $heure h $minutes m"
