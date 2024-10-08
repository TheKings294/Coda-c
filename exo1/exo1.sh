#!/bin/bash

count=$1

while [ $count -ge 0 ]; 
do
echo $count
((count--))
done
